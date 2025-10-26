/*Space required to store any two-dimensional array is 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 𝑟𝑜𝑤𝑠 × 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 
�
�𝑜𝑙𝑢𝑚𝑛𝑠. Assuming array is used to store elements of the following matrices, 
implement an efficient way that reduces the space requirement. 
(a) Diagonal Matrix.*/
#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

// (a) Diagonal Matrix
void diagonalMatrix() {
    int n;
    cout << "Enter size of diagonal matrix: ";
    cin >> n;
    
    int diag[MAX_SIZE] = {0};
    

    cout << "Enter diagonal elements: ";
    for(int i = 0; i < n; i++) {
        cin >> diag[i];
    }
    cout << "Diagonal Matrix: "<< endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) cout << diag[i] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}
// (b) Tri-diagonal Matrix
void triDiagonalMatrix() {
    int n;
    cout << "Enter size of tri-diagonal matrix: ";
    cin >> n;
    int mainDiag[MAX_SIZE];
    int upperDiag[MAX_SIZE];
    int lowerDiag[MAX_SIZE];
    cout << "Enter main diagonal elements: ";
    for(int i = 0; i < n; i++) {
        cin >> mainDiag[i];
    }
    cout << "Enter upper diagonal elements: ";
    for(int i = 0; i < n-1; i++) {
        cin >> upperDiag[i];
    }
    cout << "Enter lower diagonal elements: ";
    for(int i = 0; i < n-1; i++) {
        cin >> lowerDiag[i];
    }
    // Display matrix
    cout << "Tri-diagonal Matrix: "<< endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) cout << mainDiag[i] << " ";
            else if(i == j-1) cout << upperDiag[i] << " ";
            else if(i == j+1) cout << lowerDiag[j] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}
// (c) Lower Triangular Matrix
void lowerTriangularMatrix() {
    int n;
    cout << "Enter size of lower triangular matrix: ";
    cin >> n;
    int total = n * (n + 1) / 2;
    int elements[total];
    for(int i = 0; i < total; i++) elements[i] = 0;
    cout << "Enter lower triangular elements row-wise: "<< endl;
    int index = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> elements[index++];
        }
    }
    cout << "Lower Triangular Matrix: "<< endl;
    index = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i >= j) cout << elements[index++] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}
// (d) Upper Triangular Matrix
void upperTriangularMatrix() {
    int n;
    cout << "Enter size of upper triangular matrix: ";
    cin >> n;
    int total = n * (n + 1) / 2;
    int elements[total];
    for(int i = 0; i < total; i++) elements[i] = 0;
    cout << "Enter upper triangular elements column-wise: "<< endl;
    int index = 0;
    for(int j = 0; j < n; j++) {
        for(int i = 0; i <= j; i++) {
            cin >> elements[index++];
        }
    }
    cout << "Upper Triangular Matrix: "<< endl;
    index = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i <= j) cout << elements[index++] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}
// (e) Symmetric Matrix
void symmetricMatrix() {
    int n;
    cout << "Enter size of symmetric matrix: ";
    cin >> n;
    int total = n * (n + 1) / 2;
    int elements[total];
    for(int i = 0; i < total; i++) elements[i] = 0;
    cout << "Enter lower triangular elements: "<< endl;
    int index = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> elements[index++];
        }
    }
    cout << "Symmetric Matrix:"<< endl;
    index = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i >= j) {
                cout << elements[i*(i+1)/2 + j] << " ";
            } else {
                cout << elements[j*(j+1)/2 + i] << " ";
            }
        }
        cout << endl;
    }
}
int main() {
    diagonalMatrix();
    cout << "\n";
    triDiagonalMatrix();
    cout << "\n";
    lowerTriangularMatrix();
    cout << "\n";
    upperTriangularMatrix();
    cout << "\n";
    symmetricMatrix();
    return 0;
}