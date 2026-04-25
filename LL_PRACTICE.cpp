#include<bits/stdc++.h>
using namespace std;

template<typename T>
class LL{
    private:
        struct Node{
            T data;
            Node* next;
            Node(T val):data(val),next(nullptr){} 
        };
        Node* head;
    public:
        LL(){
            head =nullptr;
        }
        ~LL(){
            Node* temp = head;
            while(temp){
                Node* del = temp;
                temp = temp->next;
                delete del;
            }
        }
        void insertfront(T val){
            Node* newnode = new Node(val);
            if(!head){ head = newnode;return;}
            newnode->next = head;
            head=newnode;
        }
        void insertback(T val){
            Node* newnode = new Node(val);
            if(!head){ head = newnode;return;}
            Node* temp = head;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = newnode;
        }
        void deleteval(T val){
            if(!head){return;}
            if(head->data == val){ Node* temp = head; head = head->next;delete temp;return;}
            Node* curr = head;
            Node* prev = nullptr;
            while(curr){
                if(curr->data == val){
                    prev->next = curr->next;
                    delete curr;
                    return;
                }
                prev = curr;
                curr = curr->next;
            }
        }
        void reverse(){
            Node* curr = head;
            Node* prev = nullptr;
            Node* next = nullptr;
            while(curr){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
        }
        T findmid(){
            Node* fast = head;
            Node* slow = head;
            while(fast && fast->next){
                fast = fast->next->next;
                slow = slow->next;
            }
            return slow->data;
        }
        bool detectcycle(){
            Node* fast = head;
            Node* slow = head;
            while(fast && fast->next){
                fast = fast->next->next;
                slow = slow->next;
                if(fast == slow){ cout<<"cycle detected"<<endl;return true;}
            }
            cout<<"cycle not detected"<<endl;
            return false;
        }
        void printll(){
            Node* temp = head;
            while(temp){
                cout<<temp->data<<endl;
                temp = temp->next;
            }
        }

};
