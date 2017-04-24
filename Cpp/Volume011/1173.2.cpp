//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    string s;
    cin.get();
    while(getline(cin, s), s!=".") {
        stack<int> st;
        int f = 0;
        for(int i=0; i<s.size(); ++i) {
            char c = s[i];
            if(c=='(') st.push(0);
            else if(c=='[') st.push(1);
            else if(c==')') {
                if(st.empty()) {
                    cout << "no" << endl;
                    f++;
                    break;
                }
                if(st.top() == 0) st.pop();
                else {
                    cout << "no" << endl;
                    f++;
                    break;
                }
            }
            else if(c==']') {
                if(st.empty()) {
                    cout << "no" << endl;
                    f++;
                    break;
                }
                if(st.top() == 1) st.pop();
                else {
                    cout << "no" << endl;
                    f++;
                    break;
                }
            }
        }
        if(f==0) {
            if(st.empty()) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
    return 0;
}

