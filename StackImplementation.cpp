#include<bits/stdc++.h>
using namespace std;

template <typename T>
class stackk{
    private:
        T* data;
        size_t cap;
        int topidx;
        void resize(int newcap){
            T* data1 = new T[newcap];
            for(int i=0;i<=topidx;i++){
                data1[i] = data[i];
            }
            delete[] data;
            data = data1;
            cap = newcap;
        }

    public:
        stackk(int x =20){
            cap = 20;
            topidx = -1;
            data = new T[cap];
        }
        stackk(const stackk& other){
            cap = other.cap;
            topidx = other.topidx;
            data = new T[other.cap];
            for(int i=0;i<=topidx;i++){
                data[i] = other.data[i];
            }
        }
        stackk& operator=(const stackk& other){
            if(this != &other){
                delete[] data;
                cap = other.cap;
                topidx = other.topidx;
                data = new T[other.cap];
                for(int i=0;i<=topidx;i++){
                    data[i] = other.data[i];
                }
            }
            return *this;
        }
        stackk(const stackk&& other){
            cap = other.cap;
            topidx = other.topidx;
            data = other.data;
            other.data = nullptr;
        }
        stackk& operator=(const stackk&& other){
            if(this != &other){
                delete[] data;
                cap = other.cap;
                topidx = other.topidx;
                data = other.data;
                other.data = nullptr;
            }
            return *this;
        }
        void push(const T& value){
            if(topidx+1 == cap)
                resize(cap*2);
            data[++topidx] = value;
        }
        void pop(){
            if(topidx == -1){
                throw runtime_error("Stack overflow");
            }
            topidx--;
        }
        const T& top(){
            if(topidx == -1){
                throw runtime_error("Stack is empty");
            }
            return data[topidx];
        }
        bool isEmpty(){
            return topidx == -1;
        }
        int size(){
            return topidx+1;
        }
        void printstack(){
            for(int i=0;i<=topidx;i++){
                cout<<data[i]<<endl;
            }
        }

};
class minstack{
    private:
        stackk<int>ss;
        stackk<int>minss;
    public:
        void push(const int& val){
            ss.push(val);
            if(minss.isEmpty() || val<=minss.top()){
                minss.push(val);
            }
        }
        void pop(){
            if(minss.top() == ss.top()){
                minss.pop();
            }
            ss.pop();
        }
        const int& top(){
            return ss.top();
        }
        const int& mintop(){
            return minss.top();
        }


};

template<typename T>
class sttack{
    private:
        T* data;
        int top;
        int cap;
        void resize(){
            T* newdata = new T[cap*2];
            for(int i=0;i<=top;i++){
                newdata[i] = data[i];
            }
            delete[data];
            data = newdata;
            newdata = nullptr;
            cap = cap*2;  
        }
    public:
        sttack(int cap = 20){
            top = -1;
            cap = 20;
            data = new T[cap];
        }
        sttack(const sttack& other){
            top = other.top;
            cap = other.cap;
            data = new T[other.cap];
            for(int i=0;i<=top;i++){
                data[i]=other.data[i];
            }
        }
        sttack& operator=(const sttack& other){
            if(this != &other){
                delete[] data;
                top = other.top;
                cap = other.cap;
                data = new T[other.cap];
                for(int i=0;i<=top;i++){
                    data[i]=other.data[i];
                }
            }
            return *this;
        }
        sttack(const sttack&& other){
            top = other.top;
            cap = other.cap;
            data = other.data;
            other.data = nullptr;
        }
        sttack& operator=(const sttack&& other){
            if(this != &other){
                delete[] data;
                top = other.top;
                cap = other.cap;
                data = other.data;
                other.data = nullptr;
            }
            return *this;
        }
        void push(const T& val){
            if(top >=cap){
                resize();
            }
            data[++top] = val;
        }
        const T& pop(){
            if(top != -1){
                return data[top--];
            }else{
                throw runtime_error "stack is empty";
            }
        }
        const T& top(){
            if(top != -1){
                return data[top];
            }else{
                throw runtime_error "stack is empty";
            }
        }
        bool IsEmpty() const{
            return top == -1;
        }
        
};
int main(){
    minstack s;
    for(int i=0;i<10;i++){
        s.push(i+1);
    }
    cout<<s.top()<<endl;
    cout<<s.mintop()<<endl;
}
