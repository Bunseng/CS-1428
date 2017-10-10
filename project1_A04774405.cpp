/*
    Bunrith Seng
    Project #1
    A04774405
    Due Date sept. 13, 2016
*/
//This program reports final weighted evaluation

#include <iostream>

using namespace std;

int main()
{

    //declare variables
    string employee, supervisor, id;
    double fall, spring, summer;
    double computedValue;

    cout << "           Texas State University, San Marcos      " << endl;
	cout << "Annual Employee Evaluation Report Sept. 1, 2015 to August 31, 2016" << endl;\

	//double space
    cout << endl;

    //Enter name of the employee
    cout << "Name of the Employee: ";
    cin >> employee;

    //Enter name of the supervisor
    cout << "Name of the Supervisor: ";
    cin >> supervisor;

    //enter employee ID
    cout << "Employee ID #: ";
    cin >> id;

    //Enter Fall semester evaluation
    cout << "Fall Semester Evaluation: ";
    cin >> fall;

    //Enter Spring semester evaluation
    cout << "Spring Semester Evaluation: ";
    cin >> spring;

    //Enter Spring semester evaluation
    cout << "Fall Semester Evaluation: ";
    cin >> summer;

    //compute final weighted evaluation
    computedValue = 0.36*fall + 0.38*spring + 0.26*summer;
    cout << "Final Weighted Evaluation: " << computedValue << endl;

    //double space
    cout << endl;

    //important note
	cout << "Note:    This report for Jane was prepared according to the fair practice of the University." << endl;
	cout << "       Any discrepancies must be reported by June to her supervisor, Paul.  " << endl;


	return 0;
}
