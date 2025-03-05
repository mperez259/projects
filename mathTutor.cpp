// FINAL math tutor program
// Math tutor program with functions and enhancements

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <string>
#include <ctime>
#include <iomanip>


int displayMenu();           // menu prototype fcn.
bool isValid(int num);       // validation prototype fcn.
// prototype arithmetic fcns
void addition(double &);
void subtraction(double &);
void multiplication(double &);
void division(double &);
void displayResults(double, double , double , double , double , double , double , double, double&, double&, double&, double&, double&);

using namespace std;

int main()
{
    int age = 0, grade = 0;
    int seed = time(0);
    double a = 0, s = 0, m = 0, d = 0;
    double total =0, totalProblems = 0;
    double addAvg = 0, subAvg = 0, multAvg = 0, divAvg = 0, avg = 0;
    double addCorrect = 0, subCorrect = 0, multCorrect = 0, divCorrect = 0;
    srand(seed);
    char choice;
    string name, schoolName;
    const string QUIT_1 = "Thank you , ";
    const string QUIT_2 = ", for using this program! Please use it again if you need more practice! \n\n";

    cout << "Enter name: ";                            // get student name
    getline(cin, name);

    cout << "Enter school: ";                          // get school name
    getline(cin, schoolName);

    cout << "Enter age: ";                             // get student age
    cin >> age;

    cout << "Enter grade: ";                           // enter what grade student is in
    cin >> grade;

    do
    {
        choice = displayMenu();                         // display menu
        while (isValid(choice) == false)                // validate entry
        {
            cout << "Invalid choice.Please choose a given option.\n\n";
            choice = displayMenu();
        }
        switch (choice)                                 // begin switch for menu
        {
        case 1:
            addition(addCorrect);                       // call addition function and return accumulated correct answers
            a++;                                        // accumulate number of addition problems
            break;
        case 2:
            subtraction(subCorrect);                    // call subtraction function and return accumulated correct answers
            s++;                                        // accumulate number of subtraction problems
            break;
        case 3:
            multiplication(multCorrect);                // call multiplication function and return accumulated correct answers
            m++;                                        // accumulate number of multiplication problems
            break;
        case 4:
            division(divCorrect);                       // call division function and return accumulated correct answers
            d++;                                        // accumulate number of division problems
            break;
        case 5:
            displayResults(a, addCorrect, s, subCorrect, m, multCorrect, d, divCorrect, addAvg, subAvg, multAvg, divAvg, avg);    // shows stats
            break;
        case 6:
            cout << QUIT_1 << name << QUIT_2 << endl;   // quit option results
            break;
        default:
            cout << "Invalid entry\n\n";                // invalid input message
        }
    }
    while (choice != 6);

    // final display of results after quitting
    displayResults(a, addCorrect, s, subCorrect, m, multCorrect, d, divCorrect, addAvg, subAvg, multAvg, divAvg, avg);

    // chart summary of results
    cout << "===============================================================================================================================\n";
    cout << "                                                  " << schoolName << "                                                       \n";
    cout << "===============================================================================================================================\n\n";
    cout << "name\t\t  addition\t\tsbtraction\t\tmultiplication\t\t  division\t\ttotal average\n";
    cout << left << name << right << setw(31) << addAvg << "%" << setw(25) << subAvg << "%" << setw(25) << multAvg << "%" << setw(25) << divAvg << "%" << setw(25) << avg << "%\n\n";
}

//==========================================================================
//         display menu function that shows options returns choice
//==========================================================================
int displayMenu() // menu function
{
    int choice;
    cout << "\nWhich would you like to practice?" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Show Stats" << endl;
    cout << "6. Quit" <<  endl;
    cin >> choice;                      // get user choice
    return choice;
}

//==========================================================================
//     validation function so you don't pick anything not in the menu
//==========================================================================
bool isValid(int num)
{
    bool isValid = true;
    if (num > 0 && num < 7)         // range of choices must be grater than
    {                               // and less than 7
        isValid = true;
    }
    return (num > 0 && num < 7);
}

//==========================================================================
//     addition function returns amount of correct answers accumulator
//==========================================================================
void addition(double &correct) //addition function
{
    int num1, num2, min, max;
    int attempts = 1;
    int answer;
    min = 2;
    max = 500;
    // generate random numbers
    num1 = (rand() % (max - min + 1)) + min;
    min = 1;
    max = 99;
    num2 = (rand() % (max - min + 1)) + min;
    while (num1 <= num2) //make sure num1 > num2
    {
        num2 = (rand() % (max - min + 1)) + min;
    }
    int result = num1 + num2;

    cout << "You have chosen addition." << endl;
    cout << endl << "Input your answer." << endl;
    cout << " " << num1 << endl;
    cout << "+" << num2 << endl;
    cout << "_____" << endl;
    cin >> answer;

    while (attempts < 3)
    {
        if (result == answer)
        {
            cout << "\nExcellent! you are correct. \n\n";
            correct++;                      // accumulator
            break;
        }
        else if (result != answer)
        {
            cout << "\nNope. That's not correct. Review your notes and try again." << endl << endl;
            cout << "attempts remaining: " << 3 - attempts << endl;
            cin >> answer;
            attempts++;
        }
        if (attempts == 3 && result == answer)
        {
            cout << "\nExcellent! you are correct. \n\n";
            correct++;                      // accumulator
            break;
        }
        if (attempts == 3 && result != answer)
        {
            cout << "\nreview notes\n";
            break;
        }
    }
}

//==========================================================================
//    subtraction function returns amount of correct answers accumulator
//==========================================================================
void subtraction(double& correct) //subtraction function
{
    int num1, num2, min, max;
    int attempts = 1;
    int answer;
    min = 2;
    max = 500;
    // generate random numbers for num1 and num2
    num1 = (rand() % (max - min + 1)) + min;
    min = 1;
    max = 500;
    num2 = (rand() % (max - min + 1)) + min;
    while (num1 <= num2)
    {
        num2 = (rand() % (max - min + 1)) + min;
    }
    int result = num1 - num2;

    cout << "You have chosen subtraction." << endl;
    cout << endl << "Input your answer." << endl;
    cout << " " << num1 << endl;
    cout << "-" << num2 << endl;
    cout << "_____" << endl;
    cin >> answer;

    while (attempts < 3)
    {
        if (result == answer)
        {
            cout << "\nExcellent! you are correct. \n\n";
            correct++;                          // accumulator
            break;
        }
        else if (result != answer)
        {
            cout << "\nNope. That's not correct. Review your notes and try again." << endl << endl;
            cout << "attempts remaining: " << 3 - attempts << endl;
            cin >> answer;
            attempts++;
        }
        if (attempts == 3 && result == answer)
        {
            cout << "\nExcellent! you are correct. \n\n";
            correct++;                          // accumulator
            break;
        }
        if (attempts == 3 && result != answer)
        {
            cout << "\nreview notes\n";
            break;
        }
    }
}

//==========================================================================
//    multiplication function returns amount of correct answers accumulator
//==========================================================================
void multiplication(double& correct) //multiplication function
{
    int attempts = 1;
    int answer;
    int min = 1;
    int max = 12;
    // generate random numbers for num1 and num2
    int num1 = (rand() % (max - min + 1)) + min;
    int num2 = (rand() % (max - min + 1)) + min;

    int result = num1 * num2;

    cout << "You have chosen multiplication." << endl;
    cout << endl << "Input your answer." << endl;
    cout << " " << num1 << endl;
    cout << "x" << num2 << endl;
    cout << "_____" << endl;
    cin >> answer;

    while (attempts < 3)
    {
        if (result == answer)
        {
            cout << "\nExcellent! you are correct. \n\n";
            correct++;                      // accumulator
            break;
        }
        else if (result != answer)
        {
            cout << "\nNope. That's not correct. Review your notes and try again." << endl << endl;
            cout << "attempts remaining: " << 3 - attempts << endl;
            cin >> answer;
            attempts++;
        }
        if (attempts == 3 && result == answer)
        {
            cout << "\nExcellent! you are correct. \n\n";
            correct++;                      // accumulator
            break;
        }
        if (attempts == 3 && result != answer)
        {
            cout << "\nreview notes\n";
            break;
        }
    }
}

//==========================================================================
//    division function returns amount of correct answers accumulator
//==========================================================================
void division(double& correct) // division function
{
    int attempts = 1;
    int answer;
    int min;
    int max;

    min = 10;
    max = 999;

    int num1 = (rand() % (max - min + 1)) + min;

    min = 1;
    max = 9;

    int num2 = (rand() % (max - min + 1)) + min;

    while (num1 % num2 != 0) //makes division possible without a remainder
    {
        num2 = (rand() % (max - min + 1)) + min;
    }

    int result = num1 / num2;

    cout << "You have chosen division." << endl;
    cout << endl << "Input your answer." << endl;
    cout << " " << num1 << endl;
    cout << "/" << num2 << endl;
    cout << "_____" << endl;
    cin >> answer;

    while (attempts < 3)
    {
        if (result == answer)
        {
            cout << "\nExcellent! you are correct. \n\n";
            correct++;  // accumulator
            break;
        }
        else if (result != answer)
        {
            cout << "\nNope. That's not correct. Review your notes and try again." << endl << endl;
            cout << "attempts remaining: " << 3 - attempts << endl;
            cin >> answer;
            attempts++;
        }
        if (attempts == 3 && result == answer)
        {
            cout << "\nExcellent! you are correct. \n\n";
            correct++;  // accumulator
            break;
        }
        if (attempts == 3 && result != answer)
        {
            cout << "\nreview notes\n";
            break;
        }
    }
}

//==========================================================================
//               function to display statistics
//          returns several numbers to calculate averages
//==========================================================================
void displayResults(double a, double addCorrect, double s, double subCorrect, double m, double multCorrect, double d,
                    double divCorrect, double & addAvg, double & subAvg, double & multAvg, double & divAvg, double & avg)
{
    double total = 0, totalProblems = 0;
    cout << "Total addition problems: " << a << endl;
    cout << "Correct addition: " << addCorrect << endl;
    addAvg = (addCorrect / a) * 100;                        // average for addition problems
    cout << "Addition score: " << addAvg << "%\n\n";

    cout << "Total subtraction problems: " << s << endl;
    cout << "Correct subtraction problems: " << subCorrect << endl;;
    subAvg = (subCorrect / s) * 100;                        // average for subtraction problems
    cout << "Subtraction score: " << subAvg << "%\n\n";

    cout << "Total multiplication problems: " << m << endl;
    cout << "Correct mulitiplication problems: " << multCorrect << endl;
    multAvg = (multCorrect / m) * 100;                      // avarage for multiplication problems
    cout << "Mulitiplication score: " << multAvg << "%\n\n";

    cout << "Total division problems: " << d << endl;
    cout << "Correct division problems: " << divCorrect << endl;
    divAvg = (divCorrect / d) * 100;                        // average for division
    cout << "Division score: " << divAvg << "%\n\n";

    //finds total correct answers
    total = addCorrect + subCorrect + multCorrect + divCorrect;

    totalProblems = a + s + m + d;                  //finds amount of total problems answered
    avg = (total / totalProblems) * 100;            //finds total average
    cout << "Total overall score: " << total << " out of " << totalProblems << endl << endl;
    cout << "Your total percentage is " << avg << "%\n\n";
}

