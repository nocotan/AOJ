//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<string> ans;
string s;

auto rec(int n, char c, string t) -> void {
    if(n==s.size()) {
        ans.push_back(t);
        return;
    }
}

auto main() -> signed {
    while(cin>>s, s!="#") {
        ans.clear();
        rec(0, s[0], "");
        int sum = ans.size();
        cout << sum << endl;
        if(sum<=10) {
            for(int i=0; i<sum; ++i) cout << ans[i] << endl;
        } else {
            for(int i=0; i<5; ++i) cout << ans[i] << endl;
            for(int i=ans.size()-5; i<ans.size(); ++i) cout << ans[i] << endl;
        }
    }
    return 0;
}

