// Harrison Lara
// May Zeineldin
// March 19, 2017

// includes
#include"Student.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

Student::Student() : Student(-1, " ", " ") { } //constructor sets for id, name, course

Student::Student(int id, string first, string last) // constructor sets the id to a default of 0, empty strings for first and lat name
{
	string emp_course[9]; // set array for the empty courses
	
	id = 0; // set id to default
	first = ""; // default first name
	last = ""; // default last name
}

//getters
const int Student:: get_id() { return id; } // gets and returns the ID

const string Student::get_name() { return last + " , " + first; } // gets name and returns it last, space, first

//getters
const void Student::set_id(int new_id) { id =  new_id; } //sets the students id

const void Student::set_name(string new_first, string new_last) // sets the name
{
	string first = new_first; // set first name to temporary variable
	string last = new_last; // set last name to temporary variable
}

int Student::hours_completed() const { return hours; } // returns the amount of credit hours completed

float Student:: gpa() const { return GPA; } //returns the students GPA per course 

bool Student:: is_enrolled(const string& course_name) const // searches the courses file and takes in the course name for each student
{
	ifstream classes; // opening course files
	classes.open("courses.txt");
	int name[8]; // set array to max course name size

	while (!classes.eof()) // read till file is at the end
	{
		for (int i = 0; i < 8; i++)
		{
			classes >> name[i]; // loop increments through the file and adds the name to the array
		}
		if (name != 0) // if the array did fill, returns true
		{
			return true;
		}
		else // array did not fill, returns false
		{
			return false;
		}
	}
}

Student::~Student(void)
{
	delete value; // destructor deletes the temporary variable
}

bool Student:: enroll(const course& c)
{
	ifstream person; // open the students file
	person.open("students.txt");
	int kids[10]; // set array to max name size

	while (person.good())
	{
		for (int i = 0; i < 11; i++)// loop increments through the file and adds the student to the array
		{
			person >> kids[i];
		}
		if (kids != 0) // if the array did fill, returns true
		{
			return true;
		}
		else
		{
			return false;// array did not fill, returns false
		}
	}
}

Student::Student(const Student& obj) // copy all members and places them into new objects
{
	hours = obj.hours; // set hours to new hours object
	id = obj.id; // set id to new id object
	value = obj.value;// set value to new value object
	emp_course = obj.emp_course;// set empty course to new empty course object

	for (int *i = 0; *i < emp_course; i++) // fills new array for the empty course elements to new objects
	{
		emp_course[i] = obj.emp_course[i];
	}
}

bool Student:: record_grade(const course& c) 
{
	ifstream classes; // opens the course file
	classes.open("courses.txt");
	int find_grade[1]; // set array to max size of grade

	while (!classes.eof())// loop increments through the file and adds the grade to the array
	{
		for (int i = 0; i < 8; i++)
		{
			classes >> find_grade[i];
		}
		if (find_grade != 0)  // if the array did fill, returns true
		{
			return true;
		}
		else
		{
			return false;// array did not fill, returns false
		}
	}
}


Student Student::operator+(const Student& grade) const //operator function adds together the gpa's for each course for a total average gpa
{
	Student gpa;
	//gpa.record_grade = (grade + grade)/ 9;
	return Student(gpa); // return the total gpa
} 