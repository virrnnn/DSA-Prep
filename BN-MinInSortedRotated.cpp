# include<bits/stdc++.h>
using namespace std;

int MinInSortedRotated(const vector<int>&v){
    int low=0,high=v.size()-1,ans=INT_MAX;
    while(low<=high){
        int mid = low+(high-low)/2;
        //OPTIMISATION ONLY IF NO DUPLICATES ARE PRESENT[s]
        if(v[low]<=v[high]){  
            ans = min(ans,v[low]);
            break;
        }
        //OPTIMISATION ONLY IF NO DUPLICATES ARE PRESENT[e]
        if(v[low]<=v[mid]){
            ans = min(ans,v[low]);
            low = mid+1;
        }
        else{
            ans = min(ans,v[mid]);
            high = mid-1;
        }   }
    
    return ans;
}
//No Of Times Array Rotated  is the INDEX OF MIN ELEMENT 
int NoOfTimesRotation(vector<int>&v){
    int low=0,high=v.size()-1,ans=INT_MAX,idx=-1;
    while(left<=high){
        int mid = low+(high-low)/2;
        //OPTIMISATION ONLY IF NO DUPLICATES ARE PRESENT[s]
        if(v[low]<=v[high]){  
            if(v[low]<ans){
                ans = v[low];
                idx = low;
            }
            break;
        }
        //OPTIMISATION ONLY IF NO DUPLICATES ARE PRESENT[e]
        if(v[low]<=v[mid]){
            if(ans<v[low]){
                idx = low;
                ans = v[low];
            }
            low = mid+1;
        }
        else{
            if(ans>v[mid]){
                idx = mid;
                ans = v[mid];
            }
            high = mid-1;
        }
    }
    return idx;
}

int main(){
    vector<int>v={4,5,1,2,3};
    cout<<"MIN = "<<MinInSortedRotated(v)<<endl;
}