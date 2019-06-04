#include "EE_Course.h"
#include <string.h>
#include <math.h> 

EE_Course::EE_Course(int num,const char* name, int hw_num, double hw_weigh,int factor) 
	:Course(num,  name, hw_num,hw_weigh),factor_(factor){}

EE_Course::~EE_Course(){}

int EE_Course::getFactor() const { return factor_; }

int EE_Course::setFactor(int factor)
{
	factor_ = factor;
	return 1;
}

int EE_Course::getCourseGrade() const
{
	double  hw_average = getHwAverage();
	int course_grade = round((1 - hw_weigh_)*exam_grade_ + hw_weigh_ * hw_average) + factor_;
	if (course_grade > 100)
	{
		course_grade = 100;
	}
	return course_grade;

}