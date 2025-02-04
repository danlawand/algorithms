#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<int> v(n, 1);
        vector<int> u(n, 1);
        int i = 1;
        v[i] = nums[i-1];
        i++;
        int j = n-2;
        u[j] = nums[j+1];
        j--;
        while (j >= 0 && i < n) {
            v[i] = v[i-1] * nums[i-1];
            u[j] = u[j+1] *nums[j+1];
            i++;
            j--;
        }

        vector<int> ans(n, 0);
        for (int k = 0; k < n; k++) {
            ans[k] = v[k]*u[k];
        }
        return ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> v = {1,2,3,4};
    vector<int> ans = sol.productExceptSelf(v);
    for (int i = 0; i < 4; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}