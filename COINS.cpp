#include <bits/stdc++.h>
using namespace std;
map<long long,long long> m;
long long int sum(long long int n)
{
    if(n == 0) {
        return 0;
    }


    if(m[n] == 0) {
        m[n] = max(n,sum(n/2)+sum(n/3)+sum(n/4));

    }

    return m[n];
}

int main()
{
    long long int n;

    while((cin>>n)) {

    cout<<sum(n)<<endl;
    }

    return 0;
}
