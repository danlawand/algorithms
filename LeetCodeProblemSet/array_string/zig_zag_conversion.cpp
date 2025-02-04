#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        // Time: O(s.length)
        // Auxiliary Memory: O(s.length + numRows)
        vector<string> matrix(numRows);

        int i = 0;
        while (i < s.length()) {
            // Faz a linha de decida
            for (int j = 0; j < numRows && i < s.length(); j++) {
                matrix[j].push_back(s[i++]);
            }
            // Faz a subida (cresce na diagonal)
            for (int j = numRows-2; j > 0 && i < s.length(); j--) {
                matrix[j].push_back(s[i++]);
            }
        }
        string ans = "";
        for (i = 0; i < numRows; i++) {
            ans = ans + matrix[i];
        }
        return ans;
    }

    string optimConvert(string s, int numRows) {
        vector<string> p(numRows);

    }
};

/* PAYPALISHIRING
row 0 p   a
row 1 a p 
row 2 y
0 1 2 1 0 1 2 1 0 1 2 1 0 1
P A Y P A L I S H I R I N G

4 rows
0 1 2 3 | 2 1 | 0 1 2 3 | 2  1  | 0  1
P A Y P | A L | I S H I | R  I  | N  G
0 1 2 3 | 4 5 | 6 7 8 9 | 10 11 | 12 13
0 1 2 3 | 3 1 | 2 3 0 1 | 2  3  | 0  1  %rows
*/
int main() {
    Solution sol = Solution();
    string s;
    int n;
    string ans;

    s = "PAYPALISHIRING";
    n = 3;
    ans = sol.convert(s, n);
    cout << s <<"-->"<<ans<<endl;

    s = "PAYPALISHIRING";
    n = 4;
    ans = sol.convert(s, n);
    cout << s <<"-->"<<ans<<endl;

    s = "A";
    n = 1;
    ans = sol.convert(s, n);
    cout << s <<"-->"<<ans<<endl;
}