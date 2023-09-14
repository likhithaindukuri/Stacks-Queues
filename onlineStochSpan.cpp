class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<pair<int,int>> st;
    int next(int price) {
         pair<int,int> val;
        if(!st.empty()){
            int flag=0;
            val.first=0;
            val.second=1;
            while(!st.empty() && st.top().first<=price){
                val.first=price;
                val.second+=st.top().second; //count increase
                st.pop();
                flag=1;
            }
            if(!st.empty() && st.top().first>price && flag==0){
                //price less than prev
                val.first=price;
                val.second=1;
            }

            st.push(val);

        }else{
            val.first=price;
            val.second=1;
            st.push(val);
        }
        
        return st.top().second;
    }
};