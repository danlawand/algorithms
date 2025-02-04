#include<bits/stdc++.h>

using namespace std;

class Solution {
public: 
    string getNSpaces(int n) {
        if (n <= 0) {
            return "";
        }
        string spaces = "";
        for (int i = 0; i < n; i++){
            spaces += " ";
        }
        return spaces;
    }

    vector<string> fullyJustify(vector<string>& words, int maxWidth) {
        int numberWords = static_cast<int>(words.size());
        vector<string> answer;
        string line = "", current_word = "";
        vector<string> wordsToNewLine;
        int spacesBetweenWords, numberSpacesPerLine = 0, stackSize, leastLineSpaces = 0;
        int lineSize = words[0].length(), possible_line_size;
        wordsToNewLine.push_back(words[0]);

        // Invariante: wordsToNewLine tem palavras cujo o tamanho não ultrapassem o maxwidth
        // lineSize fits in maxWidth
        for (int i = 1; i < numberWords; i++) {
            current_word = words[i];
            stackSize = static_cast<int>(wordsToNewLine.size());
            possible_line_size = current_word.length() + lineSize + stackSize;
            if (possible_line_size == maxWidth) {
                cout << "===="<<endl;
                cout<<"lineSize: "<<lineSize<<endl;
                cout << "leastLineSpaces: " << leastLineSpaces<<endl;
                // então considero todas as palavras da pilha e a atual, e só apenas um espaço por palavra
                wordsToNewLine.push_back(current_word);
                line = "";
                while (!wordsToNewLine.empty()) {
                    line = " " + wordsToNewLine.back() + line;
                    wordsToNewLine.pop_back();
                }
                cout << "1="<<line<<endl;
                answer.push_back(line.substr(1,line.length()));
                lineSize = 0;
            }
            else if (possible_line_size > maxWidth) {
                // Então considere todas a palavras da pilha, e não considero a atual
                line = "";
                numberSpacesPerLine = maxWidth - lineSize;
                if (stackSize == 1) {
                    line = wordsToNewLine.back() + getNSpaces(numberSpacesPerLine);
                    wordsToNewLine.pop_back();
                }
                while (!wordsToNewLine.empty()) {
                    if (stackSize==1) {
                        spacesBetweenWords = 0; 
                    } else {
                        spacesBetweenWords = floor(numberSpacesPerLine/(stackSize-1));
                    }
                    line = getNSpaces(spacesBetweenWords) + wordsToNewLine.back() + line;
                    wordsToNewLine.pop_back();
                    numberSpacesPerLine -= spacesBetweenWords;
                    stackSize--;
                }
                cout << ">"<<line<<endl;
                answer.push_back(line);

                wordsToNewLine.push_back(current_word);
                lineSize = current_word.length();

            } else {
                // então adicione a current to the stack
                wordsToNewLine.push_back(current_word);
                lineSize += current_word.length();
            }
        }
        if (!wordsToNewLine.empty()) {
            line = "";
            while (!wordsToNewLine.empty()) {
                line = " " + wordsToNewLine.back() + line;
                wordsToNewLine.pop_back();
            }
            line = line + getNSpaces(maxWidth-line.length()+1);
            cout << "f"<<line<<endl;
            answer.push_back(line.substr(1, line.length()));
        }
        return answer;
    }
};


int main() {
    vector<string> words, ans, e;
    int maxWidth;
    Solution sol = Solution();

    words = {"Here","is","an","example","of","text","justification."};
    maxWidth = 15;
    e = {"Here    is   an","example of text","justification. "};
    ans = sol.fullyJustify(words, maxWidth);
    cout << "1 test: " << maxWidth <<endl;
    for (int i = 0; i < static_cast<int>(ans.size()); i++) {
        cout<<"="<<e[i]<<"="<<endl;
        cout << "-" << ans[i] << "-" <<endl<<endl;
    }


    words = {"Listen","to","many,","speak","to","a","few."};
    maxWidth = 6;
    e = {"Listen","to    ","many, ","speak ","to   a","few.  "};
    ans = sol.fullyJustify(words, maxWidth);
    cout << "1 test: " << maxWidth <<endl;
    for (int i = 0; i < static_cast<int>(ans.size()); i++) {
        cout<<"="<<e[i]<<"="<<endl;
        cout << "-" << ans[i] << "-" <<endl<<endl;
    }



    words = {"The","important","thing","is","not","to","stop","questioning.","Curiosity","has","its","own","reason","for","existing."};
    maxWidth = 17;
    e = {"The     important","thing  is  not to","stop questioning.","Curiosity has its","own   reason  for","existing.        "};
    ans = sol.fullyJustify(words, maxWidth);
    cout << "1 test: " << maxWidth <<endl;
    for (int i = 0; i < static_cast<int>(ans.size()); i++) {
        cout<<"="<<e[i]<<"="<<endl;
        cout << "-" << ans[i] << "-" <<endl<<endl;
    }
    
    words = {"This", "is", "an", "example", "of", "text", "justification."};
    maxWidth = 16;
    e = {
    "This    is    an",
    "example  of text",
    "justification.  "
    };

/*
    "This    is    an",
    "example  of text",
    "justification.  "
-This    is    an-
"This    is    an"
-example  of text-
"example  of text",
-justification. -
-This    is    an-
-example  of text-
-justification. -
-justification.  -
"justification.  "
*/

    ans = sol.fullyJustify(words, maxWidth);
    cout << "1 test: " << maxWidth <<endl;
    for (int i = 0; i < static_cast<int>(ans.size()); i++) {
        cout<<"="<<e[i]<<"="<<endl;
        cout << "-" << ans[i] << "-" <<endl<<endl;
    }

    words = {"What","must","be","acknowledgment","shall","be"};
    maxWidth = 16;
    e = {
    "What   must   be",
    "acknowledgment  ",
    "shall be        "
    };

    ans = sol.fullyJustify(words, maxWidth);
    cout << "2 test: " << maxWidth <<endl;
    for (int i = 0; i < static_cast<int>(ans.size()); i++) {
        cout<<"="<<e[i]<<"="<<endl;
        cout << "-" << ans[i] << "-" <<endl<<endl;
    }

    words = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    maxWidth = 20;
    e = {
    "Science  is  what we",
    "understand      well",
    "enough to explain to",
    "a  computer.  Art is",
    "everything  else  we",
    "do                  "
    };


/*

"Science  is  what we",
-Science  is  what we-
"understand      well",
-understand      well-
"enough to explain to",
-enough to explain to-
"a  computer.  Art is",
-a  computer.  Art is-
"everything  else  we", 16 letras 4 espaços
-everything  else  we-
"do                  "
-do                 -
everything else we do

*/

    ans = sol.fullyJustify(words, maxWidth);
    cout << "3 test: " << maxWidth <<endl;
    for (int i = 0; i < static_cast<int>(ans.size()); i++) {
        cout<<"="<<e[i]<<"="<<endl;
        cout << "-" << ans[i] << "-" <<endl<<endl;
    }
}
