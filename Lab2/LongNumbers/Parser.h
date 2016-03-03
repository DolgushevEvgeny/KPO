#pragma once
#include <vector>
#include <string>

class CParser
{
public:
	CParser(const std::string &input);
	~CParser();

	void Parse(const std::string &input);
	std::pair<std::vector<int>, bool> ParseNumber(const std::string &input);
	
	std::pair<std::pair<std::vector<int>, bool>, std::pair<std::vector<int>, bool>> GetNumbers() const;
	const char* GetOperation() const;
private:
	std::pair<std::vector<int>, bool> m_num1;
	std::pair<std::vector<int>, bool> m_num2;
	const char* m_operation;
};

bool IsDigit(char symbol);
bool IsPositive(char symbol);
