// Write a program to reverse a string. 
#include <iostream>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin>>str;
    int n = str.length();
    for (int i = n-1; i < n/2;i--) {
        str[i]=str[n-1];
    }
    cout << "Reversed string: " << str << endl;
    return 0;
}
