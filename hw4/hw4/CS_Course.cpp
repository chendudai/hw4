#include "CS_Course.h"
#include <string.h>
#include <math.h> 
#include <algorithm>

CS_Course::CS_Course(int num, char* name, int hw_num, double hw_weigh, bool isTakef, char* book)
	:Course(num, name, hw_num, hw_weigh), isTakef_(isTakef) 
{
	book_ = new char[strlen(book) + 1];
	strcpy(book_, book);
}

CS_Course::~CS_Course() {}

int CS_Course::isTakef() const { return isTakef_; }

int CS_Course::setTakef(int isTakef)
{
	isTakef_ = isTakef;
	return 1;
}

void CS_Course::setBook(char* book)
{
	book_ = new char[strlen(book) + 1];
	strcpy(book_, book);
	return;
}

int CS_Course::getCourseGrade() const
{
	double  hw_average = getHwAverage();
	int course_grade = 0;
	if (isTakef_)
	{
		course_grade= round((1 - hw_weigh_)*exam_grade_ + hw_weigh_ * hw_average);
	}
	else
	{
		if (round((1 - hw_weigh_)*exam_grade_ + hw_weigh_ * hw_average) > exam_grade_)
		{
			course_grade = (round((1 - hw_weigh_)*exam_grade_ + hw_weigh_ * hw_average);
		}
		else
		{
			course_grade = exam_grade_;
		}
		
	}
	return course_grade;
}