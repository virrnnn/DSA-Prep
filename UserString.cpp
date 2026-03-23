#include<bits/stdc++.h>
using namespace std;

class stringx{

    private:
        char* data; 
    public:
        stringx(){
            data = new char[1];
            data[0] = '\0';
        }
        ~stringx() {   // ADDED
            delete[] data;
        }
        stringx(const char* str){
            data = new char[strlen(str)+1];
            strcpy(data,str);
        }
        stringx(const stringx& other){
            data = new char[strlen(other.data)+1];
            strcpy(data,other.data);
        }
        stringx& operator=(const stringx& other){
            if(this == &other)
                return *this;

            delete[] data;
            data = new char[strlen(other.data)+1];
            strcpy(data,other.data);
            return *this;
        }
        stringx(stringx &&other)noexcept{
            data = other.data;
            other.data = nullptr;
        }
        stringx& operator=(stringx &&other)noexcept{
            if(this!=&other){
                delete[] data;
                data = other.data;
                other.data = nullptr;
            }
            return *this;
        }
        stringx operator+(const stringx& other)const{  // should not return by reference
            stringx temp;
            delete[] temp.data;
            temp.data = new char[strlen(data)+strlen(other.data)+1];
            strcpy(temp.data,data);
            strcat(temp.data,other.data);
            return temp; // return temp not this 
        }

        //should be friend if overloaded inside class and if not friend then declare it outside
        friend ostream& operator<<(ostream& os, const stringx&other){
            if(other.data){
                os<<other.data;                                                                                                             
            }
            return os;
        }
        void print(){
            if(data)
                cout<<data;
        }
};

int main(){
    stringx str("Viren");
    stringx str1 = str;
    str.print();
    stringx str2 = move(str);
    str.print();
    str2.print();
    stringx str4("BOOK");
    cout<<str4;
}