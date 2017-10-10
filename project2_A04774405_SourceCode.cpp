/*
    Bunrith Seng
    Project #2
    A04774405
    Due Date sept. 29, 2016
*/
//This program reports final weighted evaluation and salary raise percent

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{

    //declare variables
    string employee, supervisor, id, phoneNum, address;
    double fall, spring, summer, computedValue;


    //declare an input file stream variable and open it
    ifstream fin;
    fin.open("project2_A04774405_input.txt");

    //declare an output file stream variable and open it
    ofstream fout;
    fout.open("project2_A04774405_output.txt");

    fout << endl;

    fout << "           Texas State University, San Marcos      " << endl;
	fout << "Annual Employee Evaluation Report Sept. 1, 2015 to August 31, "
         << " 2016" << endl;

    fout << endl;

    //read data from the file
    getline(fin, employee);
    getline(fin, supervisor);
    getline(fin, id );
    getline(fin, phoneNum);
    getline(fin, address);



    fin >> fall >> spring >> summer;

    fout << right << showpoint << setprecision(2) << fixed;
    fout <<   "      Name of the Employee:  " << employee << "\n"
         <<   "    Name of the Supervisor:  " << supervisor << "\n"
         <<   "             Employee ID #:  " << id << "\n"
         <<   "          Telephone Number:  " << phoneNum << "\n"
         <<   "                   Address:  " << address  << "\n";
    fout <<   "  Fall Semester Evaluation:  " << fall << "\n"
         <<   "Spring Semester Evaluation:  " << spring << "\n"
         <<   "Summer Semester Evaluation:  " << summer << "\n";

    computedValue = (0.36*fall) + (0.38*spring) + (0.26*summer);
    fout << setw(29) << "Final Weighted Evaluation:  " <<computedValue<< endl;

    if (computedValue < 75)
    {
        fout << setw(31) << "Salary Raise:  0%";
    }
    else if (computedValue > 75 && computedValue <= 80)
    {
        fout << setw(31) << "Salary Raise:  1%";
    }
    else if (computedValue > 80 && computedValue <= 90)
    {
        fout << setw(31) << "Salary Raise:  3%";
    }
    else if (computedValue  > 90 && computedValue <= 100)
    {
        fout <<  setw(31) << "Salary Raise:  5%" ;
    }
    else
        fout << setw(31) << "Salary Raise:  10%" << endl;

    //double space
    fout << endl;
    fout << endl;

    if (computedValue < 70)
    {
        fout << "Warning/Appreciation Letter: C";
    }
    else if (computedValue >= 95)
    {
        fout << "Warning/Appreciation Letter: A";
    }
    else
        fout << "Warning/Appreciation Letter: B";

    fout << endl;
    fout << endl;

	fout << "Note:    This report for Jane was prepared according "
         << " to the fair practice "
         << " of the University." << endl;
	fout << "         Any discrepancies must be reported by June to her "
         << "supervisor, Paul.  " << endl;

	cout << "Done!" << endl;

	fin.close();
	fout.close();


	return 0;
}
