#include"main.h"
using namespace std;
void ReadFile(FILE* fp)//从文件中读取一个数独
{
	Grid grid;
	int temp=0,count=0;
	while (!feof(fp)) {
		if (fscanf(fp,"%d",&temp) == EOF) 
			break;
		grid.map[count / 9][count % 9] = temp;
		count++;
		if (count == 81)//若读完81个数，则对数独进行求解
		{
			SolveSudoku(grid);
			count = 0;
		}
	}
	return;
}