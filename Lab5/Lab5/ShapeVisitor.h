#pragma once

class CCircle;
class CRectangle;
class CTriangle;

class CShapeVisitor
{
public:
	virtual ~CShapeVisitor() = default;
	virtual void Visit(CCircle const& shape) = 0;
	virtual void Visit(CRectangle const& shape) = 0;
	virtual void Visit(CTriangle const& shape) = 0;
};
