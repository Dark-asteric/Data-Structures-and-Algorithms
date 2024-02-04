/**
*	author: shafi
*	created: 04.02.2024 12.45.40
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
// Method - 1:

int height(TreeNode* root){
    if(root == 0){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return 1 + max(left,right);
}

int getDepth(TreeNode* root){
    if(root == 0){
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    int ld = getDepth(root->left);
    int rd = getDepth(root->right);
    return max(lh+rh+1,max(ld,rd));
}

// Method - 2:
/// O(n^2)
int getHeight(TreeNode* root,int &maxDia){
    if(root == 0){
        return 0;
    }
    int lh = getHeight(root->left,maxDia);
    int rh = getHeight(root ->right, maxDia);
    int current = lh + rh + 1;
    maxDia = max(maxDia,current);
    return max(lh,rh) + 1;
}

int depth(TreeNode* root){
    int maxDia = INT_MIN;
    getHeight(root,maxDia);
    return maxDia;
}

// Method - 3: optimized way:
// O(n)
int getdepth(TreeNode* root, int* h){
    if(root == 0){
        *h = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int ld = getdepth(root->left,&lh);
    int rd = getdepth(root->right,&rh);
    int cur = lh + rh + 1;
    *h = max(lh,rh) + 1;
    return max(cur,max(ld,rd));
}
/**
 *     4
 *  5    3
 * 8 10    18
*/

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
    int ans0 = getDepth(root);
    cout<<ans0<<endl;
    int ans1 = depth(root);
    cout<<ans1<<endl;
    int h = 0;
    int ans2 = getdepth(root,&h);
    cout<<ans2<<endl;
    return 0;
}
