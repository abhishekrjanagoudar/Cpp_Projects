/*
 * University.cpp
 *
 *  Created on: 19 May 2026
 *      Author: abhir
 */

#include "University.h"
#include <iostream>

University::University()
{
	// Initialize member smart pointers

	course = std::make_unique<Course>();

	topper = std::make_shared<Student>(1, "Abhishek");
}

University::~University()
{
}

void University::setup()
{
	/*
	 * =========================
	 * VECTOR PRACTICE
	 * =========================
	 */

	course->students.push_back(Student(1, "Abhi"));
	course->students.push_back(Student(2, "Rahul"));
	course->students.push_back(Student(3, "Neha"));

	/*
	 * =========================
	 * SET PRACTICE
	 * =========================
	 */

	course->courseCodes.insert("AUT101");
	course->courseCodes.insert("ROB202");
	course->courseCodes.insert("CV303");

	// Duplicate test
	course->courseCodes.insert("AUT101");

	/*
	 * =========================
	 * LIST PRACTICE
	 * =========================
	 */

	course->attendanceQueue.push_back(101);
	course->attendanceQueue.push_back(102);

	course->attendanceQueue.push_front(100);

	// Insert in middle
	auto it = course->attendanceQueue.begin();

	it++;

	course->attendanceQueue.insert(it, 999);

	/*
	 * =========================
	 * MAP PRACTICE
	 * =========================
	 */

	course->studentMarks[1] = 95;
	course->studentMarks[2] = 88;
	course->studentMarks[3] = 91;

	// Update marks
	course->studentMarks[2] = 90;

	/*
	 * =========================
	 * MAP SEARCH PRACTICE
	 * =========================
	 */

	if (course->studentMarks.find(2) != course->studentMarks.end())
	{
		std::cout << "Student 2 found in map\n";
	}
}

void University::display()
{
	/*
	 * =========================
	 * DISPLAY VECTOR
	 * =========================
	 */

	std::cout << "\n===== STUDENTS =====\n";

	for (const Student& s : course->students)
	{
		s.display();
		std::cout << '\n';
	}

	/*
	 * =========================
	 * DISPLAY SET
	 * =========================
	 */

	std::cout << "\n===== COURSE CODES =====\n";

	for (const std::string& code : course->courseCodes)
	{
		std::cout << code << '\n';
	}

	/*
	 * =========================
	 * DISPLAY LIST
	 * =========================
	 */

	std::cout << "\n===== ATTENDANCE QUEUE =====\n";

	for (int roll : course->attendanceQueue)
	{
		std::cout << roll << '\n';
	}

	/*
	 * =========================
	 * DISPLAY MAP
	 * =========================
	 */

	std::cout << "\n===== STUDENT MARKS =====\n";

	for (const auto& pair : course->studentMarks)
	{
		std::cout << "ID: "
				  << pair.first
				  << " -> Marks: "
				  << pair.second
				  << '\n';
	}

	/*
	 * =========================
	 * SHARED POINTER PRACTICE
	 * =========================
	 */

	std::cout << "\n===== TOPPER =====\n";

	topper->display();

	std::shared_ptr<Student> anotherTopperPointer = topper;

	std::cout << "\nShared Pointer Count: "
			  << topper.use_count()
			  << '\n';

	/*
	 * =========================
	 * ERASE PRACTICE
	 * =========================
	 */

	// Remove first student
	course->students.erase(course->students.begin());

	// Remove course code
	course->courseCodes.erase("ROB202");

	// Remove attendance value
	course->attendanceQueue.remove(999);

	// Remove marks entry
	course->studentMarks.erase(3);

	std::cout << "\n===== DATA AFTER ERASE =====\n";

	std::cout << "\nStudents Remaining: "
			  << course->students.size()
			  << '\n';

	std::cout << "Course Codes Remaining: "
			  << course->courseCodes.size()
			  << '\n';

	std::cout << "Attendance Entries Remaining: "
			  << course->attendanceQueue.size()
			  << '\n';

	std::cout << "Marks Entries Remaining: "
			  << course->studentMarks.size()
			  << '\n';
}
