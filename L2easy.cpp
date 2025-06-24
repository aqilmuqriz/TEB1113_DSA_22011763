/*
id: 22011763
name: Aqil Muqriz Bin Mohd Khairul Hasni
lab group: G1
lab: L2 (Easy) - Program to multiply two matrices
problem: https://www.geeksforgeeks.org/dsa/c-program-multiply-two-matrices/
*/

#include <iostream>
using namespace std;

const int row1 = 2, column1 = 2; 
const int row2 = 2, column2 = 2; 

void mulMat(int m1[row1][column1], int m2[row2][column2], int res[row1][column2]) {
    if (column1 != row2) {
        cout << "Invalid Input" << endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < column2; j++) {
            res[i][j] = 0;
        }
    }

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < column2; j++) {
            for (int k = 0; k < column1; k++) {
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

int main() {
    int m1[row1][column1] = { {3, 4}, {2, 2} };
    int m2[row2][column2] = { {1, 1}, {5, 6} };
    int res[row1][column2];

    mulMat(m1, m2, res);

    cout << "Multiplication of given two matrices is:\n";
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < column2; j++) {
            cout << res[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}