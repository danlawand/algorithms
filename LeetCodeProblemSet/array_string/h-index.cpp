#include <bits/stdc++.h>
#include <algorithm> 
using namespace std;

class Solution {
public:
    int hIndex_optimized(vector<int>& citations) {
        int papers = static_cast<int>(citations.size());
        vector<int> citation_buckets(papers+1);
        for (int j = 0; j < papers; j++) {citation_buckets[j] = 0;}
        for (int j = 0; j < papers; j++) {citation_buckets[min(citations[j], papers)] += 1;}

        int cumulative_papers = 0;
        for (int h_index = papers; h_index >= 0; h_index--) {
            cumulative_papers += citation_buckets[h_index];
            if (cumulative_papers >= h_index) {
                return h_index;
            }
        }
        return 0;
    }

    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        size_t n = citations.size();
        vector<int> val(n+1);
        int i = n-1;
        int aux = n-1;
        for (int j = 0; j < n; j++) {val[j] = 0;}
        int pos;

        while (i >= 0 ) {
            pos = aux;
            if (citations[i] >= aux+1) {
                val[aux]++;
                i--;
            } 
            
            if (val[pos] >= pos+1) {
                return pos+1;
            }
            if (citations[i] < aux+1) {
                if (aux == 0) {return 0;}
                val[aux-1] = val[aux];
                aux--;
            }
        }
        return 0;
    }
};

int main() {
    Solution solution;
    int i = 0, expected;

    vector<int> v = {3,0,6,1,5};
    expected = 3;
    cout << "Teste: " << i << endl;
    for (const int& number : v) {
        cout << number << " ";
    }
    cout << endl;
    cout << "Answer: "<< solution.hIndex_optimized(v) << " -- Expected: " << expected << endl;

    i++;
    v = {1,3,1};
    expected = 1;
    cout << "Teste: " << i << endl;
    for (const int& number : v) {
        cout << number << " ";
    }
    cout << endl;
    cout << "Answer: "<< solution.hIndex_optimized(v) << " -- Expected: " << expected << endl;

    i++;
    v = {0};
    expected = 0;
    cout << "Teste: " << i << endl;
    for (const int& number : v) {
        cout << number << " ";
    }
    cout << endl;
    cout << "Answer: "<< solution.hIndex_optimized(v) << " -- Expected: " << expected << endl;
}