#include <bits/stdc++.h>
using namespace std;
long long int a[1000];
long long int ncr(long long int n,long long int r,long long int m)
{
    int i;
    a[0]  = 1;
    a[1] = n;

    for(i = 2; i <= r; i++) {
        a[i] = (a[i - 1]  * (n - (i - 1))) / i;
        a[i] = a[i] % m;
    }

    return a[r];

}
int main()
{
    long long int n;
    long long int r;
    long long int m;
    m = 10000007;

    cin>>n>>r;

    if(r > n) {
        cout<<-1;
    }
    else {

    cout<<ncr(n-1,r-1,m);
    }
}
