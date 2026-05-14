// Enrollment implementation.
#include "Enrollment.h"
#include <sstream>
#include <iostream>

using namespace std;

Course* Enrollment::getCourse() const
{
	return course;
}

float Enrollment::getGrade() const
{
	return grade;
}

void Enrollment::setGrade(float grade)
{
	this->grade = grade;
}

const std::string& Enrollment::getSemester() const
{
	return semester;
}

Enrollment::Enrollment(std::string semester, float grade, Course *course)
{
	this->semester = semester;
	this->grade = grade;
	this->course = course;
}

Enrollment::~Enrollment()
{

}

void Enrollment::write(ostringstream &os) const
{
	os << course->getCourseKey() << ';' << semester << ';' << grade;
}

void Enrollment::read(istringstream &is)
{
	string sem, grade;

	getline(is, sem, ';');
	getline(is, grade, '\n');

	this->semester = sem;
	this->grade = stof(grade);
}
