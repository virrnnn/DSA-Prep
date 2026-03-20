#include<bits/stdc++.h>
using namespace std;

template <typename T>
class ll{

    private:
    struct Node{
        T data;
        Node* next;

        Node(const T &val):data(val),next(nullptr){}
    };
    Node* head;

    public:
        ll(){
            head = nullptr; 
        }
        ~ll(){
            Node* temp = head;
            while(temp){
                Node* deleten = temp;
                temp = temp->next;
                delete deleten;
            }
        }
        void insertfirst(const T &val){
            Node* newnode = new Node(val);
            newnode->next = head;
            head = newnode;
        }
        void insertback(const T &val){
            Node* newnode = new Node(val);
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
        void insertatpos(int pos,T &val){
            if(pos<=0 || !head){
                insertfirst(val);
                return;
            }
            int x=0;
            Node* temp = head;
            while(temp->next && x<pos-1){
                temp = temp->next;
                x++;
            }
            Node* newnode = new Node(val);
            newnode->next = temp->next;
            temp->next = newnode;
        }
        void printll(){
            Node* temp = head;
            while(temp){
                cout<<temp->data<<endl;
                temp = temp->next;
            }
        }
        void findmid(){
            if(!head){return;}
            Node* fast = head;
            Node* slow = head;
            while(fast->next && fast->next->next){
                fast = fast->next->next;
                slow = slow->next;
            }
            cout<<"Middle : "<<slow->data<<endl;
        }
        void deleteval(const T&val){
            if(!head){return;}
            if(head->data==val){
                Node* temp1 = head->next;
                delete head;
                head = temp1;
                return;
            }
            Node* temp = head;
            while(temp->next){
                Node* check = temp->next;
                if(check->data==val){
                    temp->next = check->next;
                    delete check;
                    return;
                }
                else
                    temp = temp->next;
            }
        }
        void reverse(){
            Node* curr=head;
            Node* prev = nullptr;
            Node* next = nullptr;
            while(curr){
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            head = prev;
        }
};

int main(){
    ll<int> l1;
    l1.insertfirst(6);
    l1.insertfirst(7);
    l1.insertfirst(8);
    l1.insertback(9);
    l1.insertback(10);
    l1.insertback(11);
    l1.insertback(12);
    l1.printll();
    l1.findmid();
    cout<<"After Delete"<<endl;
    l1.deleteval(9);
    l1.printll();
    cout<<"After reverse"<<endl;
    l1.reverse();
}