//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> sieve_of_eratosthenes(int n)
{
    vector<int> primes(n);
    for (int i=2; i<n; ++i)
        primes[i] = i;
    for (int i=2; i*i<n; ++i)
        if (primes[i])
            for (int j=i*i; j<n; j+=i)
                primes[j] = 0;

    primes.erase(remove(primes.begin(), primes.end(), 0), primes.end());
    return primes;
}

signed main()
{
    vector<int> primes = sieve_of_eratosthenes(123456*3);
    int n;
    while(cin>>n, n) {
        auto iter = upper_bound(primes.begin(), primes.end(), n);
        int ans = 0;

        for(;*iter<=2*n; ++iter) {
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}

