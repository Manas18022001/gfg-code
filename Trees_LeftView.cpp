/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    void solve(Node* root, vector<int> &ans, int lvl, map<int, int> &mp){
        if(root == NULL){
            return;
        }
        
        mp[lvl] = root->data;
        
        if(root->right)
            solve(root->right, ans, lvl+1, mp);
        
        if(root->left)
            solve(root->left, ans, lvl+1, mp);
        
    }
    
    // Function to return list containing elements of right view of binary tree.
    vector<int> leftView(Node *root) {
        // Your Code here
        vector<int> ans;
        map<int, int> mp;
        int lvl = 0;
        
        if(root == NULL){
            return ans;
        }
        
        solve(root, ans, lvl, mp);
        
        for(auto i:mp){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};
int main()
{
    std::cout<<"Hello World";

    return 0;
}