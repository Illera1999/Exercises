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
        ListNode* aux = new ListNode(0);
        ListNode* tail = aux;
        int ten = 0;
        while(l1 != nullptr or l2 != nullptr or ten != 0){
            int a = (l1 != nullptr) ? l1->val : 0;
            int b = (l2 != nullptr) ? l2->val : 0;
            int val = a + b + ten;
            if(val >= 10){
                val -= 10;
                ten = 1;
            }else{
                ten = 0;
            }
            ListNode* newNode = new ListNode(val);
            tail->next = newNode;
            tail = newNode;

            if(l1 != nullptr){
                l1=l1->next;
            }
            if(l2 != nullptr){
                l2=l2->next;
            }
        }
        ListNode* result = aux->next;
        delete aux;
        return result;
    }
};

int main(){
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node9 = new ListNode(3);

    node1->next = node2;
    node2->next = node3;
    node3->next = node9;

    ListNode* node4 = new ListNode(1);
    ListNode* node5 = new ListNode(2);
    ListNode* node6 = new ListNode(3);

    node4->next = node5;
    node5->next = node6;

    Solution solution;
    ListNode* result = solution.addTwoNumbers(node1, node4);
    ListNode* print = result;

    cout << "El resultado es: [ ";
    while(result->next != nullptr){
        cout << print->val << ", ";
        result = print->next;
        print = result;
    }
    cout << result->val << "]" << endl;

}