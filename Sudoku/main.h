#pragma once
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
typedef struct node //����һ�������̵���Ϣ
{
	int map[9][9];
}Grid;
bool InputJudge(char p1[], char p2[]);
void CreateSudoku(int n);//����ָ�������������վ�
void SolveSudoku(Grid grid, FILE* fp);//���������������д��ָ���ļ���
void PrintFile(FILE* fp, Grid grid, int flag);//��һ�������վ�д��ָ���ļ���
void ReadFile(FILE* fp);//��ָ���ļ��ж�ȡһ������