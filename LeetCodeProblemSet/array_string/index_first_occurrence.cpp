#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        // Time: O((n-m)*m) == O(nm - m^2)
        int n, m;
        n = haystack.length();
        m = needle.length();
        int ans;
        for (int i = 0; i < n-m+1; i++) {
            ans = -1;
            if (haystack[i] == needle[0]) {
                ans = i;

                for (int j = 0; j < m; j++) {
                    if (haystack[i+j] != needle[j]) {
                        ans = -1;
                    }
                }
                if (ans != -1) {return ans;}
            }
        }
        return -1;
    }
};

int main() {
    Solution sol = Solution();
    string h, n;
    int e, ans;

    h = "sadbutsad";
    n = "sad";
    e = 0;
    ans = sol.strStr(h, n);
    cout << "h:->"<<h<<"-- n-->"<<n<<endl;
    cout << "Expected: " << e << " --- Result: " << ans << endl;
    cout << "-----------" << endl;

    h = "leetcode";
    n = "leeto";
    e = -1;
    ans = sol.strStr(h, n);
    cout << "h:->"<<h<<"-- n-->"<<n<<endl;
    cout << "Expected: " << e << " --- Result: " << ans << endl;
    cout << "-----------" << endl;

    h = "leetleet";
    n = "leeto";
    e = -1;
    ans = sol.strStr(h, n);
    cout << "h:->"<<h<<"-- n-->"<<n<<endl;
    cout << "Expected: " << e << " --- Result: " << ans << endl;
    cout << "-----------" << endl;

    cout << "###################################"<<endl;
    h = "a";
    n = "a";
    e = 0;
    ans = sol.strStr(h, n);
    cout << "h:->"<<h<<"-- n-->"<<n<<endl;
    cout << "Expected: " << e << " --- Result: " << ans << endl;
    cout << "-----------" << endl;

    h = "a";
    n = "b";
    e = -1;
    ans = sol.strStr(h, n);
    cout << "h:->"<<h<<"-- n-->"<<n<<endl;
    cout << "Expected: " << e << " --- Result: " << ans << endl;
    cout << "-----------" << endl;

    h = "aaaaaaaaaaa";
    n = "a";
    e = 0;
    ans = sol.strStr(h, n);
    cout << "h:->"<<h<<"-- n-->"<<n<<endl;
    cout << "Expected: " << e << " --- Result: " << ans << endl;
    cout << "-----------" << endl;

    h = "abcde";
    n = "a";
    e = 0;
    ans = sol.strStr(h, n);
    cout << "h:->"<<h<<"-- n-->"<<n<<endl;
    cout << "Expected: " << e << " --- Result: " << ans << endl;
    cout << "-----------" << endl;

    h = "a";
    n = "aa";
    e = -1;
    ans = sol.strStr(h, n);
    cout << "h:->"<<h<<"-- n-->"<<n<<endl;
    cout << "Expected: " << e << " --- Result: " << ans << endl;
    cout << "-----------" << endl;

    h = "abcabae";
    n = "aba";
    e = 3;
    ans = sol.strStr(h, n);
    cout << "h:->"<<h<<"-- n-->"<<n<<endl;
    cout << "Expected: " << e << " --- Result: " << ans << endl;
    cout << "-----------" << endl;

}