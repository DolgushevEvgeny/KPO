#pragma once

#include "ShapeVisitor.h"
#include "LongNumber.h"

class CShapePerimeterVisitor : public CShapeVisitor
{
public:
	void Visit(CCircle const& shape) override final;
	void Visit(CRectangle const& shape) override final;
	void Visit(CTriangle const& shape) override final;
	std::string GetValue();
private:
	std::string m_result;
};
