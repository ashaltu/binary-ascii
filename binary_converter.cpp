
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

string toBinary(const string &);
string toAscii(const string &);

int main()
{
    string text, binary;
    string choice;
    bool done = false;
    cout << "\nSelect 1 or 2 for the following options:";
    while (!done)
    {
        cout << "\n1)ASCII to Binary\n2)Binary to ASCII\n(Press any key to end program)" << endl;
        getline(cin,choice);
        if (choice[0] == '1')
        {
            cout<<"Enter your word(s):"<<endl;
            getline(cin, text);
            binary = toBinary(text);
            cout << "ASCII to Binary: " << binary << endl;
        }
        else if (choice[0] == '2')
        {
            cout<<"Enter your binary:"<<endl;
            getline(cin, binary);
            text = toAscii(binary);
            cout << "Binary to ASCII: " << text << endl;
        }
        else
        {
            break;
        }
    }

    cout << "Ending program..." << endl;
    return 0;
}

string toBinary(const string &val)
{
    string convert;
    for (int i = 0; i < val.size(); i++)
    {
        int temp = (int)val[i];
        for (int j = 7; j >= 0; j--)
        {
            if (temp >= pow(2, j))
            {
                convert += "1";
                temp -= pow(2, j);
            }
            else
            {
                convert += "0";
            }
        }
        convert += " ";
    }
    return convert;
}

string toAscii(const string &binary)
{
    string val;
    int ascii;
    for (int i = 0; i < binary.size(); i += 8)
    {
        if (binary[i] == ' ')
        {
            ++i;
        }
        for (int j = 0; j <= 7; j++)
        {
            if (binary[i + j] == '1')
            {
                ascii += pow(2, 7 - j);
            }
        }
        val += (char)ascii;
        ascii = 0;
    }
    return val;
}