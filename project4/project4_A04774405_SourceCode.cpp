/*
    Bunrith Seng
    Project #4
    A04774405
    Due Date november 8, 2016
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{

    const double FALL = 0.39,
                 SPRING = 0.27,
                 SUMMER = 0.24;

    int n;

  //input number of employees and validating.
  cout << " Enter number of employees you want to evaluate: ";
  cin >> n;

  string myStrings[n][7];
  double myScores[n][3][3];
  double compV[n][9];


  while (n < 1 || n > 100)
  {
      cout << "Invalid input:  Enter a number between 1-100: ";
      cin >> n;
  }

  ifstream inFile;
  inFile.open("project4_A04774405_input.txt");

  ofstream outFile;
  outFile.open("project4_A04774405_output.txt");

  //validate if the file exists.
  if (!inFile)
  {
      cout << "File does not exist." << endl;
      return 0;
  }

  //get number of employees
  for (int emp = 0; emp < n; emp++)
  {

      for(int a = 0; a < 7; a++)
      {
              getline(inFile, myStrings[emp][a]);
              //outFile<< myStrings[emp][a] << "\n";
      }
      outFile << "\t\t" << myStrings[0][0] << endl;
      outFile << "\t" << myStrings[0][1] << endl;
      outFile << endl;
      outFile << "  Name of the Employee: \t" << myStrings[0][2] << endl;
      outFile << "Name of the Supervisor: \t" << myStrings[0][3] << endl;
      outFile << "        Employee's ID#: \t" << myStrings[0][4] << endl;
      outFile << "      Telephone number: \t" << myStrings[0][5] << endl;
      outFile << "               Address: \t" << myStrings[0][6] << endl;

      outFile << endl;



      for (int i = 0; i < 3; i++)
      {
          for(int j = 0 ; j < 3; j++)
          {
                inFile >> myScores[emp][i][j];

           switch(j)
                {
                case 0:

                    outFile << fixed << showpoint << setprecision(2);
                    outFile << "  Spring Semester Evaluation, " << 2013+i  <<":  \t" << myScores[emp][i][j]<< "\n";
                    break;

                case 1:
                    outFile << fixed << showpoint << setprecision(2);
                    outFile <<  "  Summer Semester Evaluation, " << 2013+i <<":  \t" << myScores[emp][i][j]<< "\n";
                    break;

                case 2:
                    outFile << fixed << showpoint << setprecision(2);
                    outFile <<  "  Fall Semester Evaluation,   " << 2013+i <<":  \t" << myScores[emp][i][j]<< "\n";
                    break;
                  }

            }
          outFile << endl;

     }

          compV[emp][0] = (myScores[emp][0][0]*FALL)+ (myScores[emp][0][1]*SUMMER) + (myScores[emp][0][2]*SPRING);
          compV[emp][1] = (myScores[emp][1][0]*FALL)+ (myScores[emp][1][1]*SUMMER) + (myScores[emp][1][2]*SPRING);
          compV[emp][2] = (myScores[emp][2][0]*FALL)+ (myScores[emp][2][1]*SUMMER) + (myScores[emp][2][2]*SPRING);

          compV[emp][3] = compV[emp][0]+ compV[emp][1]+ compV[emp][2];
          compV[emp][4] = compV[emp][3]/3;

          inFile >> myScores[emp][0][1];

           //display evaluation for each year, total, and average
          outFile << fixed << showpoint << setprecision(2);
          outFile << "  Final Semester Evaluation, 2013: \t" << compV[emp][0] << endl;
          outFile << "  Final Semester Evaluation, 2014: \t" << compV[emp][1] << endl;
          outFile << "  Final Semester Evaluation, 2015: \t" << compV[emp][2] << endl;

          outFile << "  Total Final Weighted Evaluation: \t" << compV[emp][3] << endl;
          outFile << "  Average Final Weighted Evaluation: \t" << compV[emp][4]<< endl;

          //get input data
          outFile << "  Current Salary \t\t: \t" << "$"<<myScores[emp][0][1]<< endl;

            if (compV[emp][4] < 75)
            {
                 compV[emp][5] = 0;
                 outFile << setw(31) << "Salary Raise in %\t: \t\t0%" << "\n";
                 double raise$ = compV[emp][4] * 0.00;
                 outFile << setw(31) << "Salary Raise in Dollars: \t\t"<< "$"<< raise$ << endl;
                 double totalRaise = myScores[emp][0][1]+ raise$;
                 outFile << "Salary in Dollars with the Raise: \t"<<"$"<< totalRaise<< endl;
            }
            else if (compV[emp][4] > 75 && compV[emp][4] <= 80)
            {
                 compV[emp][5] = compV[][4] * 0.01;
                 outFile << setw(31) << "Salary Raise in %\t:   \t\t1%"<< "\n";
                 double raise$ = compV[emp][4] * 0.01;
                 outFile << setw(31) << "Salary Raise in Dollars: \t\t"<< "$"<< raise$ << endl;
                 double totalRaise = myScores[emp][0][1]+ raise$;
                 outFile << "Salary in Dollars with the Raise: \t"<<"$"<< totalRaise<< endl;

            }
            else if (compV[emp][4] > 80 && compV[emp][4] <= 90)
            {
                compV[emp][5] = compV[][4]  * 0.03;
                outFile << setw(31) << "Salary Raise in %\t:\t\t3%" << "\n";
                double raise$ = compV[emp][4] * 0.3;
                outFile << setw(31) << "Salary Raise in Dollars: \t\t"<< "$"<< raise$ << endl;
                double totalRaise = myScores[emp][0][1]+ raise$;
                outFile << "Salary in Dollars with the Raise: \t"<<"$"<< totalRaise<< endl;
            }
            else if (compV[emp][4]  > 90 && compV[emp][4] <= 100)
            {
                compV[emp][5] = compV[][4]  * 0.05;
                outFile <<  setw(31) << "Salary Raise in %\t:  \t\t5%" <<"\n";
                double raise$ = compV[emp][4] * 0.05;
                outFile << setw(31) << "Salary Raise in Dollars: \t\t"<< "$"<< raise$ << endl;
                double totalRaise = myScores[emp][0][1]+ raise$;
                outFile << "Salary in Dollars with the Raise: \t"<<"$"<< totalRaise<< endl;
            }
            else{
                compV[emp][5] = compV[][4]  * 0.1;
                outFile << setw(31) << "Salary Raise in %\t:  \t\t10%" << endl;
                double raise$ = compV[emp][4] * 0.1;
                outFile << setw(31) << "Salary Raise in Dollars: \t\t"<< "$"<< raise$ << endl;
                double totalRaise = myScores[emp][0][1]+ raise$;
                outFile << "Salary in Dollars with the Raise: \t"<<"$"<< totalRaise<< endl;
            }

            if (compV[emp][4] < 70)
            {
                outFile << "Your Grade is\t\t: C" << endl;
            }
            else if(compV[emp][4] >= 90)
                outFile << "Your grade is \t\t: A" << endl;
            else
                outFile<< "Your grade is \t\t: B" << endl;


        outFile << endl;

        outFile << "Note:    This report for "<< myStrings[emp][2] << " was prepared according "
                << " to the fair practice "
                << " of the University." << endl;
        outFile << "         Any discrepancies must be reported by " << myStrings[emp][2] << " to her/his "
                << "supervisor, "<< myStrings[emp][3] << endl;

        outFile << endl;

        inFile.ignore();
  }
      inFile.close();
      outFile.close();
      return 0;
}
