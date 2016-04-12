#include "stdafx.h"
#include "ShapeAreaVisitor.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "ShapePerimeterVisitor.h"
#include "Functions.h"

void CShapeAreaVisitor::Visit(CCircle const& shape)
{
	result = CFunctions::Sqr(shape.m_radius) * 314 / 100;
}

void CShapeAreaVisitor::Visit(CRectangle const& shape)
{
	result = shape.m_sideA * shape.m_sideB;
}

void CShapeAreaVisitor::Visit(CTriangle const& shape)
{
	CShapePerimeterVisitor perimeterVisitor;
	shape.Accept(perimeterVisitor);
	const CLongNumber semiperimeter = perimeterVisitor.result / CLongNumber("2");
	
	result = CFunctions::Sqrt(semiperimeter * (semiperimeter - shape.m_sideA) * (semiperimeter - shape.m_sideB) * (semiperimeter - shape.m_sideC));
}
