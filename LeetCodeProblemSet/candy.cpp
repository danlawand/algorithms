#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int candy(vector<int>& r) {
        int n = static_cast<int>(r.size());
        vector<int> ca;
        int c = 0;
        int mudanca = 0;
        int cresc = 0;
        int n_passo = 0;

        for (int i = 0; i < n; i++) {
            ca.push_back(0);
        }

        for (int i = 0; i < n; i++) {
            
            if (r[i] > r[i+1]) {
                if (cresc == -1) {
                    // Está decrescente
                    n_passo++;
                } else {
                    c = (((n_passo + 1) / 2) * (n_passo+2));
                    n_passo = 0;
                    cresc = -1;
                }
            }

            if (r[i] < r[i+1]) {
                if (cresc == 1) {
                    // Está crescente
                    n_passo++;
                } else {
                    c = (((n_passo + 1) / 2) * (n_passo+2));
                    n_passo = 0;
                    cresc = 1;
                }
            }

            if (r[i] == r[i+1]) {
                if (cresc == 0) {
                    // Está crescente
                    n_passo++;
                } else {
                    c = (((n_passo + 1) / 2) * (n_passo+2));
                    n_passo = 0;
                    cresc = 0;
                }
            }
        }

        // while (passo < n) {
        //     e = r[passo-1];
        //     m = r[passo];
        //     d = r[passo+1];

        //     if (e > m && m > d) {
        //         cresc = 1;
        //     }
        //     if (e < m && m < d) {
        //         cresc = -1;
        //         c = c + 
        //     }
        // }

        for (int i = 1; i < n-1; i++) {
            e = r[i-1];
            m = r[i];
            d = r[i+1];

            if (e > m && m > d) {
                cresc = 1;
                ca[i-1] = ca[i] + 1;
                ca[i] = 
                ca[i+1] = ca[i] - 1;
            }
            if (e < m && m < d) {
                cresc = -1;
                ca[i] = ca[i-1] + 1;
                ca[i+1] = ca[i] + 1;
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