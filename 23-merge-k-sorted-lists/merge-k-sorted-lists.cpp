#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Min heap
        priority_queue<
            ListNode*,
            vector<ListNode*>,
            compare
        > pq;

        // Add first node of every list
        for (ListNode* node : lists) {
            if (node != NULL) {
                pq.push(node);
            }
        }

        // Dummy node
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while (!pq.empty()) {

            // Get smallest node
            ListNode* smallest = pq.top();
            pq.pop();

            // Add it to result
            current->next = smallest;
            current = current->next;

            // Add next node from same list
            if (smallest->next != NULL) {
                pq.push(smallest->next);
            }
        }

        return dummy->next;
    }

private:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
};