class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        vector<int>ans;
        for(int i=0;i<asteroids.size();i++)
        {
            while(!s.empty() && asteroids[i]<0 && s.top()>0)  
            {
                int magnitude=s.top()+asteroids[i]; 
                if(magnitude<0) 
                {
                    s.pop();
                }
                else if(magnitude>0) {
                    asteroids[i]=0;
                }
                else{
                    s.pop();
                    asteroids[i]=0;
                }
            }
            if(asteroids[i]) 
                s.push(asteroids[i]);
        }
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};