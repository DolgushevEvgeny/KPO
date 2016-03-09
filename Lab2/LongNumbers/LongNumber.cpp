#include "stdafx.h"
#include <vector>
#include <string>
#include "LongNumber.h"
#include <algorithm>
#include <functional>

using namespace std;

CLongNumber::CLongNumber()
: m_num({ 0 })
, m_size(1)
, m_isPositive(true)
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
		if (result.size() - 1 > i)
		{
			result[i + 1] += result[i] / 10;
			result[i] %= 10;
		}
	}
}

void CLongNumber::SetVector(vector<int> num)
{
	m_num = num;
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

const CLongNumber operator + (const CLongNumber &num1, const CLongNumber &num2)
{
	vector<int> first = num1.GetVector();
	vector<int> second = num2.GetVector();
	size_t length = GetNewSize(num1.GetSize(), num2.GetSize());
	size_t minLength = num1.GetSize() > num2.GetSize() ? num2.GetSize() : num1.GetSize();

	pair<vector<int>, bool> result;
	result.second = true;

	InitArray(length, result.first);
	SumVectors(first, second, result.first, minLength);

	if (num1.GetSize() > num2.GetSize())
	{
		reverse(first.begin(), first.end());
		reverse(second.begin(), second.end());
		AddLeftOver(num1.GetVector(), result.first, minLength, length);
	}
	else
	{
		reverse(first.begin(), first.end());
		reverse(second.begin(), second.end());
		AddLeftOver(num2.GetVector(), result.first, minLength, length);
	}

	DropZeros(result.first);
	//reverse(result.first.begin(), result.first.end());
	return (CLongNumber)result;
}

void Subst(vector<int> first, vector<int> second, vector<int> &result, size_t length)
{
	for (size_t i = 0; i < length; ++i) // проход по всем разрядам числа, начиная с последнего, не доходя до первого
	{
		if (i < (length - 1)) // если текущий разряд чисел не первый
		{
			first[i + 1]--; // в следующуем разряде большего числа занимаем 1.
			result[i] += 10 + first[i]; // в ответ записываем сумму значения текущего разряда большего числа и 10-ти
		}
		else  // если текущий разряд чисел - первый
		{
			result[i] += first[i]; // в ответ суммируем значение текущего разряда большего числа
		}

		result[i] -= second.size() > i ? second[i] : 0; // вычитаем значение текущего разряда меньшего числа

		if (result[i] / 10 > 0) // если значение в текущем разряде двухразрядное
		{
			first[i + 1]++; // переносим единицу в старший разряд
			result[i] %= 10; // в текущем разряде отсекаем ее
		}
	}
}

int MatchingNumbers(const vector<int> &first, const vector<int> &second, size_t &length)
{
	int k = 3; // если к == 3, значит числа одинаковой длинны
	length = first.size();
	if (first.size() > second.size())
	{
		length = first.size();
		k = 1; // если к == 1, значит первое число длиннее второго
	}
	else
	{
		if (second.size() > first.size())
		{
			length = second.size();
			k = 2; // если к == 2, значит второе число длиннее первого
		}
		else // если числа одинаковой длинны, то необходимо сравнить их веса
		{
			for (size_t i = 0; i < length; ++i) // поразрядное сравнение весов чисел
			{
				if (first[i] > second[i]) // если разряд первого числа больше
				{
					k = 1; // значит первое число длиннее второго
					break; // выход из цикла for
				}
				if (second[i] > first[i]) // если разряд второго числа больше
				{
					k = 2; // значит второе число длиннее первого
					break; // выход из цикла for
				}
			} // конец for
		}
	}

	return k;
}

const CLongNumber operator - (const CLongNumber &num1, const CLongNumber &num2)
{
	if (num1.GetSize() == 1 && num1.GetVector()[0] == 0)
	{
		pair<vector<int>, bool> result;
		result.second = false;
		result.first = num2.GetVector();
		return result;
	}
	if (num2.GetSize() == 1 && num2.GetVector()[0] == 0)
	{
		return num1;
	}

	vector<int> first = num1.GetVector();
	vector<int> second = num2.GetVector();
	size_t minLength = num1.GetSize() > num2.GetSize() ? num2.GetSize() : num1.GetSize();

	pair<vector<int>, bool> result;
	
	//reverse(first.begin(), first.end());
	//reverse(second.begin(), second.end());
	if (num1 > num2)
	{
		//reverse(first.begin(), first.end());
		//reverse(second.begin(), second.end());
		size_t length = num1.GetSize();
		InitArray(length, result.first);
		Subst(first, second, result.first, length);
		result.second = true;
		AddLeftOver(num1.GetVector(), result.first, minLength + 1, length);
	}
	else
	{
		if (num2 > num1)
		{
			//reverse(first.begin(), first.end());
			//reverse(second.begin(), second.end());
			size_t length = num2.GetSize();
			InitArray(length, result.first);
			Subst(second, first, result.first, length);
			result.second = false;
			AddLeftOver(num2.GetVector(), result.first, minLength + 1, length);
		}
		else
		{
			//reverse(first.begin(), first.end());
			//reverse(second.begin(), second.end());
			size_t length = num2.GetSize();
			InitArray(length, result.first);
			Subst(second, first, result.first, length);
			result.second = false;
			AddLeftOver(num2.GetVector(), result.first, minLength, length + 1);
		}
	}
	
	DropZeros(result.first);
	//reverse(result.first.begin(), result.first.end());
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
	//reverse(result.first.begin(), result.first.end());
	return (CLongNumber)result;
}

const CLongNumber operator / (const CLongNumber &num1, const CLongNumber &num2)
{
	unsigned int count = 0;
	//pair<vector<int>, bool> result;
	CLongNumber curValue;
	
	if (num2.GetVector().size() == 1 && num2.GetVector()[0] == 0)
	{
		throw runtime_error("Division by zero");
	}
	//ToDo делитель больше делимого
	if (num2 > num1)
	{
		return (CLongNumber)count;
	}
	
	CLongNumber first = num1;
	CLongNumber second = num2;
	size_t length = num1.GetSize() + num2.GetSize() + 1;

	//result.second = true;
	//InitArray(length, result.first);

	while (curValue < first)
	{
		curValue = curValue + second;
		if (curValue.GetVector().size() > 1)
		{
			vector<int> tmp = curValue.GetVector();
			//reverse(tmp.begin(), tmp.end());
			tmp.resize(tmp.size() + 1);
			curValue.SetVector(tmp);
			
			//reverse(curValue.GetVector().begin(), curValue.GetVector().end());
		}
		++count;
	}
	if (curValue > first)
	{
		--count;
	}
	return count;
}

const bool operator < (const CLongNumber &num1, const CLongNumber &num2)
{
	size_t i = 0;
	if (num1.GetSize() < num2.GetSize())
	{
		return true;
	}
	if (num1.GetSize() > num2.GetSize())
	{
		return false;
	}
	if (num1.GetSize() == num2.GetSize())
	{
		for (i = num2.GetVector().size() - 1; i < -1; --i)
		{
			if (num1.GetVector()[i] < num2.GetVector()[i])
			{
				return true;
			}
			if (num1.GetVector()[i] > num2.GetVector()[i])
			{
				return false;
			}
		}
	}

	return false;
}

const bool operator > (const CLongNumber &num1, const CLongNumber &num2)
{
	size_t i = 0;
	if (num1.GetSize() > num2.GetSize())
	{
		return true;
	}
	if (num1.GetSize() < num2.GetSize())
	{
		return false;
	}
	if (num1.GetSize() == num2.GetSize())
	{
		for (i = num2.GetVector().size() - 1; i < -1; --i)
		{
			if (num1.GetVector()[i] > num2.GetVector()[i])
			{
				return true;
			}
			if (num1.GetVector()[i] < num2.GetVector()[i])
			{
				return false;
			}
		}
	}

	return false;
}

const bool operator <= (const CLongNumber &num1, const CLongNumber &num2)
{
	return !(num1 > num2);
}

const bool operator >= (const CLongNumber &num1, const CLongNumber &num2)
{
	return !(num1 < num2);
}

const bool operator == (const CLongNumber &num1, const CLongNumber &num2)
{
	if (num1.GetSize() == num2.GetSize())
	{
		return equal(num1.GetVector().begin(), num1.GetVector().end(), num2.GetVector().begin(), equal_to<unsigned>());
	}

	return false;
}

void Increase(vector<int> &num)
{
	num.resize(num.size() + 1);
	for (size_t i = num.size() - 1; i >= 1; i--)
	{
		num[i] = num[i - 1];
	}
}

size_t GetNewSize(const size_t &size_a, const size_t &size_b)
{
	if (size_a > size_b)
	{
		return size_a + 1;
	}

	return size_b + 1;
}