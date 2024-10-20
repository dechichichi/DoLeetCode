class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int tag = 0;
        ListNode *ans = nullptr, *head = nullptr;
        
        while (l1 != nullptr || l2 != nullptr || tag > 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;
            int sum = val1 + val2 + tag;
            tag = sum / 10;
            
            ListNode* newNode = new ListNode(sum % 10);
            if (head == nullptr) {
                head = newNode;
                ans = head;
            } else {
                ans->next = newNode;
                ans = newNode;
            }
            
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        
        return head;
    }
};
