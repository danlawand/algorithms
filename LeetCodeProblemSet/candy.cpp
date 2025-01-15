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

    int __candy(vector<int>& r) {
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

    int candy(vector<int>& ratings) {
        int n = static_cast<int>(ratings.size());
        if (n == 1) { return 1;}
        vector<int> seq;

        // int min = 20000, min_index;
        // for (int i = 0; i < n; i++) {
        //     seq.push_back(1);
        //     // Find the minimum values indexes
        //     if (ratings[i] <= min) {
        //         min = ratings[i];
        //         min_index = i;
        //     }
        // }
        int l, r;
        int sum = 0;
        int incr;

        if (ratings[0] > ratings[1]) {
            incr = 1;
        } else if (ratings[0] < ratings[1]) {
            incr = -1;
        } else {
            incr = 0;
        }

        int seq_ele = 0;
        for (int s = 0; s < n; s++) {
            l = s - 1;
            r = s + 1;

            if (l < 0) {
                if (ratings[s] > ratings[r]) {
                    incr = -1;
                    seq_ele++;
                } else if (ratings[s] < ratings[r]) {
                    incr = 1;
                    seq_ele++;
                } else {
                    incr = 0;
                    seq_ele++;
                }
            } else if (r >= n) {
                if (ratings[l] > ratings[s]) {
                    if (incr == -1) {
                        seq_ele++;
                    } else if (incr == 1) {
                        // Encerra a contagem no elemento s fazendo a PA com razão 1
                        // E adiciona +1 (PA de apenas o elemento atual)
                    } else{
                        // Encerra a contagem no elemento l, fazendo a PA com razão seria 0
                        // E finaliza com a PA de (l, s)
                    }
                    incr = -1;
                } else if (ratings[l] < ratings[s]) {
                    if (incr == -1) {
                        // Encerra a contagem no elemento s fazendo a PA com razão 1
                        // E adiciona +2 (pq sei que a seq anterior é decrescent, portanto l = 1) 
                    } else if (incr == 1) {
                        seq_ele++;
                    } else{
                        // Isso está certo? 1 2 2(l) 3(s) != 2 2 2(l) 3(s)
                        // Encerra a contagem no elemento l, fazendo a PA com razão seria 0
                        // E finaliza com a PA de (l, s)
                    }
                    incr = 1;
                } else {
                    incr = 0;
                    seq_ele++;
                }
            } else {

            }

        }
        
        while (l >= 0 || r < n) {
            l = start_l - 1;
            r = start_r + 1;
            if (l >=0) {
                if (ratings[l] > ratings[start_l]) {
                    seq[l] = seq[start_l]+1;
                } else if (ratings[l] < ratings[start_l]) {
                    seq[l] = seq[start_l]-1;
                } else {
                    if (l-1 >= 0) {
                        if (ratings[l] > ratings[l-1]) {
                            seq[l] = 0;
                        } else {
                            seq[l] = 1;
                        }
                }
            }

            if (r < n) {
                if (ratings[r] > ratings[start_r]) {
                    seq[r] = seq[start_r]+1;
                } else if (ratings[r] < ratings[start_r]) {
                    seq[r] = seq[start_r]-1;
                } else {
                    seq[r] = 1;
                }
            }

            start_r = r;
            start_l = l; 
        }
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

    // r = {1, 0, 1, 1, 1, 1, 0};
    // e = 10; // 2 1 2 1 1 2 1 
    // cout << "Expected: " << e << " -> Actual: " << endl << sol.candy(r) << endl;


    r = {2, 3, 0, 0, 0, 1, 2, 5, 5, 5, 4, 2, 3, 3, 2};
    e = 27; //  
    cout << "Expected: " << e << " -> Actual: " << endl << sol.candy(r) << endl;

}