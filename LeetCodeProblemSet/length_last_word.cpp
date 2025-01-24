#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int ans = 0;
        bool space = 0;
        if (s[n-1] == ' ') {
            space = 1;
        }
        for(int i = n-1; i>=0; i--) {
            if (s[i] == ' ') {
                if (space == 0) {return ans;}
            } else {
                space = 0;
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    string s;
    Solution sol = Solution();

    s = "ola meu amig0o";
    cout << sol.lengthOfLastWord(s) << endl;

    s = "   fly me   to   the moon  ";
    cout << sol.lengthOfLastWord(s) << endl;
}