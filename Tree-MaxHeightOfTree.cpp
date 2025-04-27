// User function template for C++

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int height(Node* node) {
        // code here
        if(node == NULL){
            return -1;
        }
        int hLeft = height(node->left);
        int hRight = height(node->right);
        
        int ans = max(hLeft,hRight) + 1;
        return ans;
    }
};