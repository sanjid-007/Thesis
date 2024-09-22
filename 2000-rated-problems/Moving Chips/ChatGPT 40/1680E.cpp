#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate the minimum number of moves for a single test case
int calculateMoves(vector<int>& row1_chips, vector<int>& row2_chips) {
    // Merge row1_chips and row2_chips into one array of positions
    vector<int> all_chips = row1_chips;
    all_chips.insert(all_chips.end(), row2_chips.begin(), row2_chips.end());
    
    // Sort all chip positions based on columns
    sort(all_chips.begin(), all_chips.end());
    
    // Median minimizes the distance
    int median_col = all_chips[all_chips.size() / 2];
    
    // Calculate total moves to align all chips to the median column
    int moves = 0;
    for (int chip_col : all_chips) {
        moves += abs(chip_col - median_col);
    }
    
    return moves;
}

int main() {
    int t; // number of test cases
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        // Read the two rows of the board
        string s1, s2;
        cin >> s1 >> s2;

        // Collect chip positions in each row
        vector<int> row1_chips, row2_chips;
        for (int i = 0; i < n; ++i) {
            if (s1[i] == '*') {
                row1_chips.push_back(i); // Chips in row 1
            }
            if (s2[i] == '*') {
                row2_chips.push_back(i); // Chips in row 2
            }
        }

        // If there's only one chip across both rows, no moves are required
        if (row1_chips.size() + row2_chips.size() == 1) {
            cout << 0 << endl;
        } else {
            // Calculate minimum moves for this test case
            cout << calculateMoves(row1_chips, row2_chips) << endl;
        }
    }

    return 0;
}
