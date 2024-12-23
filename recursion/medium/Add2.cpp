#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0) {
    // Base case: if both lists are null and no carry, return null
    if (!l1 && !l2 && carry == 0) return nullptr;

    // Calculate the sum of the current digits and the carry
    int sum = carry;
    if (l1) sum += l1->val;
    if (l2) sum += l2->val;

    // Create a new node with the value of the sum's digit
    ListNode* newNode = new ListNode(sum % 10);

    // Recursive call for the next digits with the updated carry
    newNode->next = addTwoNumbers(
        l1 ? l1->next : nullptr,
        l2 ? l2->next : nullptr,
        sum / 10
    );

    return newNode;
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

int main() {
    // Example lists
    int arr1[] = {2, 4, 3};  // Represents 342
    int arr2[] = {5, 6, 4};  // Represents 465

    ListNode* l1 = createList(arr1, 3);
    ListNode* l2 = createList(arr2, 3);

    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);

    ListNode* result = addTwoNumbers(l1, l2);

    cout << "Sum: ";
    printList(result);

    return 0;
}
