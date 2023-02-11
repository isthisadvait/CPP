#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(){
        left = NULL;
        right = NULL;
    }
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
class BinaryTree{
    Node *root;
    public:
    BinaryTree(){
        root = NULL;
    }
    BinaryTree(Node *root){
        this->root = root ;
    }

    void inorder(){
       inOrder(root);
    }
    void preorder(){
        preOrder(root);
    }
    void postorder(){
        postOrder(root);
    }
    int height(){
        return heightOfBT(root);
    }
    void printNodesKDistance(int k){
        printK(root,k);
    }
    private :
    void inOrder(Node *root){
        if(root != NULL){
            inOrder(root->left);
            cout<<root->data<<" ";
            inOrder(root->right);

        }
    }
    void preOrder(Node *root){
        if(root !=  NULL){
         cout<<root->data<<" ";
         preOrder(root->left);
         preOrder(root->right);
        }
    } 
    void postOrder(Node *root){
        if(root !=  NULL){
        
         postOrder(root->left);
         postOrder(root->right);
         cout<<root->data<<" ";
        }
    } 
    int heightOfBT(Node *root){
          if (root == NULL) return 0;
          return max(heightOfBT(root->left),heightOfBT(root->right))+1;
    }
    void printK(Node *root ,int k){
        if(root == NULL) return;
        if(k==0) cout<<root->data<<" ";
        printK(root->left,k-1); 
        printK(root->right,k-1); 
    }
};
int main(){
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
    t->inorder();
    cout<<"\n";
    t->preorder();
    cout<<"\n";
    t->postorder();
    cout<<"\n";
    cout<<t->height()<<"\n";
    t->printNodesKDistance(2);
    
}