#include<bits/stdc++.h>
using namespace std;

class arr{
    private:
    int * data;
    size_t size;
    public:
    arr(size_t s):size(s)
    {
        data = new int[size];
        cout<<"constructor called"<<endl;
    }
    ~arr(){
        delete[] data;
        cout<<"destructor called"<<endl; 
    }
    arr(const arr&other):size(other.size)
    {
        data = new int[other.size];
        for(size_t i=0;i<size;i++)  
            data[i] = other.data[i];
        cout<<"copy constructor called"<<endl;
    }
    arr& operator=(const arr& other)
    {
        if(this == &other)  
            return *this;
        
        arr temp(other);
        swap(data,temp.data);
        swap(size,temp.size);
        cout<<"copy assignment operator called"<<endl;
        return *this;
    }
    arr(arr&& other)noexcept:size(other.size),data(other.data)
    {
        other.data = nullptr;
        other.size = 0;
        cout<<"Move constuctor called"<<endl;
    }
    arr& operator=(arr&& other)noexcept
    {
        if(this == &other)
            return *this;
        delete[] data;
        data = other.data;
        size = other.size;

        other.data = nullptr;
        other.size=0;
        cout<<"move assignment operator called"<<endl;
        return *this;
    }
};
