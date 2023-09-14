class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i = 0;
        for(int a : pushed){
            st.push(a);
            while(!st.empty() && st.top() == popped[i]){
                i++;
                st.pop();
            }
        }
        return i==popped.size();
    }
};