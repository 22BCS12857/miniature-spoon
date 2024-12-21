#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Main function to find the twin sum of the linked list.
    int pairSum(ListNode* head) {
        // Use two pointers 'slow' and 'fast' to find the midpoint of the linked list.
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
      
        // Split the linked list into two halves.
        ListNode* firstHalf = head;
        ListNode* secondHalfStart = slow->next;
        slow->next = nullptr; // This null assignment splits the linked list into two.

        // Reverse the second half of the linked list.
        ListNode* reversedSecondHalf = reverse(secondHalfStart);

        // Initialize the maximum pair sum as zero.
        int maxPairSum = 0;

        // Traverse the two halves in tandem to calculate the max pair sum.
        while (firstHalf && reversedSecondHalf) {
            maxPairSum = max(maxPairSum, firstHalf->val + reversedSecondHalf->val);
            firstHalf = firstHalf->next;
            reversedSecondHalf = reversedSecondHalf->next;
        }
      
        return maxPairSum;
    }

    // Helper function to reverse the linked list.
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
      
        // Iterate over the linked list and reverse the pointers.
        while (current) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        // The 'prev' pointer now points to the new head of the reversed linked list.
        return prev;
    }
};

// Helper function to create a linked list from a vector of values.
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to delete a linked list and free memory.
void deleteLinkedList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Main function for testing.
int main() {
    // Example input.
    vector<int> values = {5, 4, 2, 1};
    ListNode* head = createLinkedList(values);

    // Find the maximum twin sum.
    Solution solution;
    int result = solution.pairSum(head);
    cout << "Maximum Twin Sum: " << result << endl;

    // Clean up memory.
    deleteLinkedList(head);

    return 0;
}
