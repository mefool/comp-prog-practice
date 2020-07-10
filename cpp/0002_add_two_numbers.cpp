/* Leetcode - Problem 2 - Add two numbers
  From two non-empty linked lists representing two non-negative integers.
  The digits are stored in reverse order and each of their nodes contain 
  a single digit. Add the two numbers and return it as a linked list.
  
  0002_two_sum.cpp
  g++ 0002_add_two_numbers.cpp -o add_two_numbers.exe

  References:
  > https://leetcode.com/problems/add-two-numbers/discuss/1340/a-summary-about-how-to-solve-linked-list-problem-c
*/

#include <iostream>

using namespace std;

/** SOME OF IT DONE
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
 
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};


void printListNode(ListNode *l1){
  // print the value of the first node
  cout << l1->val;
  // add " -> " between the values of the other nodes
  for(ListNode *aux = l1; aux = aux->next; aux == nullptr){
    cout << " -> ";
    cout << aux->val;
  }
  cout << endl;
}


class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode preNode(-1), *p = &preNode;
    int carry = 0, sum;
        
    while (l1 || l2 || carry){
      sum = (l1?l1->val:0) + (l2?l2->val:0) + carry;
      p->next = new ListNode(sum%10);
      carry = sum/10;
            
      p = p->next;
      l1 = l1?l1->next:l1;
      l2 = l2?l2->next:l2;
    }
    return preNode.next;
  }
};

int main() {
  ListNode l1(1);
  ListNode l2(9);

  l1.next = new ListNode(1);
  l1.next->next = new ListNode(2);

  cout << "l1: ";
  printListNode(&l1);
  
  cout << "l2: ";
  printListNode(&l2);
  
  Solution solver;
  ListNode *result = solver.addTwoNumbers(&l1, &l2);

  cout << "result: ";
  printListNode(result);
  
  return 0;
}
