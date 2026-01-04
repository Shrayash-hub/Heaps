class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // using min heap
        priority_queue<int,vector<int>,greater<int>> p;

        // pushing k elements into the queue
        for(int i=0;i<k;i++){
            p.push(nums[i]);
        }

        // now intution is to check the top(smallest among them) of queue with the leftout elements of the array
        for(int i=k;i<nums.size();i++){
            // if any element is greater than the minimum in queue , push it in and take previous minimum out
            if(nums[i]>p.top()){
                p.pop();
                p.push(nums[i]);
            }
        }
        return p.top();
    }
};