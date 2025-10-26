/*Write a program to count the total number of distinct elements in an array of length 
n.*/
#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int countDistinct = 0;
    int j;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                break;
            }
        }
        if ( j ==  i) {
            countDistinct++;
        }
    }
    cout << "Total number of distinct elements: " << countDistinct << endl;
    return 0;
}
