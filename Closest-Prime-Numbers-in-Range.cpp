class Solution {
public:
    bool isPrime(int& n) {
        if(n==1)
        {
            return false;
        }
        for (int x = 2; x <= sqrt(n); x++) {
            if (n % x == 0) {
                return false;
            }
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        int length = right - left;
        vector<bool> primes(length + 1, true);
        vector<int> allPrimes;
        for (int x = left; x <= right; x++) {
            if (primes[x - left] == false || x==1) {
                continue;
            }
            if (isPrime(x)) {
                allPrimes.push_back(x);
                primes[x - left] = true;
            }
            long long m = x;
            if (m * m <= right) {
                for (long long j = m * m; j <= right; j += m) {
                    primes[j - left] = false;
                }
            }
        }
        // for(int x:allPrimes)
        // {
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        if (allPrimes.size() > 1) {
            int start = allPrimes[0];
            int end = allPrimes[1];
            int diff = end - start;
            for (int x = 1; x < allPrimes.size() - 1; x++) {
                int s2 = allPrimes[x];
                int e2 = allPrimes[x + 1];
                int d2 = e2 - s2;
                if (d2 < diff) {
                    start = s2;
                    end = e2;
                    diff = d2;
                }
            }
            return {start, end};
        }
        return {-1, -1};
    }
};