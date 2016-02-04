#pragma once
#include <string>

class CShape
{
public:
	CShape();
	virtual ~CShape();

	virtual std::string GetInformation();
	virtual double GetPerimetr() const;
	virtual double GetSquare() const;
	virtual std::string GetType() const;

protected:
	double m_perimetr;
	double m_square;
	std::string m_shapeType;
};

