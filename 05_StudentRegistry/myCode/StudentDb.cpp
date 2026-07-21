// Student database implementation.

#include "StudentDb.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include "Student.h"

using namespace std;

StudentDb::StudentDb()
{

}

StudentDb::~StudentDb()
{

}

std::map<int, std::unique_ptr<Course>>& StudentDb::getCourses()
{
	return courses;
}

std::map<int, Student>& StudentDb::getStudents()
{
	return students;
}

void StudentDb::addCourse(unique_ptr<Course> course)
{
	if (course == nullptr)
	{
		return;
	}

	// Exam note: unique_ptr owns the course object here.
	int courseKey = course->getCourseKey();
	courses[courseKey] = move(course);
}

void StudentDb::addStudent(Student &student)
{
	students[student.getMatrikelNumber()] = student;
	student.refreshNextMatrikelNumber();
}

void StudentDb::addEnrollment(int matrikelNo, Enrollment &enrollment)
{
	auto studentIt = students.find(matrikelNo);
	if (studentIt != students.end())
	{
		studentIt->second.addEnrollment(enrollment);
	}
}

void StudentDb::write(ostringstream &os) const
{

	// Save courses first, then students, then enrollments.
	os << static_cast<int>(courses.size());
	for (const auto &pair : courses)
	{
		os << endl;
		pair.second->write(os);
	}

	os << endl << static_cast<int>(students.size());

	ostringstream enrolStream;
	int enrCount = 0;
	for (const auto &pair : students)
	{
		os << endl;
		pair.second.write(os);

		// Exam note: vector stores the enrollments of one student.
		for (const auto &en : pair.second.getEnrollments())
		{
			enrCount++;
			enrolStream << endl;
			enrolStream << pair.second.getMatrikelNumber() << ';';
			en.write(enrolStream);
		}
	}

	os << endl << enrCount;
	os << enrolStream.str();
}

void StudentDb::read(istringstream &is)
{
	courses.clear();
	students.clear();
	Student::resetNextMatrikelNumber();

	string count;

	// Read the number of saved courses.
	getline(is, count, '\n');

	string courseType;
	for (int i = 0; i < stoi(count); ++i)
	{
		getline(is, courseType, ';');

		// Exam note: course type tells us which derived class to build.
		if (courseType == "W")
		{
			WeeklyCourse wCourse(0, "", "", 5.0,
					Poco::DateTime::DaysOfWeek::SUNDAY,
					Poco::Data::Time(0, 0, 0), Poco::Data::Time(0, 0, 0));

			wCourse.read(is);

			this->addCourse(make_unique<WeeklyCourse>(move(wCourse)));
		}
		else if (courseType == "B")
		{
			BlockCourse bCourse(0, "", "", 5.0, Poco::Data::Date(2001, 1, 1),
					Poco::Data::Date(2001, 1, 1), Poco::Data::Time(0, 0, 0),
					Poco::Data::Time(0, 0, 0));

			bCourse.read(is);

			this->addCourse(make_unique<BlockCourse>(move(bCourse)));
		}
	}

	// Read the saved students.
	getline(is, count, '\n');
	for (int i = 0; i < stoi(count); ++i)
	{
		Student student("", "", Poco::Data::Date(2001, 1, 1), "", 0, "", "");
		student.read(is);
		students[student.getMatrikelNumber()] = student;
	}

	// Read enrollments and connect them back to the stored student and course.
	getline(is, count, '\n');
	for (int i = 0; i < stoi(count); ++i)
	{
		string matrikelNo, courseKey;
		getline(is, matrikelNo, ';');
		getline(is, courseKey, ';');

		Enrollment enrollment("", -1, courses.at(stoi(courseKey)).get());
		enrollment.read(is);

		students[stoi(matrikelNo)].addEnrollment(enrollment);
	}
}
