/*
    Bunrith Seng
    Project #3
    A04774405
    Due Date October 13, 2016
*/
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{

    //declare variables
    string head1, head2, employee, supervisor, id, phoneNum, address;
    double fall, spring, summer;
    double current_salary,
           average_1,
           total_1 =0.0 ,
           salary,
           total;
    int n;

    int min_employees = 1,
        max_employees = 100;
    const double FALL = 0.36,
                 SPRING = 0.38,
                 SUMMER = 0.26;



    cout << "Enter how many employees you want to see: ";
    cin >> n;

    //validate the input using while-loop
    while (n < min_employees ||  n > max_employees)
    {
        cout << "You should have at least "<< min_employees
             << " but no more than " << max_employees << endl;

        //get input again
        cout << "Enter how many employees you want to see:  ";
        cin >> n;
    }

    //declare an input file stream variable and open it
    ifstream fin;
    fin.open("project3_A04774405_input.txt");

    //declare an output file stream variable and open it
    ofstream fout;
    fout.open("project3_A04774405_output.txt");

    fout << endl;

    for (int start = 1; start <= n; start++)
    {
        getline (fin, head1);
        cout << head1 << endl;
        fout <<"\t\t\t"<<  head1 << "\n";

        getline(fin, head2);
        cout << head2 << endl;
        fout << "\t\t\t"<<head2 << "\n"
        << "***************************************************************************************************************" << "\n";

        getline(fin, employee);
        cout << employee << endl;
        fout <<   "            Name of the Employee:  \t" << employee << "\n";

        getline(fin, supervisor);
        cout << supervisor << endl;
        fout <<   "          Name of the Supervisor:  \t" << supervisor << "\n";

        getline(fin, id);
        cout << id << endl;
        fout <<   "                   Employee ID #:  \t" << id << "\n";

        getline(fin, phoneNum);
        cout << phoneNum << endl;
        fout <<   "                Telephone Number:  \t" << phoneNum << "\n";

        getline(fin, address);
        cout << address << endl;
        fout <<   "                         Address:  \t" << address  << "\n";

        if (employee.length() < 1 || employee.length() > 100)
    {
        cout << " Invalid name input: " << endl;
    }

        for (int i = 2013; i <= 2015; i++)
        {

            fin >> fall>> spring >> summer;
            cout << fall << " " << spring << " " << summer<< endl;


            fout <<   "  Fall Semester Evaluation, " << i <<":  \t" << fall << "\n"
                 <<   "Spring Semester Evaluation, " << i <<":  \t" << spring << "\n"
                 <<   "Summer Semester Evaluation, " << i <<":  \t" << summer<< "\n";

           average_1 = (FALL*fall) + (SPRING*spring) + (SUMMER*summer);

           total_1 += average_1;

           fout << "Final Weight Evaluation for, " << i <<":  \t" << average_1 << "\n";
        }
            fin >> current_salary;
            cout << "Current salary: " << current_salary << endl;

            total = total_1 / 3.0;

         fout <<  "Total final weight Evaluation    :  \t" << total_1 << "\n"
              <<  "Average final weight evaluation  :  \t" << total << "\n"
              <<  "Current Salary                   :  \t" << current_salary << "\n";


    if (total < 75)
    {
         salary = 90000.00 * 0;
         fout << setw(31) << "         Salary Raise in %:  \t 0%";
    }
    else if (total > 75 && total <= 80)
    {
         salary = 90000 * 0.01;
         fout << setw(31) << "         Salary Raise in %:  \t 1%";
    }
    else if (total > 80 && total <= 90)
    {
        salary = 90000.00 * 0.03;
        fout << setw(31) << "          Salary Raise in %:  \t 3%";
    }
    else if (total  > 90 && total <= 100)
    {
        salary = 90000.00 * 0.05;
        fout <<  setw(31) << "         Salary Raise in %:  \t 5%";
    }
    else{
        salary = 90000.00 * 0.1;
        fout << setw(31) << "          Salary Raise in %:  \t 10%" << endl;
    }

    fout << "\n Salary raise in dollar             :  \t" << salary << "\n"
         << " Salary in dollar with the raise: \t" << (salary + current_salary) << "\n";

    //space out
    fout << endl;
    fout << endl;

	fout << "Note:    This report for "<< employee << " was prepared according "
         << " to the fair practice "
         << " of the University." << endl;
	fout << "         Any discrepancies must be reported by June to her/his "
         << "supervisor, Paul.  " << endl;

    fout << endl;
    fout << endl;
    fin.ignore();
    }


	cout << "Done!" << endl;

	fin.close();
	fout.close();


	return 0;
}
