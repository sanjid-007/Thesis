#include <bits/stdc++.h>
using namespace std;

// Function to check if number exists in a vector starting from a given index
int checkNumber(const vector<int>& arr, int start, int size) {
    if (start + 7 >= size) return 0;
    
    string num;
    for(int i = start; i < start + 8; i++) {
        num += to_string(arr[i]);
    }
    return (num == "15431543") ? 1 : 0;
}

// Function to extract layer into a single vector in clockwise order
vector<int> getLayer(vector<vector<int>>& matrix, int startRow, int startCol, int rows, int cols) {
    vector<int> layer;
    
    // Top row
    for(int j = startCol; j < cols; j++)
        layer.push_back(matrix[startRow][j]);
    
    // Right column
    for(int i = startRow + 1; i < rows; i++)
        layer.push_back(matrix[i][cols-1]);
    
    // Bottom row (if exists)
    if(rows - 1 > startRow) {
        for(int j = cols - 2; j >= startCol; j--)
            layer.push_back(matrix[rows-1][j]);
    }
    
    // Left column (if exists)
    if(cols - 1 > startCol) {
        for(int i = rows - 2; i > startRow; i--)
            layer.push_back(matrix[i][startCol]);
    }
    
    return layer;
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    // Read the matrix
    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for(int j = 0; j < m; j++) {
            matrix[i][j] = row[j] - '0';
        }
    }
    
    int answer = 0;
    int startRow = 0, startCol = 0;
    int rows = n, cols = m;
    
    // Process each layer
    while(startRow < rows && startCol < cols) {
        // Get current layer in clockwise order
        vector<int> currentLayer = getLayer(matrix, startRow, startCol, rows, cols);
        
        // Check for the number in the current layer
        for(int i = 0; i < currentLayer.size(); i++) {
            answer += checkNumber(currentLayer, i, currentLayer.size());
        }
        
        // Move to inner layer
        startRow++; startCol++;
        rows--; cols--;
    }
    
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
