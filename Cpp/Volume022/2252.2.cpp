//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define int long long


signed main()
{
    string s;
    string left = "qwertasdfgzxcvb";
    while(cin>>s, s!="#") {
        int f = -1;
        int cnt = 0;
        for(int i=0; i<s.size(); ++i) {
            int lf = 0;
            auto iter = find(left.begin(), left.end(), s[i]);
            if(iter!=left.end()) lf = 1;
            if(f==-1) f = lf;
            else {
                if(f!=lf) {
                    f = lf;
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

