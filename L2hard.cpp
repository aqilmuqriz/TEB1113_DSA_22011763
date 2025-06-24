/*
id: 22011763
name: Aqil Muqriz Bin Mohd Khairul Hasni
lab group: G1
lab: L2 (Hard) - Find a specific pair in Matrix
problem: https://www.geeksforgeeks.org/dsa/find-a-specific-pair-in-matrix/
*/

#include <iostream>
#include <climits> 
using namespace std;

const int N = 5;

int findMaxValue(int mat[N][N]) {
    int maxValue = INT_MIN;

    for (int a = 0; a < N - 1; ++a) {
        for (int b = 0; b < N - 1; ++b) {
            for (int d = a + 1; d < N; ++d) {
                for (int e = b + 1; e < N; ++e) {
                    int current = mat[d][e] - mat[a][b];
                    if (current > maxValue) {
                        maxValue = current;
                    }
                }
            }
        }
    }

    return maxValue;
}

int main() {
    int mat[N][N] = {
        {  1,  2, -1, -4, -20 },
        { -8, -3,  4,  2,   1 },
        {  3,  8,  6,  1,   3 },
        { -4, -1,  1,  7,  -6 },
        {  0, -4, 10, -5,   1 }
    };

    cout << "Maximum Value is " << findMaxValue(mat) << endl;

    return 0;
}