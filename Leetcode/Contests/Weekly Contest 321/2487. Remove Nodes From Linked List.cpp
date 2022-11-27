// Problem Link - https://leetcode.com/contest/weekly-contest-321/problems/remove-nodes-from-linked-list/

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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp = head;
        while(temp)
        {
            while(st.size() and temp->val>st.top()->val)
                st.pop();
            st.push(temp);
            temp = temp->next;
        }
        ListNode* ans;
        ans = st.top();
        temp = ans;
        st.pop();
        while(st.size())
            temp->next = st.top(), temp = st.top(), st.pop();
        temp->next = nullptr;
        ListNode* pre = nullptr;
        while(ans)
        {
            ListNode* nex = ans->next;
            ans->next = pre;
            pre = ans;
            ans = nex;
        }
        return pre;
    }
};