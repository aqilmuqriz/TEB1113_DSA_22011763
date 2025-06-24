/*
id: 22011763
name: Aqil Muqriz Bin Mohd Khairul Hasni
lab group: G1
lab: L2 (Medium) - Number of Islands
problem: https://www.geeksforgeeks.org/dsa/find-the-number-of-islands-using-dfs/
*/

#include <iostream>
using namespace std;

const int row = 5;
const int column = 5;

bool isSafe(char grid[row][column], int r, int c, bool visited[row][column]) {
    return (r >= 0) && (r < row) && 
           (c >= 0) && (c < column) && 
           (grid[r][c] == 'L' && !visited[r][c]);
}

void dfs(char grid[row][column], int r, int c, bool visited[row][column]) {
    int rNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int cNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    visited[r][c] = true;

    for (int k = 0; k < 8; ++k) {
        int newR = r + rNbr[k];
        int newC = c + cNbr[k];
        if (isSafe(grid, newR, newC, visited)) {
            dfs(grid, newR, newC, visited);
        }
    }
}

int countIslands(char grid[row][column]) {
    bool visited[row][column] = { false };

    int count = 0;
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < column; ++c) {
            if (grid[r][c] == 'L' && !visited[r][c]) {
                dfs(grid, r, c, visited);
                ++count;
            }
        }
    }
    return count;
}

int main() {
    char grid[row][column] = {
        { 'L', 'W', 'W', 'W', 'W' },
        { 'W', 'L', 'W', 'W', 'L' },
        { 'L', 'W', 'W', 'L', 'L' },
        { 'W', 'W', 'W', 'W', 'W' },
        { 'L', 'W', 'L', 'L', 'W' }
    };

    cout << "Number of islands: " << countIslands(grid) << endl;

    return 0;
}