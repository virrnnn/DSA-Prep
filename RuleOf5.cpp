#include <bits/stdc++.h>

using namespace std; 

class myarr {
    private:
        int * data;
        size_t size;

    public:
        myarr() : size(0),data(nullptr)
        {
            cout<<"constructor called "<<endl;
        }
        ~myarr()
        {
            delete[] data;
        }
        myarr(const myarr &other) : size(other.size)
        {
            data = new int[size];
            for(size_t i=0;i<size;i++)      
                data[i] = other.data[i];
            cout<<"copy consturctor called"<<endl;
        }
        myarr& operator=(const myarr& other)
        {
            if(this == &other)
                return *this;
            delete[] data;
            data = new int[other.size];
            size = other.size;
            for(size_t i=0;i<size;i++)      
                data[i] = other.data[i];
            cout<<"copy assignment operator called"<<endl;
            return *this;
        }
        myarr(myarr&& other)noexcept : size(other.size),data(other.data)
        {
            other.data = nullptr;
            other.size = 0;
            cout<<"move constructor called"<<endl;
        }
        myarr& operator=(myarr&& other)noexcept
        {
            if(this == &other)
                return *this;

            delete[] data;
            data = other.data;
            size = other.size;

            other.data = nullptr;
            other.size = 0;
            cout<<"Move assignment operator called"<<endl;
            return *this;
        }
};

int main()
{
    myarr a;
    myarr b = a;
}