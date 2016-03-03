// LongNumbers.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
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
	CLongNumber result(CLongNumber(parser.GetNumbers().first) * CLongNumber(parser.GetNumbers().second));

	int i = 0;
}

void Div(CLongNumber num1, CLongNumber num2, CParser parser)
{
	CLongNumber result(CLongNumber(parser.GetNumbers().first) / CLongNumber(parser.GetNumbers().second));

	int i = 0;
}

int main(int argc, char* argv[])
{
	ifstream inputFile;
	inputFile.open("input.txt", ifstream::in);

	ofstream outputFile;
	outputFile.open("output.txt", ofstream::out);

	while (inputFile.good())
	{
		string inputLine;
		getline(inputFile, inputLine);

		CParser parser(inputLine);

		switch ((int)parser.GetOperation())
		{
		case 43: Sum(CLongNumber(parser.GetNumbers().first), CLongNumber(parser.GetNumbers().second), parser); break;
		case 45: Sub(CLongNumber(parser.GetNumbers().first), CLongNumber(parser.GetNumbers().second), parser); break;
		case 42: break;
		case 47: break;
		}
	}

	return 0;
}

