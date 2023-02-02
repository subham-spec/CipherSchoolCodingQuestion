#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
bool isLeaf(Node* root){
    return (root!=NULL && !root->left && !root->right);
}
void maxPath(Node* root, int sum, int &maxSum){
    if(root == NULL)
        return;
    sum += root->data;
    if(isLeaf(root)){
        maxSum = max(maxSum, sum);
        return;
    }
    else{
        maxPath(root->left, sum, maxSum);
        maxPath(root->right, sum, maxSum);
    }
}
int maxPath(Node* root){
    int maxSum = 0;
    maxPath(root, 0, maxSum);
    return maxSum;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->right->left->left = new Node(6);

    maxPath(root);

    return 0;
}