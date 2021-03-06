#include <iostream> 
#include <math.h>  
#include "Proj.h"
#include "Student.h"
#include "Person.h"
#include "CS_Course.h"
#include "EE_Course.h"

 
 Student::Student(int id,const char* name, int EE_course_num, int CS_course_num)
	 :Person(id,name),EE_course_num_(EE_course_num), CS_course_num_(CS_course_num)
{
	 pEE_courses_arr_ = new EE_Course*[MAX_COURSE_NUM]{NULL};
	 pCS_courses_arr_ = new CS_Course*[MAX_COURSE_NUM]{NULL};
}
 Student::~Student()
 {
	 for (int i = 0; i < MAX_COURSE_NUM; i++)
	 {
		 if (pEE_courses_arr_[i] != NULL)
		 {
			 delete pEE_courses_arr_[i];
		 }
		 if (pCS_courses_arr_[i] != NULL)
		 {
			 delete pCS_courses_arr_[i];
		 }
		
	 }
	 if (pEE_courses_arr_ != NULL)
	 {
		 delete[] pEE_courses_arr_;
	 }
	 if (pCS_courses_arr_ != NULL)
	 {
		 delete[] pCS_courses_arr_;
	 }
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
			EE_course_num_++;
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
			CS_course_num_++;
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
			if (pCS_courses_arr_[i] != NULL)
			{
				delete pCS_courses_arr_[i];
				CS_course_num_--;
				pCS_courses_arr_[i] = NULL;
				return 1;
			}

		}

		else if (pEE_courses_arr_[i]->getNum() == course_num)
		{
			if (pEE_courses_arr_[i] != NULL)
			{
				delete pEE_courses_arr_[i];
				EE_course_num_--;
				pEE_courses_arr_[i] = NULL;
				return 1;
			}
	
		}

	}
	return 0;
}

EE_Course* Student::getEE_Course(int EE_course_num) const
{
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (pEE_courses_arr_[i] != NULL)
		{
			if (pEE_courses_arr_[i]->getNum() == EE_course_num)
			{
				return pEE_courses_arr_[i];
			}
		}
		
	}
	return NULL;
}

CS_Course* Student::getCS_Course(int CS_course_num) const
{
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (pCS_courses_arr_[i] != NULL)
		{
			if (pCS_courses_arr_[i]->getNum() == CS_course_num)
			{
				return pCS_courses_arr_[i];
			}
		}
		
	}
	return NULL;
}

int Student::getAvg() const
{
	double sum = 0;
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (pEE_courses_arr_[i] != NULL)
		{
			sum += pEE_courses_arr_[i]->getCourseGrade();
		}
		
	}
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (pCS_courses_arr_[i] != NULL)
		{
			sum += pCS_courses_arr_[i]->getCourseGrade();
		}
		
	}
	if ((EE_course_num_ + CS_course_num_) == 0)
	{
		return 0;
	}
	return round(sum / (EE_course_num_ + CS_course_num_));
}


using namespace std;

void Student::print() const
{
	cout << "Student name: " << name_ << endl;
	cout << "Student ID: " << id_ << endl;
	cout << "Average grade: " << getAvg() << "\n" <<endl;
	cout << "EE courses:" << endl;

	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (pEE_courses_arr_[i] != NULL)
		{
			char* course_name;
			course_name = pEE_courses_arr_[i]->getName();
			if (course_name != NULL)
			{
				cout << pEE_courses_arr_[i]->getNum() << " " << course_name << ": " << pEE_courses_arr_[i]->getCourseGrade() << endl;;
				delete[] course_name;
			}

		} 
	}
	cout << "" << endl;
	cout << "CS courses:" << endl;
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (pCS_courses_arr_[i] != NULL )
		{
			char* course_name;
			course_name = pCS_courses_arr_[i]->getName();
			if (course_name != NULL)
			{
				cout << pCS_courses_arr_[i]->getNum() << " " << course_name << ": " << pCS_courses_arr_[i]->getCourseGrade() << endl;;
				delete[] course_name;
			}
		}
	}
	cout << "" << endl;
	
}