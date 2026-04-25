#include<bits/stdc++.h>
using namespace std;
//SELECTION SORT     ------------------    find minimum and push it to first
void Selection(vector<int> &nums){
    int n = nums.size();
    for(int i=0;i<=n-2;i++){
        int minidx=i;
        for(int j=i+1;j<=n-1;j++){             // Best case O(n2) //Worst O(n2)
            if(nums[minidx]>nums[j]){ 
                minidx = j;
            }
        }
        swap(nums[i],nums[minidx]);
    }
} 
//BUBBLE SORT      -------------------     compare n and n+1 element idx
void Bubble(vector<int> &v){
    int n = v.size();
    for(int i=0;i<=n-2;i++){
        bool swapped = 0;
        for(int j=0;j<=n-2-i;j++){     // Best case O(n) //Worst O(n2)
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
                swapped = 1;
            }
        }
        if(!swapped) break;//already sorted
    }
}
//INSERTION SORT
void Insertion(vector<int>& a){
    int n = a.size();
    for(int i=1;i<n;i++){
        int j=i;
        while(j>0 && a[j]<a[j-1]){
            swap(a[j],a[j-1]);
            j--;
        }
    }
}


///////////////////////////////////////////// PRACTICE  ///////////////////////////////////////////////

void bubble(vector<int> &v){
    for(int i=0;i<=v.size()-2;i++){
        int isSwap = false;
        for(int j=0;j<=v.size()-2-i;j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
                isSwap=true;
            }
        }
        if(!isSwap) break;
    }
}
void selection(vector<int>&v){
    for(int i=0;i<=v.size()-2;i++){
        int min = i;
        for(int j=i;j<=v.size()-1;j++){
            if(v[min]>v[j]){
                min = j;
            }
        }
        swap(v[min],v[i]);
    }
}
void insertion(vector<int>&v){
    for(int i=0;i<=v.size()-1;i++){
        int j=i;
        while(j>0 && v[j]<v[j-1]){
            swap(v[j],v[j-1]);
            j--;
        }
    }
}
int main(){
    vector<int>vec = {11,8,7,6,0,5,4,9,1};
    insertion(vec);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }
}