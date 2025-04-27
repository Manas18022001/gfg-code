/* A binary tree node structure

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
 */

class Solution {
  public:
  
    // int height (Node* root){
    //     if(root == NULL){
    //         return 0;
    //     }
        
    //     int left = height(root->left);
    //     int right = height(root->right);
        
    //     int ans = max(left, right) + 1;
    //     return ans;
    // }  
    
    pair<bool, int> isBalancedFast(Node* root){
        if(root == NULL){
            pair<bool, int> p = make_pair(1, 0);
            return p;
        }
        
        pair<bool, int> left  = isBalancedFast(root->left);
        pair<bool, int> right = isBalancedFast(root->right);
        
        bool leftAns  = left.first;
        bool rightAns = right.first;
        int hLeft = left.second;
        int hRight = right.second;
        bool diff = abs(hLeft-hRight) <= 1;
        
        pair<bool, int> ans;
        ans.first = leftAns&rightAns&diff;
        ans.second = max(hLeft, hRight) + 1;
        
        return ans;
        
    }
    
    bool isBalanced(Node* root) {
        // Code here
        // if(root == NULL){
        //     return true;
        // }
        
        // bool left = isBalanced(root->left);
        // bool right = isBalanced(root->right);
        
        // int hLeft = height(root->left);
        // int hRight = height(root->right);
        
        // bool diff = abs(hLeft - hRight) <= 1;
        
        // return left&right&diff;
        
        return isBalancedFast(root).first;
        
    }
};