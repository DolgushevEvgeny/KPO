#include "stdafx.h"
#include "ShapeAreaVisitor.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "ShapePerimeterVisitor.h"
#include "Functions.h"

void CShapeAreaVisitor::Visit(CCircle const& shape)
{
	m_result = "; S=" + shape.GetSquare().ToString();
}

void CShapeAreaVisitor::Visit(CRectangle const& shape)
{
	m_result = "; S=" + shape.GetSquare().ToString();
}

void CShapeAreaVisitor::Visit(CTriangle const& shape)
{
	m_result = "; S=" + shape.GetSquare().ToString();
}

std::string CShapeAreaVisitor::GetValue()
{
	return m_result;
}
