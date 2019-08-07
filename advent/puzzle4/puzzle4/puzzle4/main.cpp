#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int main()
{
    string line;
    ifstream myfile("C:\\Users\\blazej.ciok1\\Documents\\Visual Studio 2013\\Projects\\Advent_of_Code\\advent\\puzzle4\\puzzle4\\puzzle4\\puzzle_input.txt");
    if (myfile.is_open())
    {
        while (myfile.good())
        {
            getline(myfile, line);
            cout << "LINE : " << line << endl;
        }

        myfile.close();
    } 
    else
    {
       cout << "Unable to open file";
    }
    return 0;
}