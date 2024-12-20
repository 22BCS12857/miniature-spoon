#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Linked List class
class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = nullptr;
    }

    // Function to add a node at the end of the list
    void append(int newData) {
        Node* newNode = new Node();
        newNode->data = newData;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = newNode;
    }

    // Function to delete a node with a specific key
 void deleteNode(int key) {
    Node* temp = head;
    Node* prev = nullptr;

    // Traverse the list and delete all occurrences of the specified key
    while (temp != nullptr) {
        // If the node to be deleted is the head node
        if (temp->data == key) {
            if (prev == nullptr) {
                // If the node to be deleted is the head, update head pointer
                head = temp->next;
            } else {
                // If the node is not the head, adjust the previous node's next pointer
                prev->next = temp->next;
            }
            // Delete the current node and move to the next node
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        } else {
            // Move to the next node if current node is not the one to delete
            prev = temp;
            temp = temp->next;
        }
    }
}
bool hasCycle() {
    if (head == nullptr) return false;

    Node* slow = head;
    Node* fast = head;

    // Traverse the list with two pointers
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;         
        fast = fast->next->next;   

        if (slow == fast) {
            // If slow and fast pointers meet, there is a cycle
            return true;
        }
    }

    // If fast pointer reaches the end, there's no cycle
    return false;
}


    // Function to print the linked list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* current = head;
        Node* next;

        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }

        head = nullptr;
    }
};

int main() {
    LinkedList list;
    int arr[4]={7,7,7,7};
    for(int i=0;i<7;i++){
        list.append(arr[i]);
    }
    cout << "Created Linked List: ";
    list.printList();

    list.deleteNode(7);
    cout << "Linked List after Deletion: ";
    list.printList();

    return 0;
}
