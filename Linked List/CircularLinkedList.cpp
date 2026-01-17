#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
    Node* head;
    Node* tail;

public:
    CircularLinkedList() {
        head = tail = NULL;
    }

    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (tail == NULL) {
            head = tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
            tail->next = head;  
        } else {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteAtHead() {
        if (head == NULL){
            cout << "List is empty" << endl;
            return;
        }
        else if (head == tail) {
            delete head;
            head = tail = NULL;
        } 
        else {
            Node* temp = head;
            head = head->next;
            tail->next = head;
            temp->next = head;
            delete temp;
        }
    }

    void deleteAtTail() {
        if (head == NULL){
            cout << "List is empty" << endl;
            return;
        }
        else if (head == tail) {
            delete head;
            head = tail = NULL;
        } 
        else {
            Node* temp = head;
            Node* prev = head;
            while (prev->next != tail) {
                prev = prev->next;  
            }
            tail = prev;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }

    void print(){
        if(head == NULL){
            cout << "List is empty" << endl;
            return;
        }
        cout<< head->data << "->";
        Node* temp = head->next;
        while (temp != head){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
};

int main() {
    CircularLinkedList dll;
    dll.insertAtHead(10);
    dll.insertAtTail(20);
    dll.insertAtTail(30);
    dll.print();

    dll.deleteAtHead();
    dll.print();

    dll.deleteAtTail();
    dll.print();
    
    return 0;
}