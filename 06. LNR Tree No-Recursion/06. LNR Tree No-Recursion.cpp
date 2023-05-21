#include <iostream>
#include <stack>
using namespace std;

class Node 
{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) 
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node* insert(Node* root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else 
        {
            Node* cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else 
            {
                cur = insert(root->right, data);
                root->right = cur;
            }
            return root;
        }
    }

    void inOrder(Node* root)
    {
        stack<Node*> s;
        Node* current = root;
        while (current != NULL || !s.empty())
        {
            while (current != NULL)
            {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }

};

int main()
{
    Solution myTree;
    Node* root = NULL;
    int t;
    int data;
    std::cin >> t;
    while (t-- > 0)
    {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
    myTree.inOrder(root);
    return 0;
}