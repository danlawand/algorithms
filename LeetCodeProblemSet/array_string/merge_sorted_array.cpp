#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // O((n+m) log(n+m))
    void merge(vector<int>& n1, int n, vector<int>& n2, int m) {
        // O(n+m)
        for (int i = n; i < n+m; i++) {
            n1[i] = n2[i-n];
        }

        // O((n+m)log(n+m))
        sort(n1.begin(), n1.end());
    }

    void Optm(vector<int>& n1, int n, vector<int>& n2, int m) {
        // O(n+m)
        vector<int> aux(n1);
        int p1 = 0, p2 = 0;
        for (int i = 0; i < n+m; i++) {
            if (p1 >= n) {
                n1[i] = n2[p2];
                p2++;
                continue;
            }
            if (p2 >= m) {
                n1[i] = aux[p1];
                p1++;
                continue;
            }
            if (aux[p1] <= n2[p2]) {
                n1[i] = aux[p1];
                p1++;
            } else {
                n1[i] = n2[p2];
                p2++;
            }
        }
    }
};

int main() {
    Solution sol = Solution();
    vector<int> n1 = {1, 2, 3, 3, 0, 0, 0};
    int n = 4;
    vector<int> n2 = {4, 5, 6};
    int m = 3;
    sol.Optm(n1, n, n2, m);
    for (int i = 0; i < n+m; i++) {
        cout << n1[i] << " ";
    }
    cout << endl;
}