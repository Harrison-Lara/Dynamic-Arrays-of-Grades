// Harrison Lara
// May Zeineldin
// March 19, 2017

#pragma once

// includes
#include<iostream>
#include<fstream>
#include<string>	
using namespace std;

#define STUDENT
#ifndef MY_STUDENT
 
// course structure
struct course // this structure holds the data for the courses name, the amount of credit hours and grade points
{
	string course_name; // variable for course name
	int credit_hours; // variable for amount of credit hours
	double grade_points; // variable for grade points 
};

// student class
class Student /* this class takes the name, gpa, id, and courses then seperates the data 
			  into two files which will output the students classes with each classes grade
			  then the other file will list the students name again and their total gpa*/
{
public:
	//constructors
	Student();
	Student(int id, string first, string last); // takes students ID, first name and last

// overloaded operator
	Student operator+(const Student& grade) const; // adds the grades for a total gpa for each student

	friend istream& operator >> (istream& in, course& b );  // takes in the data from the courses and students files

	friend ostream& operator << (ostream& out, course& b); // outputs the students information to the new students and gpa files

	//getters
	const int get_id(); // gets the students ID
	const string get_name(); // gets the students name

	//setters
	const void set_id(int new_id); // sets the ID
	const void set_name(string new_first, string new_last); // sets the name into first and last

	int hours_completed() const; // defaults the hours completed 
	float gpa() const; // defaults the students gpa

	bool is_enrolled(const string& course_name) const; //returns true or false if the student has data or not
	bool enroll(const course& c); // returns true or false if the student has classes without a grade
	bool record_grade(const course& c); // returns true or false while taking the grade students information

	// copy constructor and destructor
	Student(const Student& obj); // holds temporary variables so originals arent changed
	~Student();  // deletes the changed data from the temporary variables

private:
	//variables being used
	int hours; // amount of hours
	int id; // student ID
	int *value; // grabs the students value (pointer)
	string first; // first name of students
	string last; // students last name
	float GPA = -1; // set gpa to a default of -1
	int emp_course; // empty course for array and iteration

};
#endif // !MY_STUDENT
