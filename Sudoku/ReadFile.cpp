#include"main.h"
using namespace std;
void ReadFile(FILE* fp)//从指定文件中读取一个数独
{
	Grid grid;
	int temp = 0, count = 0;
	FILE* fp_s;
	fp_s = fopen("sudokusolution.txt", "w");//存放数独求解的结果
	while (!feof(fp)) {
		if (fscanf(fp, "%d", &temp) == EOF)
			break;
		grid.map[count / 9][count % 9] = temp;
		count++;
		if (count == 81)//若读完81个数，则对数独进行求解
		{
			SolveSudoku(grid, fp_s);//对grid进行求解后写入fp_s中
			count = 0;
		}
	}
	fclose(fp_s);
	return;
}