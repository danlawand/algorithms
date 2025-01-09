#include <bits/stdc++.h>

using namespace std;

int pa(int n) {
    double a = (double(n))/2;
    double b = a * (double(n)+1);
    return int(b);
}

class Solution {
public:
    int _candy(vector<int>& r) {
        int n = static_cast<int>(r.size());
        vector<int> ca;
        int sum = 0;
        int c = 0;
        int n_passo = 0;
        int to_remove = 0;

        if (r[0] > r[1]) {
            c = -1;
        } else if (r[0] < r[1]) {
            c = 1;
        } else {
            c = 0;
        }
        n_passo=2;

        for (int i = 1; i < n; i++) {
            if (r[i] > r[i+1]) {
                if (c == -1) {
                    n_passo++;
                } else if (c == 0) {
                    if (n_passo > 1) {
                        cout << "Add_1: " << n_passo-1 << endl;
                        sum += n_passo-1;
                    }
                    c = -1;
                    n_passo = 2;
                } else {
                    to_remove++;                    
                    cout << "Add_2: " << pa(n_passo) << endl;
                    sum += pa(n_passo);
                    n_passo = 1;
                    c = -1;
                }
            }

            if (r[i] < r[i+1]) {
                if (c == 1) {
                    n_passo++;
                } else if (c == 0) {
                    if (n_passo > 1) {
                        cout << "Add_3: " << n_passo-1 << endl;
                        sum += n_passo-1;
                    }
                    c = 1;
                    n_passo = 2;
                } else {
                    to_remove++;
                    cout << "Add_4: " << pa(n_passo) << endl;
                    sum += pa(n_passo);
                    n_passo = 1;
                    c = 1;
                }
            }

            if (r[i] == r[i+1]) {
                if (c == 0) {
                    n_passo++;
                } else {
                    cout << "Add_5: " << pa(n_passo) << endl;
                    sum += pa(n_passo);
                    n_passo = 1;
                    c = 0;
                }
            }
        }

        if (c == 0) {
            sum += n_passo;
        } else {
            cout << "Add: " << pa(n_passo) << endl;
            sum += pa(n_passo);
        }
        cout << "Actual: " << sum << " - " << to_remove << " = " << sum-to_remove << endl;
        return sum-to_remove;
    }

    int candy(vector<int>& r) {
        int n = static_cast<int>(r.size());
        if (n == 1) { return 1;}
        vector<int> seq;
        
        int c;
        if (r[0] > r[1]) {
            c = -1;
        } else if (r[0] < r[1]) {
            c = 1;
        } else {
            c = 0;
        }
        seq.push_back(0);
        int cp = 0;
        for (int i = 1; i < n; i++) {
            // -1
            if (r[i] > r[i+1]) {
                if (c == 0) {
                    // fim da anterior é na anterior
                    seq.push_back(i-1);
                    // inicio da outra é agora
                    seq.push_back(i);
                }
                if (c == 1) {
                    // fim da anterior é agora
                    seq.push_back(i);
                    // inicio da outra é agora
                    if (i != n-1) {
                        seq.push_back(i);
                        cp++;
                    }
                }
                c = -1;
            }
            // 1 
            else if (r[i] < r[i+1]) {
                if (c == 0) {
                    // fim da anterior é agora
                    seq.push_back(i-1);
                    // inicio da outra é na próxima
                    seq.push_back(i);
                }
                if (c == -1) {
                    // fim da anterior é agora
                    seq.push_back(i);
                    // inicio da outra é agora
                    if (i != n-1) {
                        seq.push_back(i);
                        cp++;
                    }
                }
                c = 1;
            } 
            // 0
            else {
                if (c != 0) {
                    // fim
                    seq.push_back(i);
                    // inicio da outra
                    if (i != n-1) {seq.push_back(i+1);}
                }
                c = 0;
            }
        }
        cout << endl << "****" << endl;
        int sum = 0;
        int a, b;
        for (int i = 0; i < seq.size(); i+=2) {
            cout << "i: " << i << " i+1: " << i+1 << endl;
            cout << "seq[i]: " << seq[i] << " seq[i+1]: " << seq[i+1] << endl;
            a = seq[i+1];
            b = seq[i];
            if (r[a] == r[b]) {
                cout << "==> " << b-a+1 << endl;
                sum += b-a+1;
            } else {
                cout << "pa("<<a<<"-"<<b<<"+1): " << pa(a-b+1) << endl;
                sum += pa(a-b+1);
            }
        }
        cout << "With cp: " << sum << endl;
        sum -= cp;
        cout << "Total: " << sum << endl;
        cout << endl << "****" << endl;
        cout << endl << "----------------" << endl;
        for (int num : seq) {
            cout << num << " ";
        }
        cout << endl << "----------------" << endl;
        return sum;
    }

};


int main() {
    Solution sol = Solution();
    vector<int> r;
    int e;
    
    
    // r = {0,1,2};
    // e = 6; // 1 2 3
    // cout << "Expected: " << e << " -> Actual: " << endl << sol.candy(r) << endl;

    // r = {3, 0, 0, 0, 1, 2, 5, 5, 1, 2, 3};
    // e = 22; // 2, 1, 1, 1, 2, 3, 4, 2, 1, 2, 3
    // cout << "Expected: " << e << " -> Actual: " << endl << sol.candy(r) << endl;

//     r = {0};
//     e = 1; // 1
//     cout << "Expected: " << e << " -> Actual: " << endl << sol.candy(r) << endl;

//     r = {1, 0};
//     e = 3; // 2 1
//     cout << "Expected: " << e << " -> Actual: " << endl << sol.candy(r) << endl;

//     r = {5, 5};
//     e = 2; // 1 1
//     cout << "Expected: " << e << " -> Actual: " << endl << sol.candy(r) << endl;

//     r = {2,1,0};
//     e = 6; // 3 2 1
//     cout << "Expected: " << e << " -> Actual: " << endl << sol.candy(r) << endl;

//     r = {1,0,2};
//     e = 5; // 2 1 2
//     cout << "Expected: " << e << " -> Actual: " << endl << sol.candy(r) << endl;
    
//     r = {1,2,2};
//     e = 4; // 1 2 1 
//     cout << "Expected: " << e << " -> Actual: " << endl << sol.candy(r) << endl;

    r = {1, 0, 1, 1, 1, 1, 0};
    e = 10; // 2 1 2 1 1 2 1 
    cout << "Expected: " << e << " -> Actual: " << endl << sol.candy(r) << endl;

}