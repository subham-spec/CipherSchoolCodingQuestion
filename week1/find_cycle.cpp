#include <bits/stdc++.h>
using namespace std;
class ListNode{
    public:
        int val;
        ListNode* next;
        ListNode(int v){
            val = v;
        }
};
bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next ->next;
        slow = slow -> next;
        if(slow == fast)
            return true;
    }
    return false;
}
int main(){

}