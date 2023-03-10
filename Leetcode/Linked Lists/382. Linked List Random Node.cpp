// Problem Link - https://leetcode.com/problems/linked-list-random-node/description/

#define ll int

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
    ListNode* head;
    Solution(ListNode* head) {
        this->head = head;
        std::srand(std::time(0));
    }
    
    int getRandom() {
        ll count = 0;
        ListNode* ans;
        ListNode* cur = head;
        while(cur)
        {
            count++;
            if(std::rand()%count==0)
                ans = cur;
            cur = cur->next;
        }
        return ans->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */