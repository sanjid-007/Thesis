
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int n, m;
vector<vector<int>> canvas;
vector<vector<int>> result;
vector<tuple<int, int, int>> operations;

// Function to check if a 2x2 block can be painted with a single color
bool can_paint(int i, int j) {
    if (i < 1 || j < 1 || i >= n || j >= m) return false;
    int color = canvas[i][j];
    if (canvas[i][j+1] == color && canvas[i+1][j] == color && canvas[i+1][j+1] == color) {
        return true;
    }
    return false;
}

// Function to apply an operation and paint the result grid
void apply_operation(int i, int j, int color) {
    result[i][j] = result[i][j+1] = result[i+1][j] = result[i+1][j+1] = color;
}

int main() {
    cin >> n >> m;
    canvas.resize(n, vector<int>(m));
    result.assign(n, vector<int>(m, 0)); // Empty canvas (unpainted)

    // Read input
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> canvas[i][j];
        }
    }

    // Traverse the grid from bottom-right to top-left
    for (int i = n-2; i >= 0; --i) {
        for (int j = m-2; j >= 0; --j) {
            if (can_paint(i, j)) {
                int color = canvas[i][j];  // All four cells have the same color
                operations.push_back(make_tuple(i+1, j+1, color));  // Store the operation (1-indexed)
                apply_operation(i, j, color);  // Paint the result grid
            }
        }
    }

    // Check if the result grid matches the original canvas
    if (result == canvas) {
        cout << operations.size() << endl;
        for (auto op : operations) {
            int x, y, c;
            tie(x, y, c) = op;
            cout << x << " " << y << " " << c << endl;
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}
