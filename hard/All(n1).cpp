#include <unordered_map>
#include<iostream>
#include <unordered_set>
#include <string>
using namespace std;

class Node {
public:
    Node *prev; // Pointer to the previous node in the doubly linked list
    Node *next; // Pointer to the next node in the doubly linked list
    int count; // Count of occurrences for this node
    unordered_set<string> keys; // Set of keys with this occurrence count

    // Constructor for sentinel node
    Node() : prev(nullptr), next(nullptr), count(0) {}

    // Constructor for actual nodes with a given key and count
    Node(const string &key, int count) : prev(nullptr), next(nullptr), count(count) {
        keys.insert(key);
    }

    // Method to insert a node after this node
    Node *insert(Node *node) {
        node->prev = this;
        node->next = this->next;
        this->next->prev = node;
        this->next = node;
        return node;
    }

    // Remove the node from the doubly linked list
    void remove() {
        this->prev->next = this->next;
        this->next->prev = this->prev;
    }
};

class AllOne {
private:
    Node root; // Sentinel node to mark the beginning and end of the doubly linked list
    unordered_map<string, Node *> nodes; // Mapping from keys to their corresponding nodes

public:
    AllOne() {
        // Initialize the doubly linked list with the sentinel node linking to itself
        root.next = &root;
        root.prev = &root;
    }

    void inc(const string &key) {
        // Increase the count for the key
        if (nodes.find(key) == nodes.end()) {
            // If key is new, insert it into the list
            if (root.next == &root || root.next->count > 1) {
                nodes[key] = root.insert(new Node(key, 1));
            } else {
                root.next->keys.insert(key);
                nodes[key] = root.next;
            }
        } else {
            // If the key already exists, move it to a new or next existing Node
            Node *current = nodes[key];
            Node *next = current->next;

            if (next == &root || next->count > current->count + 1) {
                nodes[key] = current->insert(new Node(key, current->count + 1));
            } else {
                next->keys.insert(key);
                nodes[key] = next;
            }

            // Remove the key from the current Node and delete the Node if it's empty
            current->keys.erase(key);
            if (current->keys.empty()) {
                current->remove();
                delete current; // C++ requires explicit deletion
            }
        }
    }

    void dec(const string &key) {
        auto it = nodes.find(key);
        if (it == nodes.end()) return;

        Node *current = it->second;

        if (current->count == 1) {
            // Remove the key completely if the count is 1
            nodes.erase(key);
        } else {
            // Move the key to the previous Node or create a new Node
            Node *prev = current->prev;

            if (prev == &root || prev->count < current->count - 1) {
                nodes[key] = prev->insert(new Node(key, current->count - 1));
            } else {
                prev->keys.insert(key);
                nodes[key] = prev;
            }
        }

        // Remove the key from the current Node and delete the Node if empty
        current->keys.erase(key);
        if (current->keys.empty()) {
            current->remove();
            delete current; // C++ requires explicit deletion
        }
    }

    string getMaxKey() {
        // Return a key with the maximum count (from the last node with the highest count)
        if (root.prev == &root)
            return ""; // Handle case with no keys

        return *root.prev->keys.begin();
    }

    string getMinKey() {
        // Return a key with the minimum count (from the first node with the lowest count)
        if (root.next == &root)
            return ""; // Handle case with no keys

        return *root.next->keys.begin();
    }
};

int main() {
    AllOne a;

    // Performing various operations and printing the results
    a.inc("hello");
    a.inc("hello");
    cout << "Max Key: " << a.getMaxKey() << endl; // Max Key: hello
    cout << "Min Key: " << a.getMinKey() << endl; // Min Key: Hello
    a.inc("leet");
    cout << "Max Key: " << a.getMaxKey() << endl; // Max Key: hello
    cout << "Min Key: " << a.getMinKey() << endl; // Min Key: Hello

    return 0;
}
