#include <bits/stdc++.h>
using namespace std;

class PrimePlain
{
public:

    // Prime Check
    static bool isPrime(int n){
        if(n <= 1) return false;

        for(int i = 2; i * i <= n; i++){
            if(n % i == 0)
                return false;
        }
        return true;
    }

    // Palindrome Check
    static bool isPalindrome(int n){
        if(n < 0) return false;

        int original = n;
        int reverse = 0;

        while(n != 0){
            reverse = reverse * 10 + (n % 10);
            n /= 10;
        }

        return original == reverse;
    }

    // Armstrong Check (Works for any digits)
    static bool isArmstrong(int n){
        if(n < 0) return false;

        int original = n;
        int digits = 0;
        int temp = n;

        while(temp != 0){
            digits++;
            temp /= 10;
        }

        int sum = 0;
        while(n != 0){
            int rem = n % 10;

            int power = 1;
            for(int i = 0; i < digits; i++)
                power *= rem;

            sum += power;
            n /= 10;
        }

        return original == sum;
    }
};

int main()
{
    cout << boolalpha;

    cout << "Prime(7): " << PrimePlain::isPrime(7) << endl;
    cout << "Palindrome(121): " << PrimePlain::isPalindrome(121) << endl;
    cout << "Armstrong(153): " << PrimePlain::isArmstrong(153) << endl;

    return 0;
}