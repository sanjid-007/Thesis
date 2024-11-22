#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 501;

string answers[MAX_N];

void precompute() {
    for (int n = 1; n <= 500; ++n) {
        // Initialize BFS
        queue<tuple<int, int, int, string>> q;
        // sum_mod3, diff_mod11, pos, number
        bool visited[3][11][MAX_N] = {{{false}}};

        q.push(make_tuple(0, 0, 0, ""));
        visited[0][0][0] = true;

        string solution = "-1";

        while (!q.empty()) {
            // Explicitly specify the type of `current`
            tuple<int, int, int, string> current = q.front();
            q.pop();

            // Unpack `current`
            int sum_mod3 = get<0>(current);
            int diff_mod11 = get<1>(current);
            int pos = get<2>(current);
            string number = get<3>(current);

            if (pos == n - 1) {
                // Fix last digit to '6'
                int digit_value = 6;
                int sum_mod3_new = (sum_mod3 + digit_value) % 3;
                int diff_mod11_new;
                if ((pos + 1) % 2 == 1) { // Next position is odd
                    diff_mod11_new = (diff_mod11 + digit_value) % 11;
                } else {
                    diff_mod11_new = (diff_mod11 - digit_value + 11) % 11;
                }

                if (sum_mod3_new == 0 && diff_mod11_new == 0) {
                    solution = number + '6';
                    break;
                }
                continue;
            }

            // Try adding '3' and '6'
            for (char digit_char : {'3', '6'}) {
                int digit_value = digit_char - '0';
                int sum_mod3_new = (sum_mod3 + digit_value) % 3;
                int diff_mod11_new;
                if ((pos + 1) % 2 == 1) { // Next position is odd
                    diff_mod11_new = (diff_mod11 + digit_value) % 11;
                } else {
                    diff_mod11_new = (diff_mod11 - digit_value + 11) % 11;
                }

                if (!visited[sum_mod3_new][diff_mod11_new][pos + 1]) {
                    visited[sum_mod3_new][diff_mod11_new][pos + 1] = true;
                    q.push(make_tuple(sum_mod3_new, diff_mod11_new, pos + 1, number + digit_char));
                }
            }
        }
        answers[n] = solution;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << answers[n] << '\n';
    }

    return 0;
}
