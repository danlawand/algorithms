#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        // return optMemoryIntToRoman(num);
        return optTimeIntToRoman(num);
    }

    string optTimeIntToRoman(int num) {
        // O(1)
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]={"","M","MM","MMM"};
        
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }

    string optMemoryIntToRoman(int num) {
        // Memory: O(4)
        // Time: O(4*4) => O(number_of_digits*se_tem_algum_com_3_char)
        vector<char> roman(7);
        roman[0] = 'I';     
        roman[1] = 'V';
        roman[2] = 'X';
        roman[3] = 'L';
        roman[4] = 'C';
        roman[5] = 'D';
        roman[6] = 'M';

        int count = 0;
        int aux = num;

        vector<int> r(4);

        while(aux != 0) {
            r[count] = aux%10;
            cout << "r["<< count<< "]: "<<r[count]<<endl;
            aux/=10;
            count++;
        }
        string ans;
        // 58 => LVIII

        cout << endl;
        int h = 2*(count-1);
        if (count >= 4) {
            for(int j = 0; j < r[3]; j++) {
                ans.push_back(roman[6]);
            }
            h -= 2;
            count--;
        }
        cout << "count: "<<count<<endl;
        for (int i = count-1; i >= 0; i--) {
            if (r[i] == 0) {
                h -=2;
                continue;
            }
            cout << "h: "<< h << " -- r["<<i<<"]: "<<r[i];
            cout << " -- str inicial: "<<ans;
            if (r[i] == 9) {
                ans.push_back(roman[h]);
                ans.push_back(roman[h+2]);
            } else if (r[i] == 4) {
                ans.push_back(roman[h]);
                ans.push_back(roman[h+1]);
            }
            else {
                if (r[i] > 4) {
                    ans.push_back(roman[h+1]);
                    r[i] = r[i] - 5;
                }
                for (int j = 1; j <= r[i]; j++) {
                    ans.push_back(roman[h]);
                }
            }
            cout << "-- str final: "<<ans<<endl;
            h -=2;
        }
        return ans;
    }
   
    string notSoOptTimeIntToRoman(int num) {
        // Memory: O(30)
        // Time: O(4)
        unordered_map<string, string> roman;
        roman["0"] = "";
        roman["1"] = "I";
        roman["2"] = "II";
        roman["3"] = "III";
        roman["4"] = "IV";
        roman["5"] = "V";
        roman["6"] = "VI";
        roman["7"] = "VII";
        roman["8"] = "VIII";
        roman["9"] = "IX";
        roman["10"] = "X";     
        roman["20"] = "XX";
        roman["30"] = "XXX";
        roman["40"] = "XL";
        roman["50"] = "L";
        roman["60"] = "LX";
        roman["70"] = "LXX";
        roman["80"] = "LXXX";
        roman["90"] = "XC";
        roman["100"] = "C";     
        roman["200"] = "CC";
        roman["300"] = "CCC";
        roman["400"] = "CD";
        roman["500"] = "D";
        roman["600"] = "DC";
        roman["700"] = "DCC";
        roman["800"] = "DCCC";
        roman["900"] = "CM";
        roman["1000"] = "M";
        roman["2000"] = "MM";
        roman["3000"] = "MMM";

        int count = 0;
        int aux = num;

        string ans = "";
        int r, i = 0;
        int index;
        while(aux != 0) {
            r = aux%10;
            aux/=10;
            if (i == 0) {index = 1;}
            if (i == 1) {index = 10;}
            if (i == 2) {index = 100;}
            if (i == 3) {index = 1000;}
            ans = roman[to_string(index*r)] + ans;
            i++;
        }
        return ans;
    }
};

int main() {
    Solution sol = Solution();
    int num = 3749;
    string e = "MMMDCCXLIX";
    string ans;

    ans = sol.intToRoman(num);
    cout << "Case: " << num << ": Expected: "<<e<<"  --> " << ans << endl;

    num = 58;
    e = "LVIII";
    ans = sol.intToRoman(num);
    cout << "Case: " << num << ": Expected: "<<e<<"  --> " << ans << endl;

    num=1994;
    e = "MCMXCIV";
    ans = sol.intToRoman(num);
    cout << "Case: " << num << ": Expected: "<<e<<"  --> " << ans << endl;

    num = 1909;
    e = "MCMIX";
    ans = sol.intToRoman(num);
    cout << "Case: " << num << ": Expected: "<<e<<"  --> " << ans << endl;

    num = 3888;
    e = "MMMIX";
    ans = sol.intToRoman(num);
    cout << "Case: " << num << ": Expected: "<<e<<"  --> " << ans << endl;
}
