#include "stdafx.h"
#include <iostream>

/* 
A quick script that can create points and convert them into axis aligned rectangles, 
then it can check if the points are overlapping rectangles, or if the rectangles are overlapping rectangles
*/

using namespace std;

struct Point2D {
	explicit Point2D(float x, float y)
		:x(x), y(y) {}
	float x;
	float y;
};

struct Rectangle {
	explicit Rectangle(Point2D point1, Point2D point2)
		: point1(point1), point2(point2) {
		// this is added for expandability, allowing the user to enter whatever two points they want; the rectangle could technically just be a line.
		// it picks the highest and lowest values of both x and y and sets them upon construction
		xMax = fmax(point1.x, point2.x);
		xMin = fmin(point1.x, point2.x);
		yMax = fmax(point1.y, point2.y);
		yMin = fmin(point1.y, point2.y);
	}

	Point2D point1, point2;
	float xMin, xMax, yMin, yMax;
};

bool IsValueInRange(float value, float min, float max) {
	// just a quick function to check if a value is within two others
	return (value >= min) && (value <= max);
}

bool IsOverlappedPoint(Rectangle rect, Point2D point) {
	// if both of the point's x or y values are within the respective ranges of the rectangle, then it is overlapped
	return IsValueInRange(point.x, rect.xMin, rect.xMax) && 
		   IsValueInRange(point.y, rect.yMin, rect.yMax);
}

bool IsOverlappedRectangle(Rectangle rect1, Rectangle rect2) {
	// if the left side of either rectangle is within the horizontal range of the other, then it is overlapped on the x axis
	bool x_overlap = IsValueInRange(rect1.xMin, rect2.xMin, rect2.xMax) ||
					 IsValueInRange(rect2.xMin, rect1.xMin, rect1.xMax);

	// if the bottom side of either rectangle is within the vertical range of the other, then it is overlapped on the y axis
	bool y_overlap = IsValueInRange(rect1.yMin, rect2.yMin, rect2.yMax) ||
					 IsValueInRange(rect2.yMin, rect1.yMin, rect1.yMax);

	// it must overlap on both axes to be considered truly overlapped
	return x_overlap && y_overlap;
}

int main()
{
	// this might be a bit overkill on the proofing, but I wanted to make sure it works with actual testing

	// create all the points that will be used
	Point2D base_1(-2, -2);
	Point2D base_2(2, 2);

	Point2D overlap_Point_1(1.5, 1.5);
	Point2D overlap_Point_2(-1.5, -1.5);
	Point2D overlap_Point_3(0, 0);

	Point2D nonoverlap_Point_1(5, 5);
	Point2D nonoverlap_Point_2(-15, -20);
	Point2D nonoverlap_Point_3(-10, 50);

	// create all the rectangles that will be used
	Rectangle base_Rect(base_1, base_2);

	Rectangle overlap_Rect_1(overlap_Point_1, nonoverlap_Point_1);
	Rectangle overlap_Rect_2(overlap_Point_2, overlap_Point_3);
	Rectangle overlap_Rect_3(nonoverlap_Point_1, nonoverlap_Point_2);

	Rectangle nonoverlap_Rect_1(nonoverlap_Point_1, nonoverlap_Point_1);
	Rectangle nonoverlap_Rect_2(nonoverlap_Point_1, nonoverlap_Point_3);
	Rectangle nonoverlap_Rect_3(nonoverlap_Point_2, nonoverlap_Point_2);

	// i made the overlap check functions return bools instead of just printing out true or false themselves because I thought it would be more realistic for an actual program
	// this should print out 3 'OVERLAPPED's, 3 'NOT OVERLAPPED's, 3 'OVERLAPPED's, and 3 'NOT OVERLAPPED's
#pragma region PointOverlapTesting

	// should be true
	IsOverlappedPoint(base_Rect, overlap_Point_1) ? cout << "OVERLAPPED" : cout << "NOT OVERLAPPED";

	cout << endl;

	// should be true
	IsOverlappedPoint(base_Rect, overlap_Point_2) ? cout << "OVERLAPPED" : cout << "NOT OVERLAPPED";

	cout << endl;

	// should be true
	IsOverlappedPoint(base_Rect, overlap_Point_3) ? cout << "OVERLAPPED" : cout << "NOT OVERLAPPED";

	cout << endl;

	//should be false
	IsOverlappedPoint(base_Rect, nonoverlap_Point_1) ? cout << "OVERLAPPED" : cout << "NOT OVERLAPPED";

	cout << endl;

	//should be false
	IsOverlappedPoint(base_Rect, nonoverlap_Point_2) ? cout << "OVERLAPPED" : cout << "NOT OVERLAPPED";

	cout << endl;

	//should be false
	IsOverlappedPoint(base_Rect, nonoverlap_Point_3) ? cout << "OVERLAPPED" : cout << "NOT OVERLAPPED";

	cout << endl;

#pragma endregion

#pragma region RectangleOverlapTesting

	// should be true
	IsOverlappedRectangle(base_Rect, overlap_Rect_1) ? cout << "OVERLAPPED" : cout << "NOT OVERLAPPED";

	cout << endl;

	// should be true
	IsOverlappedRectangle(base_Rect, overlap_Rect_2) ? cout << "OVERLAPPED" : cout << "NOT OVERLAPPED";

	cout << endl;

	// should be true
	IsOverlappedRectangle(base_Rect, overlap_Rect_3) ? cout << "OVERLAPPED" : cout << "NOT OVERLAPPED";

	cout << endl;

	// should be false
	IsOverlappedRectangle(base_Rect, nonoverlap_Rect_1) ? cout << "OVERLAPPED" : cout << "NOT OVERLAPPED";

	cout << endl;

	// should be false
	IsOverlappedRectangle(base_Rect, nonoverlap_Rect_2) ? cout << "OVERLAPPED" : cout << "NOT OVERLAPPED";

	cout << endl;

	// should be false
	IsOverlappedRectangle(base_Rect, nonoverlap_Rect_3) ? cout << "OVERLAPPED" : cout << "NOT OVERLAPPED";

	cout << endl;



#pragma endregion

	system("pause");
};

