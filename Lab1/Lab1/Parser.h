#pragma once
#include "ShapeType.h"
#include <string>
#include <vector>
#include "Point.h"

class CParser
{
public:
	CParser(const std::string &input);
	~CParser();

	void SetShapeType(const std::string &input);
	Point ParsePoint(const std::string &input);
	int ParseRadius(const std::string &input);
	bool IsDigit(char symbol);
	int FromStrToInt(const std::string &input);
	void SetPoints(const std::string &input);

	SHAPETYPE GetShapeType() const;
	int GetRadius() const;
	std::vector<Point> GetPoints() const;

private:
	size_t m_letterIndex;
	SHAPETYPE m_shapeType;
	int m_radius;
	std::vector<Point> m_points;
};

