// Assignment 1 - SECJ2013 - 23241 (Assg1.cpp)
// Group Members:
// 1. Muhammad Iman Firdaus Bin Baharuddin A22EC0216
// 2. Muhammad Ariff Danish Bin Hashnan A22EC0204
// 3. Che Marhumi Bin Che AB Rahim A22EC0147
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm> // for std::tranform
using namespace std;

// Task Create Class (Iman)
class Cust
{
private:
    string name, destination, airlines;
    int day, month, years;

public:
    Cust(string x, int z, int c, int v, string d, string a)
    {
        name = x;
        day = z;
        month = c;
        years = v;
        destination = d;
        airlines = a;
    }

    void printResult()
    {
        cout << left << setw(15) << name << setw(2) << day << " / " << setw(2) << month << " / " << setw(15) << years << setw(15) << destination << setw(16) << airlines << endl;
    }

    int getdate()
    {
        return day + years * 10000 + month * 100;
    }

    string getName()
    {
        return name;
    }

    string getDestination()
    {
        return destination;
    }

    string getAirlines()
    {
        return airlines;
    }
};

// function implementation
void listcust(Cust *cl[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cl[i]->printResult();
    }
}

void sortname(Cust *cl[], int size)
{ // bubble sort
    int pass;
    Cust *tempValue;

    for (pass = 1; pass < size; pass++)
    { // moves the largest element to the
        // end of the array
        for (int x = 0; x < size - pass; x++)
        { // compare adjacent elements
            if (cl[x]->getName() > cl[x + 1]->getName())
            { // swap elements
                tempValue = cl[x];
                cl[x] = cl[x + 1];
                cl[x + 1] = tempValue;
            }
        }
    }
} // end Bubble Sort

void sortDestination(Cust *cl[], int size)
{ // bubble sort
    int pass;
    Cust *tempValue;

    for (pass = 1; pass < size; pass++)
    { // moves the largest element to the
        // end of the array
        for (int x = 0; x < size - pass; x++)
        { // compare adjacent elements
            if (cl[x]->getDestination() > cl[x + 1]->getDestination())
            { // swap elements
                tempValue = cl[x];
                cl[x] = cl[x + 1];
                cl[x + 1] = tempValue;
            }
        }
    }
} // end Bubble Sort

void sortAirlines(Cust *cl[], int size)
{ // bubble sort
    int pass;
    Cust *tempValue;

    for (pass = 1; pass < size; pass++)
    { // moves the largest element to the
        // end of the array
        for (int x = 0; x < size - pass; x++)
        { // compare adjacent elements
            if (cl[x]->getAirlines() > cl[x + 1]->getAirlines())
            { // swap elements
                tempValue = cl[x];
                cl[x] = cl[x + 1];
                cl[x + 1] = tempValue;
            }
        }
    }
} //  end Bubble Sort

void sortdate(Cust *cl[], int size)
{ // bubble sort
    int pass;
    Cust *tempValue;

    for (pass = 1; pass < size; pass++)
    { // moves the largest element to the
        // end of the array
        for (int x = 0; x < size - pass; x++)
        { // compare adjacent elements
            if (cl[x]->getdate() > cl[x + 1]->getdate())
            { // swap elements
                tempValue = cl[x];
                cl[x] = cl[x + 1];
                cl[x + 1] = tempValue;
            }
        }
    }
}

// --------------------------------------------------------------------------------
// Task function searching + file input (Che Marhumi)
/// implemented sequential search

// Helper function to convert a string to lowercase
std::string toLowercase(const std::string &str)
{
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// searchByName function
std::vector<int> searchByName(Cust *cl[], int size, const std::string &targetName)
{
    std::vector<int> foundIndices;

    // Convert target name to lowercase
    std::string lowercaseTarget = toLowercase(targetName);

    for (int i = 0; i < size; i++)
    {
        // Convert name in Cust object to lowercase for comparison
        std::string lowercaseName = toLowercase(cl[i]->getName());

        if (lowercaseName == lowercaseTarget)
        {
            foundIndices.push_back(i);
        }
    }

    return foundIndices;
}

// Search function for date
std::vector<int> searchByDate(Cust *cl[], int size, int targetDate)
{
    std::vector<int> foundIndices;

    for (int i = 0; i < size; i++)
    {
        if (cl[i]->getdate() == targetDate)
        {
            foundIndices.push_back(i);
        }
    }

    return foundIndices;
}

// Search function for destination
std::vector<int> searchByDestination(Cust *cl[], int size, const std::string &targetDestination)
{
    std::vector<int> foundIndices;

    std::string lowercaseDestination = toLowercase(targetDestination);

    for (int i = 0; i < size; i++)
    {
        std::string lowercaseDest = toLowercase(cl[i]->getDestination());
        if (lowercaseDest == lowercaseDestination)
        {
            foundIndices.push_back(i);
        }
    }

    return foundIndices;
}

// Search function for airline
std::vector<int> searchByAirline(Cust *cl[], int size, const std::string &targetAirline)
{
    std::vector<int> foundIndices;

    std::string lowercaseAirline = toLowercase(targetAirline);

    for (int i = 0; i < size; i++)
    {
        std::string lowercaseAirlines = toLowercase(cl[i]->getAirlines());
        if (lowercaseAirlines == lowercaseAirline)
        {
            foundIndices.push_back(i);
        }
    }

    return foundIndices;
}
// ---------------------------------------------------------------------------------------------------

// Task int main (Ariff)
// main function
int main()
{
    const int LIST_SIZE = 10;
    string line;
    int idx = 0;
    Cust *custlist[LIST_SIZE];

    fstream fileIn("booking.txt", ios::in);

    if (!fileIn)
    {
        cout << "File input/output error!\n";
        return 1;
    }
    else
    {
        while (getline(fileIn, line))
        {
            // Use stringstream to parse the line
            stringstream ss(line);
            string name, destination, airlines;
            int day, month, years;

            ss >> name >> day;
            // Ensure the next character is a dot (.)
            if (ss.peek() == '.')
            {
                ss.ignore();
                ss >> month;
            }
            if (ss.peek() == '.')
            {
                ss.ignore();
                ss >> years;
                ss >> destination >> airlines;
                custlist[idx] = new Cust(name, day, month, years, destination, airlines);
                idx++;
            }
            else
            {
                cout << "Invalid date format in line: " << line << endl;
            }
        }
    }

    int opt = 0;
    std::string searchName, searchDestination, searchAirline;
    int searchDate;

    while (opt != 10)
    {
        cout << "\n1. List results (original list)";
        cout << "\n2. List results (sort by name)";
        cout << "\n3. List results (sort by date of booking)";
        cout << "\n4. List results (sort by destination)";
        cout << "\n5. List results (sort by airlines)";
        cout << "\n---------------------------------------------" << endl;
        cout << "6. Search Passenger (by name)";
        cout << "\n7. Search Passenger (by date of booking)";
        cout << "\n8. Search Passenger (by destination)";
        cout << "\n9. Search Passenger (by airline)";
        cout << "\n10. Exit\n\n";

        cout << "Enter your choice [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]: ";
        cin >> opt;

        cout << endl;

        std::vector<int> foundIndices;
        std::vector<int> foundDateIndices;
        std::vector<int> foundDestIndices;
        std::vector<int> foundAirlineIndices;

        switch (opt)
        {
        case 1:
            cout << ">>>>>>>>>>>>>>>>>>>>>>>>>> BOOKING DETAILS <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
            cout << "----------------------------------------------------------------------" << endl;
            cout << left << setw(15) << "Name"
                 << "Date of Booking"
                 << "\t\tDestination"
                 << "\tAirlines" << endl;
            cout << "----------------------------------------------------------------------" << endl;
            listcust(custlist, idx);
            cout << endl;
            system("pause");
            break;

        // sort by name
        case 2:
            sortname(custlist, idx);
            cout << "BOOKING DETAILS" << endl;
            cout << "----------------------------------------------------------------------" << endl;
            cout << left << setw(15) << "Name"
                 << "Date of Booking"
                 << "\t\tDestination"
                 << "\tAirlines" << endl;
            cout << "----------------------------------------------------------------------" << endl;
            listcust(custlist, idx);
            cout << endl;
            system("pause");
            break;

        // sort by grade
        case 3:
            sortdate(custlist, idx);
            cout << "BOOKING DETAILS" << endl;
            cout << "----------------------------------------------------------------------" << endl;
            cout << left << setw(15) << "Name"
                 << "Date of Booking"
                 << "\t\tDestination"
                 << "\tAirlines" << endl;
            cout << "----------------------------------------------------------------------" << endl;
            listcust(custlist, idx);
            cout << endl;
            system("pause");
            break;

        // sort by grade
        case 4:
            sortDestination(custlist, idx);
            cout << "BOOKING DETAILS" << endl;
            cout << "----------------------------------------------------------------------" << endl;
            cout << left << setw(15) << "Name"
                 << "Date of Booking"
                 << "\t\tDestination"
                 << "\tAirlines" << endl;
            cout << "----------------------------------------------------------------------" << endl;
            listcust(custlist, idx);
            cout << endl;
            system("pause");
            break;

        // sort by grade
        case 5:
            sortAirlines(custlist, idx);
            cout << "BOOKING DETAILS" << endl;
            cout << "----------------------------------------------------------------------" << endl;
            cout << left << setw(15) << "Name"
                 << "Date of Booking"
                 << "\t\tDestination"
                 << "\tAirlines" << endl;
            cout << "----------------------------------------------------------------------" << endl;
            listcust(custlist, idx);
            cout << endl;
            system("pause");
            break;

            // search by name

        case 6:
            cout << "Enter the name to search: ";
            cin >> searchName;

            foundIndices = searchByName(custlist, idx, searchName);

            if (!foundIndices.empty())
            {
                cout << "Bookings found for name " << searchName << ":\n";
                cout << "----------------------------------------------------------------------\n";
                cout << left << setw(15) << "Name"
                     << "Date of Booking"
                     << "\t\tDestination"
                     << "\tAirlines" << endl;
                cout << "----------------------------------------------------------------------\n";

                for (int foundIndex : foundIndices)
                {
                    custlist[foundIndex]->printResult();
                }

                cout << endl;
            }
            else
            {
                cout << "Booking not found for name: " << searchName << endl;
            }
            system("pause");
            break;

            // search by date

        case 7:

            cout << "Enter the date to search (DD.MM.YYYY): ";
            cin >> ws; // Consume any leading whitespace characters

            int searchDay, searchMonth, searchYear;
            char dot;

            if (cin >> searchDay >> dot >> searchMonth >> dot >> searchYear)
            {
                int formattedSearchDate = searchDay + searchYear * 10000 + searchMonth * 100;
                foundDateIndices = searchByDate(custlist, idx, formattedSearchDate);

                if (!foundDateIndices.empty())
                {
                    cout << "Bookings found for date " << searchDay << "." << searchMonth << "." << searchYear << ":\n";
                    cout << "----------------------------------------------------------------------\n";
                    cout << left << setw(15) << "Name"
                         << "Date of Booking"
                         << "\t\tDestination"
                         << "\tAirlines" << endl;
                    cout << "----------------------------------------------------------------------\n";

                    for (int foundIndex : foundDateIndices)
                    {
                        custlist[foundIndex]->printResult();
                    }

                    cout << endl;
                }
                else
                {
                    cout << "Booking not found for date: " << searchDay << "." << searchMonth << "." << searchYear << endl;
                }
            }
            else
            {
                cout << "Invalid date format. Please enter the date in the format DD.MM.YYYY.\n";
            }

            system("pause");
            break;

            // search by destination

        case 8:
            cout << "Enter the destination to search: ";
            cin >> searchDestination;

            foundDestIndices = searchByDestination(custlist, idx, searchDestination);

            if (!foundDestIndices.empty())
            {
                cout << "Bookings found for destination " << searchDestination << ":\n";
                cout << "----------------------------------------------------------------------\n";
                cout << left << setw(15) << "Name"
                     << "Date of Booking"
                     << "\t\tDestination"
                     << "\tAirlines" << endl;
                cout << "----------------------------------------------------------------------\n";

                for (int foundIndex : foundDestIndices)
                {
                    custlist[foundIndex]->printResult();
                }

                cout << endl;
            }
            else
            {
                cout << "Booking not found for destination: " << searchDestination << endl;
            }

            system("pause");
            break;

            // search by airline

        case 9:
            cout << "Enter the airline to search: ";
            cin >> searchAirline;

            foundAirlineIndices = searchByAirline(custlist, idx, searchAirline);

            if (!foundAirlineIndices.empty())
            {
                cout << "Bookings found for airline " << searchAirline << ":\n";
                cout << "----------------------------------------------------------------------\n";
                cout << left << setw(15) << "Name"
                     << "Date of Booking"
                     << "\t\tDestination"
                     << "\tAirlines" << endl;
                cout << "----------------------------------------------------------------------\n";

                for (int foundIndex : foundAirlineIndices)
                {
                    custlist[foundIndex]->printResult();
                }

                cout << endl;
            }
            else
            {
                cout << "Booking not found for airline: " << searchAirline << endl;
            }

            system("pause");
            break;
        }
    }
    system("pause");

    for (int i = 0; i < idx; i++) // release memory allocated for each object
    {
        delete custlist[i];
    }

    fileIn.close();
    return 0;
}
