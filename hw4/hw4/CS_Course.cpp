#include "CS_Course.h"
#include <string.h>
#include <math.h> 
#include <algorithm>

CS_Course::CS_Course(int num,const char* name, int hw_num, double hw_weigh, bool isTakef,const char* book)
	:Course(num, name, hw_num, hw_weigh), isTakef_(isTakef) 
{
	if (book != NULL)
	{
		book_ = new char[strlen(book) + 1];
		strcpy(book_, book);
	}
}

CS_Course::~CS_Course() 
{
	if (book_ != NULL)
	{
		delete[] book_;
	}
}

int CS_Course::isTakef() const { return isTakef_; }

char* CS_Course::getBook() const
{

	if (book_ != NULL)
	{
		char* copy_book = new char[strlen(book_) + 1];
		copy_book = strcpy(copy_book, book_);
		return copy_book;
	}
	return NULL;

}


int CS_Course::setTakef(int isTakef)
{
	isTakef_ = isTakef;
	return 1;
}

void CS_Course::setBook(const char* book)
{
	delete[] book_;
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
			course_grade = (round((1 - hw_weigh_)*exam_grade_ + hw_weigh_ * hw_average));
		}
		else
		{
			course_grade = exam_grade_;
		}
		
	}
	return course_grade;
}