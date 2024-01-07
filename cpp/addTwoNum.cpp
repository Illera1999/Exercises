/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode();
        ListNode* tail = result;
        int ten = 0;
        while(l1->next != nullptr and l2->next != nullptr){
            int val = l1->val + l2->val + ten;
            if(val >= 10){
                val -= 10;
                ten = 1;
            }else{
                ten = 0;
            }
            ListNode* newNode = new ListNode();
            tail->val = val;
            tail->next = newNode;
            tail = newNode;

            l1=l1->next;
            l2=l2->next;
        }

        return result;

    }
};

int main(){
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);

    node1->next = node2;
    node2->next = node3;

    ListNode* node4 = new ListNode(1);
    ListNode* node5 = new ListNode(2);
    ListNode* node6 = new ListNode(3);

    node4->next = node5;
    node5->next = node6;
    // ListNode* node1 = new ListNode(1);
    // ListNode* node2 = new ListNode(0);
    // node1->next = node2;
    // ListNode* node4 = new ListNode(1);
    // ListNode* node5 = new ListNode(0);
    // node4->next = node5;

    Solution solution;
    ListNode* result = solution.addTwoNumbers(node1, node4);
    ListNode* print = result;

    cout << result->val << endl;
    cout << "El resultado es: [ ";
    while(result->next != nullptr){
        cout << print->val << ", ";
        result = print->next;
        print = result;
    }
    cout << result->val << "]" << endl;

}