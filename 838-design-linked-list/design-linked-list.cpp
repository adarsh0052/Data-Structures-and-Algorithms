
class MyLinkedList {
private:
    ListNode* head;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    int get(int index) {
        if (index < 0 || index >= size)
            return -1;
        ListNode* curr = head;
        while (index--) {
            curr = curr->next;
        }

        return curr->val;
    }
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = head;
        head = node;
        size++;
    }

    void addAtTail(int val) {
        ListNode* node = new ListNode(val);

        if (head == nullptr) {
            head = node;
            size++;
            return;
        }

        ListNode* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = node;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size)
            return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        if (index == size) {
            addAtTail(val);
            return;
        }

        ListNode* prev = head;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->next;
        }

        ListNode* node = new ListNode(val);
        node->next = prev->next;
        prev->next = node;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
            return;

        if (index == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }

        ListNode* prev = head;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->next;
        }

        ListNode* temp = prev->next;
        prev->next = temp->next;
        delete temp;
        size--;
    }
};