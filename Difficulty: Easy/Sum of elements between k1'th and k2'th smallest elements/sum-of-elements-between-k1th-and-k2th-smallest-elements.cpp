class Solution {
  public:
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        // Your code goes here
        priority_queue<long long> h1, h2;

        for(int i = 0; i < N; i++)
        {
        h1.push(A[i]);
        if(h1.size() > K1) h1.pop();

        h2.push(A[i]);
        if(h2.size() > K2) h2.pop();
    }

    long long k1th = h1.top();
    long long k2th = h2.top();

    long long sum = 0;
    for(int i = 0; i < N; i++)
        if(A[i] > k1th && A[i] < k2th)
            sum += A[i];

    return sum;
    }
};