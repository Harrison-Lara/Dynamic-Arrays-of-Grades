// Harrison Lara
// May Zeineldin
// March 19, 2017

// includes
#include"Student.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

istream & operator >> (istream & in, course & b) /* input operator takes in the information from the students and course files
												 then assigns the data to the variables, which is then returned and repeated 
												 for each student*/
{
	ifstream student; // open studenst and courses files
	ifstream classes;
	student.open("students.tx");
	classes.open("courses.txt");

	in >> b.course_name; // takes in course name
	classes >> b.course_name; 
	return in; // returns course name
	
	in >> b.credit_hours; // takes in the credit hours completed
	student >> b.credit_hours;
	return in; // returns the completed hours

	in >> b.grade_points; // takes in the grade points for each class
	student >> b.grade_points;
	return in; // returns the grade points
}

ostream & operator<<(ostream & out, course & in) /* this operator takes the data from the input operator and outs 
												 all the students information for both files to the new students 
												 and gpa location*/
{
	out << "Course is: " << in.course_name << "credit are: " << in.credit_hours << "Student GPA is: " << in.grade_points;
	ofstream output; // open outputs files
	output.open("students.txt",ios::app);
	output << in.course_name << in.credit_hours << in.grade_points; // outputting information
	return out; 
}

void main() // main function
{
	cout << " Welcome to the AwesomeCS U!" << endl; // greet user

	ifstream finCourse; // open courses file
	finCourse.open("courses.txt");

	ifstream finStudent; // open students file
	finStudent.open("students.txt");

	ofstream output;// open new students file
	output.open("new_students.txt");

	ofstream output2; // open GPA file
	output2.open("GPA.txt");

	if (!finCourse || !finStudent) // checks to make sure the input files are present and if they arent, reports an error message
	{
		output << "Files not found!\n"; // error message
		system("pause");
		exit(1);
	}
	
	cout << "\n Files being processed...\n"; // let user know the program is running
 
	&Student::enroll; // call enroll function for new students with classes with no grade

	&Student::is_enrolled; // call is enrolled function for student information

	&Student::record_grade; // call record grade function for grade setting

	istream& operator >> (istream& in, course& b); // call input operator

	ostream& operator << (ostream& out, course& in); // call output operator

	output << "ID and Student name: \n" << "Course listing follow by Hours completed and Grade point: "; // output header to new student file

	output2 << "Student name followed by total GPA: "; // output header to gpa file

	cout << "\n Your output file is now complete!\n" << endl; // tell user the program has finished
	
	// close files
	finCourse.close();
	finStudent.close();
	output.close();

}