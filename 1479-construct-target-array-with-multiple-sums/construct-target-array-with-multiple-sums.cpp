class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long totalSum = 0;
        priority_queue<int> pq;

        // Push all elements and calculate sum
        for(int x : target) {
            pq.push(x);
            totalSum += x;
        }

        while(true) {
            int largest = pq.top();
            pq.pop();

            long long restSum = totalSum - largest;

            // If everything is 1
            if(largest == 1 || restSum == 1)
                return true;

            // Impossible cases
            if(restSum == 0 || largest <= restSum)
                return false;

            // Previous value of this element
            int oldValue = largest % restSum;
            if(oldValue == 0) return false;

            // Update sum
            totalSum = restSum + oldValue;
            pq.push(oldValue);
        }
    }
};