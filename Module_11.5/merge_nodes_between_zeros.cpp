#include <iostream>
using namespace std;
// Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    void insert_at_tail(ListNode*& head, ListNode*& tail, int val){
        ListNode* newnode = new ListNode(val);
        if(head == nullptr){
            head = newnode;
            tail = newnode;
            return;
        }
        tail->next = newnode;
        tail = newnode;
    }
    ListNode* mergeNodes(ListNode* head) {
        ListNode* modif_head = nullptr;
        ListNode* modif_tail = nullptr;

        ListNode* tmp = head;
        int sum = 0;
        while(tmp != nullptr){
            
            
            if(sum != 0 && tmp->val == 0){
                insert_at_tail(modif_head, modif_tail, sum);
                sum = 0;
            }
            
            if(tmp->val != 0){
                sum += tmp->val;
            }else{
                sum = 0;
            }
            tmp = tmp->next;
        }
        return modif_head;
    }
};