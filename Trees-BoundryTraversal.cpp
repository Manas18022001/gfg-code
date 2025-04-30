/*
// Tree Node
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
  
    void printLeft(vector<int> &ans, Node* root){
        if((root==NULL) || (root->left == NULL && root->right == NULL)){
            return;
        }
        ans.push_back(root->data);
        if(root->left)
            printLeft(ans, root->left);
        else
            printLeft(ans, root->right);
    }
    void printRight(vector<int> &ans, Node* root){
        if((root==NULL) || (root->left == NULL && root->right == NULL)){
            return;
        }
        
        if(root->right)
            printRight(ans, root->right);
        else
            printRight(ans, root->left);
            
        ans.push_back(root->data);
    }
    void printLeaf(vector<int> &ans, Node* root){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return;
        }
        printLeaf(ans, root->left);
        printLeaf(ans, root->right);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        ans.push_back(root->data);
        //left print
        if(root->left)
            printLeft(ans, root->left);
        //leaf print
        printLeaf(ans, root->left);
        printLeaf(ans, root->right);
        //right print
        if(root->right)
            printRight(ans, root->right);
        
        return ans;
    }
};