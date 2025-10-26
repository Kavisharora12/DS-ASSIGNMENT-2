//Write a program to concatenate one string to another string. 
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;
    cout << "Enter the first string: ";
    cin>>str2;  
    cout << "Enter the second string: ";
    cin>>str2; 
    str1 += str2;
    cout << "After concatenation: " << str1 << endl;
    return 0;
}
