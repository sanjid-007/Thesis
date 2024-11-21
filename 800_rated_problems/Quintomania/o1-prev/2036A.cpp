#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int t; // Number of melodies
    cin >> t;
    while(t--) {
        int n; // Number of notes in the melody
        cin >> n;
        vector<int> notes(n);
        for(int i = 0; i < n; i++) {
            cin >> notes[i];
        }
        bool perfect = true; // Flag to determine if the melody is perfect
        for(int i = 0; i < n - 1; i++) {
            int diff = abs(notes[i+1] - notes[i]);
            if(diff != 5 && diff != 7) {
                perfect = false;
                break; // No need to check further if one interval is incorrect
            }
        }
        if(perfect) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
