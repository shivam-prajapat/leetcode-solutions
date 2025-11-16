class MyQueue {
public:
    stack<int> inStack;
    stack<int> outStack;

    MyQueue() {}

    // Push element to back of queue
    void push(int x) {
        inStack.push(x);
    }

    // Pop from front of queue
    int pop() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        int front = outStack.top();
        outStack.pop();
        return front;
    }

    // Get front element
    int peek() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        return outStack.top();
    }

    // Check if empty
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};
