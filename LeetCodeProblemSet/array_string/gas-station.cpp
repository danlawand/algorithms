#include <bits/stdc++.h>

using namespace std;

class Solution {
public: 
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = static_cast<int>(gas.size());
        int total_surplus = 0; // it will give us a difference b/w gas & cost
        int surplus = 0; // our tank
        int start = 0; // and the index of gas station
        
        for(int i = 0; i < n; i++){
            total_surplus += gas[i] - cost[i];
            surplus += gas[i] - cost[i];
            if(surplus < 0){ // if the tank goes -ve
                surplus = 0; // reset our tank
                start = i + 1; // and update the stating gas station
            }
        }
        return (total_surplus < 0) ? -1 : start;
    }
};

/*
// class Solution {
// public: 
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n = static_cast<int>(gas.size());
//         int flag;
//         if (n == 1) {
//             if (gas[0] - cost[0] >= 0) {
//                 return 0;
//             }
//             else {
//                 return -1;
//             }
//         }

//         vector<int> diff(n);
//         vector<int> cumulate(n, 0);

//         diff[0] = (gas[0] - cost[0]);
//         cumulate[0] = diff[0];
//         for (int j = 1; j < n; j++) {
//             diff[j] = (gas[j] - cost[j]);
//             cumulate[j] = diff[j] + cumulate[j-1];
//         }
        
//         if (cumulate[n-1] < 0) {
//             return -1;
//         }

//         int aux = 0;
//         for (int j = 0; j < n; j++) {
//             if (diff[j] >= 0 && gas[j] > 0) {
//                 aux = diff[j];
//                 flag = 1;
//                 for (int i = 1; i < n; i++) {
//                     aux += diff[(i+j)%n];
//                     if (aux < 0) {
//                         flag = 0;
//                         break;
//                     }
//                 }
//                 if (flag) {
//                     return j;
//                 }
//             }
//         }

//         return -1;
//     }
// };

*/


int main() {
    Solution sol = Solution();
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    // vector<int> gas = {4,5,2,6,5,3};
    // vector<int> cost = {3,2,7,3,2,9};
    int ans = sol.canCompleteCircuit(gas, cost);
    cout << "Ans: "<< ans << endl;

}


