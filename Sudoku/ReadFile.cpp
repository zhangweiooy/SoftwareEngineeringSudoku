#include"main.h"
using namespace std;
void ReadFile(FILE* fp)//��ָ���ļ��ж�ȡһ������
{
	Grid grid;
	int temp = 0, count = 0;
	FILE* fp_s;
	fp_s = fopen("sudokusolution.txt", "w");//����������Ľ��
	while (!feof(fp)) {
		if (fscanf(fp, "%d", &temp) == EOF)
			break;
		grid.map[count / 9][count % 9] = temp;
		count++;
		if (count == 81)//������81��������������������
		{
			SolveSudoku(grid, fp_s);//��grid��������д��fp_s��
			count = 0;
		}
	}
	fclose(fp_s);
	return;
}