class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        
        // firstly we need to sort the arrays , so that we get to know the elements that can make max sum together
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        
        int n = a.size();
        
        // we are going to save the value if sum and pair indexs , as there are chance of duplicates insertion
        priority_queue<pair<int,pair<int,int>>> sum;
        
        // largest sum can be obtained by last elements of sorted arrays
        int i = n-1;
        int j = n-1;
        sum.push({a[n-1]+b[n-1],{i,j}});
        
        // to get rid of duplicate index insertion , we are going to make a visited set , thats going to
        // check before insertion , that this particular pair is previously inserted or not
        set<pair<int,int>> visited;
        
        // marking (n-1,n-1) as visited
        visited.insert({i,j});
        
        vector<int> ans;
        
        // intution is that after pushing i and j , chances of elements combination thats going to give
        // maximum sum is either (i-1,j) or (i,j-1)
        
        while(k--){
            pair<int,pair<int,int>> temp = sum.top();
            ans.push_back(temp.first);
            sum.pop();
            int curr_i = temp.second.first;
            int curr_j = temp.second.second;
            
            // curr_i-1 can be go negative
            
            if(curr_i-1>=0 && visited.find({curr_i-1,curr_j})== visited.end()){
                sum.push( {a[curr_i-1]+b[curr_j] ,{curr_i-1,curr_j}});
                visited.insert({curr_i-1,curr_j});
            }
            
            if(curr_j-1>=0 && visited.find({curr_i,curr_j-1})== visited.end()){
                sum.push( {a[curr_i]+b[curr_j-1] ,{curr_i,curr_j-1}});
                visited.insert({curr_i,curr_j-1});
            }
        }
        return ans;
    }
};