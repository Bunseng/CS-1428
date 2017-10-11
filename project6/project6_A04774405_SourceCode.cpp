/*
    Bunrith Seng
    Project #6
    A04774405
    Due Date December 6, 2016
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//Global constant variables
const double FALL = 0.39,
             SPRING = 0.37,
             SUMMER = 0.24;
const int YEAR3 = 3;
const int SEMESTER3 = 3;
const int COMPUTED = 9;

//Global variable for employee number
int n;
//int alphabets;

struct Personal
{
   string  head1,
            head2,
            name,
            supervisor,
            ID,
            phone,
            address,
            letter_one,
            letter_two;
};

struct Compute
{
    double  evaluation[YEAR3][SEMESTER3],
            computed[COMPUTED];
};

struct Employee_Data
{
    Personal non_numeric;
    Compute numeric;
};


//function prototypes
void inputData(ifstream &, struct Employee_Data employee[], int );
void validateData(struct Employee_Data employee[], int );
void validateData(struct Employee_Data employee[], int );
void FWE(struct Employee_Data employee[], int );
void TAFWE(struct Employee_Data employee[], int );
void SRinPercent(struct Employee_Data employee[], int );
void Salary(struct Employee_Data employee[], int );
void Letter(struct Employee_Data employee[], int );
void Report(ofstream &, struct Employee_Data employee[], int );


int main()
{

  //input number of employees
  cout << " Enter number of employees you want to evaluate (3-100): ";
  cin >> n;

  Employee_Data employees[n];

  //validate input for employee numbers
  while (n < 3 || n > 100)
  {
      cout << "Invalid input:  Enter a number between 3-100: ";
      cin >> n;

  }

  ifstream inFile;
  inFile.open("project6_A04774405_input.txt");

   //validate if the inFile exists.
  if (!inFile)
  {
      cout << "ERROR! Make sure the file is in the same directory." << endl;
      return -1;
  }

  ofstream outFile;
  outFile.open("project6_A04774405_output.txt");

  //validate outFile
  if (!outFile)
  {
      cout << "ERROR! Make sure the file is in the same directory." << endl;
      return -1;
  }

   for (int emp = 0; emp < n ; emp++) //Outer for-loop for employees

    {
        //function calls
        inputData(inFile, employees, emp);
        validateData(employees, emp);
        validateData(employees, emp);
        FWE(employees, emp);
        TAFWE(employees, emp);
        SRinPercent(employees, emp);
        Salary(employees, emp);
        Letter(employees, emp);
        Report(outFile, employees, emp);
    }

  inFile.close();
  outFile.close();
  return 0;
}

//get input data from the file
  void inputData(ifstream &inFile, struct Employee_Data employee[],int emp)
  {

        /*  for(int i = 0; i < 7; i++)
          {
            getline(inFile, employee[emp].non_numeric.s[i]);
          } */

            getline(inFile, employee[emp].non_numeric.head1);//get heading 1
            getline(inFile, employee[emp].non_numeric.head2);//get heading 2
            getline(inFile, employee[emp].non_numeric.name);//get name of the employee
            getline(inFile, employee[emp].non_numeric.supervisor);//get supervisor's name
            getline(inFile, employee[emp].non_numeric.ID);//get employee's id
            getline(inFile, employee[emp].non_numeric.phone);//get employee's phone #
            getline(inFile, employee[emp].non_numeric.address);//get employee's address

            for (int year = 0; year < YEAR3; year++)//years for-loop
            {
                for(int semester = 0 ; semester < SEMESTER3; semester++)//semesters for-loop
                {
                    inFile >> employee[emp].numeric.evaluation[year][semester];//get years and semesters' data
                }

            }

            //get current salary
            inFile >> employee[emp].numeric.computed[5];
            inFile.ignore();
  }


//validate strings data
void validateData(struct Employee_Data employee[], int emp)
{
      if (employee[emp].non_numeric.head1.length() > 50)
        {
            cout << "ERROR 1!\n";
            return;
        }
        if (employee[emp].non_numeric.head2.length() > 75)
        {
            cout << "ERROR 2!\n";
            return;
        }
        if (employee[emp].non_numeric.name.length() < 0)
        {
            cout << "ERROR 3\n";
            return;
        }
        if (employee[emp].non_numeric.supervisor.length()< 0)
        {
            cout << "ERROR 4\n";
            return;
        }
        if (employee[emp].non_numeric.ID.length() > 20)
        {
            cout << "ERROR 5\n";
            return;
        }
         if (employee[emp].non_numeric.phone.length() > 20)
        {
            cout << "ERROR 6\n";
            return;
        }
        if (employee[emp].non_numeric.address.length() > 75)
        {
            cout << "ERROR 7\n";
            return;
        }

      /*  for (int validate = 0; validate < alphabets; validate++)
        {
            if (employee[emp].non_numeric[validate].length <= 0)
            {
                cout << "It is an invalid number of strings characters. ";
                continue;
            }
        } */

}

//validate numeric data
void validateData1(struct Employee_Data employee[], int emp )
{

        for (int year = 0; year < YEAR3; year++)
        {
            for (int semester =0; semester < SEMESTER3; semester++)
            {
            if (employee[emp].numeric.evaluation[year][semester] < 3.00 ||
                employee[emp].numeric.evaluation[year][semester] > 1000.00)
                {
                    cout << "Invalid numerical data!";
                    break;
                }
            }
        }
}

//computer final weighted evaluation
void FWE(struct Employee_Data employee[], int emp)
{
    employee[emp].numeric.computed[0] = (employee[emp].numeric.evaluation[0][0]*FALL)+
                                        (employee[emp].numeric.evaluation[0][1]*SUMMER) +
                                        (employee[emp].numeric.evaluation[0][2]*SPRING);
    employee[emp].numeric.computed[1] = (employee[emp].numeric.evaluation[1][0]*FALL)+
                                        (employee[emp].numeric.evaluation[1][1]*SUMMER) +
                                        (employee[emp].numeric.evaluation[1][2]*SPRING);
    employee[emp].numeric.computed[2] = (employee[emp].numeric.evaluation[2][0]*FALL)+
                                        (employee[emp].numeric.evaluation[2][1]*SUMMER) +
                                        (employee[emp].numeric.evaluation[2][2]*SPRING);

}

//compute total final weighted and average final weighted
void TAFWE(struct Employee_Data employee[], int emp)
{
    employee[emp].numeric.computed[3] = employee[emp].numeric.computed[0]+
                                        employee[emp].numeric.computed[1]+
                                        employee[emp].numeric.computed[2];
    employee[emp].numeric.computed[4] = employee[emp].numeric.computed[3]/3;

}

//This function will compute and store into proper array elements the Salary Raise in %.
void SRinPercent( struct Employee_Data employee[], int emp)
{
        if (employee[emp].numeric.computed[4] < 75)
        {
            employee[emp].numeric.computed[6] = 0;
        }
        else if ( employee[emp].numeric.computed[4] > 75 &&
                 employee[emp].numeric.computed[4] <= 80)
        {
            employee[emp].numeric.computed[6]= 1;
        }
        else if (employee[emp].numeric.computed[4] > 80 &&
                 employee[emp].numeric.computed[4] <=90 )
        {
            employee[emp].numeric.computed[6]= 3;
        }
        else if (employee[emp].numeric.computed[4] > 90 &&
                 employee[emp].numeric.computed[4] <=100)
        {
            employee[emp].numeric.computed[6] = 5;
        }
        else if (employee[emp].numeric.computed[4] > 100)
        {
            employee[emp].numeric.computed[6] = 10;
        }

}

//compute salary in dollars and the final total amount
void Salary( struct Employee_Data employee[], int emp)
{

        employee[emp].numeric.computed[7] = (employee[emp].numeric.computed[6]/100) *
                                            employee[emp].numeric.computed[5];
        employee[emp].numeric.computed[8] = employee[emp].numeric.computed[5] +
                                            employee[emp].numeric.computed[7];
}

//stored letter notes in proper arrays
void Letter( struct Employee_Data employee[], int emp)
{
        if (employee[emp].numeric.computed[4] < 70)//letter one stored in letter_one array
        {
            employee[emp].non_numeric.letter_one = "Warning letter: "
                           " We are concerned with your grade and we would like "
                           " to speak with you as soon as possible.";

        }
        else if (employee[emp].numeric.computed[4] >= 90)//letter two stored in letter_two array
        {

            employee[emp].non_numeric.letter_two =  "Appreciation Letter: "
                            " Congratulation, your hard work has paid off. Your first step to success looks great!";

        }

}

//Output all the data to a file
void Report(ofstream &outFile, struct Employee_Data employee[], int emp)
{
        //set format
        outFile << setprecision(2) << fixed << showpoint;

        outFile << "\t\t" << employee[emp].non_numeric.head1 << endl; //report header 1
        outFile << "\t" << employee[emp].non_numeric.head2 << endl; //report header 2
        outFile << endl; //space
        outFile << "  Name of the Employee: \t" << employee[emp].non_numeric.name << endl;//report employee name
        outFile << "Name of the Supervisor: \t" << employee[emp].non_numeric.supervisor << endl;//report supervisor name
        outFile << "        Employee's ID#: \t" << employee[emp].non_numeric.ID << endl;//report employee ID
        outFile << "      Telephone number: \t" << employee[emp].non_numeric.phone << endl;//report employee phone #
        outFile << "               Address: \t" << employee[emp].non_numeric.address << endl;//report employee address

        outFile << endl;

        for (int year = 0; year < YEAR3; year++)//loop for years
        {
            for(int semester = 0 ; semester < SEMESTER3; semester++)//loop to get each semester value
            {
                switch(semester)//show three semesters
                {
                    case 0://spring semesters for 2013-2015
                        outFile << fixed << showpoint << setprecision(2);
                        outFile << "  Spring Semester Evaluation, " << 2013+year
                                <<":  \t" << employee[emp].numeric.evaluation[year][semester]<< "\n";
                        break;

                    case 1://summer semester for 2013-2015
                        outFile << fixed << showpoint << setprecision(2);
                        outFile <<  "  Summer Semester Evaluation, " << 2013+year
                                <<":  \t" << employee[emp].numeric.evaluation[year][semester]<< "\n";
                        break;

                    case 2://fall semester for 2013-2015
                        outFile << fixed << showpoint << setprecision(2);
                        outFile <<  "  Fall Semester Evaluation,   " << 2013+year
                                <<":  \t" << employee[emp].numeric.evaluation[year][semester]<< "\n";
                        break;
                }

            }
            //space
            outFile << endl;

        }

          //set format
          outFile << fixed << showpoint << setprecision(2);

          //display final semester evaluation
          outFile << "  Final Semester Evaluation, 2013: \t" << employee[emp].numeric.computed[0] << endl;
          outFile << "  Final Semester Evaluation, 2014: \t" << employee[emp].numeric.computed[1] << endl;
          outFile << "  Final Semester Evaluation, 2015: \t" << employee[emp].numeric.computed[2] << endl;

          outFile << endl;

          //display total weighted and average final weighted
          outFile << "  Total Final Weighted Evaluation: \t" << employee[emp].numeric.computed[3] << endl;
          outFile << "  Average Final Weighted Evaluation: \t" << employee[emp].numeric.computed[4]<< endl;

          //output current salary, percent, raised in dollar, and total
          outFile << "  Current Salary \t\t: \t" << "$"<<employee[emp].numeric.computed[5]<< endl;
          outFile << "  Salary Raised in percent \t: \t"<< employee[emp].numeric.computed[6]<< "%"<< endl;
          outFile << "  Salary Raised in Dollar\t: \t$"<< employee[emp].numeric.computed[7] << endl;
          outFile << "  Total Salary Raised with Dollar: \t$"<< employee[emp].numeric.computed[8] << endl;

          outFile << endl;


        //Determine what type of letter to write to the output file
        if (employee[emp].numeric.computed[4] < 70)
            {
                outFile << "Your average is: " << employee[emp].numeric.computed[4] //re-display the average for a letter
                        << "\n"
                        <<  employee[emp].non_numeric.letter_one << endl;
            }
        else if(employee[emp].numeric.computed[4] >= 90)
                outFile << "Your average is: " << employee[emp].numeric.computed[4] //re-display the average for a letter
                        << "\n"
                        <<  employee[emp].non_numeric.letter_two<< endl;
        else
        {
           outFile << "Your average is: " << employee[emp].numeric.computed[4] //re-display the average for a letter
                    << "\n"
                      "Congratulation:  You're doing perfectly okay at this point. Keep up the good work!" << endl;
        }

        //space
        outFile << endl;
        outFile << endl;

        //Display notes
        outFile << "Note:    This report for "<< employee[emp].non_numeric.name << " was prepared according "
                << " to the fair practice "
                << " of the University." << endl;
        outFile << "         Any discrepancies must be reported by " << employee[emp].non_numeric.name << " to her/his "
                << "supervisor, "<< employee[emp].non_numeric.supervisor <<"." << endl;
        outFile << "****************************************************************************************************" << endl;

        //space
        outFile << endl;

}
