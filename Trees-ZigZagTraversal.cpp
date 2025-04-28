// User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node* root) {
        // Code here
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> v(size,0);
            
            for(int i=0; i<size; i++){
                Node* temp = q.front();
                q.pop();
                
                if(temp->left){
                    q.push(temp->left);
                }    
                if(temp->right){
                    q.push(temp->right);
                }  
                
                int index = leftToRight?i:size-i-1;
                v[index] = temp->data;
            }
            
            leftToRight = !leftToRight;
            
            for(auto i:v){
                ans.push_back(i);
            }        
            
        }
        return ans;
    }
};