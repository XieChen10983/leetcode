#include <iostream>
#include "2021_3_1/2021_3_1_6.h"
#include <cctype>

using namespace std;

void printList(ListNode* head){
    while (head != nullptr){
        cout << head->val << '\t';
        head = head->next;
    }

    cout << endl;
}

int main() {
    auto* base = new ListNode(1);
    base->next = new ListNode(4);
    base->next->next = new ListNode(3);
    base->next->next->next = new ListNode(2);
    base->next->next->next->next = new ListNode(5);
    base->next->next->next->next->next = new ListNode(2);
    printList(base);
    auto* out = partition(base, 3);
    printList(out);
    return 0;
}
