#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        int n = s.length();
        unordered_map<char, int> dict;
        dict['I'] = 1;
        dict['V'] = 5;
        dict['X'] = 10; 
        dict['L'] = 50;
        dict['C'] = 100;
        dict['D'] = 500;
        dict['M'] = 1000;
        
        if (n == 1) {
            return dict[s[0]];
        }

        for (int i = 0; i < s.size() - 1; i++) {
            if (dict[s[i]] < dict[s[i + 1]]) {
                sum -= dict[s[i]];
            } else {
                sum += dict[s[i]];
            }
        }

        return sum + dict[s[s.size() - 1]];
    }
};


int main() {
    Solution sol = Solution();
    string s = "MCMXCIV";
    int ans = sol.romanToInt(s);
    cout << s <<": " << ans << endl; 
}