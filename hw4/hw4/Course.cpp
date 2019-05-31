#include "Course.h"
#include <string.h>
#include <math.h> 


Course::Course(int num, char* name, int hw_num, double hw_weigh) : num_(num), hw_num_(hw_num), hw_weigh_(hw_weigh)
{
	name_ = new char[strlen(name) + 1];
	strcpy(name_, name);
	hw_grades_ = new int[hw_num_];
}

Course::~Course()
{
	if (name_ != NULL)
	{
		delete []name_;
	}
	if (hw_grades_ != NULL)
	{
		delete [] hw_grades_;
	}
}

int Course::getNum() const { return num_; }

char* Course::getName()const
{
	char* course_name = strcpy(course_name, name_);
	return course_name;
	
}

int Course::getExamGrade() const { return exam_grade_; }

int Course::getHwGrade(int hw_num) const { return hw_grades_[hw_num]; }

int Course::getHwNum() const { return hw_num_; }

double  Course::getHwWeigh() const { return hw_weigh_; }

double Course::getHwAverage() const
{
	double average=0;
	int* tmp = hw_grades_;
	while (tmp != NULL)
	{
		average += *tmp;
		tmp++;
	}
	average = average / hw_num_;
	return average;
}

int Course::getCourseGrade() const 
{
	double  hw_average = getHwAverage();	int course_grade = round( (1-hw_weigh_)*exam_grade_ + hw_weigh_ * hw_average );	return course_grade;
}

int Course::setExamGrade(int grade)

{
	if ((grade > 100) || (grade < 0))
	{
		return 0;
	}
	exam_grade_ = grade;
	return 1;
}

int Course::setHwGrade(int hw_num, int grade) 
{ 
	if ((grade > 100) || (grade < 0))
	{
		return 0;
	}
	hw_grades_[hw_num] = grade;
	return 1;
}