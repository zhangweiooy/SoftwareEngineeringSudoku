#include"main.h"
using namespace std;
#define GetPalace(x,y) (x / 3) * 3 + y / 3

int markrow[9];
int markcol[9];
int markpalace[9];
Grid result;
int flag = 0;
int FindLocation(Grid& grid)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (grid.map[i][j] == 0)
				return i * 9 + j;
		}
	}
	return -1;
}
void DFS(Grid& grid)
{
	int loc = FindLocation(grid);
	if (loc < 0)
	{
		result = grid;
		return;
	}
	//for (int i = 0; i < 9; i++)
	//{
	//	for (int j = 0; j < 9; j++)
	//	{
			//if (grid.map[i][j] == 0)
			//{
	int i = loc / 9;
	int j = loc % 9;
	for (int num = 1; num < 10; num++)//�ֱ���1~9
	{
		int valid = (markrow[i] & (1 << num)) || (markcol[j] & (1 << num)) || (markpalace[GetPalace(i, j)] & (1 << num));
		if (valid)//����ǰ��/��/��������num��������һ������
		{
			continue;
		}
		else//�������֣�����ǵ�ǰ��/��/�������и�����
		{
			grid.map[i][j] = num;
			markrow[i] |= (1 << num);
			markcol[j] |= (1 << num);
			markpalace[GetPalace(i, j)] |= (1 << num);
		}
		DFS(grid);
		if (1)
		{
			markrow[i] ^= (1 << num);
			markcol[j] ^= (1 << num);
			markpalace[GetPalace(i, j)] ^= (1 << num);
			grid.map[i][j] = 0;
		}
	}
	//}
//	}
//}
	return;
}
void SolveSudoku(Grid grid)//�������
{
	memset(markrow, 0, sizeof(markrow));
	memset(markcol, 0, sizeof(markcol));
	memset(markpalace, 0, sizeof(markpalace));
	int num = 0;
	int blank = 0;
	for (int i = 0; i < 9; i++)//��¼�¸��и��и��������ֵĳ������
	{
		for (int j = 0; j < 9; j++)
		{
			if (grid.map[i][j] != 0)
			{
				num = grid.map[i][j];
				markrow[i] |= 1 << num;
				markcol[j] |= 1 << num;
				markpalace[GetPalace(i, j)] |= 1 << num;
			}
			else
				blank++;
		}
	}
	DFS(grid);
	FILE* fp;
	fp = fopen("sudokusolution.txt", "a");
	PrintFile(fp, result, flag);
	flag = 1;
	fclose(fp);
	return;
}