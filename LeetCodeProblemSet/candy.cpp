#include <bits/stdc++.h>

using namespace std;

int pa(int n) {
    double a = (double(n))/2;
    double b = a * (double(n)+1);
    return int(b);
}

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = static_cast<int>(ratings.size());
        if (n == 1) { return 1;}
        vector<int> seq;

        int min = 20000, min_index;
        for (int i = 0; i < n; i++) {
            seq.push_back(1);
        }
        
        int incr = 0;

        int l;
        for (int i = 1; i < n; i++) {
            l = i -1;
            // Crescente
            if (ratings[l] < ratings[i]) {
                seq[i] = seq[l]+1;
            }
        }
        cout << "Crescente:"<< endl;
        for (int i = 0; i < n; i++) {
            cout << seq[i] << " ";
        }
        cout << endl;
        for (int i = n-1; i >= 1; i--) {
            l = i - 1;
            // Decrescente
            if (ratings[l] > ratings[i]) {
                if (seq[l] <= seq[i]+1){
                    seq[l] = seq[i]+1;
                }
            }
        }
        cout << endl;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cout << seq[i] << " ";
            sum += seq[i];
        }
        cout << endl;
        return sum;
    }
};


int main() {
    Solution sol = Solution();
    vector<int> r;
    int e;
    int ans;
    
    
    r = {0,1,2};
    e = 6; // 1 2 3
    ans = sol.candy(r);
    cout << "Expected: " << e << " -> Actual: " << endl << ans << endl;

    r = {3, 0, 0, 0, 1, 2, 5, 5, 1, 2, 3};
    e = 22; // 2, 1, 1, 1, 2, 3, 4, 2, 1, 2, 3
    ans = sol.candy(r);
    cout << "Expected: " << e << " -> Actual: " << endl << ans << endl;

    r = {0};
    e = 1; // 1
    ans = sol.candy(r);
    cout << "Expected: " << e << " -> Actual: " << endl << ans << endl;

    r = {1, 0};
    e = 3; // 2 1
    ans = sol.candy(r);
    cout << "Expected: " << e << " -> Actual: " << endl << ans << endl;

    r = {5, 5};
    e = 2; // 1 1
    ans = sol.candy(r);
    cout << "Expected: " << e << " -> Actual: " << endl << ans << endl;

    r = {2,1,0};
    e = 6; // 3 2 1
    ans = sol.candy(r);
    cout << "-------Expected: " << e << " -> Actual: " << endl << ans << endl;

    r = {1,0,2};
    e = 5; // 2 1 2
    ans = sol.candy(r);
    cout << "Expected: " << e << " -> Actual: " << endl << ans << endl;
    
    r = {1,2,2};
    e = 4; // 1 2 1 
    ans = sol.candy(r);
    cout << "Expected: " << e << " -> Actual: " << endl << ans << endl;

    r = {1, 0, 1, 1, 1, 1, 0};
    e = 10; // 2 1 2 1 1 2 1 
    ans = sol.candy(r);
    cout << "Expected: " << e << " -> Actual: " << endl << ans << endl;


    r = {2, 3, 0, 0, 0, 1, 2, 5, 5, 5, 4, 2, 3, 3, 2};
    e = 27; //  
    ans = sol.candy(r);
    cout << "Expected: " << e << " -> Actual: " << endl << ans << endl;

    r = {1,3,4,5,2};
    e = 11; // 1 2 3 4 1  
    ans = sol.candy(r);
    cout << "Expected: " << e << " -> Actual: " << endl << ans << endl;

}