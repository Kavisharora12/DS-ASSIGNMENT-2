#include <iostream>
using namespace std;
struct Triplet {
    int row;
    int col;
    int val;
};
void transposeSparseMatrix(Triplet matrix[], int nonZero, Triplet result[]) {
    for (int i = 0; i < nonZero; i++) {
        result[i].row = matrix[i].col;
        result[i].col = matrix[i].row;
        result[i].val = matrix[i].val;
    }
    for (int i = 0; i < nonZero - 1; i++) {
        for (int j = 0; j < nonZero - i - 1; j++) {
            if (result[j].row > result[j + 1].row ||
               (result[j].row == result[j + 1].row && result[j].col > result[j + 1].col)) {
                Triplet temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
            }
        }
    }
}
int main() {
    int rows, cols, nonZero;
    cout << "Enter number of rows, columns and non-zero elements: ";
    cin >> rows >> cols >> nonZero;
    Triplet matrix[nonZero];
    Triplet transposed[nonZero];
    cout << "Enter row, column and value for each non-zero element:\n";
    for (int i = 0; i < nonZero; i++) {
        cin >> matrix[i].row >> matrix[i].col >> matrix[i].val;
    }
    transposeSparseMatrix(matrix, nonZero, transposed);
    cout << "\nTransposed sparse matrix in triplet form:\n";
    cout << "Row\tCol\tValue\n";
    for (int i = 0; i < nonZero; i++) {
        cout << transposed[i].row << "\t" << transposed[i].col << "\t" << transposed[i].val << "\n";
    }
    return 0;
}
