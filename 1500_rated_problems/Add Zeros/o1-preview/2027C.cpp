#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cstdint>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int64_t> a(n + 1);
        std::map<int64_t, std::queue<int>> sum_map;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            int64_t sum_i = a[i] + i;
            sum_map[sum_i].push(i);
        }
        int64_t req = n + 1;
        int64_t total_delta = 0;
        while (true) {
            auto it = sum_map.find(req);
            if (it == sum_map.end()) break;
            int i = it->second.front();
            it->second.pop();
            if (it->second.empty()) {
                sum_map.erase(it);
            }
            int64_t delta = i - 1;
            total_delta += delta;
            req += delta;
        }
        int64_t max_length = n + total_delta;
        std::cout << max_length << '\n';
    }
    return 0;
}
