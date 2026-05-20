/*
 * Student.cpp
 *
 *  Created on: 19 May 2026
 *      Author: abhir
 */

#include "Student.h"
#include <iostream>

Student::Student()
{
	// TODO Auto-generated constructor stub

}

Student::~Student()
{
	// TODO Auto-generated destructor stub
}

Student::Student(int id, const std::string name) : id(id) , name(name) {}

void Student::display() const
{
	std::cout << "ID: " << id << '\n' << "Name: " << name << '\n';
}

int Student::getId() const
{
	return id;
}

std::string Student::getName() const
{
	return name;
}
