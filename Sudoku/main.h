#pragma once
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
typedef struct node
{
	int map[9][9];
}Grid;
void CreateSudoku(int n);
void SolveSudoku(Grid grid);
void PrintFile(FILE* fp, Grid grid, int flag);
Grid ReadFile(FILE* fp);