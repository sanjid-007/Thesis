#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to check if a melody is perfect
bool isPerfectMelody(const vector<int>& melody) {
    int n = melody.size();
    for (int i = 1; i < n; ++i) {
        int interval = abs(melody[i] - melody[i - 1]);
        if (interval != 5 && interval != 7) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t; // Number of melodies
    while (t--) {
        int n;
        cin >> n; // Number of notes in the melody
        vector<int> melody(n);
        for (int i = 0; i < n; ++i) {
            cin >> melody[i];
        }

        // Output whether the melody is perfect or not
        if (isPerfectMelody(melody)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
