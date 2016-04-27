#include "stdafx.h"
#include "ShapePerimeterVisitor.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

void CShapePerimeterVisitor::Visit(CCircle const& shape)
{
	m_result = "CIRCLE: P=" + shape.GetPerimetr().ToString();
}

void CShapePerimeterVisitor::Visit(CRectangle const& shape)
{
	m_result = "RECTANGLE: P=" + shape.GetPerimetr().ToString();
}

void CShapePerimeterVisitor::Visit(CTriangle const& shape)
{
	m_result = "TRIANGLE: P=" + shape.GetPerimetr().ToString();
}

std::string CShapePerimeterVisitor::GetValue()
{
	return m_result;
}