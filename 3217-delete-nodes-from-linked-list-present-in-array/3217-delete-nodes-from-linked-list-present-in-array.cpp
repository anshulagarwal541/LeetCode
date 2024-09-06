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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* p = head;
        ListNode* q = NULL;
        unordered_map<int, int> mp;
        for(int x=0;x<nums.size();x++)
        {
            mp[nums[x]]=1;
        }
        while (p != NULL) {
            if (mp.find(p->val)!=mp.end()) {
                if (p == head) {
                    head = head->next;
                    p = head;
                } else if (p->next == NULL) {
                    q->next = NULL;
                    p = p->next;
                } else {
                    q->next = p->next;
                    p->next = NULL;
                    p = q->next;
                }
            } else {
                q = p;
                p = p->next;
            }
        }
        return head;
    }
};