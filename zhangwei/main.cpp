#include"main.h"
using namespace std;
int main(int argc, char *argv[])
{
/*	if (strcmp(argv[1],"-c")==0)
	{
		int len = strlen(argv[2]);
		for(int i=0;i<len;i++)//�ж������Ƿ�Ϊ����
		{
			if (isdigit(argv[2][i]))
				continue;
			else
			{
				cout << "���������֣�" << endl;
				return  0;
			}
		}
		if (len > 7)
		{
			cout << "�������ֹ���" << endl;
			return  0;
		}
		int n = atoi(argv[2]);
		if (n > 1000000 || n < 1)//�ж������Ƿ���Ҫ��Χ��
		{
			cout << "�������ֲ��Ϸ���" << endl;
			return  0;
		}
		else
		{
			CreateSudoku(n);
		}
	}
	else if (strcmp(argv[1],"-s")==0)
	{
		/////////
	}*/CreateSudoku(100);
	return 0;
}