// Write a program to sort the strings in alphabetical order
#include <iostream>
using namespace std;
int main() {
    string str[5], temp;
    cout << "Enter 5 strings: ";
    for (int i = 0; i < 5; i++) {
        cin >> str[i];
    }
    for (int i = 0; i < 5 - 1; i++) {
        for (int j = 0; j < 5 - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
    cout << "Strings in alphabetical order:\n";
    for (int i = 0; i < 5; i++) {
        cout << str[i] << endl;
    }
    return 0;
}