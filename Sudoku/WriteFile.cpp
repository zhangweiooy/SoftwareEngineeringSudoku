#include"main.h"
using namespace std;
void PrintFile(FILE* fp, Grid grid, int flag)//��һ�������վ�д��ָ���ļ���
{
	if (flag != 0)//�������֮�����һ������
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
			if (j == 0)
				fprintf(fp, "%d", grid.map[i][j]);
			else
				fprintf(fp, "%c%d", ' ', grid.map[i][j]);
		}
	}
	return;
}