class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> mp;
        Node* curr = head;
        while (curr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        while (curr) {
            if (curr->next)   mp[curr]->next   = mp[curr->next];
            if (curr->random) mp[curr]->random = mp[curr->random];
            curr = curr->next;
        }
        return mp[head];
    }
};