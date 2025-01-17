#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
   int trap(vector<int>& height) {
        int n = static_cast<int>(height.size());
        if (n <= 1) {
            return 0;
        }
        vector<int> high_peaks;
        int inc = 1;
        int highest_peak = height[0];

        int n_peaks = 0;
        if (height[0] > height[1]) {
            cout << 0 << endl;
            high_peaks.push_back(0);
            n_peaks++;
            inc = -1;
        }
        for (int i = 1; i < n; i++) {
            highest_peak = (height[i] > highest_peak) ? height[i] : highest_peak;
            cout << "height["<<i-1<<"] = " << height[i-1] <<" ? > ? height["<<i<<"] = " << height[i]<<endl; 
            if (height[i-1] > height[i]) {
                if (inc == 1) {
                    cout << i-1 << endl;
                    high_peaks.push_back(i-1);
                    n_peaks++;
                }
                inc = -1;
            
            } else if (height[i-1] < height[i]) {
                inc = 1;
            } else {
                if (inc == 1) {
                    cout << i-1 << endl;
                    high_peaks.push_back(i-1);
                    n_peaks++;
                }
                inc = 0;
            }
        }
        if (height[n-1] > height[n-2]) {
            cout << n-1 << endl;
            high_peaks.push_back(n-1);
            n_peaks++;
        }
        cout << "SET HIGH_PEAKS" << endl;
        for (int i = 0; i < n_peaks; i++) {
            cout << "(height["<<high_peaks[i]<<"] : "<< height[high_peaks[i]]<< ") ";
        }
        cout << endl;
        if (n_peaks <= 1) {
            return 0;
        }
        int sum = 0;
        int min_height_peak, max_height_peak;
        int left=0, right=1, left_peak, right_peak;
        cout << "BEFORE WHILE" << endl;
        while(right < n_peaks) {
            left_peak = high_peaks[left];
            right_peak = high_peaks[right];
            cout << "**** height left_peak: " << height[left_peak] << " index: " << left_peak << endl;
            cout << "**** Height right_peak: " << height[right_peak] << " index: " << right_peak << endl; 

            min_height_peak = min(height[left_peak], height[right_peak]);
            max_height_peak = max(height[left_peak], height[right_peak]);

            for (int j = left_peak; j <= right_peak; j++) {
                if (min_height_peak - height[j] > 0) {
                    cout << min_height_peak << " - " << height[j] << endl;
                    sum += (min_height_peak - height[j]);
                    height[j] = min_height_peak;
                }
            }


            if (max_height_peak == height[right_peak]) {
                left = right;
            }
            right++;
        }

        right = n_peaks-1;
        left = n_peaks-2; 
        cout << "((())) SEGUNDA" << endl;
        while(left > 0) {
            left_peak = high_peaks[left];
            right_peak = high_peaks[right];
            cout << "**** height left_peak: " << height[left_peak] << " index: " << left_peak << endl;
            cout << "**** Height right_peak: " << height[right_peak] << " index: " << right_peak << endl; 

            min_height_peak = min(height[left_peak], height[right_peak]);
            max_height_peak = max(height[left_peak], height[right_peak]);

            for (int j = left_peak; j < right_peak; j++) {
                if (min_height_peak - height[j] > 0) {
                    cout << min_height_peak << " - " << height[j] << endl;
                    sum += (min_height_peak - height[j]);
                    height[j] = min_height_peak;
                }
            }

            if (max_height_peak == height[left_peak]) {
                right = left; 
            }
            left--;
        }
        return sum;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> height;
    int e;
    int ans;

    height = {0,1,0,2,1,0,1,3,2,1,2,1};
    e = 6;
    ans = sol.trap(height);
    cout << "Expected: " << e << " Answer: " << ans << endl;

    height = {4,2,0,3,2,5};
    cout<< endl;
    cout << "{4, 2, 0, 3, 2, 5}" << endl;
    e = 9;
    ans = sol.trap(height);
    cout << "Expected: " << e << " Answer: " << ans << endl;


    cout<< "--------------------------" << endl;
    height = {5,3,7,9,7,9,9,9};
    cout << "{5,3,7,9,7,9,9,9}" << endl;
    e = 4; // 2,0,0,0,2,0
    ans = sol.trap(height);
    cout << "Expected: " << e << " Answer: " << ans << endl;
}