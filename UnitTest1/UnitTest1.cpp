#include "pch.h"
#include "CppUnitTest.h"
#include"../Sudoku/main.h"
#include"../Sudoku/main.cpp"
#include"../Sudoku/CreateSudoku.cpp"
#include"../Sudoku/SolveSudoku.cpp"
#include"../Sudoku/WriteFile.cpp"
#include"../Sudoku/ReadFile.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)//����
		{
			int a = 1, b = 2;
			swap(a, b);
			Assert::AreEqual(a == 2, true);
			Assert::AreEqual(b == 1, true);
		}
		TEST_METHOD(TestMethod2)//����������Ĳ���
		{
			char s1[] = "-a";
			char s2[] = "100000";
			bool temp = InputJudge(s1, s2);
			Assert::AreEqual(temp, false);
		}
		TEST_METHOD(TestMethod3)//���������ݷ�Χ�Ĳ��ԣ�����
		{
			char s1[] = "-c";
			char s2[] = "2000000";
			bool temp = InputJudge(s1, s2);
			Assert::AreEqual(temp, false);
		}
		TEST_METHOD(TestMethod4)//���������ݷ�Χ�Ĳ��ԣ���С��
		{
			char s1[] = "-c";
			char s2[] = "0";
			bool temp = InputJudge(s1, s2);
			Assert::AreEqual(temp, false);
		}
		TEST_METHOD(TestMethod5)//���������ݷ�Χ�Ĳ��ԣ�������
		{
			char s1[] = "-c";
			char s2[] = "20";
			bool temp = InputJudge(s1, s2);
			Assert::AreEqual(temp, true);
		}
		TEST_METHOD(TestMethod6)//�������ļ�·���Ĳ��ԣ�����
		{
			char s1[] = "-s";
			char s2[] = "testerror.txt";
			bool temp = InputJudge(s1, s2);
			Assert::AreEqual(temp, false);
		}
		TEST_METHOD(TestMethod7)//�������ļ�·���Ĳ��ԣ���ȷ��
		{
			char s1[] = "-s";
			char s2[] = "sudokupuzzle.txt";
			bool temp = InputJudge(s1, s2);
			Assert::AreEqual(temp, true);
		}
		TEST_METHOD(TestMethod8)//�����������վֵĲ���
		{
			Initialize();
			Assert::AreEqual(src[0][0] == 9, true);
			Assert::AreEqual(src[0][1] == 1, true);
			Assert::AreEqual(src[0][2] == 2, true);
			Assert::AreEqual(src[0][3] == 3, true);
			Assert::AreEqual(src[0][4] == 4, true);
			Assert::AreEqual(src[0][5] == 5, true);
		}
		TEST_METHOD(TestMethod9)//�����������վֵĲ���
		{
			Grid grid = {
				{
					{9,1,2,3,4,5,6,7,8},
					{6,7,8,9,1,2,3,4,5},
					{3,4,5,6,7,8,9,1,2},
					{1,2,3,4,5,6,7,8,9},
					{7,8,9,1,2,3,4,5,6},
					{4,5,6,7,8,9,1,2,3},
					{8,9,1,2,3,4,5,6,7},
					{5,6,7,8,9,1,2,3,4},
					{2,3,4,5,6,7,8,9,1}
				}
			};
			Grid grid_swap;
			Swap(1, 3, 5, grid.map, grid_swap.map);

			Assert::AreEqual(grid_swap.map[0][0] == 9, true);
			Assert::AreEqual(grid_swap.map[1][0] == 3, true);
			Assert::AreEqual(grid_swap.map[2][0] == 6, true);
			Assert::AreEqual(grid_swap.map[3][0] == 7, true);
			Assert::AreEqual(grid_swap.map[4][0] == 4, true);
			Assert::AreEqual(grid_swap.map[5][0] == 1, true);
			Assert::AreEqual(grid_swap.map[6][0] == 2, true);
			Assert::AreEqual(grid_swap.map[7][0] == 8, true);
			Assert::AreEqual(grid_swap.map[8][0] == 5, true);
		}
		TEST_METHOD(TestMethod10)//�����������վֵĲ���
		{
			CreateSudoku(1);
			FILE* fp;
			fp = fopen("sudoku.txt", "r");
			int temp = 0;
			fscanf(fp, "%d", &temp);
			fclose(fp);
			Assert::AreEqual(temp == 9, true);
		}
		TEST_METHOD(TestMethod11)//����������Ĳ��ԣ�����һ���գ�
		{
			Grid grid = {
				{
					{0,3,8,5,6,2,1,9,4},
					{5,6,2,1,9,4,7,3,8},
					{1,9,4,3,7,8,5,6,2},
					{3,8,5,6,2,1,9,4,7},
					{6,4,7,9,8,5,3,2,1},
					{9,2,1,4,3,7,6,8,5},
					{4,7,3,8,5,6,2,1,9},
					{8,5,6,2,1,9,4,7,3},
					{2,1,9,7,4,3,8,5,6}
				}
			};
			FILE* fp = fopen("D:/test.txt", "w");
			SolveSudoku(grid, fp);
			fclose(fp);
			int temp = 0;
			fp = fopen("D:/test.txt", "r");
			fscanf(fp, "%d", &temp);
			fclose(fp);
			Assert::AreEqual(temp == 7, true);
		}
		TEST_METHOD(TestMethod12)//����������Ĳ��ԣ��ڶ���գ�
		{
			Grid grid = {
				{
					{0,0,7,0,0,0,1,0,0},
					{9,0,0,0,0,0,6,2,8},
					{6,0,2,0,0,0,5,9,0},
					{0,0,0,0,8,1,0,0,5},
					{0,7,0,5,0,3,0,0,0},
					{0,9,0,0,6,0,0,7,0},
					{0,0,0,0,0,5,0,0,0},
					{2,0,0,0,4,0,0,8,6},
					{0,4,0,0,3,0,0,0,0}
				}
			};
			FILE* fp = fopen("test.txt", "w");
			SolveSudoku(grid, fp);
			fclose(fp);
			int temp = 0;
			fp = fopen("test.txt", "r");
			for (int count = 0; count < 81; count++)
			{
				if (fscanf(fp, "%d", &temp) == EOF)
					break;
				grid.map[count / 9][count % 9] = temp;
			}
			fclose(fp);
			Assert::AreEqual(grid.map[0][0] != 0, true);
			Assert::AreEqual(grid.map[8][8] != 0, true);
		}
		TEST_METHOD(TestMethod13)//�Ի�ȡ��ǰ���ڹ��Ĳ���
		{
			int temp = GetPalace(5, 5);

			Assert::AreEqual(temp == 4, true);
		}
	};
}
