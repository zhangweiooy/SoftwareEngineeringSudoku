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
		TEST_METHOD(TestMethod5)//对输入文件路径的测试
		{
			char s1[] = "-s";
			char s2[] = "testerror.txt";
			bool temp = InputJudge(s1, s2);
			Assert::AreEqual(temp, false);
		}
		TEST_METHOD(TestMethod6)//对生成数独终局的测试
		{
			Initialize();
			Assert::AreEqual(src[0][0] == 9, true);
			Assert::AreEqual(src[0][1] == 1, true);
			Assert::AreEqual(src[0][2] == 2, true);
			Assert::AreEqual(src[0][3] == 3, true);
			Assert::AreEqual(src[0][4] == 4, true);
			Assert::AreEqual(src[0][5] == 5, true);
		}
		TEST_METHOD(TestMethod7)//对生成数独终局的测试
		{
			Grid temp = {
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
			Grid temp_swap;
			Swap(1, 3, 5, temp.map, temp_swap.map);

			Assert::AreEqual(temp_swap.map[0][0] == 9, true);
			Assert::AreEqual(temp_swap.map[1][0] == 3, true);
			Assert::AreEqual(temp_swap.map[2][0] == 6, true);
			Assert::AreEqual(temp_swap.map[3][0] == 7, true);
			Assert::AreEqual(temp_swap.map[4][0] == 4, true);
			Assert::AreEqual(temp_swap.map[5][0] == 1, true);
			Assert::AreEqual(temp_swap.map[6][0] == 2, true);
			Assert::AreEqual(temp_swap.map[7][0] == 8, true);
			Assert::AreEqual(temp_swap.map[8][0] == 5, true);
		}
		TEST_METHOD(TestMethod8)//对求解数独的测试（仅挖一个空）
		{
			Grid temp = {
				{
					{7,3,8,5,6,2,1,9,4},
					{5,6,2,1,9,4,7,3,8},
					{1,9,4,3,7,8,5,6,2},
					{3,8,5,6,2,1,9,4,7},
					{6,4,7,9,8,5,3,2,1},
					{9,2,1,4,3,7,6,8,5},
					{4,7,3,8,5,6,2,1,9},
					{8,5,6,2,1,9,4,7,3},
					{2,1,9,7,4,3,8,5,0}
				}
			};
			DFS(temp, 0);
			Assert::AreEqual(temp.map[8][8] == 6, true);
		}
		TEST_METHOD(TestMethod9)//对求解数独的测试（挖多个空）
		{
			Grid temp = {
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
			DFS(temp, 0);

			Assert::AreEqual(temp.map[0][0] != 0, true);
			Assert::AreEqual(temp.map[8][8] != 0, true);
		}
		TEST_METHOD(TestMethod11)//对获取当前所在宫的测试
		{
			int temp = GetPalace(5, 5);

			Assert::AreEqual(temp == 4, true);
		}
	};
}
