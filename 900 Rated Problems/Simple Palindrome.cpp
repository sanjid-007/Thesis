#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    string vowels = "uoiea";  // Using this pattern as shown in the example
    
    while (t--) {
        int n;
        cin >> n;
        
        string result = "";
        for (int i = 0; i < n; i++) {
            result += vowels[i % 5];  // Still use cyclic access, but based on "uoiea"
        }
        
        cout << result << endl;
    }
    
    return 0;
}
