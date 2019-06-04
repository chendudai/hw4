####################################################################
# Makefile for building the theater application
#

#
# Definitions
#
CC = g++
CFLAGS = -g -Wall
CCLINK = $(CC)
OBJS = Course.o CS_Course.o EE_Course.o Person.o Student.o StArray.o main.o
LIBS = 
RM = rm -f
TARGET = UpGrade

$(TARGET): $(OBJS)
	$(CCLINK) -o $(LIBS) $(TARGET) $(OBJS)

Course.o: Course.cpp Course.h
CS_Course.o: CS_Course.cpp CS_Course.h Course.h
EE_Course.o: EE_Course.cpp EE_Course.h Course.h
Person.o: Person.cpp Person.h
Student.o: Student.cpp Student.h Person.h EE_Course.h CS_Course.h Proj.h
StArray.o: StArray.cpp StArray.h EE_Course.h CS_Course.h Student.h Proj.h
main.o: main.cpp StArray.h Student.h Proj.h

#
# Cleaninng
#
clean:
	$(RM) $(TARGET) *.o *.bak *~* *"#"* core
