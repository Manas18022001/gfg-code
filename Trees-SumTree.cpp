/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
    pair<bool, int> isSumTreeFast(Node* root){
        if(root == NULL){
            pair<bool, int> p = make_pair(1, 0);
            return p;
        }    
        
        if(root->left == NULL && root->right == NULL){
            pair<bool, int> p = make_pair(1, root->data);
            return p;
        }
        
        pair<bool, int> leftAns  = isSumTreeFast(root->left);
        pair<bool, int> rightAns = isSumTreeFast(root->right);
        
        bool left = leftAns.first;
        bool right = rightAns.first;
        bool val = (root->data == leftAns.second + rightAns.second);
        pair<bool, int> ans;
        
        if(left&&right&&val){
            ans.first = 1;
            ans.second = 2*root->data;
        }
        
        else{
            ans.first = 0;
        }
        
        return ans;
    }
    
    bool isSumTree(Node* root) {
        // Your code here
        if(root == NULL){
            return 1;
        }
        
        return isSumTreeFast(root).first;
        
    }
};