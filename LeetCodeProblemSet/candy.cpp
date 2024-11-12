#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int candy(vector<int>& r) {
        int n = static_cast<int>(r.size());
        int c = 0, ant = 0, q = 0;
        for (int i = 1; i < n-1; i++) {
            if (r[i] == r[i-1]) { 
                c++; 
                ant = r[i];
                q = 1;
            }
            else if (r[i] < r[i-1]) {
                if (r[i] > ant) {
                    q++;
                    c += q;
                }
                else {

                }
            }
            else {
                c
            }


        }
    }
};


int main() {
    Solution sol = Solution();
    vector<int> r = {1,0,2};
    int e = 5; // 2 1 2
    cout << "Expected: " << e << " -> Actual: " << sol.candy(r) << endl;
    
    r = {1,2,2};
    e = 4; // 1 2 1 
    cout << "Expected: " << e << " -> Actual: " << sol.candy(r) << endl;

    r = {1, 0, 1, 1, 1, 1, 0};
    e = 10; // 2 1 2 1 1 2 1 
    cout << "Expected: " << e << " -> Actual: " << sol.candy(r) << endl;

}