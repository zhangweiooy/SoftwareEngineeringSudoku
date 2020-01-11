#include"main.h"
using namespace std;
#define GetPalace(x,y) (x / 3) * 3 + y / 3

int markrow[9];
int markcol[9];
int markpalace[9];
int blank ;//记录空格数
void DFS(Grid &grid)
{
	if (blank<=0)
	{
		return;
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (grid.map[i][j] == 0)
			{
				for (int num = 1; num < 10; num++)//分别尝试1~9
				{
					int valid = (markrow[i]&(1<<num)) || (markcol[j]&(1<<num)) || (markpalace[GetPalace(i, j)]&(1<<num));
					if (valid)//若当前行/列/宫中已有num，则尝试下一个数字
					{
						continue;
					}
					else//填入数字，并标记当前行/列/宫中已有该数字
					{
						grid.map[i][j] = num;
						markrow[i] |= (1 << num);
						markcol[j] |= (1 << num);
						markpalace[GetPalace(i,j)] |= (1 << num);
						blank--;
					}
					DFS(grid);
					if (blank > 0)
					{
						markrow[i] ^= (1 << num);
						markcol[j] ^= (1 << num);
						markpalace[GetPalace(i, j)] ^= (1 << num);
						grid.map[i][j] = 0;
					}
				}
			}
		}
	}
	return;
}
void SolveSudoku(Grid grid)//求解数独
{
	memset(markrow, 0, sizeof(markrow));
	memset(markcol, 0, sizeof(markcol));
	memset(markpalace, 0, sizeof(markpalace));
	int num = 0;
	blank = 0;
	for (int i = 0; i < 9; i++)//记录下各行各列各宫中数字的出现情况
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
	fp = fopen("sudokusolution.txt", "w");
	PrintFile(fp, grid, 1);
	fclose(fp);
	return;
}