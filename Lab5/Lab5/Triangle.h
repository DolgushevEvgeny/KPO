#pragma once

#include "Point.h"
#include "Shape.h" 

class CTriangle : public CShape
{
public:
	CTriangle(Point A, Point B, Point C);
	void Accept(CShapeVisitor &visitor) const;
	~CTriangle();

	CLongNumber SumTwoSides(CLongNumber semiP, CLongNumber side) const;
	CLongNumber SquareDifferenceOfCoordinates(CLongNumber x1, CLongNumber x2) const;

	void SetSemiPerimetr();

	CLongNumber m_sideA, m_sideB, m_sideC, m_semiperimeter;
	CLongNumber CalcSide(Point first, Point second);
};