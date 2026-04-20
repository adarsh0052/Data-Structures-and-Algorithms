class MyQueue {
private:
    stack<int> s1;  
    stack<int> s2;  

    void transfer() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        transfer();
        int val = s2.top();
        s2.pop();
        return val;
    }

    int peek() {
        transfer();
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};