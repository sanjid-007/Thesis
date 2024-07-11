#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        // Store in an array and sort to always start with the smallest values
        int nums[3] = {a, b, c};
        sort(nums, nums + 3);

        int increments = 5;

        // Distribute the increments
        while (increments > 0) {
            if (nums[0] <= nums[1] && nums[0] <= nums[2]) {
                nums[0]++;
            } else if (nums[1] <= nums[0] && nums[1] <= nums[2]) {
                nums[1]++;
            } else {
                nums[2]++;
            }
            increments--;
        }

        // Calculate the product after all increments
        int result = nums[0] * nums[1] * nums[2];
        cout << result << endl;
    }
    return 0;
}
