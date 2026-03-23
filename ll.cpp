#include<bits/stdc++.h>
using namespace std;


class linkedlist
{
    private:
        struct Node
        {
            int val;
            Node* next;

            Node(int value){
                val = value;
                next = nullptr;
            }
        };
        Node* head;
    public:
        linkedlist(){
            head = nullptr;
        }
        ~linkedlist(){
            Node* temp = head;
            while(temp){
                Node* deleten = temp;
                temp = temp->next;
                delete deleten;
            }
        }
        void insertfront(int value){
            Node* temp = new Node(value);
            if(!head){
                head = temp;
                return;
            }
            temp->next = head;
            head = temp;
        }
        void insertback(int value){
            Node* newnode = new Node(value);
            if(!head){
                head = newnode;
                return;
            }
            Node* temp = head;
            while(temp->next){
                temp=temp->next;
            }
            temp->next = newnode;

        }
        void deletevalue(int val){
            if(!head){return;}//zero item
            if(head->val==val){//first item
                Node* temp = head;
                head = head->next;
                delete temp;
                return;
            }
            Node* curr = head;
            Node* prev = nullptr;
            while(curr)
            {
                if(curr->val == val){
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
        void findmiddle(){
            if(!head){return;}//zero item
            Node* fast = head;
            Node* slow = head;
            while(fast->next && fast->next->next){ //while(fast && fast->next)Second Middle Instead
                fast = fast->next->next;
                slow = slow->next;
            }
            cout<<"Middle element is : "<<slow->val<<endl;
        }
        bool detectcycle(){
            Node* fast = head;
            Node* slow = head;
            while(fast && fast->next){
                fast = fast->next->next;
                slow = slow->next;
                if(fast==slow)  
                    return true;
            }
            return false;
        }
        void printll(){
            Node* temp = head;
            while(temp)
            {
                cout<<temp->val<<endl;
                temp = temp->next;
            }
        }
        
};

int main(){
    linkedlist l;
    l.insertfront(4);
    l.insertfront(5);
    l.insertfront(6);
    l.insertback(7);
    l.printll();
    l.reverse();
    cout<<"reversed"<<endl;
    l.printll();
    l.findmiddle();
}