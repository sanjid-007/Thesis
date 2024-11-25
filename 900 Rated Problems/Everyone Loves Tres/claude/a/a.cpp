#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solve(int n) {
    // Base cases from the examples
    if (n == 1) return "-1";  // No single digit works
    if (n == 2) return "66";  // Smallest possible 2-digit number
    if (n == 3) return "-1";  // No 3-digit number works

    // For n ≥ 4, we can construct numbers based on patterns
    // Start with the smallest working number for n=4: "3366"
    if (n == 4) return "3366";
    
    // For n > 4, we can construct numbers following the pattern
    // Observe that "36366" works for n=5
    if (n == 5) return "36366";
    
    // For n > 5, we can insert '3's after the first '3'
    // Example: n=7 -> "3336366"
    string result = "3";
    // Add (n-5) '3's
    for (int i = 0; i < n-5; i++) {
        result += "3";
    }
    result += "6366";
    
    return result;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    
    return 0;
}
