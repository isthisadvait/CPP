#include <iostream>
#include <queue>
#include <stack>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node()
    {
        left = NULL;
        right = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
class BinaryTree
{
    Node *root;

public:
    BinaryTree()
    {
        root = NULL;
    }
    BinaryTree(Node *root)
    {
        this->root = root;
    }

    void insert(int data)
    {
        insertData(root, data);
    }
    void inorder()
    {
        inOrder(root);
    }
    void preorder()
    {
        preOrder(root);
    }
    void postorder()
    {
        postOrder(root);
    }
    void levelorder()
    {
        levelOrder(root);
    }
    int height()
    {
        return heightOfBT(root);
    }
    void printNodesKDistance(int k)
    {
        printK(root, k);
    }
    int size()
    {
        return getSize(root);
    }
    int maximumValue()
    {
        return getMax(root);
    }

private:
    // Function to insert a new element in a Binary Tree
    void insertData(struct Node *root, int key)
    {
        queue<struct Node *> q;
        q.push(temp);

        // Do level order traversal until we find
        // an empty place.
        while (!q.empty())
        {
            struct Node *temp = q.front();
            q.pop();

            if (!temp->left)
            {
                temp->left = newNode(key);
                break;
            }
            else
                q.push(temp->left);

            if (!temp->right)
            {
                temp->right = newNode(key);
                break;
            }
            else
                q.push(temp->right);
        }
    }
    void inOrder(Node *root)
    {
        if (root != NULL)
        {
            inOrder(root->left);
            cout << root->data << " ";
            inOrder(root->right);
        }
    }
    void inOrderIterative(Node *root)
    {
        stack<Node *> st;
        Node *curr = root;
        while (curr != NULL || st.empty() == false)
        {
            while (curr != NULL)
            {
                /* code */
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            cout << curr->data << " ";
            curr = curr->left;
        }
    }
    void preOrder(Node *root)
    {
        if (root != NULL)
        {
            cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }
    void preOrderIterative(Node *root)
    {
        stack<Node *> st;
        Node *curr = root;
        while (curr != NULL || st.empty() == false)
        {
            while (curr != NULL)
            {
                /* code */
                cout << curr->data << " ";
                if (curr->right)
                    st.push(curr->right);
                curr = curr->left;
            }
            if (st.empty() == false)
            {
                curr = st.top();
                st.pop();
            }
        }
    }
    void postOrder(Node *root)
    {
        if (root != NULL)
        {

            postOrder(root->left);
            postOrder(root->right);
            cout << root->data << " ";
        }
    }
    void levelOrder(Node *root)
    {
        if (root == NULL)
            return;
        queue<Node *> qu;
        qu.push(root);
        while (!qu.empty())
        {

            Node *temp = qu.front();
            cout << temp->data << " ";
            qu.pop();
            if (temp->left)
            {
                qu.push(temp->left);
            }
            if (temp->right)
            {

                qu.push(temp->right);
            }
        }
    }
    int heightOfBT(Node *root)
    {
        if (root == NULL)
            return 0;
        return max(heightOfBT(root->left), heightOfBT(root->right)) + 1;
    }
    void printK(Node *root, int k)
    {
        if (root == NULL)
            return;
        if (k == 0)
            cout << root->data << " ";
        printK(root->left, k - 1);
        printK(root->right, k - 1);
    }
    int getSize(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return 1 + getSize(root->left) + getSize(root->right);
    }
    int getMax(Node *root)
    {
        if (root == NULL)
        {
            return INT_MIN;
        }
        return max(root->data, max(getMax(root->left), getMax(root->right)));
    }
};
int main()
{
    Node *n1 = new Node(2);
    Node *n2 = new Node(3);
    Node *n3 = new Node(4);
    Node *n4 = new Node(6);
    Node *n5 = new Node(7);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n3->right = n5;

    BinaryTree *t = new BinaryTree(n1);
    // t->inorder();
    // cout << "\n";
    // t->preorder();
    // cout << "\n";
    // t->postorder();
    // cout << "\n";
    // cout << t->height() << "\n";
    // t->printNodesKDistance(2);
    // t->levelorder();
    // cout << t->inOrderIterative(n1);
}