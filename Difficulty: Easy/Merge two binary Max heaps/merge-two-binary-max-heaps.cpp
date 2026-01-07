// User function Template for C++

class Solution {
  public:
    void Heapify(vector<int> &ans,int index,int n){
        int largest = index;
        int left = 2*index +1;
        int right = 2*index +2;
        
        if(left<n && ans[left]>ans[largest]){
           largest = left; 
        }
        
        if(right<n && ans[right]>ans[largest]){
           largest = right; 
        }
        
        if(largest!=index){
            swap(ans[index],ans[largest]);
            Heapify(ans,largest,n);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> ans;
        
        for(int i=0;i<a.size();i++){
            ans.push_back(a[i]);
        }
        
        for(int i=0;i<b.size();i++){
            ans.push_back(b[i]);
        }
        int size = ans.size();
        for(int i=size/2-1;i>=0;i--){
            Heapify(ans,i,size);
        }
        
        return ans;
    }
};