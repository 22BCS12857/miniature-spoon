#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        queue<Node*> q;
        q.push(root);        
        while(q.size()) {
            Node* rightNode = nullptr;                    // set rightNode to null initially
            for(int i = q.size(); i; i--) {                // traversing each level
                auto cur = q.front(); q.pop();            // pop a node from current level and,
                cur -> next = rightNode;                  // set its next pointer to rightNode
                rightNode = cur;                          // update rightNode as cur for next iteration
                if(cur -> right)                          // if a child exists
                    q.push(cur -> right),                 // IMP: push right first to do right-to-left BFS
                    q.push(cur -> left);                  // then push left
            }
        }
        return root;
    }
};

void printNextPointers(Node* root) {
    while (root) {
        Node* current = root;
        cout<<"[";
        while (current) {
            cout << current->val;
            if (current->next) {
                cout << " -> ";
            } else {
                cout << " ->#";
            }
            current = current->next;
        }
        root = root->left;
        cout<<"]";
    }
}

int main() {
    // Create nodes
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    // Create solution object and call the connect method
    Solution solution;
    solution.connect(root);

    // Print the tree with next pointers
    printNextPointers(root);

    return 0;
}
