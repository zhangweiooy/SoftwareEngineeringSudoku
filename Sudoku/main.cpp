#include"main.h"
using namespace std;
int main(int argc, char* argv[])
{
	if (argc != 3)//�������в����ĺϷ��Խ����ж�
	{
		cout << "���벻�Ϸ���" << endl;
		return 0;
	}
	else
	{
		if (!InputJudge(argv[1], argv[2]))
			cout << "���벻�Ϸ��� ���飺�����������/-cʱ���������/�������ݲ��ڷ�Χ��/-sʱ�����ļ�·������" << endl;
	}
	return 0;
}
bool InputJudge(char p1[], char p2[])
{
	{
		if (strcmp(p1, "-c") == 0)
		{
			int len = strlen(p2);
			for (int i = 0; i < len; i++)//�ж������Ƿ�Ϊ����
			{
				if (isdigit(p2[i]))
					continue;
				else
					return false;
			}
			if (len > 7)
				return false;
			int n = atoi(p2);
			if (n > 1000000 || n < 1)//�ж������Ƿ���Ҫ��Χ��
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