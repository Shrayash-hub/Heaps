class Solution {
  public:
    priority_queue<int> leftMaxHeap;
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;
    
    void InsertInheap(int x){
        if(leftMaxHeap.size()==0){
            leftMaxHeap.push(x);
            return;
        }
        if(x>leftMaxHeap.top()){
            rightMinHeap.push(x);
        }
        else{
            leftMaxHeap.push(x);
        }
        balanceHeap();
    }
    
    void balanceHeap(){
        if(leftMaxHeap.size()<rightMinHeap.size()){
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
        else if(leftMaxHeap.size()>rightMinHeap.size()+1){
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        }

    }
    vector<double> getMedian(vector<int> &arr) {
        // code here
        vector<double> ans;
        for(int i=0;i<arr.size();i++){
            InsertInheap(arr[i]);
            if(leftMaxHeap.size() == rightMinHeap.size()){
                ans.push_back((leftMaxHeap.top() + rightMinHeap.top()) / 2.0);
            }
            else{
                ans.push_back(leftMaxHeap.top());
            }
        }
        return ans;
        
    }
};
