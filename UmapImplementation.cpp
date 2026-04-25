#include<bits/stdc++.h>
using namespace std;

template<typename K,  typename V>
class Umap{
    private:
        struct Node{
            K key;
            V value;
            Node* next;
            Node(const K& Key,const V& Value):key(Key),value(Value),next(nullptr){}
        };
        vector<Node*> bucket;
        int bucketcount;
        float threshold;
        int currentsize;
        
        int GetBucketIdx(const K& Key){
            return hash<K>{}(Key)%bucketcount;
        }
        void rehash(){
            vector<Node*> oldbucket = bucket;
            int oldbucketcount = bucketcount;
            bucketcount*=2;
            currentsize = 0;
            bucket.clear();
            bucket.resize(bucketcount,nullptr);
            for(int i=0;i<oldbucketcount;i++){
                Node* head = oldbucket[i];
                while(head){
                    insert(head->key,head->value);
                    Node* temp = head;
                    head = head->next;
                    delete temp;
                } 
            } 

        }
    
    public:
        Umap(int IniBucketCount = 8,float Inithreshold = 0.75f){
            bucketcount = IniBucketCount;
            threshold = Inithreshold;
            currentsize = 0;
            bucket.resize(bucketcount,nullptr);
        }
        
        ~Umap(){
            for(int i=0;i<bucketcount;i++){
                Node* head = bucket[i];
                while(head){
                    Node* temp = head;
                    head = head->next;
                    delete temp;
                }
            }
        }
        void insert(const K& Key,const V& Value){
            int idx = GetBucketIdx(Key);
            Node* head = bucket[idx];
            while(head){
                if(head->key == Key){
                    head->value = Value;
                    return;
                }
                head = head->next;
            }
            Node* newnode = new Node(Key,Value);
            newnode->next = bucket[idx];
            bucket[idx] = newnode;
            currentsize++;
            float loadfactor = (1.0f*currentsize)/bucketcount;
            if(loadfactor>threshold){
                rehash();
            }
        }
        bool get(const K& Key,V& Value){
            int idx = GetBucketIdx(Key);
            Node* head = bucket[idx];
            while(head){
                if(head->key == Key){
                    head->value = Value;
                    return true;
                }
                head = head->next;
            }
            return false;
        }
        bool contains(const K& Key){
            V dummy;
            return get(Key,dummy); 
        }
        bool remove(const K& Key){
            int idx = GetBucketIdx(Key);
            Node* head = bucket[idx];
            Node* prev =nullptr;
            while(head){
                if(head->key == Key){
                    if(prev == nullptr){
                        bucket[idx] = head->next;
                    }
                    else{
                        prev->next = head->next;
                    }
                    delete head;
                    currentsize--;
                    return true;
                }
                prev = head;
                head = head->next;
            }
            return false;
        }
        int size(){
            return currentsize;
        }
        bool empty(){
            return currentsize == 0;
        }
        void display(){
            cout<<"Hash Map Contains : "<<endl;
            for(int i=0;i<bucketcount;i++){
                cout<<"Bucket : "<<i<<endl;
                Node* head = bucket[i];
                while(head){
                    cout<<"Key : "<<head->key<<" Value : "<<head->value<<endl;\
                    head = head->next;
                }
            }
        }
};
int main(){
    Umap<int,int> myMap;
    myMap.insert(1, 10);
    myMap.insert(9, 90);
    myMap.insert(17, 170);
    myMap.insert(2,2);
    myMap.insert(3,3);
    myMap.insert(4,4);
    myMap.insert(5,5);
    myMap.display();
}