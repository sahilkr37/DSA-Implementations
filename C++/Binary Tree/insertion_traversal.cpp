// Create binary tree using level order
#include <bits/stdc++.h>
using namespace std;

class Node
{
private:
    int val;
    Node *left, *right;

public:
    Node(int value)
    {
        val = value;
        left = right = NULL;
    }
    friend class BinaryTree;
};
class BinaryTree
{
private:
    Node *root;

public:
    BinaryTree()
    {
        root = NULL;
    }
    void levelOrderInsertion()
    {
        int rootVal;
        cout << "Enter the root element of tree: ";
        cin >> rootVal;
        cout << endl;
        root = new Node(rootVal);

        queue<Node *> q;
        q.push(root);
        int first, last;

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            cout << "Enter left value of " << temp->val << " (-1 for no node): ";
            cin >> first;
            cout << endl;
            if (first != -1)
            {
                temp->left = new Node(first);
                q.push(temp->left);
            }

            cout << "Enter right value of " << temp->val << " (-1 for no node): ";
            cin >> last;
            cout << endl;
            if (last != -1)
            {
                temp->right = new Node(last);
                q.push(temp->right);
            }
        }
    }

    void levelOrderTraversal(){
        
    }
};

int main()
{
    BinaryTree bt1;
    bt1.levelOrderInsertion();

    return 0;
}