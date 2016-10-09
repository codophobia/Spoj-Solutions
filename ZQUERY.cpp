#include <bits/stdc++.h>
using namespace std;
long long int a[100005];
long long int h1[100005];
long long int h2[100005];
long long int dp[400][100005];
long long int n;
long long int lmt = 100005;
vector<long long int> v1[100005];
vector<long long int> v2[100005];
void process()
{
    long long int s = sqrt(n);
    long long int m = ceil((double)n/s);
    long long int mx = 0;
    long long int i;
    long long int j;
    long long int e;

    //stores answer for each block from its start to n
    for(i = 1; i <= m; i++) {
        mx = 0;
        e = (i)*s-s+1;
        for(j = 0; j <= lmt; j++) {
            h1[j] = -1;
            h2[j] = -1;
        }
        for(j = e; j <= n; j++) {
            if(a[j] >= 0) {
                if(h1[a[j]] != -1) {
                    mx = max(mx,j-h1[a[j]]);
                }
                else {
                    h1[a[j]] = j;
                }
            }
            else  {
                if(h2[a[j]*-1] != -1) {
                    mx = max(mx,j-h2[a[j]*-1]);
                }
                else {
                    h2[a[j]*-1] = j;
                }
            }
           // cout<<mx<<' ';
            dp[i][j] = mx;
        }
       // cout<<endl;
    }
}
int main()
{
    long long int q;
    long long int m;
    long long int i;
    long long int mb;
    long long int l;
    long long int bs;
    long long int j;
    long long int r;
    long long int mx = 0;
    scanf("%lld%lld",&n,&q);
    a[1] = 0;
    v1[0].push_back(1);
    n = n+1;
    for(i = 2; i <= n; i++) {
        scanf("%lld",&a[i]);
        //cout<<a[i]<<' '<<a[i-1]<<endl;
        a[i] = a[i] + a[i-1];
        if(a[i] >= 0) {
            v1[a[i]].push_back(i); //storing index for positive numbers
        }
        else {
            v2[a[i]*-1].push_back(i); //storing index fro negative numbers
        }
    }
    process();
    bs = sqrt(n); //block size
    mb = ceil((double)n/bs); //last block number
    for(i = 1; i <= q; i++) {
        cin>>l>>r;
        r++;
        mx = 0;
        long long int x = ceil((double)l/bs);
        mx = dp[x+1][r];
        long long int ub;
        for(j = l; j < x*bs+1 && j <= r; j++) { //move to the start of the nearest block
            if(a[j] >= 0) {
                ub = upper_bound(v1[a[j]].begin(),v1[a[j]].end(),r)-v1[a[j]].begin();
                ub = ub - 1;
                ub = v1[a[j]][ub];
                //cout<<ub<<endl;
                mx = max(mx,ub-j);
            }
            else {
                ub = upper_bound(v2[a[j]*-1].begin(),v2[a[j]*-1].end(),r)-v2[a[j]*-1].begin();
                ub = ub - 1;
                ub = v2[a[j]*-1][ub];
                mx = max(mx,ub-j);
            }
        }
        printf("%lld\n",mx);


    }
}

