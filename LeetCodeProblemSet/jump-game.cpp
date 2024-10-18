#include <iostream>
#include <vector>


class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        std::size_t n = nums.size();
        // std::cout << n << std::endl;
        if (n == 1) return 1;
        int pos = n-1;
        int i = n-2;
        while(i >= 0) {
            // std::cout << i << std::endl;
            // std::cout << pos << std::endl << std::endl;
            if (nums[i] >= pos - i) {
                pos = i;
            }
            i --;
        }
        // std::cout << pos << std::endl;
        if (pos == 0) {
            return 1;
        }
        return 0;
    }
};

int main() {
    Solution solution;
    std::vector<int> t1 = {2, 3, 1, 1, 4};
    int i = 0;
    std::cout << "Teste: " << i << std::endl;
    for (const int& number : t1) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
    std::cout << solution.canJump(t1) << std::endl;

    i++;
    std::vector<int> t2 = {3,2,1,0,4};
    std::cout << "Teste: " << i << std::endl;
    for (const int& number : t2) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
    std::cout << solution.canJump(t2) << std::endl;

    i++;
    std::vector<int> t3 = {5};
    std::cout << "Teste: " << i << std::endl;
    for (const int& number : t3) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
    std::cout << solution.canJump(t3) << std::endl;

    i++;
    std::vector<int> t4 = {0};
    std::cout << "Teste: " << i << std::endl;
    for (const int& number : t4) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
    std::cout << solution.canJump(t4) << std::endl;

    i++;
    std::vector<int> t5 = {2, 0};
    std::cout << "Teste: " << i << std::endl;
    for (const int& number : t5) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
    std::cout << solution.canJump(t5) << std::endl;


    i++;
    std::vector<int> t6 = {3, 0, 1, 1, 0, 5};
    std::cout << "Teste: " << i << std::endl;
    for (const int& number : t6) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
    std::cout << solution.canJump(t6) << std::endl;


    i++;
    std::vector<int> t7 = {3, 0, 3, 1, 0, 4};
    std::cout << "Teste: " << i << std::endl;
    for (const int& number : t7) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
    // Expected true
    std::cout << solution.canJump(t7) << std::endl;


}