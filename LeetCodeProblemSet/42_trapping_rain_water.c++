#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = static_cast<int>(height.size());
        // current Highest peak (chp)
        // if chp < current_high
        for (int i = 0; i < n; i++) {
            
        }
    }
};

int main() {
    Solution sol = Solution();
    vector<int> height;
    int e;
    int ans;

    height = {0,1,0,2,1,0,1,3,2,1,2,1};
    e = 6;
    ans = sol.trap(height);
    cout << "Expected: " << e << "Answer: " << ans << endl;

    height = {4,2,0,3,2,5};
    e = 9;
    ans = sol.trap(height);
    cout << "Expected: " << e << "Answer: " << ans << endl;
}