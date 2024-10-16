#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
How to compile: g++ add-two-numbers.cpp -o exe
Complexity analysis:
n = l1.length
m = l2.length

Time O(max(n, m))

Aditional Space: O(1)

Space used: O(n + m)
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *answer = l1;
        int unidade, soma, vai_um = 0;

        soma = l2->val + l1->val;
        vai_um = soma / 10;
        unidade = soma % 10;
        l1->val = unidade;
        std::cout << "Unidade: " << unidade << "--- Vai_um: " << vai_um << std::endl;
        
        while(l2->next != nullptr) {
            if (l1->next == nullptr) {
                soma = vai_um + l2->next->val;
                vai_um = soma / 10;
                unidade = soma%10;
                l1->next = new ListNode(unidade);
            } else {
                soma = vai_um + l2->next->val + l1->next->val;
                vai_um = soma / 10;
                unidade = soma%10;
                l1->next->val = unidade;
            }
            std::cout << "Unidade: " << unidade << "--- Vai_um: " << vai_um << std::endl;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (vai_um > 0) {
            if (l1->next != nullptr) {
                soma = vai_um + l1->next->val;
                vai_um = soma / 10;
                unidade = soma % 10;
                l1->next->val = unidade;
                l1 = l1->next;
                std::cout << "Unidade: " << unidade << "--- Vai_um: " << vai_um << std::endl;
            } else {
                l1->next = new ListNode(vai_um);
                std::cout << "Unidade: " << vai_um << "--- Vai_um: " << 0 << std::endl;
                vai_um = 0;
            }
        }
        return answer;
    }
    ListNode* addTwoNumbersOptimized(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int digit1 = (l1 != nullptr) ? l1->val : 0;
            int digit2 = (l2 != nullptr) ? l2->val : 0;

            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};

void test0() {
    ListNode node1(5);
    ListNode *l1 = &node1;

    ListNode* current = l1;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    ListNode node2(6);
    ListNode *l2 = &node2;

    current = l2;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);
    std::cout << "--Solution--" << std::endl;
    while (result != nullptr) {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;
}


void test1() {
    ListNode node2(3);
    ListNode node1(2, &node2);
    ListNode *l1 = &node1;

    ListNode* current = l1;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    ListNode node5(1);
    ListNode node4(2, &node5);
    ListNode *l2 = &node4;

    current = l2;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);
    std::cout << "--Solution--" << std::endl;
    while (result != nullptr) {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;
}

void test2() {
    ListNode node3(3);
    ListNode node2(4, &node3);
    ListNode node1(2, &node2);
    ListNode *l1 = &node1;

    ListNode* current = l1;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    ListNode node6(4);
    ListNode node5(6, &node6);
    ListNode node4(5, &node5);
    ListNode *l2 = &node4;

    current = l2;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);
    std::cout << "--Solution--" << std::endl;
    while (result != nullptr) {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;
}

void test3() {
    int l1[] = {9,9,9,9,9,9,9}; 
    int n = sizeof(l1) / sizeof(l1[0]);
    int l2[] = {9,9,9,9};
    int m = sizeof(l2)/sizeof(l2[0]);

    ListNode* ll1 = new ListNode(9);
    ListNode *l_l1 = ll1;
    for (int i = 1; i < n; i++) {
        ll1->next = new ListNode(l1[i]);
        ll1 = ll1->next;
    }
    ListNode* current = l_l1;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    ListNode* ll2 = new ListNode(9);
    ListNode* l_l2 = ll2;
    for (int i = 1; i < m; i++) {
        ll2->next = new ListNode(l2[i]);
        ll2 = ll2->next;
    }
    current = l_l2;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
    Solution sol;
    ListNode *result = sol.addTwoNumbers(l_l1, l_l2);
    std::cout << "--Solution--" << std::endl;
    while (result != nullptr) {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;
//Output: [8,9,9,9,0,0,0,1]
           8 9 9 9 0 0 0 1
}

int main() {
    std::cout << "Teste 0" << std::endl;
    test0();
    std::cout << "Teste 1" << std::endl;
    test1();
    std::cout << "Teste 2" << std::endl;
    test2();
    std::cout << "Teste 3" << std::endl;
    test3();

    return 0;
}