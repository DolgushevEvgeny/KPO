#pragma once

#include "ShapeVisitor.h"
#include "LongNumber.h"

class CShapePerimeterVisitor : public CShapeVisitor
{
public:
	CLongNumber result;
	void Visit(CCircle const& shape) override final;
	void Visit(CRectangle const& shape) override final;
	void Visit(CTriangle const& shape) override final;
};
