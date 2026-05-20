// Demo entry point for the student database.

#include <iostream>
#include <cstdlib>
#include <memory>
#include "StudentDb.h"
#include "SimpleUI.h"

using namespace std;

int main()
{
	// Exam note: disable buffering so output appears immediately.
	setvbuf(stdout, NULL, _IONBF, 0);

	// Display a welcome message
	std::cout << "Welcome to the Student Database System!" << std::endl;

	// Create a database object for storing student data
	StudentDb database;

	// Initialize the user interface with the database pointer
	SimpleUI ui(&database);

	// Creating a dummy weekly course
	// Sample data helps the UI show something at startup.
	WeeklyCourse dummyCourse(101,                     // courseKey
			"Automation Basics",                     // title
			"Electrical Engineering",               // major
			3.0,                                   // creditPoints
			Poco::DateTime::DaysOfWeek::WEDNESDAY,// dayOfWeek
			Poco::Data::Time(9, 30, 0),          // startTime (09:30:00)
			Poco::Data::Time(11, 0, 0)          // endTime (11:00:00)
					);

	// Creating a dummy block course
	BlockCourse dummyBlockCourse(102,               // courseKey
			"Advanced Automation",                 // title
			"Electrical Engineering",             // major
			4.0,                                 // creditPoints
			Poco::Data::Date(2025, 2, 1),       // startDate (1st Feb 2025)
			Poco::Data::Date(2025, 5, 1),      // endDate (1st May 2025)
			Poco::Data::Time(9, 0, 0),        // startTime (09:00:00)
			Poco::Data::Time(12, 0, 0)       // endTime (12:00:00)
					);

	// Creating a dummy student
	Student dummyStudent("John",                    // firstName
			"Doe",                                 // lastName
			Poco::Data::Date(1998, 5, 15),        // dateOfBirth (15th May 1998)
			"123 Elm Street",                    // street
			12345,                              // postalCode
			"Springfield",                     // cityName
			"Additional details about the student."      // additionalDetails
			);

	// Creating unique pointers for block and weekly courses
	// Exam note: unique_ptr owns heap objects and cleans them up automatically.
	unique_ptr<Course> bCourse = make_unique<BlockCourse>(
			move(dummyBlockCourse));
	unique_ptr<Course> wCourse = make_unique<WeeklyCourse>(move(dummyCourse));

	// Adding courses to the database
	database.getCourses()[bCourse->getCourseKey()] = move(bCourse);
	database.getCourses()[wCourse->getCourseKey()] = move(wCourse);

	database.addStudent(dummyStudent);

	// Exam note: enrollment stores a pointer to the selected course.
	Enrollment enrollment("Win24", 2.5, database.getCourses().at(101).get());
	database.addEnrollment(100000, enrollment);

	ostringstream oss;
	ostringstream oss1;
	database.write(oss);
	database.write(oss1);

	cout << endl << endl;
	cout << oss.str();

	cout << endl << endl;

	ui.run();

	return 0;
}
