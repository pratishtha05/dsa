#include <iostream>
#include <vector>
using namespace std;

class Stack {
    vector<int> v;

public:
    void push(int val) {
        v.push_back(val);
    }

    void pop() {
        if (v.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        v.pop_back();
    }

    int top() {
        if (v.empty()) {
            cout << "Stack is empty" << endl;
            return -1; 
        }
        return v[v.size() - 1];
    }

    bool isEmpty() {
        return v.size() == 0;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    while (!s.isEmpty()) {
        cout << s.top() << endl;
        s.pop();
    }
    cout<<endl;
    
    return 0;
}

// #inlcude <stack>
// using namespace std;
// int main() {
//     stack<int> s;
//     s.push(10);
//     s.push(20);
//     s.push(30);
// }