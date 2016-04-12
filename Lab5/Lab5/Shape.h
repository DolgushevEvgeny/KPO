#pragma once
#include <string>

class CShapeVisitor;

class CShape
{
public:
	CShape();
	virtual ~CShape();
	virtual void Accept(CShapeVisitor &visitor) const = 0;
	//virtual std::string GetInformation();
	virtual CLongNumber GetPerimetr() const;
	virtual CLongNumber GetSquare() const;
	virtual std::string GetType() const;

protected:
	CLongNumber m_perimetr = 0;
	CLongNumber m_square = 0;
	std::string m_shapeType;
};