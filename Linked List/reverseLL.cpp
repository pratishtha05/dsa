#include <iostream>
using namespace std; 

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class LinkedList{
    Node* head;

public:
    LinkedList(){
        head = NULL;
    }

    void push_back(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = newNode;
            return;
        } else{
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
    }

    void printLL(){
        Node* temp = head;
        cout<< "head -> ";
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp -> next;
        }
        cout<<" -> NULL";
        cout<<endl;
    }

    void reverseLL(){
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;

            prev = curr;
            curr = next;
        }

        head = prev;
    }

};

int main(){

    LinkedList ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);

    ll.printLL();  

    ll.reverseLL();

    ll.printLL(); 

    return 0;
}