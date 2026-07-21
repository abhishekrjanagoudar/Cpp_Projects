#ifndef STUDENT_DB_H
#define STUDENT_DB_H

#include <string>
#include <iostream>
#include <map>
#include <memory>
#include <sstream>

#include "Student.h"
#include "Course.h"
#include "Enrollment.h"
#include "WeeklyCourse.h"
#include "BlockCourse.h"

// Holds the students and courses.
class StudentDb
{
private:
	// Map of students indexed by their ID.
	std::map<int, Student> students;

	// Map of courses indexed by course ID.
	std::map<int, std::unique_ptr<Course>> courses;

public:
	StudentDb();

	virtual ~StudentDb();

	void addStudent(Student &student);

	void addCourse(std::unique_ptr<Course> course);

	void addEnrollment(int matrikelNo, Enrollment &enrollment);

	std::map<int, std::unique_ptr<Course>>& getCourses();

	std::map<int, Student>& getStudents();

	void write(std::ostringstream &os) const;

	void read(std::istringstream &is);
};

#endif // STUDENT_DB_H
