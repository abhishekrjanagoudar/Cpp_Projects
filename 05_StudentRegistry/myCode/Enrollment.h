#ifndef ENROLLMENT_H
#define ENROLLMENT_H

#include <iostream>
#include <string>
#include <ostream>
#include <istream>
#include <sstream>
#include "Course.h"

// Stores one course enrollment.
class Enrollment
{
private:
	std::string semester; // Semester in which the course is taken.
	float grade = -1.0;  // Grade received , initialized to -1.0.
	Course *course;     // Pointer to the enrolled course.

public:
	Enrollment(std::string semester, float grade, Course *course);

	virtual ~Enrollment();

	Course* getCourse() const;

	float getGrade() const;

	void setGrade(float grade);

	const std::string& getSemester() const;

	void write(std::ostringstream &os) const;

	void read(std::istringstream &is);
};

#endif // ENROLLMENT_H
