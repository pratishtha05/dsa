#include <iostream>
#include <list>
using namespace std;

class Stack {
    list<int> ll;

public:
    void push(int val) {
        ll.push_front(val);
    }

    void pop() {
        if (ll.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        ll.pop_front();
    }

    int top() {
        if (ll.empty()) {
            cout << "Stack is empty" << endl;
            return -1; 
        }
        return ll.front();
    }

    bool Empty() {
        return ll.size() == 0;
    }

};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    while (!s.Empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    cout<<endl;
    
    return 0;
}