/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}
*/

class Solution {
  public:
    // int height(Node *root){
    //     if(root == NULL){
    //         return 0;
    //     }
    //     int hl = height(root->left);
    //     int hr = height(root->right);
        
    //     return max(hl, hr) + 1;
    // }
    // int diameter(Node* root) {
    //     // Your code here
    //     if(root == NULL){
    //         return 0;
    //     }
        
    //     int op1 = diameter(root->left);
    //     int op2 = diameter(root->right);
        
    //     //find left max
    //     int left = height(root->left);
    //     //find right max
    //     int right = height(root->right);
    //     //sum them
    //     int op3 = left + right;
        
    //     int ans = max(op1, max(op2,op3));
    //     return ans;
        
    // }
    pair<int, int> diameterFast(Node* root){
        if(root == NULL){
            pair<int, int> p = make_pair(0, 0);
            return p;
        }
        
        pair<int, int> left = diameterFast(root->left);
        pair<int, int> right = diameterFast(root->right);
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second;
        
        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(left.second, right.second) + 1;
        return ans;
    }
    
    int diameter(Node* root) {
        // Your code here
        if(root == NULL){
            return 0;
        }
        
        return diameterFast(root).first;
        
    }
};