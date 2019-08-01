#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() 
{
    string line;
    static int beforeDigit = 0;
    static int afterDigit = 0;
    static int sum = 0;

    ifstream myfile("puzzle1.txt");
    if (myfile.is_open())
    {
        while (myfile.good())
        {
            getline(myfile, line);
            int filePos = 0;
            int tempFilePos = 0;
            while (filePos < (line.size() - 1))
            {
                beforeDigit = static_cast<int>(line[filePos] - 48);
                tempFilePos = ((line.size()/2)) + filePos;
                if (tempFilePos > line.size() - 1)
                {
                    afterDigit = static_cast<int>(line[tempFilePos - (line.size())] - 48);
                }
                else
                {
                    afterDigit = static_cast<int>(line[tempFilePos] - 48);
                }
                
                filePos++;
                if (beforeDigit == afterDigit)
                {
                    sum += beforeDigit;
                }
            }
            beforeDigit = static_cast<int>(line[line.size() - 1] - 48);
            afterDigit = static_cast<int>(line[(line.size()/2) - 1] - 48);
            if (beforeDigit == afterDigit)
            {
                sum += beforeDigit;
            }
            cout << "CAPTCHA is : " << sum << endl;
        }
        myfile.close();
    }

    else cout << "Unable to open file";

    return 0;
}