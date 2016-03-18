#include "stdafx.h"
#include "Parser.h"
#include <vector>
#include <string>
#include <sstream>

using namespace std;

CParser::CParser(const string &input)
{
	Parse(input);
}


CParser::~CParser()
{
}

void CParser::Parse(const string &input)
{
	string source = input;
	vector<string> numbers;
	istringstream stream(source);
	string number;
	while (getline(stream, number, ' '))
	{
		numbers.push_back(number);
	}

	switch ((int)numbers[1][0])
	{
	case 43: m_operation = Operation::ADDITION; break;
	case 45: m_operation = Operation::SUBSTRACTION; break;
	case 42: m_operation = Operation::MULTIPLICATION; break;
	case 47: m_operation = Operation::DIVISION; break;
	}

	m_num1.second = true;
	m_num2.second = true;
	m_num1 = ParseNumber(numbers[0]);
	m_num2 = ParseNumber(numbers[2]);
}

pair<vector<int>, bool> CParser::ParseNumber(const string &input)
{
	pair<vector<int>, bool> number;
	number.second = true;
	for (size_t i = 0; i < input.size(); ++i)
	{
		if (IsDigit(input[i]))
		{
			number.first.push_back(input[i] - 48);
		}
		else
		{
			if (IsPositive(input[i]))
			{
				number.second = true;
			}
			else
			{
				number.second = false;
			}
		}	
	}

	reverse(number.first.begin(), number.first.end());
	return number;
}

bool IsPositive(char symbol)
{
	if (symbol == '+')
	{
		return true;
	}

	return false;
}

bool IsDigit(char symbol)
{
	if (symbol >= '0' && symbol <= '9')
	{
		return true;
	}

	return false;
}

pair<pair<vector<int>, bool>, pair<vector<int>, bool>> CParser::GetNumbers() const
{
	pair<pair<vector<int>, bool>, pair<vector<int>, bool>> numbers;
	numbers.first = m_num1;
	numbers.second = m_num2;
	return numbers;
}

Operation CParser::GetOperation() const
{
	return m_operation;
}