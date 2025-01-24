#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Time: O(n * min_str_size)
        // Additional Memory: O(1)
        int n = static_cast<int>(strs.size());
        int np, nl, nMin;

        string temp = "";
        string prefix = strs[0];

        for (int i = 1; i < n; i++) {
            nl = strs[i].length();
            np = prefix.length();
            nMin = min(np, nl);
            temp = "";
            for (int j = 0; j < nMin; j++) {
                if (prefix[j] == strs[i][j]) {
                    temp.push_back(prefix[j]);
                } else {
                    break;
                }
            }
            prefix = temp;
            if (prefix == "") {break;}
        }
        return prefix;
    }

    string optimLongestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        for (int i = 0; i < strs[0].size(); ++i) {
            for (int j = 1; j < n; ++j) {
                if (strs[j].size() <= i || strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

int main() {
    vector<string> strs = {"dog","racecar","car"};
    Solution s = Solution();

    cout << s.longestCommonPrefix(strs) << endl;

    strs = {"flower","flow","flight"};
    cout << s.longestCommonPrefix(strs) << endl;
}