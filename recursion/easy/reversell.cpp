#include <iostream>
using namespace std;

// Define the ListNode structure and merge function (same as above)
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* reversed = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;

    return reversed;
}


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

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    // Example lists
    int arr[] = {1, 2, 4};


    ListNode* list1 = createList(arr, 3);


    cout << "List 1: ";
    printList(list1);

    ListNode* reversedList = reverseList(list1);

    cout << "Reversed List: ";
    printList(reversedList);

    return 0;
}
