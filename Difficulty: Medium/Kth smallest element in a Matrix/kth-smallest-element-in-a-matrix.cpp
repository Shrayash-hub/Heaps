class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        // we are going to save the pair of value , coordinates in the heap
        vector<pair<int,pair<int,int>>> v;
        
        // pushing elements of first clm in the vector
        for(int i=0;i<mat[0].size();i++){
            v.push_back(make_pair(mat[i][0],make_pair(i,0)));
        }
        
        // using max heap 
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq(v.begin(),v.end());
        
        int ans;
        int i,j;
        pair<int,pair<int,int>> element;
        
        for(int m=0;m<k;m++){
            element = pq.top();
            pq.pop();
            ans = element.first;
            i = element.second.first;
            j = element.second.second;
            if(j+1<mat[0].size())
            pq.push(make_pair(mat[i][j+1],make_pair(i,j+1)));
        }
        return ans;
    }
};
