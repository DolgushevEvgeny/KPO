// LongNumbers.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


using namespace std;

void Sum(CLongNumber num1, CLongNumber num2, CParser parser, ofstream &output)
{
	CLongNumber result = num1 + num2;

	output << num1.ToString() << " " << "+" << " " << num2.ToString() << " = " << result.ToString() << endl;
}

void Sub(CLongNumber num1, CLongNumber num2, CParser parser, ofstream &output)
{
 	CLongNumber result = num1 - num2;

	output << num1.ToString() << " " << "-" << " " << num2.ToString() << " = " << result.ToString() << endl;
}

void Mult(CLongNumber num1, CLongNumber num2, CParser parser, ofstream &output)
{
	CLongNumber result = num1 * num2;

	output << num1.ToString() << " " << "*" << " " << num2.ToString() << " = " << result.ToString() << endl;
}

void Div(CLongNumber num1, CLongNumber num2, CParser parser, ofstream &output)
{
	CLongNumber result;
	try
	{
		result = num1 / num2;
		output << num1.ToString() << " " << "/" << " " << num2.ToString() << " = " << result.ToString() << endl;
	}
	catch (const runtime_error &e)
	{
		output << e.what() << endl;
	}
}

void Test()
{
	{
		pair<vector<int>, bool> num1;
		num1.first = { 8, 9, 6, 3, 4, 5, 9, 7, 8, 9 };
		num1.second = true;
		reverse(num1.first.begin(), num1.first.end());

		pair<vector<int>, bool> num2;
		num2.first = { 6, 6, 6, 6, 6, 6, 6, 6, 6, 6 };
		num2.second = true;
		reverse(num2.first.begin(), num2.first.end());

		CLongNumber result = (CLongNumber(num1) + CLongNumber(num2));

		vector<int> test = { 1, 5, 6, 3, 0, 1, 2, 6, 4, 5, 5 };
		reverse(test.begin(), test.end());
		assert(result.GetVector() == test);
	}
	{
		pair<vector<int>, bool> num1;
		num1.first = { 1, 5, 6, 3, 0, 1, 2, 6, 4, 5, 5 };
		num1.second = true;
		reverse(num1.first.begin(), num1.first.end());

		pair<vector<int>, bool> num2;
		num2.first = { 1, 1, 8, 9, 7, 6, 5, 4, 1, 2, 3 };
		num2.second = true;
		reverse(num2.first.begin(), num2.first.end());

		CLongNumber result = (CLongNumber(num1) - CLongNumber(num2));

		vector<int> test = { 3, 7, 3, 2, 4, 7, 2, 3, 3, 2 };
		reverse(test.begin(), test.end());
		assert(result.GetVector() == test);
	}
	{
		pair<vector<int>, bool> num1;
		num1.first = { 1, 5, 6, 3, 0, 1, 2, 6, 4, 5, 5 };
		num1.second = true;
		reverse(num1.first.begin(), num1.first.end());

		pair<vector<int>, bool> num2;
		num2.first = { 1, 1, 8, 9, 7, 6, 5, 4, 1 };
		num2.second = true;
		reverse(num2.first.begin(), num2.first.end());

		CLongNumber result = CLongNumber(num1) - CLongNumber(num2);

		vector<int> test = { 1, 5, 5, 1, 1, 1, 4, 9, 9, 1, 4 };
		reverse(test.begin(), test.end());
		assert(result.GetVector() == test);
	}
	{
		pair<vector<int>, bool> num1;
		num1.first = { 1, 1, 8, 9, 7, 6, 5, 4, 1 };
		num1.second = true;
		reverse(num1.first.begin(), num1.first.end());

		pair<vector<int>, bool> num2;
		num2.first = { 1, 5, 6, 3, 0, 1, 2, 6, 4, 5, 5 };
		num2.second = true;
		reverse(num2.first.begin(), num2.first.end());

		CLongNumber result = CLongNumber(num1) - CLongNumber(num2);

		vector<int> test = { 1, 5, 5, 1, 1, 1, 4, 9, 9, 1, 4 };
		reverse(test.begin(), test.end());
		assert(result.GetVector() == test);
	}
	{
		pair<vector<int>, bool> num1;
		num1.first = { 8, 9, 6, 3, 4, 5, 9, 7, 8, 9 };
		num1.second = true;
		reverse(num1.first.begin(), num1.first.end());

		pair<vector<int>, bool> num2;
		num2.first = { 6, 6, 6, 6, 6, 6, 6, 6, 6, 6 };
		num2.second = true;
		reverse(num2.first.begin(), num2.first.end());

		CLongNumber result(CLongNumber(num1) * CLongNumber(num2));

		vector<int> test = { 5, 9, 7, 5, 6, 3, 9, 8, 5, 8, 7, 3, 5, 7, 6, 9, 3, 4, 7, 4 };
		reverse(test.begin(), test.end());
		assert(result.GetVector() == test);
	}
	{
		pair<vector<int>, bool> num1;
		num1.first = { 8, 9, 6, 3, 4, 5, 9, 7, 8, 9 };
		num1.second = true;
		reverse(num1.first.begin(), num1.first.end());

		pair<vector<int>, bool> num2;
		num2.first = { 6, 6, 6, 6, 6, 6, 6, 6 };
		num2.second = true;
		reverse(num2.first.begin(), num2.first.end());

		CLongNumber result(CLongNumber(num1) * CLongNumber(num2));
		vector<int> test = { 5, 9, 7, 5, 6, 3, 9, 7, 9, 9, 5, 7, 6, 9, 3, 4, 7, 4 };
		reverse(test.begin(), test.end());
		assert(result.GetVector() == test);
	}
	{
		pair<vector<int>, bool> num1;
		num1.first = { 8, 9, 6, 3, 4, 5, 9, 7, 8, 9 };
		num1.second = true;
		reverse(num1.first.begin(), num1.first.end());

		pair<vector<int>, bool> num2;
		num2.first = { 0 };
		num2.second = true;
		reverse(num2.first.begin(), num2.first.end());

		CLongNumber result(CLongNumber(num1) * CLongNumber(num2));
		vector<int> test = { 0 };
		assert(result.GetVector() == test);
	}
	{
		pair<vector<int>, bool> num1;
		num1.first = { 6, 6, 6, 6, 6, 6, 6, 6, 6, 6 };
		num1.second = true;
		reverse(num1.first.begin(), num1.first.end());

		pair<vector<int>, bool> num2;
		num2.first = { 6, 6, 6, 6, 6, 6, 6, 6, 6, 6 };
		num2.second = true;
		reverse(num2.first.begin(), num2.first.end());

		CLongNumber result(CLongNumber(num1) / CLongNumber(num2));
		vector<int> test = { 1 };
		assert(result.GetVector() == test);
	}
	{
		pair<vector<int>, bool> num1;
		num1.first = { 1, 2 };
		num1.second = true;
		reverse(num1.first.begin(), num1.first.end());

		pair<vector<int>, bool> num2;
		num2.first = { 2 };
		num2.second = true;
		reverse(num2.first.begin(), num2.first.end());

		CLongNumber result(CLongNumber(num1) / CLongNumber(num2));
		vector<int> test = { 6 };
		assert(result.GetVector() == test);
	}
	{
		pair<vector<int>, bool> num1;
		num1.first = { 1, 7, 1, 1, 9, 9, 9, 9, 9, 9, 8, 2, 8, 8 };
		num1.second = true;
		reverse(num1.first.begin(), num1.first.end());

		pair<vector<int>, bool> num2;
		num2.first = { 6, 6, 6, 6, 6, 6, 6, 6, 6, 6 };
		num2.second = true;
		reverse(num2.first.begin(), num2.first.end());

		CLongNumber result(CLongNumber(num1) / CLongNumber(num2));
		vector<int> test = { 2, 5, 6, 8 };
		reverse(test.begin(), test.end());
		assert(result.GetVector() == test);
	}
	{
		pair<vector<int>, bool> num1;
		num1.first = { 1, 7, 1, 1, 9, 9, 9, 9, 9, 9, 8, 2, 8, 8 };
		num1.second = true;
		reverse(num1.first.begin(), num1.first.end());

		pair<vector<int>, bool> num2;
		num2.first = { 0 };
		num2.second = true;
		reverse(num2.first.begin(), num2.first.end());

		CLongNumber result;
		try
		{
			result = CLongNumber(num1) / CLongNumber(num2);
		}
		catch (const runtime_error &e)
		{
			cout << e.what() << endl;
		}
	}
}

int main(int argc, char* argv[])
{
	ifstream inputFile;
	inputFile.open("input.txt", ifstream::in);

	ofstream outputFile;
	outputFile.open("output.txt", ofstream::out);

	//Test();

	while (inputFile.good())
	{
		string inputLine;
		getline(inputFile, inputLine);

		CParser parser(inputLine);
		switch (parser.GetOperation())
		{
		case Operation::ADDITION: Sum(CLongNumber(parser.GetNumbers().first), CLongNumber(parser.GetNumbers().second), parser, outputFile); break;
		case Operation::SUBSTRACTION: Sub(CLongNumber(parser.GetNumbers().first), CLongNumber(parser.GetNumbers().second), parser, outputFile); break;
		case Operation::MULTIPLICATION: Mult(CLongNumber(parser.GetNumbers().first), CLongNumber(parser.GetNumbers().second), parser, outputFile); break;
		case Operation::DIVISION: Div(CLongNumber(parser.GetNumbers().first), CLongNumber(parser.GetNumbers().second), parser, outputFile); break;
		}
	}

	return 0;
}

