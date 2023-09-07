class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        string push = "Push", pop = "Pop";
        int ind = 0;
        for(int i = 1; i <= n; i++)
        {
          if(ind == target.size()) break;
          if(i == target[ind])
          {
            ind++;
            ans.push_back(push);
          }
          else
          {
            ans.push_back(push);
            ans.push_back(pop);
          }
        }
        return ans;
    }
};