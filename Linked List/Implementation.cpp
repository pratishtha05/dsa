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

    void push_front(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = newNode;
            return;
        } else{
            newNode -> next = head;
            head = newNode;
        }
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

    void pop_front(){
        if(head == NULL){
            cout<<"List is empty\n";
            return;
        } else{
            Node* temp = head;
            head = head -> next;
            temp -> next = NULL;
            delete temp;
        }
    }

    void pop_back(){
        if(head == NULL){
            cout<<"List is empty\n";
            return;
        } else{
            Node* temp = head;
            while(temp->next->next != NULL){
                temp = temp -> next;
            }
            Node* temp2 = temp->next->next;
            temp -> next = NULL;
            delete temp2;
        }
    }

    void insert(int val, int pos){
        if(pos<0){
            cout<<"Invalid position\n";
            return;
        }
        if(pos == 0){
            push_front(val);
            return;
        }
        Node* temp = head;
        for (int i = 0; i < pos -1; i++)
        {
            temp = temp -> next;
        }
        Node* newNode = new Node(val);
        newNode -> next = temp -> next;
        temp -> next = newNode;
        
    }

    void search(int val){
        if(head == NULL){
            cout<<"List is empty\n";
            return;
        }
        
        Node* temp = head;
        int idx = 0;
        while(temp != NULL){
            if(temp->data == val){
                cout<< val << " is at index: " << idx << endl;
                return;
            }
            temp = temp -> next;
            idx++;
        }
        cout<< val << " is not in the list\n";   
    }

    void printLL(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp -> next;
        }
        cout<<endl;
    }
};

int main(){

    LinkedList l1;

    l1.push_front(3);
    l1.push_front(2);
    l1.push_front(1);

    l1.printLL();

    l1.push_back(4);
    l1.push_back(5);

    l1.printLL();

    l1.insert(10, 2);

    l1.printLL();

    l1.search(5);

    l1.pop_front();

    l1.printLL();

    l1.pop_back();

    l1.printLL();
    
    return 0;
}