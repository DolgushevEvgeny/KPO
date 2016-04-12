// Lab5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Parser.h"
#include "TriangleCreator.h"
#include "RectangleCreator.h"
#include "CircleCreator.h"
#include "ShapePerimeterVisitor.h"
#include "ShapeAreaVisitor.h"

using namespace std;

static unique_ptr<CShape> GetShape(CParser &parser)
{
	const SHAPETYPE type = parser.GetShapeType();

	switch (type)
	{
	case SHAPETYPE::TRIANGLE:
	{
		vector<Point> points = parser.GetPoints();
		const Point point1 = points[0];
		const Point point2 = points[1];
		const Point point3 = points[2];
		return CTriangleCreator::GetInstance()->Create(point1, point2, point3);
	}
	case SHAPETYPE::RECTANGLE:
	{
		vector<Point> points = parser.GetPoints();
		const Point point1 = points[0];
		const Point point2 = points[1];
		return CRectangleCreator::GetInstance()->Create(point1, point2);
	}
	case SHAPETYPE::CIRCLE:
	{
		const Point point1 = parser.GetPoints()[0];
		const CLongNumber radius = parser.GetRadius();
		return CCircleCreator::GetInstance()->Create(point1, radius);
	}
	default:
		assert(false);
		return unique_ptr<CShape>();
	}
	CCircleCreator::DestroyInstance();
	CRectangleCreator::DestroyInstance();
	CTriangleCreator::DestroyInstance();
}

static void PrintShapeInfo(const CShape &shape, ostream &out)
{
	CShapePerimeterVisitor perimeterVisitor;
	shape.Accept(perimeterVisitor);

	CShapeAreaVisitor areaVisitor;
	shape.Accept(areaVisitor);

	out << shape.GetType() << ": P=" << perimeterVisitor.result.ToString() << "; S=" << areaVisitor.result.ToString() << endl;
}

int main(int argc, char* argv[])
{
	try
	{
		ifstream inputFile;
		inputFile.open("input.txt", ifstream::in);

		ofstream outputFile;
		outputFile.open("output.txt", ofstream::out);

		while (inputFile.good())
		{
			string inputLine;
			getline(inputFile, inputLine);

			CParser parser(inputLine);
			auto shape = GetShape(parser);
			PrintShapeInfo(*shape, outputFile);
		}
	}
	catch (exception const& e)
	{
		cerr << e.what() << endl;
	}

	return 0;
}

