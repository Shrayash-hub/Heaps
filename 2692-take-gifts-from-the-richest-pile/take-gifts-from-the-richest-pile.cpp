class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // we are going to use max heap
        priority_queue<long long> p;

        // pushing all the elements in the queue;
        for(long long i=0;i<gifts.size();i++){
            p.push(gifts[i]);
        }
        long long ans = 0;

        while(k>0 && !p.empty()){
            long gift = p.top();
            p.pop();
            p.push(floor(sqrt(gift)));
            k--;
        }

        while(!p.empty()) {
        ans += p.top();
        p.pop();
        }
        return ans;
    }
};