#include <iostream>
using namespace std;

struct Triplet {
    int row;
    int col;
    int val;
};
void addSparseMatrices(Triplet A[], int sizeA, Triplet B[], int sizeB, Triplet result[], int &sizeResult) {
    int i = 0, j = 0, k = 0;
    while (i < sizeA && j < sizeB) {
        if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col)) {
            result[k++] = A[i++];
        }
        else if (B[j].row < A[i].row || (B[j].row == A[i].row && B[j].col < A[i].col)) {
            result[k++] = B[j++];
        }
        else {
            int summedVal = A[i].val + B[j].val;
            if (summedVal != 0) {
                result[k].row = A[i].row;
                result[k].col = A[i].col;
                result[k].val = summedVal;
                k++;
            }
            i++;
            j++;
        }
    }
    while (i < sizeA) {
        result[k++] = A[i++];
    }
    while (j < sizeB) {
        result[k++] = B[j++];
    }

    sizeResult = k;
}
int main() {
    int rowsA, colsA, nonZeroA;
    int rowsB, colsB, nonZeroB;
    cout << "Enter rows, columns and number of non-zero elements of matrix A: ";
    cin >> rowsA >> colsA >> nonZeroA;
    Triplet A[nonZeroA];
    cout << "Enter triplets (row col value) for matrix A:\n";
    for (int i = 0; i < nonZeroA; i++) {
        cin >> A[i].row >> A[i].col >> A[i].val;
    }
    cout << "Enter rows, columns and number of non-zero elements of matrix B: ";
    cin >> rowsB >> colsB >> nonZeroB;
    if (rowsA != rowsB || colsA != colsB) {
        cout << "Matrices dimensions must be the same for addition.\n";
        return 0;
    }
    Triplet B[nonZeroB];
    cout << "Enter triplets (row col value) for matrix B:\n";
    for (int i = 0; i < nonZeroB; i++) {
        cin >> B[i].row >> B[i].col >> B[i].val;
    }
    Triplet result[nonZeroA + nonZeroB];  // Maximum possible size
    int sizeResult;
    addSparseMatrices(A, nonZeroA, B, nonZeroB, result, sizeResult);
    cout << "\nResultant sparse matrix after addition (triplet form):\n";
    cout << "Row\tCol\tValue\n";
    for (int i = 0; i < sizeResult; i++) {
        cout << result[i].row << "\t" << result[i].col << "\t" << result[i].val << "\n";
    }
    return 0;
}
