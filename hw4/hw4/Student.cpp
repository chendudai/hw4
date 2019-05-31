#include <iostream> 
#include <math.h>  
#include "Proj.h"
#include "Student.h"
#include "Person.h"
#include "CS_Course.h"
#include "EE_Course.h"

 
 Student::Student(int id, char* name, int EE_course_num, int CS_course_num)
	 :Person(id,name),EE_course_num_(EE_course_num), CS_course_num_(CS_course_num)
{
	 pEE_courses_arr_ = new EE_Course*[MAX_COURSE_NUM]{NULL};
	 pCS_courses_arr_ = new CS_Course*[MAX_COURSE_NUM]{NULL};
}
 Student::~Student()
 {
	 delete[] pEE_courses_arr_;
	 delete[] pCS_courses_arr_;
 }
 int Student::getCourseCnt() const {
	 return EE_course_num_ + CS_course_num_;
 }

int Student::addEE_Course(EE_Course* p_EE_Course)
{
	if (p_EE_Course == NULL)
	{
		return 0;
	}
	for (int i=0; i < MAX_COURSE_NUM; i++)
	{
		if (pEE_courses_arr_[i] == NULL)
		{
			pEE_courses_arr_[i] = p_EE_Course;
			return 1;
		}
	}
	return 0;
}


int Student::addCS_Course(CS_Course* p_CS_Course)
{
	if (p_CS_Course == NULL)
	{
		return 0;
	}
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (pCS_courses_arr_[i] == NULL)
		{
			pCS_courses_arr_[i] = p_CS_Course;
			return 1;
		}
	}
	return 0;

}

int Student::remCourse(int course_num)
{
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (pCS_courses_arr_[i]->getNum() == course_num)
		{
			delete pCS_courses_arr_[i];
			pCS_courses_arr_[i] = NULL;
			return 1;
		}

		else if (pEE_courses_arr_[i]->getNum() == course_num)
		{
			delete pEE_courses_arr_[i];
			pEE_courses_arr_[i] = NULL;
			return 1;
		}

	}
	return 0;
}

EE_Course* Student::getEE_Course(int EE_course_num) const
{
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (pEE_courses_arr_[i]->getNum() == EE_course_num)
		{
			return pEE_courses_arr_[i];
		}
	}
	return NULL;
}

CS_Course* Student::getCS_Course(int CS_course_num) const
{
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (pCS_courses_arr_[i]->getNum() == CS_course_num)
		{
			return pCS_courses_arr_[i];
		}
	}
	return NULL;
}

int Student::getAvg() const
{
	double sum = 0;
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		sum += pEE_courses_arr_[i]->getCourseGrade();
	}
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		sum += pCS_courses_arr_[i]->getCourseGrade(); //@@@@@@@@@@@@@@@@ how to get a member
	}
	return round(sum / (EE_course_num_ + CS_course_num_));
}


using namespace std;

void Student::print() const
{
	cout << "SName:" << name_ << endl;
	cout << "SID:" << id_ << endl;
	cout << "Avg.:" << getAvg() << endl;
	cout << "EE:" << endl;

	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (pEE_courses_arr_[i] != NULL)
		{
			cout << pEE_courses_arr_[i]->getNum() << " " << pEE_courses_arr_[i]->getNum() << " " << pEE_courses_arr_[i]->getCourseGrade() << endl;;
		}
	}
	
	cout << "CS courses:" << endl;
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (pCS_courses_arr_[i] != NULL)
		{
			cout <<  pCS_courses_arr_[i]->getName() << " " << pCS_courses_arr_[i]->getName() << " " << pCS_courses_arr_[i]->getCourseGrade() << endl;;
		}
	}
}