#include"main.h"
using namespace std;
void PrintFile(FILE* fp, Grid grid, int flag)//将一个数独终局写入指定文件中
{
	if (flag != 0)//两个结果之间输出一个换行
	{
		fputc('\n', fp);
		fputc('\n', fp);
	}
	for (int i = 0; i < 9; i++)
	{
		if (i)
			fputc('\n', fp);
		for (int j = 0; j < 9; j++)
		{
			char temp = (grid.map[i][j] + '0');//将整型转为字符型以便用fwrite输出
			if (j == 0)
				fwrite(&temp, 1, 1, fp);
			else
			{
				fputc(' ', fp);
				fwrite(&temp, 1, 1, fp);
			}
		}
	}
	return;
}