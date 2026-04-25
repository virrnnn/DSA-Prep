#include<bits/stdc++.h>
using namespace std;

int main(){
    int* ptr1 = new int(); //- returns typed pointer,Cstr is called,throws excption Bad_alloc,overloaded
    delete ptr1;



    int* ptr2 = (int*) malloc(sizeof(int));  //- returns raw memory (void*),Cstr not called,returns null on failed allocation,cannot overloaded
    free(ptr2);
}