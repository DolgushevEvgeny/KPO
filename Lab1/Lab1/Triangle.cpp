#include "stdafx.h"
#include "Triangle.h"
#include <math.h>

CTriangle::CTriangle(Point A, Point B, Point C)
	: m_sideA(CalcSide(A, B))
	, m_sideB(CalcSide(B, C))
	, m_sideC(CalcSide(C, A))
{
	SetSemiPerimetr();
	m_perimetr = m_semiperimeter * 2;
	m_square = sqrt(m_semiperimeter * SumTwoSides(m_semiperimeter, m_sideA) * SumTwoSides(m_semiperimeter, m_sideB) * SumTwoSides(m_semiperimeter, m_sideC));
	m_shapeType = "TRIANGLE";
}

CTriangle::~CTriangle()
{
}

double CTriangle::SquareDifferenceOfCoordinates(double x1, double x2) const
{
	return powl(x2 - x1, 2);
}

double CTriangle::CalcSide(Point first, Point second)
{
	return sqrt(SquareDifferenceOfCoordinates(first.x, second.x) + SquareDifferenceOfCoordinates(first.y, second.y));
}

void CTriangle::SetSemiPerimetr()
{
	m_semiperimeter = (m_sideA + m_sideB + m_sideC) / 2;
}

double CTriangle::SumTwoSides(double semiP, double side) const
{
	return semiP - side;
}