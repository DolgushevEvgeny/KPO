#pragma once
#include <vector>

class CLongNumber
{
public:
	CLongNumber();
	CLongNumber(unsigned number);
	CLongNumber(std::pair<std::vector<int>, bool> number);
	~CLongNumber();

	CLongNumber& operator = (const CLongNumber &other);

	const CLongNumber operator + (CLongNumber const & other) const;
	const CLongNumber operator - (CLongNumber const & other) const;
	const CLongNumber operator * (CLongNumber const & other) const;
	const CLongNumber operator / (const CLongNumber &other) const;

	bool const operator > (CLongNumber const & other) const;
	bool const operator <= (CLongNumber const & other) const;

	size_t GetSize() const;
	std::vector<int> GetVector() const;
	std::string ToString();

	unsigned GetLevel(const size_t arg) const;
private:
	void Increase();
	void DropZeros();
	bool m_isPositive;
	size_t m_size;
	std::vector<int> m_num;
};

const bool operator < (const CLongNumber &num1, const CLongNumber &num2);
const bool operator >= (const CLongNumber &num1, const CLongNumber &num2);
const bool operator == (const CLongNumber &num1, const CLongNumber &num2);