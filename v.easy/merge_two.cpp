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

    // Method to merge two sorted linked lists
    SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
        SinglyLinkedListNode* head = nullptr;
        if (head1 == nullptr) return head2;
        else if (head2 == nullptr) return head1;
        else {
            // Initialize the head of the merged list
            if (head1->data <= head2->data) {
                head = head1;
                head1 = head1->next;
            } else {
                head = head2;
                head2 = head2->next;
            }

            // Initialize a pointer to traverse the merged list
            SinglyLinkedListNode* ptr = head;

            // Merge the lists
            while (head1 != nullptr || head2 != nullptr) {
                if (head1 != nullptr && head2 != nullptr) {
                    if (head1->data <= head2->data) {
                        ptr->next = head1;
                        head1 = head1->next;
                    } else {
                        ptr->next = head2;
                        head2 = head2->next;
                    }
                } else if (head1 != nullptr) {
                    ptr->next = head1;
                    head1 = head1->next;
                } else if (head2 != nullptr) {
                    ptr->next = head2;
                    head2 = head2->next;
                }
                ptr = ptr->next;
            }
        }
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
    // Create two sorted lists
    SinglyLinkedList* list1 = new SinglyLinkedList();
    list1->insertNode(1);
    list1->insertNode(3);
    list1->insertNode(5);

    SinglyLinkedList* list2 = new SinglyLinkedList();
    list2->insertNode(2);
    list2->insertNode(4);
    list2->insertNode(6);

    cout << "List 1: ";
    list1->printList();

    cout << "List 2: ";
    list2->printList();

    // Merging the two lists
    SinglyLinkedListNode* mergedHead = list1->mergeLists(list1->head, list2->head);

    // Print the merged list
    cout << "Merged List: ";
    SinglyLinkedList mergedList;
    mergedList.head = mergedHead;  // Assign merged head to the merged list
    mergedList.printList();

    delete list1;
    delete list2;
    
    return 0;
}
