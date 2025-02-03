#include<bits/stdc++.h>

using namespace std;

class Solution {
public: 
    vector<string> fullyJustify(vector<string>& words, int maxWidth) {
        int n = static_cast<int>(words.size());
        int m;
        float spaces;
        int n_spaces, vai_um = 0;
        vector<string> ans;
        vector<string> line_helper;
        string line = "";
        int line_size = 0, n_lines = 0;
        for (int i = 0; i < n; i++) {
            vai_um = 0;
            if (line_size + words[i].length() < maxWidth) {
                line_helper.push_back(words[i]);
                // +1 the space
                line_size += words[i].length() + 1;
            } else if (line_size + words[i].length() == maxWidth) {
                line_helper.push_back(words[i]);
                m = static_cast<int>(line_helper.size());
                while (!line_helper.empty()) {
                    line = line_helper.back() + " " + line;
                    line_helper.pop_back();
                }
                ans[n_lines] = line.substr(0, line.length()-1);
                n_lines++;
                line = ""; 
            } else {
                m = static_cast<int>(line_helper.size());
                // Verificar essa conta aqui.
                // o da esqueda recebe mais
                spaces = (maxWidth-line_size+m+1)/(m-1);
                n_spaces = floor(spaces);
                if (spaces != floor(spaces)) {
                    vai_um = 1;
                }
                while (!line_helper.empty()) {
                    if (line_helper.size() == 1) {
                        n_spaces += vai_um;
                    }
                    string white_spaces = "";
                    for (int k = 0; k < n_spaces; k++) {
                        white_spaces += " ";
                    }
                    line = line_helper.back() + white_spaces + line;
                    line_helper.pop_back();
                }
                vai_um = 0;
                ans[n_lines] = line.substr(0, line.length()-1);
                n_lines++;
                line = ""; 
                
                line_helper.push_back(words[i]);
                line_size = words[i].length();

            }
        }
        return ""; 
    }
};


int main() {
    vector<string> words, ans, e;
    int maxWidth;
    Solution sol = Solution();

    words = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    maxWidth = 20;
    e = {
    "This    is    an",
    "example  of text",
    "justification.  "
    };

    ans = sol.fullyJustify(words, maxWidth);

    words = {"What","must","be","acknowledgment","shall","be"};
    maxWidth = 16;
    e = {
    "What   must   be",
    "acknowledgment  ",
    "shall be        "
    };
    words = {"This", "is", "an", "example", "of", "text", "justification."};
    maxWidth = 16;
    e = {
    "Science  is  what we",
    "understand      well",
    "enough to explain to",
    "a  computer.  Art is",
    "everything  else  we",
    "do                  "
    };
}
