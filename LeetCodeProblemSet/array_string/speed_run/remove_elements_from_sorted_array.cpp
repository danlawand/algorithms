#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    // Time: O(n)
    // Auxiliary Memory: O(unique_numbers)
    int removeDuplicates(vector<int>& nums) {
        int prev,ans = 1;
        vector<int> unique;
        prev = nums[0];
        unique.push_back(nums[0]);
        for (int i = 1; i < static_cast<int>(nums.size()); i++) {
            if (prev != nums[i]) {
                ans++;
                prev = nums[i];
                unique.push_back(nums[i]);
            }
        }
        for (int i = 0; i < ans; i++) {
            nums[i] = unique[i];
        }
        return ans;
    }
};
