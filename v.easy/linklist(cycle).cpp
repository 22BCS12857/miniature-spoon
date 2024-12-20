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
    int n=;
    int arr[n]={7,7,7,7};
    for(int i=0;i<n;i++){
        list.append(arr[i]);
    }
    cout << "Created Linked List: ";
    list.printList();
    if(list.hasCycle()){
        cout<<"Cycle Detected";
    }
    else{
        cout<<"No Cycle Detected";
    }

    return 0;
}
