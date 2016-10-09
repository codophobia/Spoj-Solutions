#include<bits/stdc++.h>
using namespace std;
void subset(int s[],vector<int> &v,int n,int start)
{
    int i;
    int j;
    int sum;

    for(i = 0; i < pow(2,n); i++) {
            sum = 0;
        for(j = 0; j < n; j++) {
            if(i & (1 << j)) {
                sum = sum + s[j+start];


            }

        }
         v.push_back(sum);
    }
}
int main()
{
    int n;
    int a;
    int b;
    int s[40];
    int i;
    int j;
    vector<int> left,right;
    int hi;
    int lo;
    long long int sum;
    sum = 0;

    scanf("%d%d%d",&n,&a,&b);

    for(i = 0;i < n; i++) {
        scanf("%d",&s[i]);
    }

    subset(s,left,n/2,0);
    subset(s,right,(n&1)?n/2+1:n/2,n/2);

    sort(right.begin(),right.end());

    for(i = 0; i < left.size();i++) {
        lo = lower_bound(right.begin(),right.end(),a-left[i])-right.begin();
        hi = upper_bound(right.begin(),right.end(),b-left[i])-right.begin();
        sum = sum + (hi-lo);
    }
    printf("%lld\n",sum);
}
