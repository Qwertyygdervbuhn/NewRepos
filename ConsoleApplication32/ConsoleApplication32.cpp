#include <iostream>
#include<string>
using namespace std;

bool checkBrackets(string str) {
    int round = 0; 
    int curly = 0; 
    int square = 0; 

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

      
        if (ch == '(') {
            round++;
        }
        else if (ch == '{') {
            curly++;
        }
        else if (ch == '[') {
            square++;
        }
       
        else if (ch == ')') {
            if (round == 0) {
                cout << "Error at position " << i << ": extra closing bracket ')'" << endl;
                return false;
            }
            round--;
        }
        else if (ch == '}') {
            if (curly == 0) {
                cout << "Error at position " << i << ": extra closing bracket '}'" << endl;
                return false;
            }
            curly--;
        }
        else if (ch == ']') {
            if (square == 0) {
                cout << "Error at position " << i << ": extra closing bracket ']'" << endl;
                return false;
            }
            square--;
        }
    
        else if (ch == ';') {
            break;
        }
    }
    if (round != 0) {
        cout << "Error: not all round brackets are closed." << endl;
        return false;
    }
    if (curly != 0) {
        cout << "Error: not all curly brackets are closed." << endl;
        return false;
    }
    if (square != 0) {
        cout << "Error: not all square brackets are closed." << endl;
        return false;
    }

    return true;
}

int main() {
    string input;

    cout << "Enter a string to check (end with ';'): ";
    getline(cin, input);

    if (checkBrackets(input)) {
        cout << "The string is correct!" << endl;
    }
    else {
        cout << "The string contains errors in bracket placement!" << endl;
    }

}
