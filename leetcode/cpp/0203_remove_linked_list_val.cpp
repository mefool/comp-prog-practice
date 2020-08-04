/* Leetcode - Problem 203 - Remove Linked List Elements
   g++ 0203_remove_linked_list_val.cpp -o remove_linked_list_val.exe

 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
            return head;
        
        while (head != nullptr && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        
        ListNode* aux = head;
        while (aux != nullptr && aux->next != nullptr) {
            if (aux->next->val == val){
                ListNode* temp = aux->next;
                aux->next = aux->next->next;
                delete temp;
            } 
            else
                aux = aux->next;
        }
        return head;
    }
};
