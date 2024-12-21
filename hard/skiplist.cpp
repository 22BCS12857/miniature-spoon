#include <iostream>
#include <vector>
#include <cstdlib>  // For rand()

using namespace std;

class Node {
public:
    int data;
    vector<Node *> next;
    Node(int data, int Level) : data(data), next(Level + 1, nullptr) {}
};

class skipList {
private:
    Node *head;
    int Level;

public:
    skipList(int size) {
        head = new Node(0, size);
        Level = 0;
    }

    void add(int data) {
        int newLevel = 0;
        while (newLevel < Level && (rand() % 2) == 1) {
            newLevel++;
        }
        if (Level < newLevel) {
            head->next.resize(newLevel + 1, nullptr);
            Level = newLevel;
        }

        Node *current = head;
        vector<Node *> Update(Level + 1, nullptr);
        for (int i = Level; i >= 0; i--) {
            while (current->next[i] && current->next[i]->data < data) {
                current = current->next[i];
            }
            Update[i] = current;
        }

        current = current->next[0];
        if (current == nullptr || current->data != data) {
            Node *newNode = new Node(data, Level);
            for (int i = 0; i <= newLevel; i++) {
                newNode->next[i] = Update[i]->next[i];
                Update[i]->next[i] = newNode;
            }

            cout << "Element " << data << " inserted successfully.\n";
        } else {
            cout << "Element " << data << " already exists.\n";
        }
    }

    void erase(int data) {
        Node *current = head;
        vector<Node *> Update(Level + 1, nullptr);

        for (int i = Level; i >= 0; i--) {
            while (current->next[i] && current->next[i]->data < data) {
                current = current->next[i];
            }
            Update[i] = current;
        }

        current = current->next[0];
        if (current != nullptr && current->data == data) {
            for (int i = 0; i <= Level; i++) {
                if (Update[i]->next[i] != current) {
                    break;
                } else {
                    Update[i]->next[i] = current->next[i];
                }
            }

            delete current;

            while (Level > 0 && head->next[Level] == nullptr) {
                Level--;
            }

            cout << "Element " << data << " deleted successfully." << endl;
        } else {
            cout << "Element " << data << " not found." << endl;
        }
    }

    bool search(int data) {
        Node *current = head;
        for (int i = Level; i >= 0; i--) {
            while (current->next[i] && current->next[i]->data < data) {
                current = current->next[i];
            }
        }

        current = current->next[0];
        if (current != nullptr && current->data == data) {
            cout << "Element " << data << " found.\n";
            return true;
        } else {
            cout << "Element " << data << " not found.\n";
            return false;
        }
    }

    void display() {
        cout << "Skip List:" << endl;
        for (int i = Level; i >= 0; i--) {
            Node *current = head->next[i];
            cout << "Level " << i << ": ";
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next[i];
            }
            cout << endl;
        }
    }
};

int main() {
    skipList sl(4);
    sl.add(1);
    sl.add(2);
    sl.add(3);
    sl.search(0);
    sl.add(4);
    sl.search(1);
    sl.erase(0);
    sl.erase(1);
    sl.search(1);
    sl.display();  // Optional: to display the final state of the skip list
}
