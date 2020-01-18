#pragma once
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
typedef struct node //保存一个数独盘的信息
{
	int map[9][9];
}Grid;
bool InputJudge(char p1[], char p2[]);
void CreateSudoku(int n);//生成指定数量的数独终局
void SolveSudoku(Grid grid, FILE* fp);//求解数独并将其结果写入指定文件中
void PrintFile(FILE* fp, Grid grid, int flag);//将一个数独终局写入指定文件中
void ReadFile(FILE* fp);//从指定文件中读取一个数独