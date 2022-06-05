// Problem Link - https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1#

/*struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
#define ll int
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        Node* fast = head;
        Node* slow = head;
        while(fast->next and fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow)
                return true;
        }
        return false;
    }
};