#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // rows[i][num] -> num is present in row i
        bool rows[9][9] = {};

        // cols[i][num] -> num is present in column i
        bool cols[9][9] = {};

        // boxes[i][num] -> num is present in 3x3 box i
        bool boxes[9][9] = {};

        for (int i = 0; i < 9; i++) {

            for (int j = 0; j < 9; j++) {

                // Ignore empty cells
                if (board[i][j] == '.')
                    continue;

                int num = board[i][j] - '1';

                // Find the 3x3 box number
                int box = (i / 3) * 3 + (j / 3);

                // Check duplicate
                if (rows[i][num] ||
                    cols[j][num] ||
                    boxes[box][num]) {

                    return false;
                }

                // Mark number as present
                rows[i][num] = true;
                cols[j][num] = true;
                boxes[box][num] = true;
            }
        }

        return true;
    }
};