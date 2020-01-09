#include"main.h"
using namespace std;
int src[40320][9];//��ŵ�һ�е������������
int map[9][9];//��������
int shift[9] = { 0,3,6,1,4,7,2,5,8 };//��һ���������������е�λ��
int swap0to2[2][3] = { {0,1,2},{0,2,1} };//0~2�е���������
int swap3to5[6][3] = { {3,4,5},{3,5,4},{4,3,5},{4,5,3},{5,4,3},{5,3,4} };//3~5�е���������
int swap6to8[6][3] = { {6,7,8},{6,8,7},{7,6,8},{7,8,6},{8,7,6},{8,6,7} };//6~7�е���������

void Initialize()//Ԥ�ȳ�ʼ������ȫ����
{
	int init[9] = { 9,1,2,3,4,5,6,7,8 };//��һλ��Ҫ��ȡ��
	int count = 0;
	do
	{
		for (int i = 0; i < 9; i++)
		{
			src[count][i] = init[i];
		}
		count++;
	} while (next_permutation(init + 1, init + 9));
}
void Swap(int a, int b, int c, int map[][9], int map_swap[][9])//������֮�佻����������
{
	for (int i = 0; i < 3; i++)
	{
		*map_swap[i] = *map[swap0to2[a][i]];
	}
	for (int i = 3; i < 6; i++)
	{
		*map_swap[i] = *map[swap3to5[b][i - 3]];
	}
	for (int i = 6; i < 9; i++)
	{
		*map_swap[i] = *map[swap6to8[c][i - 6]];
	}
	return;
}
void Print(FILE* fp, int map[][9], int flag)
{
	if (flag != 0)//�������֮�����һ������
		fputc('\n', fp);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (j == 0)
				fprintf(fp, "%d", map[i][j]);
			else
				fprintf(fp, "%c%d", ' ', map[i][j]);
		}
		fputc('\n', fp);
	}
	return;
}
void CreateSudoku(int n)
{
	Initialize();
	FILE* fp;
	fp = fopen("sudoku.txt", "w");
	int count = 0;
	for (int i = 0; i < 40320; i++)
	{
		for (int j = 0; j < 9; j++)//�����������ĵ�һ��
		{
			map[0][j] = src[i][j];
		}
		for (int j = 1; j < 9; j++)//�ƶ���������8��
		{
			for (int k = 0; k < 9; k++)
			{
				map[j][k] = map[0][(k + shift[j]) % 9];
			}
		}
		int map_swap[9][9];
		for (int j = 0; j < 2; j++)//ǰ���е����ֱ任
		{
			for (int jj = 0; jj < 6; jj++)//�м����е����ֱ任
			{
				for (int jjj = 0; jjj < 6; jjj++)//�����е����ֱ任
				{
					memset(map_swap, 0, sizeof(map_swap));
					if (count < n)
					{
						Swap(j, jj, jjj, map, map_swap);//�õ�9�е�һ�ֱ任��Ľ��
						Print(fp, map_swap, count);
						count++;
					}
					else if (count == n)
					{
						fclose(fp);
						return;
					}
					else
					{
						fclose(fp);
						cout << "����" << endl;
						return;
					}
				}
			}
		}
	}
	return;
}