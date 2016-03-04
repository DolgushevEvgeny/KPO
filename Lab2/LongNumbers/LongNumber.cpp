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
	size_t zeroCount = 0;
	for (size_t i = number.size() - 1; i > 0; --i)
	{
		if (number[i] == 0)
		{
			++zeroCount;
		}
		else
		{
			break;
		}
	}

	number.resize(number.size() - zeroCount);
}

void SumVectors(const vector<int> &first, const vector<int> &second, vector<int> &result, size_t length)
{
	for (size_t i = 0; i < length; ++i)
	{
		result[i] += first[i] + second[i];
		result[i + 1] += result[i] / 10;
		result[i] %= 10;
	}
}

void AddLeftOver(const vector<int> &num, vector<int> &result, size_t index, size_t length)
{
	for (size_t i = index; i < length - 1; ++i)
	{
		result[i] += num[i];
	}
}

const CLongNumber operator + (const CLongNumber &num1, const CLongNumber &num2)
{
	vector<int> first = num1.GetVector();
	vector<int> second = num2.GetVector();
	size_t length = GetNewSize(num1.GetSize(), num2.GetSize());
	size_t minLength = num1.GetSize() > num2.GetSize() ? num2.GetSize() : num1.GetSize();

	pair<vector<int>, bool> result;
	result.second = true;

	InitArray(length, result.first);
	SumVectors(num1.GetVector(), num2.GetVector(), result.first, minLength);

	if (num1.GetSize() > num2.GetSize())
	{
		AddLeftOver(num1.GetVector(), result.first, minLength, length);
	}
	else
	{
		AddLeftOver(num2.GetVector(), result.first, minLength, length);
	}

	DropZeros(result.first);
	reverse(result.first.begin(), result.first.end());
	return (CLongNumber)result;
}

void Subst(vector<int> first, vector<int> second, vector<int> &result, size_t length)
{
	for (size_t i = 0; i < length; ++i) // ������ �� ���� �������� �����, ������� � ����������, �� ������ �� �������
	{
		if (i < (length - 1)) // ���� ������� ������ ����� �� ������
		{
			first[i + 1]--; // � ���������� ������� �������� ����� �������� 1.
			result[i] += 10 + first[i]; // � ����� ���������� ����� �������� �������� ������� �������� ����� � 10-��
		}
		else  // ���� ������� ������ ����� - ������
		{
			result[i] += first[i]; // � ����� ��������� �������� �������� ������� �������� �����
		}

		result[i] -= second[i]; // �������� �������� �������� ������� �������� �����

		if (result[i] / 10 > 0) // ���� �������� � ������� ������� �������������
		{
			first[i + 1]++; // ��������� ������� � ������� ������
			result[i] %= 10; // � ������� ������� �������� ��
		}
	}
}

int MatchingNumbers(const vector<int> &first, const vector<int> &second, size_t &length)
{
	int k = 3; // ���� � == 3, ������ ����� ���������� ������
	length = first.size();
	if (first.size() > second.size())
	{
		length = first.size();
		k = 1; // ���� � == 1, ������ ������ ����� ������� �������
	}
	else
	{
		if (second.size() > first.size())
		{
			length = second.size();
			k = 2; // ���� � == 2, ������ ������ ����� ������� �������
		}
		else // ���� ����� ���������� ������, �� ���������� �������� �� ����
		{
			for (size_t i = 0; i < length; ++i) // ����������� ��������� ����� �����
			{
				if (first[i] > second[i]) // ���� ������ ������� ����� ������
				{
					k = 1; // ������ ������ ����� ������� �������
					break; // ����� �� ����� for
				}
				if (second[i] > first[i]) // ���� ������ ������� ����� ������
				{
					k = 2; // ������ ������ ����� ������� �������
					break; // ����� �� ����� for
				}
			} // ����� for
		}
	}

	return k;
}

const CLongNumber operator - (const CLongNumber &num1, const CLongNumber &num2)
{
	vector<int> first = num1.GetVector();
	vector<int> second = num2.GetVector();
	size_t length = GetNewSize(num1.GetSize(), num2.GetSize());
	size_t minLength = num1.GetSize() > num2.GetSize() ? num2.GetSize() : num1.GetSize();

	pair<vector<int>, bool> result;
	InitArray(length, result.first);

	reverse(first.begin(), first.end());
	reverse(second.begin(), second.end());
	if (MatchingNumbers(first, second, length) == 1)
	{
		reverse(first.begin(), first.end());
		reverse(second.begin(), second.end());
		Subst(first, second, result.first, minLength);
		result.second = true;
		AddLeftOver(num1.GetVector(), result.first, minLength, length + 1);
	}
	else
	{
		reverse(first.begin(), first.end());
		reverse(second.begin(), second.end());
		Subst(second, first, result.first, minLength);
		result.second = false;
		AddLeftOver(num2.GetVector(), result.first, minLength, length + 1);
	}
	
	DropZeros(result.first);
	reverse(result.first.begin(), result.first.end());
	return (CLongNumber)result;
}

const CLongNumber operator * (const CLongNumber &num1, const CLongNumber &num2)
{
	vector<int> first = num1.GetVector();
	vector<int> second = num2.GetVector();
	size_t length = num1.GetSize() + num2.GetSize() + 1;

	pair<vector<int>, bool> result;
	result.second = true;
	InitArray(length, result.first);

	reverse(first.begin(), first.end());
	reverse(second.begin(), second.end());
	for (size_t i = 0; i < first.size(); ++i)
	{
		for (size_t j = 0, carry = 0; j < second.size() || carry; ++j)
		{
			long long cur = result.first[i + j] + first[i] * 1ll * (j < second.size() ? second[j] : 0) + carry;
			result.first[i + j] = int(cur % 10);
			carry = int(cur / 10);
		}
	}

	DropZeros(result.first);
	reverse(result.first.begin(), result.first.end());
	return (CLongNumber)result;
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