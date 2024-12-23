#include <iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Base case: if there are less than k nodes left, return the head
        ListNode* temp = head;
        int count = 0;
        while (temp != nullptr && count < k) {
            temp = temp->next;
            count++;
        }
        if (count < k) {
            return head; // Less than k nodes, return the current head
        }

        // Reverse the first k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        count = 0;
        while (curr != nullptr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Now head is the last node of the reversed group
        // So, we connect the head (which is now the last node of the reversed group) to the result of the next group
        if (next != nullptr) {
            head->next = reverseKGroup(next, k);
        }

        // Return the new head after reversing the first k nodes
        return prev;
    }
};

// Helper function to create a linked list from an array
ListNode* createList(const vector<int>& arr) {
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < arr.size(); ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example usage
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode* head = createList(arr);
    int k = 2;

    Solution solution;
    ListNode* result = solution.reverseKGroup(head, k);
    printList(result);  // Output: 3 2 1 4 5

    return 0;
}
