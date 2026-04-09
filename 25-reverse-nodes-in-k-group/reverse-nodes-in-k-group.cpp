class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* check = head;
        int count = 0;
        while (check && count < k) {
            check = check->next;
            count++;
        }
        if (count < k) return head;  // fewer than k nodes, leave as-is

        ListNode* prev = nullptr;
        ListNode* curr = head;
        for (int i = 0; i < k; i++) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head->next = reverseKGroup(curr, k);

        return prev;
    }
};