#include "stdafx.h"
#include "Triangle.h"
#include "ShapeVisitor.h"
#include <math.h>

CTriangle::CTriangle(Point A, Point B, Point C)
: m_sideA(CalcSide(A, B))
, m_sideB(CalcSide(B, C))
, m_sideC(CalcSide(C, A))
{
	SetSemiPerimetr();
	m_perimetr = m_semiperimeter * 2;
	m_square = Sqrt(m_semiperimeter * SumTwoSides(m_semiperimeter, m_sideA) * SumTwoSides(m_semiperimeter, m_sideB) * SumTwoSides(m_semiperimeter, m_sideC));
	m_shapeType = "TRIANGLE";
}

CTriangle::~CTriangle()
{
}

CLongNumber CTriangle::SquareDifferenceOfCoordinates(CLongNumber x1, CLongNumber x2) const
{
	return Sqr(x2 - x1);
}

CLongNumber CTriangle::CalcSide(Point first, Point second)
{
	return Sqrt(SquareDifferenceOfCoordinates(first.x, second.x) + SquareDifferenceOfCoordinates(first.y, second.y));
}

void CTriangle::SetSemiPerimetr()
{
	m_semiperimeter = (m_sideA + m_sideB + m_sideC) / 2;
}

CLongNumber CTriangle::SumTwoSides(CLongNumber semiP, CLongNumber side) const
{
	return semiP - side;
}

void CTriangle::Accept(CShapeVisitor &visitor) const
{
	return visitor.Visit(*this);
}