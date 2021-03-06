#include"main.h"
using namespace std;
bool InputJudge(char p1[], char p2[])//对输入的命令行参数的判断
{
	{
		if (strcmp(p1, "-c") == 0)
		{
			int len = (int)strlen(p2);
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
			if (fp == NULL)
				return false;
			ReadFile(fp);
			fclose(fp);
		}
		else
			return false;
	}
	return true;
}int main(int argc, char* argv[])
{
	if (argc != 3)//对命令行参数的个数进行判断
	{
		cout << "输入不合法！" << endl;
		return 0;
	}
	else
	{
		if (!InputJudge(argv[1], argv[2]))
			cout << "输入不合法！  请检查：输入参数错误/  生成终局时输入非数字/  输入数据不在范围内/  求解数独时输入文件路径错误" << endl;
	}
	return 0;
}
