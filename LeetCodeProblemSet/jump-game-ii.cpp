#include <bits/stdc++.h>
using namespace std;

vector<int> visited;
vector<int> range;
size_t n ;
int min_jumps, pos;

class Solution {
public:
    void pulo(vector<int>& nums, int salto, int current_jumps) {
        current_jumps++;
        if (pos+salto >= n-1) {
            min_jumps = (current_jumps < min_jumps) ? current_jumps : min_jumps;
            return;
        }
        int current_pos = pos;
        for (int i = salto; i > 0; i--) {
            pos = current_pos + i;
            if (current_jumps < range[pos]) {
                range[pos] = current_jumps;
                pulo(nums, nums[pos], current_jumps);
            }
        }
        return;
    }

/*
//       0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
    v = {9,8,2,2,0,2,2,0,4,1, 5, 7, 9, 6, 6, 0, 6, 5, 0, 5};

    0 9 10 15
    0 9 10 14 19
    0 9 10 13 19
    0 9 10 12 19
    0 9 10 11 18
    0 9 

    0 9 10
    0 8 12

    correto
    0 8 12 19


    */
    int jump_optimized(vector<int>& nums) {
        n = nums.size();
        if (n == 1) return 0;
        int near, far, farthest;
        near = 0;
        far = 0;
        int jumps = 0;
        while (far < n-1) {
            farthest = 0;
            for (int i = near; i < far+1; i++) {
                farthest = (farthest >= nums[i]+i) ? farthest : nums[i]+i;
            }
            near = far + 1;
            far = farthest;
            jumps++;
        }
        return jumps;
    }

    int jump(vector<int>& nums) {
        n = nums.size();
        if (n == 1) return 0;
        int current_jumps = 0;
        min_jumps = n+1;
        pos = 0;
        visited.resize(n);
        range.resize(n);
        for (int i = 0; i < n; i++) {
            visited[i] = 0;
            range[i] = n+1;
        }
        pulo(nums, nums[0], current_jumps);
        return min_jumps;
    }
};

/*
0 1 2 3
2 1 1 8

pos = 0
salto = 2
current_jumps = 1

    salto-- 
    salto = 1

    pos = 1
    salto = nums[pos] = 1
    current_jumps++ => 2

    pos = 2
    salto = nums[pos] = 1
    current_jumps++ = 3

    pos = 3
    salto = nums[pos] = 8

    if (pos >= n-1) 
    min_jumps = (current_jumps < min_jumps) ? current_jumps : min_jumps
    return;


pos = 2
salto = nums[pos] = 1
current_jumps++ => 2

salto --
if (salto <= 0)
    return;

pos = 3
salto = nums[pos] = 8
if (pos >= n-1) 
    min_jumps = (current_jumps < min_jumps) ? current_jumps : min_jumps
    return;

*/

int main() {
    Solution solution;
    vector<int> v = {2,3,1,1,4};
    int i = 0;
    cout << "Teste: " << i << endl;
    for (const int& number : v) {
        cout << number << " ";
    }
    cout << endl;
    cout << solution.jump(v) << endl;
    
    i++;
    v = {3,0,1,4};
    cout << "Teste: " << i << endl;
    for (const int& number : v) {
        cout << number << " ";
    }
    cout << endl;
    cout << solution.jump(v) << endl;

    i++;
    v = {1,2,1,4};
    cout << "Teste: " << i << endl;
    for (const int& number : v) {
        cout << number << " ";
    }
    cout << endl;
    cout << solution.jump(v) << endl;

    i++;
    v = {1};
    cout << "Teste: " << i << endl;
    for (const int& number : v) {
        cout << number << " ";
    }
    cout << endl;
    cout << solution.jump(v) << endl;

    i++;
    v = {5, 9};
    cout << "Teste: " << i << endl;
    for (const int& number : v) {
        cout << number << " ";
    }
    cout << endl;
    cout << solution.jump(v) << endl;

    i++;
    v = {1, 1, 1, 1, 1, 9};
    cout << "Teste: " << i << endl;
    for (const int& number : v) {
        cout << number << " ";
    }
    cout << endl;
    cout << solution.jump(v) << endl;

    i++;
    v = {2,0,1,4};
    cout << "Teste: " << i << endl;
    for (const int& number : v) {
        cout << number << " ";
    }
    cout << endl;
    cout << solution.jump(v) << endl;

    i++;
    v = {5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5};
    cout << "Teste: " << i << endl;
    for (const int& number : v) {
        cout << number << " ";
    }
    cout << endl;
    cout << solution.jump(v) << endl;

    i++;
//       0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
    v = {9,8,2,2,0,2,2,0,4,1, 5, 7, 9, 6, 6, 0, 6, 5, 0, 5};

    /*
    0 9 10 15
    0 9 10 14 20
    
    */



    cout << "Teste: " << i << endl;
    for (const int& number : v) {
        cout << number << " ";
    }
    cout << endl;
    cout << solution.jump(v) << endl;

}