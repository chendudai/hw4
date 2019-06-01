#include "StArray.h"
#include "Proj.h"
#include "Student.h"
#include "EE_Course.h"
#include "CS_Course.h"
#include <string.h>


StArray::StArray():St_num_(0)
{
	pSt_arr_=new Student*[MAX_COURSE_NUM]{NULL};
}

StArray::~StArray()
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		if (pSt_arr_[i] != NULL)
		{
			delete pSt_arr_[i];
		}
		
	}
	delete[] pSt_arr_;
}

int StArray::addStudent(int id, char * name)
{
	if (name == NULL || St_num_==MAX_STUDENT_NUM)
		return 0;
	for (int i = 0; i < MAX_STUDENT_NUM; i++)// search for another student with this id,if existts then fail the addition
	{
		if (pSt_arr_[i] != NULL)
		{
			if (pSt_arr_[i]->getID() == id)
			{
				return 0;
			}
		}
		
	}
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		if (pSt_arr_[i] == NULL)
		{
			pSt_arr_[i] = new Student(id, name, 0, 0);
			St_num_++;
			return 1;
		}
	}	
}

int StArray::addEE_Course(int id, int course_num, char * course_name, int hw_num, double hw_weigh)
{
	if (course_name == NULL)
		return 0;
	Student* pSt=NULL;
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		if (pSt_arr_[i] != NULL)
		{
			if (pSt_arr_[i]->getID() == id)
			{
				pSt= pSt_arr_[i];
				break;
			}
		}
	}

	if (pSt == NULL)
		return 0;

	EE_Course* ee_course = new EE_Course(course_num, course_name, hw_num, hw_weigh, 0);
	return pSt->addEE_Course(ee_course);
}

int StArray::addCS_Course(int id, int course_num, char* course_name, int hw_num, double hw_weigh, bool isTakef, char* book)
{
	if (course_name == NULL || book == NULL)
		return 0;
	Student* pSt = NULL;
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		if (pSt_arr_[i] != NULL)
		{
			if (pSt_arr_[i]->getID() == id)
			{
				pSt = pSt_arr_[i];
				break;
			}
		}
		
	}
	if (pSt == NULL)
		return 0;

	CS_Course* cs_course=new CS_Course(course_num, course_name, hw_num, hw_weigh,isTakef,book);
	return pSt->addCS_Course(cs_course);
}

int StArray::setHwGrade(int id, int course_num, int hw_num_order, int grade)
{
	Student* pSt = NULL;
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		if (pSt_arr_[i] != NULL)
		{
			if (pSt_arr_[i]->getID() == id)
			{
				pSt = pSt_arr_[i];
				break;
			}
		}
	}
	if (pSt == NULL)
		return 0;

	if ( (pSt->getEE_Course(course_num) == NULL || pSt->getEE_Course(course_num)->getHwNum() < hw_num_order)
		&& ((pSt->getCS_Course(course_num) == NULL || pSt->getCS_Course(course_num)->getHwNum() < hw_num_order)) )//The Course does not exist or this is more homework than needed.
	{
		return 0;
	}
	else 
	{
		if (pSt->getEE_Course(course_num) != NULL)
		{
			pSt->getEE_Course(course_num)->setHwGrade(hw_num_order, grade);
			return 1;
		}

		if (pSt->getCS_Course(course_num) != NULL)
		{
			pSt->getCS_Course(course_num)->setHwGrade(hw_num_order, grade);
			return 1;
		}
	}

}





int StArray::setExamGrade(int id, int course_num, int exam_grade)
{
	Student* pSt = NULL;
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		if (pSt_arr_[i] != NULL)
		{
			if (pSt_arr_[i]->getID() == id)
			{
				pSt = pSt_arr_[i];
				break;
			}
		}
	}
	if (pSt == NULL)
		return 0;

	if (pSt->getEE_Course(course_num) == NULL && pSt->getCS_Course(course_num) == NULL) //The Course does not exist.
	{
		return 0;
	}
	else
	{
		if (pSt->getEE_Course(course_num) != NULL)
		{
			pSt->getEE_Course(course_num)->setExamGrade(exam_grade);
			return 1;
		}

		if (pSt->getCS_Course(course_num) != NULL)
		{
			pSt->getCS_Course(course_num)->setExamGrade(exam_grade);
			return 1;
		}
		
	}

}



int StArray::setFactor(int course_num, int factor)
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		if (pSt_arr_[i] != NULL && pSt_arr_[i]->getEE_Course(course_num)!=NULL)
		{
			pSt_arr_[i]->getEE_Course(course_num)->setFactor(factor);
		}

	}
	return 1;
}

int StArray::printStudent(int id)
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		if (pSt_arr_[i] != NULL)
		{
			if (pSt_arr_[i]->getID() == id)
			{
				pSt_arr_[i]->print();
				return 1;
			}
		}
		
	}
	return 0;

}

void StArray::printAll()
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		if (pSt_arr_[i] != NULL)
		{
			printStudent(pSt_arr_[i]->getID());
		}
		
	}

}


void StArray::resetStArray()
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		if (pSt_arr_[i] != NULL)
		{
			pSt_arr_[i]->~Student();
		}

	}
}

