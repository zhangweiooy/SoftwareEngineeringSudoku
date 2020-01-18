#include"main.h"
using namespace std;
int main(int argc, char* argv[])
{
	if (argc != 3)//对命令行参数的合法性进行判断
	{
		cout << "输入不合法！" << endl;
		return 0;
	}
	else
	{
		if (!InputJudge(argv[1], argv[2]))
			cout << "输入不合法！ 请检查：输入参数错误/-c时输入非数字/输入数据不在范围内/-s时输入文件路径错误" << endl;
	}
	return 0;
}
bool InputJudge(char p1[], char p2[])
{
	{
		if (strcmp(p1, "-c") == 0)
		{
			int len = strlen(p2);
			for (int i = 0; i < len; i++)//判断输入是否为数字
			{
				if (isdigit(p2[i]))
					continue;
				else
					return false;
			}
			if (len > 7)
				return false;
			int n = atoi(p2);
			if (n > 1000000 || n < 1)//判断数字是否在要求范围内
				return false;
			else
				CreateSudoku(n);
		}
		else if (strcmp(p1, "-s") == 0)
		{
			FILE* fp;
			fp = fopen(p2, "r");
			//	fp = fopen("sudokupuzzle.txt", "r");
			if (fp == NULL)
				return false;
			ReadFile(fp);
			fclose(fp);
		}
		else
			return false;
	}
	return true;
}