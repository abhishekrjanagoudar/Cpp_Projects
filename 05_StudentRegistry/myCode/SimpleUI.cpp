// Simple command-line UI for the student database.

#include "SimpleUI.h"
#include <fstream>
#include <iostream>

using namespace std;

Poco::Data::Date SimpleUI::getDateFromUser(std::string str) const
{
	int day, month, year;

	// Exam note: simple console input for a date.
	cout << str << endl << "Day: ";
	cin >> day;
	cout << endl << "Month: ";
	cin >> month;
	cout << endl << "Year: ";
	cin >> year;

	return Poco::Data::Date(year, month, day);
}

Poco::Data::Time SimpleUI::getTimeFromUser(std::string str) const
{
	int hour, min;

	// Exam note: a time is stored as hour, minute, second.
	cout << str << endl << "Hours: ";
	cin >> hour;
	cout << endl << "Min: ";
	cin >> min;

	return Poco::Data::Time(hour, min, 0);
}

// Constructor
SimpleUI::SimpleUI(StudentDb *db) :
		database(db)
{
}

// Runs the user interface
void SimpleUI::run()
{
	while (true)
	{
		// Exam note: a switch statement is used for the menu.
		cout << endl << "\nCommands:\n";
		cout << "1. Add new course\n";
		cout << "2. List courses\n";
		cout << "3. Add new student\n";
		cout << "4. Add enrollment\n";
		cout << "5. Print student\n";
		cout << "6. Search student\n";
		cout << "7. Update student\n";
		cout << "8. Save database\n";
		cout << "9. Load database\n";
		cout << "0. Exit\n";
		cout << "Enter command: ";

		int command;
		cin >> command;
		cin.ignore();

		switch (command)
		{
		case 1:
		{
			addCourse();
			break;
		}
		case 2:
		{
			listCourses();
			break;
		}
		case 3:
		{
			addStudent();
			break;
		}
		case 4:
		{
			addEnrollment();
			break;
		}
		case 5:
		{
			int matrikelNumber;
			cout << endl << "Enter matrikel number: ";
			cin >> matrikelNumber;
			printStudent(matrikelNumber);
			break;
		}
		case 6:
		{
			searchStudent();
			break;
		}
		case 7:
		{
			updateStudent();
			break;
		}
		case 8:
		{
			saveDatabase();
			break;
		}
		case 9:
		{
			loadDatabase();
			break;
		}
		case 0:
		{
			return;
		}
		default:
		{
			cout << "Invalid command!\n";
			break;
		}
		}
	}
}

void SimpleUI::addCourse()
{
	unsigned int courseKey;
	string title;
	string major;
	int courseType, dayNo;
	float creditPoints;

	cout << endl
			<< "Choose Course type (1 = Weekly Course and 2 = Block Course): ";
	cin >> courseType;

	if (courseType == 1)
	{
		// Weekly course branch.
		cout << "Enter course key: ";
		cin >> courseKey;

		cout << "Enter course name: ";
		cin.ignore();
		getline(cin, title);

		cout << "Enter major: ";
		getline(cin, major);

		cout << "Enter credit points: ";
		cin >> creditPoints;

		cout << "Enter day of week (0 = Sunday): ";
		cin >> dayNo;

		auto startTime = getTimeFromUser("Start Time: ");
		auto endTime = getTimeFromUser("End Time: ");
		// Exam note: static_cast is used to convert an int to the enum type.
		Poco::DateTime::DaysOfWeek dayOfWeek =
				static_cast<Poco::DateTime::DaysOfWeek>(dayNo);

		WeeklyCourse wCourse(courseKey, title, major, creditPoints, dayOfWeek,
				startTime, endTime);

		database->addCourse(make_unique<WeeklyCourse>(move(wCourse)));
	}
	else if (courseType == 2)
	{
		// Block course branch.
		cout << "Enter course key: ";
		cin >> courseKey;

		cout << "Enter course name: ";
		cin.ignore();
		getline(cin, title);

		cout << "Enter major: ";
		cin >> major;

		cout << "Enter credit points: ";
		cin >> creditPoints;

		auto startDate = getDateFromUser("Start Date: ");
		auto endDate = getDateFromUser("End Date: ");
		auto startTime = getTimeFromUser("Start Time: ");
		auto endTime = getTimeFromUser("End Time: ");

		database->addCourse(
				make_unique<BlockCourse>(courseKey, title, major, creditPoints,
						startDate, endDate, startTime, endTime));
	}
	cout << "Course added successfully!\n";
}

// Lists all courses
void SimpleUI::listCourses() const
{
	cout << endl;

	cout << endl << "=======Course List======";

	// Exam note: range-based for loop over the map.
	for (const auto &pair : database->getCourses())
	{
		const auto &course = pair.second.get();
		cout << course->getCourseDetail();
	}
}

// Handles adding a new student
void SimpleUI::addStudent()
{
	string firstName, lastName;
	Poco::Data::Date dateOfBirth;
	string street, city, additionalDetails;
	unsigned short postalCode;

	cout << "Enter first name: ";
	getline(cin, firstName);

	cout << "Enter last name: ";
	getline(cin, lastName);

	dateOfBirth = getDateFromUser("Enter date of birth (DD.MM.YYYY): ");

	cout << "Enter street: ";
	cin.ignore();
	getline(cin, street);

	cout << "Enter postal code: ";
	cin >> postalCode;

	cout << "Enter city: ";
	cin.ignore();
	getline(cin, city);

	cout << "Additional Details: ";
	getline(cin, additionalDetails);

	// The Address object is built inside the Student constructor.
	Student stud(firstName, lastName, dateOfBirth, street, postalCode, city,
			additionalDetails);
	database->addStudent(stud);

	cout << "Student added successfully!\n";
}

// Handles adding an enrollment
void SimpleUI::addEnrollment()
{
	int matrikelNumber, courseId;
	string semester;

	cout << "Enter matrikel number: ";
	cin >> matrikelNumber;

	cout << "Enter course ID: ";
	cin >> courseId;

	cout << "Enter semester (e.g., WS2024): ";
	cin >> semester;

	try
	{
		// Exam note: map::at throws if the course id does not exist.
		unique_ptr<Course> &course = database->getCourses().at(courseId);
		if (course != nullptr)
		{
			Enrollment enrollment(semester, -1, course.get());

			database->addEnrollment(matrikelNumber, enrollment);
			cout << endl << "Enrollment added successfully!";
		}
		else
		{
			cout << endl << "Enrollment failed!";
		}
	} catch (const exception &e)
	{
		cout << endl << "Enrollment failed!";
	}

}

// Prints student details
void SimpleUI::printStudent(int matrikelNo) const
{
	try
	{
		const auto &stud = database->getStudents().at(matrikelNo);

		cout << endl << "=========Student========";
		cout << endl << "Matrikel Number: " << stud.getMatrikelNumber();
		cout << endl << "First name: " << stud.getFirstName();
		cout << endl << "Last name: " << stud.getLastName();
		cout << endl << "Date of Birth(dd.mm.yyy): "
				<< stud.getDateOfBirth().day() << "."
				<< stud.getDateOfBirth().month() << "."
				<< stud.getDateOfBirth().year();

		cout << endl << endl << "Address:";
		cout << endl << "Street: " << stud.getAddress().getStreet();
		cout << endl << "Postal Code: " << stud.getAddress().getPostalCode();
		cout << endl << "City: " << stud.getAddress().getCityName();
		cout << endl << "Additional Details: "
				<< stud.getAddress().getAdditionDetails();

		cout << endl << "Enrollments: " << endl;
		// Each student can have a vector of enrollments.
		for (const auto &enro : stud.getEnrollments())
		{
			cout << endl << enro.getCourse()->getCourseKey() << " : "
					<< enro.getCourse()->getTitle();
			cout << endl << "Sem: " << enro.getSemester();
			if (enro.getGrade() != -1)
			{
				cout << endl << "Grades: " << enro.getGrade();
			}
			else
			{
				cout << endl << "Grades: no available grades yet";
			}
		}
	} catch (const exception &e)
	{

	}
}

// Searches for students by name substring
void SimpleUI::searchStudent() const
{
	string searchString;
	cout << "Enter name substring to search: ";
	cin.ignore();
	getline(cin, searchString);

	cout << endl << "========Search Result========";
	for (const auto &pair : database->getStudents())
	{
		const auto &stud = pair.second;
		if (stud.getFirstName().find(searchString) != string::npos)
		{
			cout << endl << stud.getMatrikelNumber() << ">>>>"
					<< stud.getFirstName() << " " << stud.getLastName();
		}
	}
}

// Updates a student's details
void SimpleUI::updateStudent()
{
	while (true)
	{
		int matrikelNumber;
		cout << endl << "Enter matrikel number: ";
		cin >> matrikelNumber;

		printStudent(matrikelNumber);

		cout << endl << endl << endl << "Commands:";
		cout << endl << "1. First name";
		cout << endl << "2. Last name";
		cout << endl << "3. DOB";
		cout << endl << "4. Address";
		cout << endl << "0. Exit";
		cout << endl << "Enter command: ";

		int command;
		cin >> command;
		cin.ignore();

		switch (command)
		{
		case 1:
		{
			string firstName;
			cout << "Enter first name: ";
			getline(cin, firstName);
			database->getStudents()[matrikelNumber].setFirstName(firstName);

			break;
		}
		case 2:
		{
			string lastName;
			cout << "Enter last name: ";
			getline(cin, lastName);
			database->getStudents()[matrikelNumber].setLastName(lastName);
			break;
		}
		case 3:
		{
			auto dateOfBirth = getDateFromUser(
					"Enter date of birth (DD.MM.YYYY): ");
			database->getStudents()[matrikelNumber].setDateOfBirth(dateOfBirth);
			break;
		}
		case 4:
		{
			string street;
			cout << "Enter street: ";
			cin.ignore();
			getline(cin, street);

			unsigned short postalCode;
			cout << "Enter postal code: ";
			cin >> postalCode;

			string city;
			cout << "Enter city: ";
			cin.ignore();
			getline(cin, city);

			string additionalDetails;
			cout << "Additional Details: ";
			getline(cin, additionalDetails);

			// Exam note: setAddress copies the new value into the student.
			Address address(street, postalCode, city, additionalDetails);
			database->getStudents()[matrikelNumber].setAddress(address);
			break;
		}
		default:
		{
			break;
		}
		}
	}
}

void SimpleUI::saveDatabase() const
{
	string filename;
	cout << "Enter filename to save the database: ";
	cin >> filename;

	ofstream outFile(filename);
	if (!outFile)
	{
		cout << "Error opening file for writing!\n";
		return;
	}

	ostringstream oss;
	database->write(oss);
	outFile << oss.str();
	outFile.close();
	cout << "Database saved successfully!\n";
}

// Loads the database from a file
void SimpleUI::loadDatabase()
{
	// Reuse the existing database object instead of leaking a new one.
	database->getCourses().clear();
	database->getStudents().clear();
	Student::resetNextMatrikelNumber();

	string filename;
	cout << "Enter filename to load the database: ";
	cin >> filename;

	ifstream inFile(filename);
	if (!inFile.is_open())
	{
		cerr << "Failed to open the file!" << endl;
		return;
	}

	stringstream buffer;
	buffer << inFile.rdbuf();
	string fileContent = buffer.str();

	inFile.close();
	istringstream iss(fileContent);
	database->read(iss);
	cout << "Database loaded successfully!\n";
}
