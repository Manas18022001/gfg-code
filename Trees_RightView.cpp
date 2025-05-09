/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution {
  public:
    
    void solve(Node* root, vector<int> &ans, int lvl, map<int, int> &mp){
        if(root == NULL){
            return;
        }
        
        mp[lvl] = root->data;
        
        if(root->left)
            solve(root->left, ans, lvl+1, mp);
        
        if(root->right)
            solve(root->right, ans, lvl+1, mp);
    }
    
    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root) {
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