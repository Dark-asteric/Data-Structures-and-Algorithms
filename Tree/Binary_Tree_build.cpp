/**
*	author: shafi
*	created: 04.02.2024 10.38.47
**/
#include "bits/stdc++.h"
using namespace std;
int idx = -1;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode* build(int nodes[]){
    idx++;
    if(nodes[idx] == -1){
        return 0;
    }
    TreeNode* new_node = new TreeNode(nodes[idx]);
    new_node->left = build(nodes);
    new_node->right = build(nodes);
    return new_node;
}

void preorder(TreeNode* root){
    if(root == NULL){
        return;
    }
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void postorder(TreeNode* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    int nodes[n];
    for(int i=0;i<n;i++){
        cin>>nodes[i];
    }
    TreeNode* root = build(nodes);
    cout<<"preorder : ";
    preorder(root);
    cout<<endl;
    cout<<"inorder : ";
    inorder(root);
    cout<<endl;
    cout<<"postorder : ";
    postorder(root);
    cout<<endl;
    cout<<root->val<<endl;
    return 0;
}
