// Write a program to delete all the vowels from the string. 
#include <iostream>
using namespace std;
int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str; 
    string result = "";
    for (char c : str) {
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            result += c; 
        }
    }
    cout << "String after removing vowels: " << result << endl;
    return 0;
}