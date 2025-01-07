#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int candy(vector<int>& r) {
        int n = static_cast<int>(r.size());
        vector<int> ca;
        int c = 0, ant = 0, q = 0;
        int i = 0;
        int e, m, d;
        int passo = 1;

        for (i = 1; i < n-1; i++) {
            e = r[i-1];
            m = r[i];
            d = r[i+1];

            if (e > m && m > d) {
                
            }

            // if (r[i] > r[i+1]) {
            //     ca[i]++;
            // } else if (r[i] < r[i+1]) {
            //     if (ca[i] >= ca[i+1]) {
            //         ca[i+1] = ca[i] + 1;
            //     }
            // }
        }
        return c;
    }
};


int main() {
    Solution sol = Solution();
    vector<int> r = {0,1,2};
    int e = 6; // 1 2 3
    cout << "Expected: " << e << " -> Actual: " << sol.candy(r) << endl;

    r = {0};
    e = 1; // 1
    cout << "Expected: " << e << " -> Actual: " << sol.candy(r) << endl;

    r = {1, 0};
    e = 3; // 2 1
    cout << "Expected: " << e << " -> Actual: " << sol.candy(r) << endl;

    r = {5, 5};
    e = 2; // 1 1
    cout << "Expected: " << e << " -> Actual: " << sol.candy(r) << endl;

    r = {2,1,0};
    e = 6; // 3 2 1
    cout << "Expected: " << e << " -> Actual: " << sol.candy(r) << endl;

    r = {1,0,2};
    e = 5; // 2 1 2
    cout << "Expected: " << e << " -> Actual: " << sol.candy(r) << endl;
    
    r = {1,2,2};
    e = 4; // 1 2 1 
    cout << "Expected: " << e << " -> Actual: " << sol.candy(r) << endl;

    r = {1, 0, 1, 1, 1, 1, 0};
    e = 10; // 2 1 2 1 1 2 1 
    cout << "Expected: " << e << " -> Actual: " << sol.candy(r) << endl;

}