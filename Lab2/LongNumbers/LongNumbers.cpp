// LongNumbers.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <assert.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "Parser.h"
#include "LongNumber.h"

using namespace std;

void Sum(CLongNumber num1, CLongNumber num2, CParser parser)
{
	CLongNumber result(num1 + num2);

	int i = 0;
}

void Sub(CLongNumber num1, CLongNumber num2, CParser parser)
{
 	CLongNumber result(num1 - num2);

	int i = 0;
}

void Mult(CLongNumber num1, CLongNumber num2, CParser parser)
{
	CLongNumber result(num1 * num2);

	int i = 0;
}

void Div(CLongNumber num1, CLongNumber num2, CParser parser)
{
	CLongNumber result(CLongNumber(parser.GetNumbers().first) / CLongNumber(parser.GetNumbers().second));

	int i = 0;
}

void TestMult()
{
	{
		pair<vector<int>, bool> num1;
		num1.first = { 8, 9, 6, 3, 4, 5, 9, 7, 8, 9 };
		num1.second = true;

		pair<vector<int>, bool> num2;
		num2.first = { 6, 6, 6, 6, 6, 6, 6, 6, 6, 6 };
		num2.second = true;

		CLongNumber result(CLongNumber(num1) * CLongNumber(num2));

		vector<int> test = { 5, 9, 7, 5, 6, 3, 9, 8, 5, 8, 7, 3, 5, 7, 6, 9, 3, 4, 7, 4 };
		assert(result.GetVector() == test);
	}
	{
		pair<vector<int>, bool> num1;
		num1.first = { 8, 9, 6, 3, 4, 5, 9, 7, 8, 9 };
		num1.second = true;

		pair<vector<int>, bool> num2;
		num2.first = { 6, 6, 6, 6, 6, 6, 6, 6 };
		num2.second = true;

		CLongNumber result(CLongNumber(num1) * CLongNumber(num2));
		vector<int> test = { 5, 9, 7, 5, 6, 3, 9, 7, 9, 9, 5, 7, 6, 9, 3, 4, 7, 4 };
		assert(result.GetVector() == test);
	}
	{
		pair<vector<int>, bool> num1;
		num1.first = { 8, 9, 6, 3, 4, 5, 9, 7, 8, 9 };
		num1.second = true;

		pair<vector<int>, bool> num2;
		num2.first = { 0 };
		num2.second = true;

		CLongNumber result(CLongNumber(num1) * CLongNumber(num2));
		vector<int> test = { 0 };
		assert(result.GetVector() == test);
	}
}

int main(int argc, char* argv[])
{
	ifstream inputFile;
	inputFile.open("input.txt", ifstream::in);

	ofstream outputFile;
	outputFile.open("output.txt", ofstream::out);

	TestMult();

	/*while (inputFile.good())
	{
		string inputLine;
		getline(inputFile, inputLine);

		CParser parser(inputLine);

		switch ((int)parser.GetOperation())
		{
		case 43: Sum(CLongNumber(parser.GetNumbers().first), CLongNumber(parser.GetNumbers().second), parser); break;
		case 45: Sub(CLongNumber(parser.GetNumbers().first), CLongNumber(parser.GetNumbers().second), parser); break;
		case 42: Mult(CLongNumber(parser.GetNumbers().first), CLongNumber(parser.GetNumbers().second), parser);break;
		case 47: break;
		}
	}*/

	return 0;
}

