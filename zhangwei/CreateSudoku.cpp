#include"main.h"
using namespace std;
int src[40320][9];//存放第一行的所有排列情况
int map[9][9];//数独盘面
int shift[9] = { 0,3,6,1,4,7,2,5,8 };//第一行右移生成其余行的位数
int swap0to2[2][3] = { {0,1,2},{0,2,1} };//0~2行的排列索引
int swap3to5[6][3] = { {3,4,5},{3,5,4},{4,3,5},{4,5,3},{5,4,3},{5,3,4} };//3~5行的排列索引
int swap6to8[6][3] = { {6,7,8},{6,8,7},{7,6,8},{7,8,6},{8,7,6},{8,6,7} };//6~7行的排列索引

void Initialize()//预先初始化所有全排列
{
	int init[9] = { 9,1,2,3,4,5,6,7,8 };//第一位按要求取九
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
void Swap(int a, int b, int c, int map[][9], int map_swap[][9])//各三行之间交换生成数独
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
	if (flag != 0)//两个结果之间输出一个换行
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
		for (int j = 0; j < 9; j++)//存放数独盘面的第一行
		{
			map[0][j] = src[i][j];
		}
		for (int j = 1; j < 9; j++)//移动生成其余8行
		{
			for (int k = 0; k < 9; k++)
			{
				map[j][k] = map[0][(k + shift[j]) % 9];
			}
		}
		int map_swap[9][9];
		for (int j = 0; j < 2; j++)//前三行的两种变换
		{
			for (int jj = 0; jj < 6; jj++)//中间三行的六种变换
			{
				for (int jjj = 0; jjj < 6; jjj++)//后三行的六种变换
				{
					memset(map_swap, 0, sizeof(map_swap));
					if (count < n)
					{
						Swap(j, jj, jjj, map, map_swap);//得到9行的一种变换后的结果
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
						cout << "错误！" << endl;
						return;
					}
				}
			}
		}
	}
	return;
}