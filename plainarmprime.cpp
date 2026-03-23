#include<bits/stdc++.h>
using  namespace std;

class PrimePalinArm{
    private:
        int num;
    public:
        void getnum()
        {
            cout<<"enter the number"<<endl;
            cin>>num;
        }
        void palindrome()
        {
            int x=num;
            int ans = 0;
            int rem;
            while(x!=0)
            {
                rem=x%10;
                ans=(10*ans)+rem;
                x/=10;
            }
            if(ans==num)        
                cout<<"Palindrome"<<endl;
            else
                cout<<"Not Palindrome"<<endl;
        }

        void prime()
        {
            if(num<=1){
                cout<<"Not Prime";
                return;
            }
            for(int i=2;i*i<num;i++)
            {
                if(num%i==0)
                {
                    cout<<"Not Prime"<<endl;
                    return;
                }
            }
            cout<<"Prime"<<endl;
        }

        void arms()
        {
            int ans=0;
            int rem;
            int x=num;
            while(x!=0)
            {
                rem=x%10;
                ans = (rem*rem*rem)+ans;
                x/=10;
            }
            if(ans==num)
                cout<<"Armstrong"<<endl;
            else    
                cout<<"Not Armstrong"<<endl;
        }
};

int main(){
    PrimePalinArm a;
    a.getnum();
    a.arms();
    a.palindrome();
    a.prime();
}