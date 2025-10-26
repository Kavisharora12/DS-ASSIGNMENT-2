#include <iostream>
using namespace std;

#define MAX 100
void readMatrix(int triplet[MAX][3], int &nonZero) {
    cout << "Enter number of rows, columns, and non-zero elements: ";
    cin >> triplet[0][0] >> triplet[0][1] >> nonZero;
    triplet[0][2] = nonZero;

    cout << "Enter row, column, and value for each non-zero element:\n";
    for (int i = 1; i <= nonZero; ++i) {
        cin >> triplet[i][0] >> triplet[i][1] >> triplet[i][2];
    }
}
void displayMatrix(int triplet[MAX][3]) {
    int n = triplet[0][2];
    cout << "Row Col Value\n";
    for (int i = 0; i <= n; ++i) {
        cout << triplet[i][0] << "   " << triplet[i][1] << "   " << triplet[i][2] << endl;
    }
}
void multiplySparse(int A[MAX][3], int B[MAX][3], int result[MAX][3]) {
    if (A[0][1] != B[0][0]) {
        cout << "Matrix multiplication not possible. Columns of A must match rows of B.\n";
        return;
    }
    int rA = A[0][0], cA = A[0][1], nA = A[0][2];
    int rB = B[0][0], cB = B[0][1], nB = B[0][2];

    int temp[MAX][3];
    int k = 1;

    for (int i = 1; i <= nA; ++i) {
        for (int j = 1; j <= nB; ++j) {
            if (A[i][1] == B[j][0]) {
                int row = A[i][0];
                int col = B[j][1];
                int val = A[i][2] * B[j][2];
                bool found = false;
                for (int t = 1; t < k; ++t) {
                    if (temp[t][0] == row && temp[t][1] == col) {
                        temp[t][2] += val;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    temp[k][0] = row;
                    temp[k][1] = col;
                    temp[k][2] = val;
                    k++;
                }
            }
        }
    }
    result[0][0] = A[0][0];
    result[0][1] = B[0][1];
    result[0][2] = k - 1;
    for (int i = 1; i < k; ++i) {
        result[i][0] = temp[i][0];
        result[i][1] = temp[i][1];
        result[i][2] = temp[i][2];
    }
}
int main() {
    int A[MAX][3], B[MAX][3], C[MAX][3];
    int nonZeroA, nonZeroB;
    cout << "Enter Matrix A:\n";
    readMatrix(A, nonZeroA);
    cout << "Enter Matrix B:\n";
    readMatrix(B, nonZeroB);
    cout << "\nMatrix A (Triplet Form):\n";
    displayMatrix(A);
    cout << "\nMatrix B (Triplet Form):\n";
    displayMatrix(B);
    multiplySparse(A, B, C);
    cout << "\nResultant Matrix after Multiplication (Triplet Form):\n";
    displayMatrix(C);

    return 0;
}
