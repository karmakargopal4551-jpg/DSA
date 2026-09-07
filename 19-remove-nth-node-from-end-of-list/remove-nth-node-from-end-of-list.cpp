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

                // Brutforse O(N)+O(N)
               
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;
        
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        
        if (count == n) {
            ListNode* newHead = head->next;
            delete head; 
            return newHead;
        }
        
        int stepsToMove = count - n - 1;
        temp = head;
        while (stepsToMove > 0) {
            temp = temp->next;
            stepsToMove--;
        }
        
        ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete; 

        return head;
    }
};




//                 // Optimum  O(N)

// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode* fast = head; 
//         ListNode* slow = head; 

//         for(int i = 0; i < n; i++) {
//             fast = fast->next;
//         }

//         if (fast == nullptr) return head->next;

//         while(fast->next != nullptr) {
//             slow = slow->next; 
//             fast = fast->next;
//         }

//         ListNode* deleteNode = slow->next;
//         slow->next = slow->next->next;

        
//         delete deleteNode;
//         return head;
//     }
// };