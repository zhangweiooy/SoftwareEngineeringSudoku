#include"main.h"
using namespace std;
#define GetPalace(x,y) (x / 3) * 3 + y / 3

int markrow[9];
int markcol[9];
int markpalace[9];
int flag = 0;
bool DFS(Grid& grid,int count)
{
	if (count ==81)
	{
		return true;
	}
	int i = count / 9, j = count % 9;
	if (grid.map[i][j] == 0)
		for (int num = 1; num < 10; num++)//分别尝试1~9
		{
			int valid = (markrow[i] & (1 << num)) || (markcol[j] & (1 << num)) || (markpalace[GetPalace(i, j)] & (1 << num));
			if (valid)//若当前行/列/宫中已有num，则尝试下一个数字
			{
				continue;
			}
			else//填入数字，并标记当前行/列/宫中已有该数字
			{
				grid.map[i][j] = num;
				markrow[i] |= (1 << num);
				markcol[j] |= (1 << num);
				markpalace[GetPalace(i, j)] |= (1 << num);
			}
			if(DFS(grid, count + 1))
				return true;
			markrow[i] ^= (1 << num);
			markcol[j] ^= (1 << num);
			markpalace[GetPalace(i, j)] ^= (1 << num);
			grid.map[i][j] = 0;
		}
	else
		return DFS(grid, count + 1);
	return false;
}
void SolveSudoku(Grid grid,FILE *fp)//求解数独
{
	memset(markrow, 0, sizeof(markrow));
	memset(markcol, 0, sizeof(markcol));
	memset(markpalace, 0, sizeof(markpalace));
	int num = 0;
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
		}
	}
	DFS(grid,0);
	PrintFile(fp, grid, flag);
	flag = 1;
	return;
}