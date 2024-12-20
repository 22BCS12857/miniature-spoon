#include <iostream>
using namespace std;

// Definition of the SinglyLinkedListNode structure
class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Definition of the SinglyLinkedList class
class SinglyLinkedList {
public:
    SinglyLinkedListNode* head;

    SinglyLinkedList() {
        head = nullptr;
    }

    // Method to insert a node at the end of the list
    void insertNode(int data) {
        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
        if (!head) {
            head = newNode;
        } else {
            SinglyLinkedListNode* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Method to reverse the linked list
    SinglyLinkedListNode* reverse() {
        SinglyLinkedListNode* prev = nullptr;
        SinglyLinkedListNode* current = head;

        while (current != nullptr) {
            SinglyLinkedListNode* nextNode = current->next;  // Save the next node
            current->next = prev;  // Reverse the current node's pointer
            prev = current;  // Move prev to the current node
            current = nextNode;  // Move to the next node
        }

        head = prev;  // prev is the new head of the reversed list
        return head;
    }

    // Method to print the linked list
    void printList() {
        SinglyLinkedListNode* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
};

// Driver code
int main() {
    SinglyLinkedList* list = new SinglyLinkedList();
    
    // Inserting nodes into the linked list
    list->insertNode(1);
    list->insertNode(2);
    list->insertNode(3);
    list->insertNode(4);
    list->insertNode(5);
    
    cout << "Original List: ";
    list->printList();

    // Reversing the linked list
    list->reverse();
    
    cout << "Reversed List: ";
    list->printList();

    delete list;
    
    return 0;
}
