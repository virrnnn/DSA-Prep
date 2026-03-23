#include<bits/stdc++.h>
using namespace std;
template <typename T>
class mvector 
{
    private:
        T* data;
        size_t size;
        size_t cap;
        void resize()
        {
            size_t newcap = (cap == 0)?1:cap*2;
            T* newdata = new T[newcap];
            for(size_t i=0;i<size;i++)
                newdata[i]=std::move(data[i]);
            delete[] data;
            data = newdata;
            cap=newcap;
        }
    public:
        mvector():size(0),cap(0),data(nullptr) {}

        mvector(size_t c):size(0),cap(c),data(new T[c]){}

        ~mvector()
        {
            delete[] data;
        }

        mvector(const mvector &other):size(other.size),cap(other.cap),data(new T[other.cap])
        {
            for(size_t i=0;i<size;i++)
                data[i]=other.data[i];
        }
        mvector& operator=(const mvector &other)
        {
            if(this == &other)
                return *this;
            
            mvector temp(other);
            swap(data,temp.data);
            swap(cap,temp.cap);
            swap(size,temp.size);

            return *this;
        }
        myvec(myvec &&other):size(other.size),cap(other.cap),data(other.data)
        {
            other.data = nullptr;
            other.size = 0;
            other.cap = 0;
        }
        myvec& operator=(myvec &&other)
        {
            if(this!=&other)
            {
                delete[] data;
                data = other.data;
                size = other.size;
                cap = other.cap;

                other.data = nullptr;
                other.size=0;
                other.cap=0;
            }
            return *this;
        }
        void pushback(const T &val)
        {
            if(size == cap)
                resize();
            data[size++] = val;
        }
        T& operator[](size_t idx)
        {
            if(idx>=size)
                throw out_of_range("Index out of range");
            return data[idx];
        }
        bool Isempty()const {return size==0;}
        void clear(){size = 0;}
        size_t getsize()const {return size;}
        size_t getcap()const{return cap;}
        void displayarr()const
        {
            for(size_t i=0;i<size;i++)
                cout<<"element - "<<i<<"="<<data[i]<<endl;
        }
}