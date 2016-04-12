#include "stdafx.h"
#include "ShapePerimeterVisitor.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

void CShapePerimeterVisitor::Visit(CCircle const& shape)
{
	result = CLongNumber("2") * shape.m_radius * 314 / 100;
}

void CShapePerimeterVisitor::Visit(CRectangle const& shape)
{
	result = CLongNumber("2") * (shape.m_sideA + shape.m_sideB);
}

void CShapePerimeterVisitor::Visit(CTriangle const& shape)
{
	result = shape.m_sideA + shape.m_sideA + shape.m_sideC;
}