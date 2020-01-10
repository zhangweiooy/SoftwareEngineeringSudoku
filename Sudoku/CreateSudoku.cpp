#include"main.h"
using namespace std;
int src[40320][9];//存放第一行的所有排列情况
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
void Swap(int a, int b, int c, int map[][9], int map_swap[][9])//各三行之间交换生成数独1
{
	for (int i = 0; i < 3; i++)
	{
		copy(map[swap0to2[a][i]],map[swap0to2[a][i]]+9,map_swap[i]);
	}
	for (int i = 3; i < 6; i++)
	{
		copy(map[swap3to5[b][i-3]], map[swap3to5[b][i-3]] + 9, map_swap[i]);
	}
	for (int i = 6; i < 9; i++)
	{
		copy(map[swap6to8[c][i-6]], map[swap6to8[c][i-6]] + 9, map_swap[i]);
	}
	return;
}

void CreateSudoku(int n)
{
	Initialize();
	FILE* fp;
	fp = fopen("sudoku.txt", "w");
	int count = 0;
	Grid grid;
	for (int i = 0; i < 40320; i++)
	{
		for (int j = 0; j < 9; j++)//存放数独盘面的第一行
		{
			grid.map[0][j] = src[i][j];
		}
		for (int j = 1; j < 9; j++)//移动生成其余8行
		{
			for (int k = 0; k < 9; k++)
			{
				grid.map[j][k] = grid.map[0][(k + shift[j]) % 9];
			}
		}
		Grid grid_swap;
		for (int j = 0; j < 2; j++)//前三行的两种变换
		{
			for (int jj = 0; jj < 6; jj++)//中间三行的六种变换
			{
				for (int jjj = 0; jjj < 6; jjj++)//后三行的六种变换
				{
					memset(grid_swap.map, 0, sizeof(grid_swap.map));
					if (count < n)
					{
						Swap(j, jj, jjj, grid.map, grid_swap.map);//得到9行的一种变换后的结果
						PrintFile(fp, grid_swap, count);
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