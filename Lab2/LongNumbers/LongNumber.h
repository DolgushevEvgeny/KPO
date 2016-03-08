#pragma once
#include <vector>

class CLongNumber final
{
public:
	CLongNumber();
	CLongNumber(unsigned number);
	CLongNumber(std::pair<std::vector<int>, bool> number);
	~CLongNumber();

	CLongNumber& operator = (const CLongNumber &other);

	size_t GetSize() const;
	std::vector<int> GetVector() const;
	bool GetNumberSymbol() const;
	void SetVector(std::vector<int> num);
	std::string ToString();

	void SetNumberSymbol(bool isPositive);
private:
	bool m_isPositive;
	size_t m_size;
	std::vector<int> m_num;
};

const CLongNumber operator + (const CLongNumber &num1, const CLongNumber &num2);
const CLongNumber operator - (const CLongNumber &num1, const CLongNumber &num2);
const CLongNumber operator * (const CLongNumber &num1, const CLongNumber &num2);
const CLongNumber operator / (const CLongNumber &num1, const CLongNumber &num2);

const bool operator < (const CLongNumber &num1, const CLongNumber &num2);
const bool operator > (const CLongNumber &num1, const CLongNumber &num2);
const bool operator <= (const CLongNumber &num1, const CLongNumber &num2);
const bool operator >= (const CLongNumber &num1, const CLongNumber &num2);

size_t GetNewSize(const size_t &size_a, const size_t &size_b);
void InitArray(size_t length, std::vector<int> &number);
void DropZeros();
void Increase(std::vector<int> &num);
void SumVectors(const std::vector<int> &first, const std::vector<int> &second, std::vector<int> &result, size_t length);
