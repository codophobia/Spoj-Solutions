#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll int b = 33;
ll int mod = 1000000007;
ll int pw[1000006];
ll int hashval(string s)
{
    ll int x;
    ll int h = 0;
    ll int b1 = 1;
    int len = s.size();

    for(int i = len-1 ;i >= 0; i--) {
        h = (h + (s[i]*b1)%mod)%mod;
        b1 = (b1*b)%mod;
    }
    return h;
}
int main()
{
    string s;
    string p;
    ll int hs = 0;
    ll int hp;
    int n,m;
    int flag;
    int i;
    int j;
    int t;
    vector<int> v;
    int cnt = 0;
    pw[0] = 1;
    for(i = 1; i <= 1000000; i++) {
        pw[i] = (pw[i-1]*b)%mod;
    }
    cin>>t;
    for(int test = 1; test <= t; test++) {
        cin>>s>>p;
        cnt = 0;
        n = s.size();
        m = p.size();
        s[n] = 'a';
        hp = hashval(p);
        hs = hashval(s.substr(0,m));
        for(i = 0; i <= n-m; i++) {
            if(hp == hs) {
                flag = 0;
                for(j = 0; j < m; j++) {
                    if(s[i+j] != p[j]) {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0) {
                    v.push_back(i);
                    cnt++;
                }
            }
            if(i < n-m) {
                hs = ((hs*b - (pw[m-1]*b*s[i])%mod) + s[i+m])%mod;
                if(hs < 0) {
                    hs = (hs + mod);
                }
            }
        }
        if(cnt == 0) {
            cout<<"Not Found"<<endl;
        }
        else {
            cout<<cnt<<endl;
            for(i = 0; i < cnt; i++) {
                cout<<v[i]+1<<endl;
            }
        }
        v.clear();


    }
}
