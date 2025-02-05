#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans, prev, occ;
        prev = nums[0];
        ans = 1;
        occ = 1;
        for (int i = 1; i < static_cast<int>(nums.size()); i++) {
            if (nums[i] != prev) {
                prev = nums[i];
                occ = 1;
                ans++;
            } else {
                occ++;
                if (occ <= 2) {
                    ans++;
                } else {
                    nums[i] = 20000;
                }
            }
        }

        sort(nums.begin(), nums.end());
        return ans;
    }
};