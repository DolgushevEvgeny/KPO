#pragma once
#include <vector>

class CLongNumber final
{
public:
	CLongNumber(std::pair<std::vector<int>, bool> number);
	~CLongNumber();

	size_t GetSize() const;
	std::vector<int> GetVector() const;
	bool GetNumberSymbol() const;

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

size_t GetNewSize(const size_t &size_a, const size_t &size_b);
void InitArray(size_t length, std::vector<int> &number);
void DropZeros();