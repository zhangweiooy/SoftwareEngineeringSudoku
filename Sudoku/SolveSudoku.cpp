#include"main.h"
using namespace std;
#define GetPalace(x, y) (x / 3) * 3 + y / 3//获取当前所在的九宫格的序号
//位运算标记
int markrow[9];//标记每一行各个数字是否被使用过
int markcol[9];//标记每一列各个数字是否被使用过
int markpalace[9];//标记每一个九宫格内各个数字是否被使用过
int flag = 0;//用于控制各个数独结果间空一行
bool DFS(Grid& grid, int count)//从第一个格开始搜索结果
{
	if (count == 81)
	{
		return true;
	}
	int i = count / 9, j = count % 9;
	if (grid.map[i][j] == 0)
	{
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
			if (DFS(grid, count + 1))//继续搜索下一个格，若无结果则回溯
			{
				return true;
			}
			else
			{
				markrow[i] ^= (1 << num);
				markcol[j] ^= (1 << num);
				markpalace[GetPalace(i, j)] ^= (1 << num);
				grid.map[i][j] = 0;
			}
		}
	}
	else//若当前格已有数据则继续搜索下一个
	{
		return DFS(grid, count + 1);
	}
	return false;
}
void SolveSudoku(Grid grid, FILE* fp)//求解数独并将其结果写入指定文件中
{
	memset(markrow, 0, sizeof(markrow));
	memset(markcol, 0, sizeof(markcol));
	memset(markpalace, 0, sizeof(markpalace));//初始化
	int num = 0;
	for (int i = 0; i < 9; i++)//标记各行各列各宫中数字的出现情况
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
	DFS(grid, 0);
	PrintFile(fp, grid, flag);
	flag = 1;
	return;
}