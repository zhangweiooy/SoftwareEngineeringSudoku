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
		TEST_METHOD(TestMethod1)//测试
		{
			int a = 1, b = 2;
			swap(a, b);
			Assert::AreEqual(a == 2, true);
			Assert::AreEqual(b == 1, true);
		}
		TEST_METHOD(TestMethod2)//对输入参数的测试
		{
			char s1[] = "-a";
			char s2[] = "100000";
			bool temp = InputJudge(s1, s2);
			Assert::AreEqual(temp, false);
		}
		TEST_METHOD(TestMethod3)//对输入数据范围的测试（过大）
		{
			char s1[] = "-c";
			char s2[] = "2000000";
			bool temp = InputJudge(s1, s2);
			Assert::AreEqual(temp, false);
		}
		TEST_METHOD(TestMethod4)//对输入数据范围的测试（过小）
		{
			char s1[] = "-c";
			char s2[] = "0";
			bool temp = InputJudge(s1, s2);
			Assert::AreEqual(temp, false);
		}
		TEST_METHOD(TestMethod5)//对输入数据范围的测试（正常）
		{
			char s1[] = "-c";
			char s2[] = "20";
			bool temp = InputJudge(s1, s2);
			Assert::AreEqual(temp, true);
		}
		TEST_METHOD(TestMethod6)//对输入文件路径的测试（错误）
		{
			char s1[] = "-s";
			char s2[] = "testerror.txt";
			bool temp = InputJudge(s1, s2);
			Assert::AreEqual(temp, false);
		}
		TEST_METHOD(TestMethod7)//对输入文件路径的测试（正确）
		{
			char s1[] = "-s";
			char s2[] = "sudokupuzzle.txt";
			bool temp = InputJudge(s1, s2);
			Assert::AreEqual(temp, true);
		}
		TEST_METHOD(TestMethod8)//对生成数独终局的测试
		{
			Initialize();
			Assert::AreEqual(src[0][0] == 9, true);
			Assert::AreEqual(src[0][1] == 1, true);
			Assert::AreEqual(src[0][2] == 2, true);
			Assert::AreEqual(src[0][3] == 3, true);
			Assert::AreEqual(src[0][4] == 4, true);
			Assert::AreEqual(src[0][5] == 5, true);
		}
		TEST_METHOD(TestMethod9)//对生成数独终局的测试
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
		TEST_METHOD(TestMethod10)//对生成数独终局的测试
		{
			CreateSudoku(1);
			FILE* fp;
			fp = fopen("sudoku.txt", "r");
			int temp = 0;
			fscanf(fp, "%d", &temp);
			fclose(fp);
			Assert::AreEqual(temp == 9, true);
		}
		TEST_METHOD(TestMethod11)//对求解数独的测试（仅挖一个空）
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
		TEST_METHOD(TestMethod12)//对求解数独的测试（挖多个空）
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
		TEST_METHOD(TestMethod13)//对获取当前所在宫的测试
		{
			int temp = GetPalace(5, 5);

			Assert::AreEqual(temp == 4, true);
		}
	};
}
