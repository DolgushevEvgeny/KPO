#include "stdafx.h"
#include <vector>
#include <string>
#include "LongNumber.h"
#include <algorithm>
#include <functional>

using namespace std;

CLongNumber Sqr(const CLongNumber &number)
{
	return number * number;
}

CLongNumber Sqrt(const CLongNumber &number)
{
	if (number.GetVector().size() == 1 && number.GetVector()[0] == 0)
	{
		return CLongNumber();
	}

	CLongNumber start;
	CLongNumber end = number;
	CLongNumber middle;
	for (;;)
	{
		middle = (start + end) / CLongNumber(2);
		if (middle * middle == number)
		{
			return middle;
		}
		else 
		{
			if (middle * middle > number)
			{
				if (end == middle)
				{
					return middle;
				}
				end = middle;
			}
			else
			{
				if (middle * middle < number)
				{
					if (start == middle)
					{
						return middle;
					}
				}
				start = middle;
			}
		}
	}
}


CLongNumber::CLongNumber()
	: m_isPositive(true)
{
}

CLongNumber::CLongNumber(pair<vector<int>, bool> number)
	: m_num(number.first)
	, m_size(number.first.size())
	, m_isPositive(number.second)
{
}

CLongNumber::CLongNumber(unsigned number)
	: m_isPositive(true)
{
	unsigned int num = number;
	do
	{
		m_num.push_back(num % 10);
		num /= 10;
	} while (num);

	m_size = m_num.size();
}

CLongNumber::~CLongNumber()
{
}

string CLongNumber::ToString()
{
	string result = "";
	
	for (size_t i = 0; i < m_num.size(); ++i)
	{
		result = to_string(m_num[i]) + result;
	}
	if (!m_isPositive)
	{
		result = "-" + result;
	}
	return result;
}

size_t CLongNumber::GetSize() const
{
	return m_size;
}

vector<int> CLongNumber::GetVector() const
{
	return m_num;
}

CLongNumber& CLongNumber::operator = (const CLongNumber &other)
{
	if (addressof(other) != this)
	{
		vector<int> tmp;
		this->m_size = other.m_size;
		this->m_isPositive = other.m_isPositive;
		tmp = other.m_num;
		swap(m_num, tmp);
	}

	return *this;
}

const CLongNumber CLongNumber::operator + (const CLongNumber &other) const
{
	CLongNumber result;
	size_t length;
	if (m_num.size() > other.m_num.size())
	{
		length = m_num.size();
	}
	else
	{
		length = other.m_num.size();
	}

	unsigned part, overBase;
	overBase = 0;
	part = 0;

	for (size_t i = 0; i < length; i++)
	{
		part = 0;
		part = GetLevel(i) + other.GetLevel(i) + overBase;
		result.m_num.push_back(part % 10);
		overBase = part / 10;
	}

	if (overBase > 0)
	{
		result.m_num.push_back(overBase);
	}
	return result;
}

unsigned CLongNumber::GetLevel(const size_t arg) const
{
	if (m_num.size() > arg)
	{
		return m_num[arg];
	}
	return 0;
}

const CLongNumber CLongNumber::operator - (const CLongNumber &other) const
{
	//проверки на ноль
	if (other.m_num.size() == 1 && other.m_num[0] == 0)
	{
		return *this;
	}
	if (this->m_num.size() == 1 && this->m_num[0] == 0)
	{
		CLongNumber result = other;
		result.m_isPositive = false;
		return result;
	}

	if (*this <= other)
	{
		CLongNumber result = other;
		result.m_isPositive = false;
		size_t len = other.m_num.size();
		for (size_t i = 0; i < len; i++)
		{
			if (i < (len - 1))
			{
				result.m_num[i + 1] --;
				result.m_num[i] += 10;
			}
			result.m_num[i] -= this->GetLevel(i);
			if (result.m_num[i] / 10 > 0)
			{
				result.m_num[i + 1]++;
				result.m_num[i] %= 10;
			}
		}

		result.DropZeros();
		return result;
	}

	CLongNumber result = *this;
	size_t len = m_num.size();
	for (size_t i = 0; i < len; i++)
	{
		if (i < (len - 1))
		{
			result.m_num[i + 1] --;
			result.m_num[i] += 10;
		}
		result.m_num[i] -= other.GetLevel(i);
		if (result.m_num[i] / 10 > 0)
		{
			result.m_num[i + 1]++;
			result.m_num[i] %= 10;
		}
	}
	result.DropZeros();
	return result;
}

const CLongNumber CLongNumber::operator * (const CLongNumber &other) const
{
	if ((this->m_num.size() == 1 && this->m_num[0] == 0) || (other.m_num.size() == 1 && other.m_num[0] == 0))
	{
		return CLongNumber(0);
	}

	CLongNumber result;
	size_t len = m_num.size() + other.m_num.size() + 1;
	result.m_num.resize(len, 0);
	for (size_t i = 0; i < m_num.size(); ++i)
	{
		for (size_t j = 0; j < other.m_num.size(); j++)
		{
			result.m_num[i + j] += m_num[i] * other.m_num[j];
		}
	}
	for (size_t i = 0; i < len - 1; i++)
	{
		result.m_num[i + 1] += result.m_num[i] / 10;
		result.m_num[i] %= 10;
	}
	result.DropZeros();
	return result;
}

const CLongNumber CLongNumber::operator / (const CLongNumber &other) const
{
	if (other.m_num.size() == 1 && other.m_num[0] == 0)
	{
		throw runtime_error("Division by zero");
	}
	if (*this < other)
	{
		return 0;
	}

	CLongNumber result;
	CLongNumber curValue;
	result.m_num.resize(m_num.size(), 0);
	for (int i = m_num.size() - 1; i >= 0; i--)
	{
		curValue.Increase();
		curValue.m_num[0] = m_num[i];
		int multiplier = 0;
		int lowerBound = 0;
		int upperBound = 10;
		while (lowerBound <= upperBound)
		{
			int m = (lowerBound + upperBound) / 2;
			CLongNumber cur = other * m;
			if (cur <= curValue)
			{
				multiplier = m;
				lowerBound = m + 1;
			}
			else
				upperBound = m - 1;
		}
		result.m_num[i] = multiplier;
		curValue = curValue - other * multiplier;
		curValue.DropZeros();
	}

	result.DropZeros();
	return result;
}

void CLongNumber::DropZeros()
{
	bool toRepeatCycle = true;
	while ((m_num.size() > 0) && toRepeatCycle)
	{
		toRepeatCycle = false;
		if (m_num[m_num.size() - 1] == 0)
		{
			m_num.pop_back();
			toRepeatCycle = true;
		}
	}
}

void CLongNumber::Increase()
{
	m_num.resize(m_num.size() + 1);
	for (int i = m_num.size() - 1; i >= 1; i--)
	{
		m_num[i] = m_num[i - 1];
	}
}

const bool CLongNumber::operator < (CLongNumber const & other) const
{
	size_t i = 0;
	if (m_num.size() < other.m_num.size())
	{
		return true;
	}
	if (m_num.size() > other.m_num.size())
	{
		return false;
	}
	if (m_num.size() == other.m_num.size())
	{
		for (int i = static_cast<int>(m_num.size() - 1); i >= 0; --i)
		{
			if (m_num[i] < other.m_num[i])
			{
				return true;
			}
			if (m_num[i] > other.m_num[i])
			{
				return false;
			}
		}
	}

	return false;
}

const bool CLongNumber::operator > (CLongNumber const & other) const
{
	if (m_num.size() > other.m_num.size())
	{
		return true;
	}
	if (m_num.size() < other.m_num.size())
	{
		return false;
	}
	if (m_num.size() == other.m_num.size())
	{
		for (int i = static_cast<int>(m_num.size() - 1); i >= 0; --i)
		{
			if (m_num[i] > other.m_num[i])
			{
				return true;
			}
			if (m_num[i] < other.m_num[i])
			{
				return false;
			}
		}
	}
	return false;
}

bool const CLongNumber::operator <= (CLongNumber const & other) const
{
	return !(*this > other);
}

const bool operator >= (const CLongNumber &num1, const CLongNumber &num2)
{
	return !(num1 < num2);
}

const bool operator == (const CLongNumber &num1, const CLongNumber &num2)
{
	if (num1.GetVector().size() == num2.GetVector().size())
	{
		vector<int> tempNum1 = num1.GetVector();
		vector<int> tempNum2 = num2.GetVector();
		return equal(tempNum1.begin(), tempNum1.end(), tempNum2.begin(), equal_to<unsigned>());
	}

	return false;
}