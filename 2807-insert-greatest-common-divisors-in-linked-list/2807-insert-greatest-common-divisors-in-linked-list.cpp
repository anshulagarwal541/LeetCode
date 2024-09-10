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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* h = head;
        ListNode* t = head;
        int count = 0;
        while (h) {
            int a = h->val;
            if (h->next) {
                int b = h->next->val;
                int LCM = lcm(a, b);
                int hcf = (a * b) / LCM;
                ListNode* temp = new ListNode(hcf);
                temp->next = h->next;
                h->next = temp;
                h = h->next;
            }
            h = h->next;
        }
        return t;
    }
};
