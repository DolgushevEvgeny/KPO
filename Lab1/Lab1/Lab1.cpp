// Lab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


using namespace std;

shared_ptr<CShape> CreateTriangle(const vector<Point> &points)
{
	CTriangle triangle(points[0], points[1], points[2]);
	return make_shared<CTriangle>(triangle);
}

shared_ptr<CShape> CreateRectangle(const vector<Point> &points)
{
	CRectangle rectangle(points[0], points[1]);
	return make_shared<CRectangle>(rectangle);
}

shared_ptr<CShape> CreateCircle(const vector<Point> &points, int radius)
{
	CCircle circle(points[0], radius);
	return make_shared<CCircle>(circle);
}

void GetInformation(const CParser &parser, ofstream &output)
{
	shared_ptr<CShape> figure;
	
	switch (parser.GetShapeType())
	{
		case SHAPETYPE::TRIANGLE: figure = CreateTriangle(parser.GetPoints()); break;
		case SHAPETYPE::RECTANGLE: figure = CreateRectangle(parser.GetPoints()); break;
		case SHAPETYPE::CIRCLE: figure = CreateCircle(parser.GetPoints(), parser.GetRadius()); break;
	}

	output << figure->GetInformation() << endl;
}

int main(int argc, char* argv[])
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

		GetInformation(parser, outputFile);
	}

	return 0;
}

