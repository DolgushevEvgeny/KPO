// Lab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Shape.h"
#include <cmath>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

enum SHAPETYPE
{
	TRIANGLE,
	RECTANGLE,
	CIRCLE
};

using namespace std;

bool IsDigit(char symbol)
{
	if (symbol >= '0' && symbol <= '9')
	{
		return true;
	}
	else
	{
		if (symbol == '-')
		{
			return true;
		}
	}
	
	return false;
}

double FromStrToDouble(const string &input)
{
	istringstream i(input);
	double x;
	if (!(i >> x))
	{
		return 0;
	}
		
	return x;
}

Point ParsePoints(const string &line)
{
	double x = 0, y = 0;

	size_t index;
	for (index = 0; index < line.size(); ++index)
	{
		if (line[index] == '=')
		{
			++index;
			break;
		}
	}

	string coord;
	vector<string> coords;
	for (size_t i = index; i < line.size(); ++i)
	{
		if (IsDigit(line[i]))
		{
			coord += line[i];
		}
		else
		{
			if (coord.size())
			{
				coords.push_back(coord);
				coord.clear();
			}
		}
	}

	coords.push_back(coord);
	Point point{ FromStrToDouble(coords[0]), FromStrToDouble(coords[1]) };

	return point;
}

SHAPETYPE GetShapeType(const string &input, size_t &index)
{
	string shapeType = "";
	for (size_t i = index; i < input.size(); ++i)
	{
		if (input[i] != ':')
		{
			shapeType += input[i];
		}
		else
		{
			index += i + 2;
			if (shapeType == "TRIANGLE")
			{
				return SHAPETYPE::TRIANGLE;
			}
			else
			{
				if (shapeType == "RECTANGLE")
				{
					return SHAPETYPE::RECTANGLE;
				}
				else
				{
					return SHAPETYPE::CIRCLE;
				}
			}
		}
	}

	throw std::exception();
}

double ParseRadius(const string &line)
{
	size_t index;
	for (index = 0; index < line.size(); ++index)
	{
		if (line[index] == '=')
		{
			++index;
			break;
		}
	}

	string radius = line.substr(index, line.length() - index);
	
	return FromStrToDouble(radius);
}

shared_ptr<CShape> CreateTriangle(const string &input, size_t &index)
{
	string source = input.substr(index, input.length() - index);
	vector<string> array1;
	istringstream is(source);
	string s;
	while (getline(is, s, ' '))
	{
		array1.push_back(s);
	}

	vector<Point> points;
	for (size_t i = 0; i < array1.size(); ++i)
	{
		points.push_back(ParsePoints(array1[i]));
	}
	
	CTriangle triangle(points[0], points[1], points[2]);
	return make_shared<CTriangle>(triangle);
}

shared_ptr<CShape> CreateRectangle(const string &input, size_t &index)
{
	string source = input.substr(index, input.length() - index);
	vector<string> array1;
	istringstream is(source);
	string s;
	while (getline(is, s, ' '))
	{
		array1.push_back(s);
	}

	vector<Point> points;
	for (size_t i = 0; i < array1.size(); ++i)
	{
		points.push_back(ParsePoints(array1[i]));
	}

	CRectangle rectangle(points[0], points[1]);
	return make_shared<CRectangle>(rectangle);
}

shared_ptr<CShape> CreateCircle(const string &input, size_t &index)
{
	string source = input.substr(index, input.length() - index);
	vector<string> array1;
	istringstream is(source);
	string s;
	while (getline(is, s, ' '))
	{
		array1.push_back(s);
	}

	Point point = ParsePoints(array1[0]);
	double radius = ParseRadius(array1[1]);

	CCircle circle(point, radius);
	return make_shared<CCircle>(circle);
}

void GetInformation(const string &input, size_t &index, SHAPETYPE type, ofstream &output)
{
	shared_ptr<CShape> figure;
	
	if (type == SHAPETYPE::TRIANGLE)
	{
		figure = CreateTriangle(input, index);
	}
	if (type == SHAPETYPE::RECTANGLE)
	{
		figure = CreateRectangle(input, index);
	}
	if (type == SHAPETYPE::CIRCLE)
	{
		figure = CreateCircle(input, index);
	}

	output << figure->GetInformation() << endl;
}


void ReadFile()
{
	ifstream inputFile;
	inputFile.open("input.txt", ifstream::in);

	ofstream outputFile;
	outputFile.open("output.txt", ofstream::out);

	while (inputFile.good())
	{
		string inputLine;
		getline(inputFile,inputLine);

		size_t letterIndex = 0;
		SHAPETYPE shapeType = GetShapeType(inputLine, letterIndex);

		switch (shapeType)
		{
			case SHAPETYPE::TRIANGLE: GetInformation(inputLine, letterIndex, shapeType, outputFile); break;
			case SHAPETYPE::RECTANGLE: GetInformation(inputLine, letterIndex, shapeType, outputFile); break;
			case SHAPETYPE::CIRCLE: GetInformation(inputLine, letterIndex, shapeType, outputFile); break;
		}
	}
}

int main(int argc, char* argv[])
{
	ReadFile();
	return 0;
}

