#include <iostream> 

/*
Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list, instead you will be given access to the node to be deleted directly.
It is guaranteed that the node to be deleted is not a tail node in the list.
*/

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
  };
 class Solution {
 public:
     void deleteNode(ListNode* node) {
         ListNode* nextNode = node->next;
         ListNode* currentNode = node;

         while (nextNode->next->next != nullptr) {
             currentNode->val = nextNode->val;
             currentNode->next = nextNode->next;
             currentNode = nextNode;
             nextNode = nextNode->next;
         }
         nextNode->next = nullptr;
     }
 };

int main() {

	return 0;
}