#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

// Structure to represent a point
struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
    
    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

bool canMeet(int n, int a, int b, const string& s) {
    // Calculate net movement after one complete sequence
    int dx = 0, dy = 0;
    for (char c : s) {
        if (c == 'N') dy++;
        else if (c == 'S') dy--;
        else if (c == 'E') dx++;
        else dx--;  // W
    }
    
    // Current position
    int x = 0, y = 0;
    
    // Store visited positions after complete sequences
    set<Point> visited;
    visited.insert(Point(x, y));
    
    // Check each point in the first sequence
    for (int i = 0; i < n; i++) {
        if (s[i] == 'N') y++;
        else if (s[i] == 'S') y--;
        else if (s[i] == 'E') x++;
        else x--;  // W
        
        // Check if we've reached the Queen
        if (x == a && y == b) return true;
    }
    
    // If no net movement, and we haven't found the Queen yet, we never will
    if (dx == 0 && dy == 0) return false;
    
    // Maximum reasonable cycles to check
    // Since coordinates are ≤ 10, if we haven't reached in 50 cycles, we never will
    const int MAX_CYCLES = 50;
    
    for (int cycle = 1; cycle <= MAX_CYCLES; cycle++) {
        x += dx;
        y += dy;
        
        // Check if this position matches the Queen's
        if (x == a && y == b) return true;
        
        // If we've seen this position before, we're in a loop that doesn't include the Queen
        Point current(x, y);
        if (visited.count(current)) return false;
        visited.insert(current);
        
        // Optional optimization: If we're too far away with no way to come back
        if (dx >= 0 && x > a && dy >= 0 && y > b) return false;
        if (dx <= 0 && x < a && dy <= 0 && y < b) return false;
    }
    
    // If we haven't found the Queen after MAX_CYCLES, we never will
    return false;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, a, b;
        string s;
        cin >> n >> a >> b;
        cin >> s;
        
        cout << (canMeet(n, a, b, s) ? "YES" : "NO") << endl;
    }
    
    return 0;
}
