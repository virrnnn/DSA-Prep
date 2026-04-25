#include "LL_PRACTICE.h"

// void sort(LL<int>&l){
//     LL::Node zerodum(0),onedum(0),twodum(0);
//     LL<int>::Node* zero = &zerodum;
//     LL<int>::Node* one = &onedum;
//     LL<int>::Node* two = &twodum;
//     LL<int>::Node* curr = l.gethead();
//     while(curr){
//         if(curr->data == 0){
//             zero->next = curr;
//             zero = zero->next;
//         }
//         else if(curr->data == 1){
//             one->next = curr;
//             one = one->next;
//         }
//         else if(curr->data == 2){
//             two->next = curr;
//             two = two->next;
//         }
//         curr = curr->next;
//     }
//     two->next = nullptr;
//     l.sethead(zerodum.next);
//     zero->next = onedum.next;
//     one->next = twodum.next;
// }
void sort012(LL<int>& l) {
    LL<int>::Node zerodum(0), onedum(0), twodum(0);
    auto zero = &zerodum;
    auto one  = &onedum;
    auto two  = &twodum;
    auto curr = l.gethead();

    while (curr) {
        if (curr->data == 0) {
            zero->next = curr;
            zero = zero->next;
        }
        else if (curr->data == 1) {
            one->next = curr;
            one = one->next;
        }
        else {
            two->next = curr;
            two = two->next;
        }
        curr = curr->next;
    }

    // terminate last list
    two->next = nullptr;

    // connect lists
    one->next = twodum.next;
    zero->next = onedum.next ? onedum.next : twodum.next;

    // set head safely
    if (zerodum.next)
        l.sethead(zerodum.next);
    else if (onedum.next)
        l.sethead(onedum.next);
    else
        l.sethead(twodum.next);
}
int main(){
    LL<int>l;
    l.insertfront(0);
    l.insertback(0);
    l.insertfront(1);
    l.insertback(1);
    l.insertfront(2);
    l.insertback(2);
    sort012(l);
    l.printll();
}
