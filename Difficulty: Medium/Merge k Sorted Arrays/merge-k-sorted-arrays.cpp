class Solution {
  public:
  
    vector<int> merge(vector<int> &a,vector<int> &b){
        vector<int> res;
        int i = 0, j = 0;

        while (i < a.size() && j < b.size()) {
            if (a[i] <= b[j])
                res.push_back(a[i++]);
            else
                res.push_back(b[j++]);
        }

        while (i < a.size())
            res.push_back(a[i++]);

        while (j < b.size())
            res.push_back(b[j++]);

        return res;
    }
    vector<int> mergeK(vector<vector<int>> &mat,int start,int end){
        if(start==end){
            return mat[start];
        }
        int mid = start + (end-start)/2;
        vector<int> left = mergeK(mat,start,mid);
        vector<int> right = mergeK(mat,mid+1,end);
        
        return merge(left,right);
    }
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        vector<int> ans = mergeK(mat,0,mat.size()-1);
        return ans;
    }
};