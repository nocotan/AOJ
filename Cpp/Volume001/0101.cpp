#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    scanf("%d%*c", &n);
    for(int i=0; i<n; ++i) {
        string s;
        getline(cin, s);
        regex re("Hoshino");
        cout << regex_replace(s, re, "Hoshina") << endl;
    }
    return 0;
}

