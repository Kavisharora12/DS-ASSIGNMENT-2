#include <iostream>
using namespace std;
int findMissingNumber(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] != i + 1) {
            return i + 1;  
        }
    }
    return size + 1;
}
int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int missing = findMissingNumber(arr, size);
    cout << "The missing number is: " << missing << endl;
    return 0;
}
