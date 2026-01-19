class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& mat) {
        int k = mat.size();
        
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        int currMax = INT_MIN;

        // Initial push
        for(int i = 0; i < k; i++){
            pq.push({mat[i][0], {i, 0}});
            currMax = max(currMax, mat[i][0]);
        }

        int rangeStart = 0, rangeEnd = INT_MAX;

        while(true){
            auto temp = pq.top();
            pq.pop();

            int currMin = temp.first;
            int row = temp.second.first;
            int col = temp.second.second;

            // Update best range
            if(currMax - currMin < rangeEnd - rangeStart){
                rangeStart = currMin;
                rangeEnd = currMax;
            }

            // Move in same row
            if(col + 1 >= mat[row].size())
                break;

            int nextVal = mat[row][col + 1];
            pq.push({nextVal, {row, col + 1}});
            currMax = max(currMax, nextVal);
        }

        return {rangeStart, rangeEnd};
    }
};