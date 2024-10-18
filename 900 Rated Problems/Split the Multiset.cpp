#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // Faster I/O
    cin.tie(0); // Disable flushing of output buffer after every output
    
    int t;
    cin >> t; // Number of test cases
    
    while (t--) {
        int n, k;
        cin >> n >> k; // Input n and k for this test case

        int operations = 0; // Count the number of operations
        queue<int> q;
        q.push(n); // Start with the multiset containing only {n}

        // BFS or greedy splitting approach
        while (!q.empty()) {
            int current = q.front(); // Get the current element from the queue
            q.pop(); // Remove the element from the queue

            if (current == 1) {
                continue; // If current element is 1, no further splitting is needed
            }

            operations++; // This counts as one operation

            if (current <= k) {
                // If current is less than or equal to k, we can split it directly into 1's
                // This requires current - 1 splits to make all of them 1's
                for (int i = 1; i < current; i++) {
                    q.push(1); // Push the necessary 1's into the queue
                }
            } else {
                // Split the current element into k parts
                // We will split current into as equal parts as possible
                int part_size = current / k;
                int remainder = current % k;

                for (int i = 0; i < k; i++) {
                    if (i < remainder) {
                        q.push(part_size + 1); // These parts are larger by 1
                    } else {
                        q.push(part_size); // These parts are smaller
                    }
                }
            }
        }

        cout << operations << "\n"; // Output the number of operations for this test case
    }

    return 0;
}
