#include "stdafx.h"
#include <vector>
#include "LongNumber.h"

using namespace std;

CLongNumber::CLongNumber(pair<vector<int>, bool> number)
	: m_num(number.first)
	, m_size(number.first.size())
	, m_isPositive(number.second)
{
}

CLongNumber::~CLongNumber()
{
}



size_t CLongNumber::GetSize() const
{
	return m_size;
}

vector<int> CLongNumber::GetVector() const
{
	return m_num;
}

bool CLongNumber::GetNumberSymbol() const
{
	return m_isPositive;
}

void CLongNumber::SetNumberSymbol(bool isPositive)
{
	m_isPositive = isPositive;
}

void InitArray(size_t length, vector<int> &number)
{
	for (size_t i = 0; i < length; ++i)
	{
		number.push_back(0);
	}
}

void DropZeros(vector<int> &number)
{
	if (number[number.size() - 1] == 0)
	{
		number.resize(number.size() - 1);
	}
}

const CLongNumber operator + (const CLongNumber &num1, const CLongNumber &num2)
{
	if (num1.GetNumberSymbol() != num2.GetNumberSymbol())
	{
		return (CLongNumber)num1 - (CLongNumber)num2;
	}

	vector<int> first = num1.GetVector();
	vector<int> second = num2.GetVector();
	size_t length = GetNewSize(num1.GetSize(), num2.GetSize());
	size_t minLength = num1.GetSize() > num2.GetSize() ? num2.GetSize() : num1.GetSize();

	pair<vector<int>, bool> result;
	result.second = num1.GetNumberSymbol() && num2.GetNumberSymbol() ? true : false;

	InitArray(length, result.first);
	for (size_t i = 0; i < minLength; ++i)
	{
		result.first[i] += first[i] + second[i];
		result.first[i + 1] += result.first[i] / 10;
		result.first[i] %= 10;
	}

	if (num1.GetSize() > num2.GetSize())
	{
		for (size_t i = minLength; i < length - 1; ++i)
		{
			result.first[i] += first[i];
		}
	}
	else
	{
		for (size_t i = minLength; i < length - 1; ++i)
		{
			result.first[i] += second[i];
		}
	}

	DropZeros(result.first);
	reverse(result.first.begin(), result.first.end());
	return result;
}

const CLongNumber operator - (const CLongNumber &num1, const CLongNumber &num2)
{
	pair<vector<int>, bool> result;

	return result;
}

const CLongNumber operator * (const CLongNumber &num1, const CLongNumber &num2)
{
	pair<vector<int>, bool> result;

	return result;
}

const CLongNumber operator / (const CLongNumber &num1, const CLongNumber &num2)
{
	pair<vector<int>, bool> result;

	return result;
}

size_t GetNewSize(const size_t &size_a, const size_t &size_b)
{
	if (size_a > size_b)
	{
		return size_a + 1;
	}

	return size_b + 1;
}