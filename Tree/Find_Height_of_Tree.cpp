/**
*	author: shafi
*	created: 04.02.2024 11.56.54
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
    new_node -> left = build(nodes);
    new_node -> right = build(nodes);
    return new_node;
}

int height(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root -> right);
    return 1 + max(left,right);
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
    int depth = height(root);
    cout<<"height of tree is : "<<depth<<endl;
    return 0;
}
