#pragma once
#include "Point.h"
#include "Shape.h" 

class CTriangle : public CShape
{
public:
	CTriangle(Point A, Point B, Point C);
	~CTriangle();

	double SumTwoSides(double semiP, double side) const;
	double SquareDifferenceOfCoordinates(double x1, double x2) const;

	void SetSemiPerimetr();

private:
	double m_sideA;
	double m_sideB;
	double m_sideC;
	double m_semiperimeter;
	double CalcSide(Point first, Point second);
};

