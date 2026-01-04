class Solution {
  public:
    int minCost(vector<int>& arr) {
        // using priority queue templete implement min heap
        // priority_queue<T, Container, Compare> name;

        priority_queue<int, vector<int>, greater<int>> p;
        // convert array in priority queue
        
        for(int i=0;i<arr.size();i++){
            p.push(arr[i]);
        }
        int cost = 0;
        
        // choose two smallest rope everytime
        while(p.size()>1){
            int rope = p.top();
            p.pop();
            rope+= p.top();
            p.pop();
            cost += rope;
            p.push(rope);
        }
        return cost;
    }
};