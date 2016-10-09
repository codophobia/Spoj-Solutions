#include <bits/stdc++.h>
using namespace std;
int f(string s,int pos,int psum,int n)
{
    if(pos == n) {
        return 1;
    }
    int csum = 0;
    int sum = 0;
    int i;

    for(i = pos; i < n; i++) {
        csum = csum + (s[i]-'0');
        if(csum >= psum) {
            sum = sum + f(s,i+1,csum,n);
        }
    }

    return sum;
}
int main()
{
    string s;
    int i;
    int j;

    for(j = 1; ; j++) {
        cin>>s;
        if(s == "bye") {
            break;
        }
        cout<<j<<"."<<" "<<f(s,0,0,s.size())<<endl;
    }
}
