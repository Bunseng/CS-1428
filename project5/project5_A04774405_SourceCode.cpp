/*
    Bunrith Seng
    Project #5
    A04774405
    Due Date November 22, 2016
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
const int NUM = 9;
const int NUM2 = 9;

//Global variable for employee number
int n;

//function prototypes
void inputData(ifstream &, string[][NUM], double[][3][3], double[][NUM2], int, int );
void validateData(string[][NUM], int, int );
void validateData(double[][3][3], int, int );
void FWE(double[][3][3], double [][NUM2], int, int );
void TAFWE(double[][NUM2], int, int );
void SRinPercent(double[][NUM2], string[][NUM], int, int );
void Salary(double[][NUM2], int, int );
void Letter(string[][NUM], double[][NUM2], int, int );
void Report(ofstream &, string[][NUM], double [][3][3], double[][NUM2], int, int );

int main()
{

  //input number of employees and validating.
  cout << " Enter number of employees you want to evaluate (3-100): ";
  cin >> n;

  string myStrings[n][NUM];
  double myScores[n][3][3];
  double compVal[n][NUM2];

  //validate input for employee numbers
  while (n < 3 || n > 100)
  {
      cout << "Invalid input:  Enter a number between 3-100: ";
      cin >> n;
  }

  ifstream inFile;
  inFile.open("project5_A04774405_input.txt");

   //validate if the inFile exists.
  if (!inFile)
  {
      cout << "ERROR! Make sure the file is in the same directory." << endl;
      return 1;
  }

  ofstream outFile;
  outFile.open("project5_A04774405_output.txt");

  //validate outFile
  if (!outFile)
  {
      cout << "ERROR! Make sure the file is in the same directory." << endl;
      return 1;
  }

   for (int emp = 0; emp < n ; emp++) //For-loop for employees
    {
      //function calls
        inputData(inFile, myStrings, myScores, compVal, n, emp);
        validateData(myStrings, n, emp);
        validateData(myScores, n, emp);
        FWE(myScores, compVal, n, emp);
        TAFWE(compVal, n, emp);
        SRinPercent(compVal, myStrings, n, emp);
        Salary(compVal, n, emp);
        Letter(myStrings, compVal, n, emp);
        Report(outFile, myStrings, myScores, compVal, n, emp);
    }

  inFile.close();
  outFile.close();
  return 0;
}

//get input data from the file
  void inputData(ifstream &inFile, string myString[][NUM], double scores[][3][3], double compV[][NUM2], int n, int emp)
  {

          for(int i = 0; i < 7; i++)
          {
            getline(inFile, myString[emp][i]);
          }
              for (int year = 0; year < 3; year++)
              {
                  for(int j = 0 ; j < 3; j++)
                  {
                        inFile >> scores[emp][year][j];
                  }

             }


              //get current salary
            inFile >> compV[emp][5];
            inFile.ignore();
  }


//validate strings data
void validateData(string myString[][NUM], int n, int emp)
{
      if (myString[emp][0].length() > 50)
        {
            cout << "ERROR 1!\n";
            return;
        }
        if (myString[emp][1].length() > 75)
        {
            cout << "ERROR 2!\n";
            return;
        }
        if (myString[emp][2].length() < 0)
        {
            cout << "ERROR 3\n";
            return;
        }
        if (myString[emp][3].length()< 0)
        {
            cout << "ERROR 4\n";
            return;
        }
        if (myString[emp][4].length() > 20)
        {
            cout << "ERROR 5\n";
            return;
        }
         if (myString[emp][5].length() > 20)
        {
            cout << "ERROR 6\n";
            return;
        }
        if (myString[emp][6].length() > 75)
        {
            cout << "ERROR 7\n";
            return;
        }

}

//validate numeric data
void validateData(double scores[][3][3], int n, int emp )
{

        for (int year = 0; year < 3; year++ )
        {
            for (int j =0; j < 3; j++)
            {
            if (scores[emp][year][j] < 1 || scores[emp][year][j] > 1000)
                {
                    cout << "Invalid numeric data!";
                    return;
                }
            }
        }
}

//computer final weighted evaluation
void FWE(double scores[][3][3],double compV[][NUM2], int n, int emp)
{
          compV[emp][0] = (scores[emp][0][0]*FALL)+ (scores[emp][0][1]*SUMMER) + (scores[emp][0][2]*SPRING);
          compV[emp][1] = (scores[emp][1][0]*FALL)+ (scores[emp][1][1]*SUMMER) + (scores[emp][1][2]*SPRING);
          compV[emp][2] = (scores[emp][2][0]*FALL)+ (scores[emp][2][1]*SUMMER) + (scores[emp][2][2]*SPRING);

}

//compute total final weighted and average final weighted
void TAFWE(double compV[][NUM2], int n, int emp)
{
        compV[emp][3] = compV[emp][0]+ compV[emp][1]+ compV[emp][2];
        compV[emp][4] = compV[emp][3]/3;

}

//This function will compute and store into proper array elements the Salary Raise in %.
void SRinPercent(double compV[][NUM2], string myString[][NUM], int n, int emp)
{
        if (compV[emp][4] < 75)
        {
            compV[emp][6] = 0;
        }
        else if ( compV[emp][4] > 75 && compV[emp][4] <= 80)
        {
            compV[emp][6]= 1;
        }
        else if (compV[emp][4] > 80 && compV[emp][4] <=90 )
        {
            compV[emp][6]= 3;
        }
        else if (compV[emp][4] > 90 && compV[emp][4] <=100)
        {
            compV[emp][6] = 5;
        }
        else if (compV[emp][4] > 100)
        {
            compV[emp][6]= 10;
        }

}

//compute salary in dollars and the final total amount
void Salary(double compV[][NUM2], int n, int emp)
{

        compV[emp][7] = (compV[emp][6]/100) * compV[emp][5];
        compV[emp][8] = compV[emp][5] + compV[emp][7];
}

//stored letter notes in proper arrays
void Letter(string myString[][NUM], double compV[][NUM2], int n, int emp)
{
        if (compV[emp][4] < 70)
        {
        myString[emp][7] = "Warning letter: "
                           " We are concerned with your grade and we would like "
                           " to speak with you as soon as possible.";

        }
        else if (compV[emp][4] >= 90)
        {

        myString[emp][8] =  "Appreciation Letter: "
                            " Congratulation, your hard work has paid off. Your first step to success looks great!";

        }

}

//Output all the data to a file
void Report(ofstream &outFile, string myString[][NUM], double scores[][3][3], double compV[][NUM2], int n, int emp)
{
          //set format
          outFile << setprecision(2) << fixed << showpoint;

          outFile << "\t\t" << myString[emp][0] << endl; //header 1
          outFile << "\t" << myString[emp][1] << endl; //header 2
          outFile << endl; //space
          outFile << "  Name of the Employee: \t" << myString[emp][2] << endl;
          outFile << "Name of the Supervisor: \t" << myString[emp][3] << endl;
          outFile << "        Employee's ID#: \t" << myString[emp][4] << endl;
          outFile << "      Telephone number: \t" << myString[emp][5] << endl;
          outFile << "               Address: \t" << myString[emp][6] << endl;

          outFile << endl;

          for (int year = 0; year < 3; year++)//loop for years
          {
              for(int j = 0 ; j < 3; j++)//loop to get get each semester value
              {

                   switch(j)
                        {
                        case 0:

                            outFile << fixed << showpoint << setprecision(2);
                            outFile << "  Spring Semester Evaluation, " << 2013+year  <<":  \t" << scores[emp][year][j]<< "\n";
                            break;

                        case 1:
                            outFile << fixed << showpoint << setprecision(2);
                            outFile <<  "  Summer Semester Evaluation, " << 2013+year <<":  \t" << scores[emp][year][j]<< "\n";
                            break;

                        case 2:
                            outFile << fixed << showpoint << setprecision(2);
                            outFile <<  "  Fall Semester Evaluation,   " << 2013+year <<":  \t" << scores[emp][year][j]<< "\n";
                            break;
                          }

                }
              outFile << endl;

         }


          outFile << fixed << showpoint << setprecision(2);

          //display final semester evaluation
          outFile << "  Final Semester Evaluation, 2013: \t" << compV[emp][0] << endl;
          outFile << "  Final Semester Evaluation, 2014: \t" << compV[emp][1] << endl;
          outFile << "  Final Semester Evaluation, 2015: \t" << compV[emp][2] << endl;

          outFile << "  Total Final Weighted Evaluation: \t" << compV[emp][3] << endl;
          outFile << "  Average Final Weighted Evaluation: \t" << compV[emp][4]<< endl;

          //output current salary, percent, raise in dollar, and total
          outFile << "  Current Salary \t\t: \t" << "$"<<compV[emp][5]<< endl;
          outFile << "  Salary Raised in percent \t: \t"<< compV[emp][6]<< "%"<< endl;
          outFile << "  Salary Raised in Dollar\t: \t$"<< compV[emp][7] << endl;
          outFile << "  Total Salary Raised with Dollar: \t$"<< compV[emp][8] << endl;

          outFile << endl;


        //Determine what type of letter to write to the output file
        if (compV[emp][4] < 70)
            {
                outFile << "Your average is: " << compV[emp][4] << "\n"
                        <<  myString[emp][7]<< endl;
            }
        else if(compV[emp][4] >= 90)
                outFile << "Your average is: " << compV[emp][4] << "\n"
                        <<  myString[emp][8]<< endl;
        else
        {
           outFile << "Your average is: " << compV[emp][4] << "\n"
                      "Congratulation:  You're doing perfectly okay at this point. Keep up the good work!" << endl;
        }


        outFile << endl;

        //Display notes
        outFile << endl;

        outFile << "Note:    This report for "<< myString[emp][2] << " was prepared according "
                << " to the fair practice "
                << " of the University." << endl;
        outFile << "         Any discrepancies must be reported by " << myString[emp][2] << " to her/his "
                << "supervisor, "<< myString[emp][3] <<"." << endl;
        outFile << "****************************************************************************************************" << endl;

        outFile << endl;

}
