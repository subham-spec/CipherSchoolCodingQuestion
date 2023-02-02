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
int leafToLeaf(Node* root, int *sum){
    if(root == NULL){
        *sum = 0;
        return 0;
    }
    if(isLeaf(root)){
        *sum = 0;
        return root->data;
    }
    int lsum = 0, rsum = 0;
    lsum = leafToLeaf(root->left, sum);
    rsum = leafToLeaf(root->right, sum);
    if(root->left && root->right){
        *sum = max(*sum, root->data+lsum+rsum);
        return max(lsum, rsum) + root->data;
    }
    else if(root->left)
        return root->data + lsum;
    else
        return root->data + rsum;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->right->left->left = new Node(6);

    int sum = leafToLeaf(root, 0);
    cout<<sum<<endl;
    return 0;
}