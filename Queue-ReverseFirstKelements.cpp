class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        int n = q.size()-k;
        stack<int> st;
        
        while(k){
            st.push(q.front());
            q.pop();
            k--;
        }
        
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        
        while(n){
            int x = q.front();
            q.pop();
            q.push(x);
            n--;
        }
        return q;
    }
};