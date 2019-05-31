#include <string.h>
#include "Person.h"

Person::Person(int id, char* name) :
	id_(id){
	name_ = new char[strlen(name) + 1];
	strcpy(name_, name);
}

Person::~Person()
{
	if (name_ != NULL)
	{
		delete [] name_;
	}
}
