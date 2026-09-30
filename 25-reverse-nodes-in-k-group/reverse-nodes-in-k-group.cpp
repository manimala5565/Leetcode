#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* groupPrev = dummy;

        while (true) {

            // Find the kth node
            ListNode* kth = groupPrev;

            for (int i = 0; i < k; i++) {
                kth = kth->next;

                // Less than k nodes remaining
                if (kth == NULL)
                    return dummy->next;
            }

            ListNode* groupNext = kth->next;

            // Reverse the group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Connect previous part to reversed group
            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;

            // Move to next group
            groupPrev = temp;
        }
    }
};