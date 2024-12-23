#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    ListNode* front;

    bool isPalindromeRecursive(ListNode* current) {
        if (!current) return true;

        bool is_palindrome = isPalindromeRecursive(current->next) && (front->val == current->val);
        front = front->next;
        return is_palindrome;
    }

public:
    bool isPalindrome(ListNode* head) {
        front = head;
        return isPalindromeRecursive(head);
    }
};

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < size; i++) {
        ListNode* newNode = new ListNode(arr[i]);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

// Helper function to print the list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test the palindrome check
int main() {
    Solution solution;

    int arr1[] = {1, 2, 2, 1};
    int arr2[] = {1, 2};

    ListNode* list1 = createList(arr1, 4);
    ListNode* list2 = createList(arr2, 3);

    cout << "List 1: ";
    printList(list1);
    cout << "Is Palindrome? " << (solution.isPalindrome(list1) ? "Yes" : "No") << endl;

    cout << "List 2: ";
    printList(list2);
    cout << "Is Palindrome? " << (solution.isPalindrome(list2) ? "Yes" : "No") << endl;

    return 0;
}
