#include "Course.h"
#include <string.h>
#include <math.h> 


Course::Course(int num,const char* name, int hw_num, double hw_weigh) : num_(num), hw_num_(hw_num), hw_weigh_(hw_weigh)
{
	if (name != NULL)
	{
		name_ = new char[strlen(name) + 1];
		strcpy(name_, name);
	}
	if (hw_num > 0)
	{
		hw_grades_ = new int[hw_num_] {0};
	}
	else
	{
		hw_grades_ = NULL;
	}
	
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
	if (name_ != NULL)
	{
		char* course_name = new char[strlen(name_) + 1];
		course_name = strcpy(course_name, name_);
		return course_name;
	}
	return NULL;
}

int Course::getExamGrade() const { return exam_grade_; }

int Course::getHwGrade(int hw_num) const { return hw_grades_[hw_num]; }

int Course::getHwNum() const { return hw_num_; }

double  Course::getHwWeigh() const { return hw_weigh_; }

double Course::getHwAverage() const
{
	double average = 0;
	if (hw_num_ > 0)
	{		
		for (int i = 0; i < hw_num_; i++)
		{
			average += hw_grades_[i];
		}
		average = average / hw_num_;
	}
	return average;
}

int Course::getCourseGrade() const 
{
	double  hw_average = getHwAverage();
	int course_grade = round( (1-hw_weigh_)*exam_grade_ + hw_weigh_ * hw_average );
	return course_grade;

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