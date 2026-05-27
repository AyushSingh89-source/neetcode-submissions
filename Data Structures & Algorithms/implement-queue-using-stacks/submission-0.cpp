class MyQueue {
private:
    stack<int> s1; // For pushing elements (Input stack)
    stack<int> s2; // For popping/peeking elements (Output stack)

    // Helper function to shift elements from s1 to s2 when s2 is empty
    void shiftStacks() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

public:
    MyQueue() {
        // Constructor
    }
    
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }
    
    // Removes the element from the front of queue and returns it.
    int pop() {
        shiftStacks();
        int front_ele = s2.top();
        s2.pop();
        return front_ele;
    }
    
    // Get the front element.
    int peek() {
        shiftStacks();
        return s2.top();
    }
    
    // Returns whether the queue is empty.
    bool empty() {
        return s1.empty() && s2.empty();
    }
};