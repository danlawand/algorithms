#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        string ans = "";

        for (int i = 0; i < s.length(); i++) {

            string word = "";
            while (s[i] != ' ' && i < s.length()) {
                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            if (word.length() > 0) {
                ans += " " + word;
            }
        }

        return ans.substr(1);
    }

    string naive(string s) {
        stringstream ss(s);
        string word;
        string ans = "";
        while (ss >> word) {
            ans = word + " " + ans;
        }
        return ans.substr(0, ans.length()-1);

    }
};


int main() {
    Solution sol = Solution();
    string s = "hello world";
    string ans;
    ans = sol.reverseWords(s);
    cout << "->"<< s << "<-->" << ans<<"<--"<<endl;
    s = " hello world ";
    ans = sol.reverseWords(s);
    cout << "->"<< s << "<-->" << ans<<"<--"<<endl;
    s = "a good   example";
    ans = sol.reverseWords(s);
    cout << "->"<< s << "<-->" << ans<<"<--"<<endl;
}