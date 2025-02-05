#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int remove(vector<int>&nums, int val) {
        int occ = 0;
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            if (nums[i] == val) {
                nums[i] = -1;
            } else {
                occ++;
            }
        }
        sort(nums.begin(), nums.end(), greater<>());
        return occ;
    }
};


int main() {
    Solution sol = Solution();
    vector<int> nums = {0, 1, 2, 2, 4, 5, 6, 2};
    int val = 2;
    int ans = sol.remove(nums, val);
    cout << "Number of ints diff than: " << val << ": "<< ans<<endl;
    for (int i = 0; i < ans; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}