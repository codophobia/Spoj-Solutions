#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    long long  int m;
    int a[300005];
    long long int i;
    long long int t;
    long long int j;
    long long int s;
    long long int minimum;
    long long int sum;


    scanf("%lld",&t);

    while(t--) {


    scanf("%lld%lld",&n,&m);
    for(i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    sum = a[0];
    minimum = 1000000000;
    i = 0;
    s = 0;
    j = 0;

    while(i < n) {
       if(sum <= m) {
            i++;
            //cout<<sum<<' '<<minimum<<' '<<s<<endl;
            if(abs(i-j) > s) {
                minimum = sum;
                s = abs(i-j);
            }
            else if(abs(i-j) == s) {
                minimum = min(minimum,sum);
            }

           // cout<<sum<<' '<<minimum<<endl;
            sum = sum + a[i];


       }
       else {

            sum = sum - a[j];
            j++;

       }
       //cout<<minimum<<' '<<s<<endl;
      // cout<<sum<<endl;
    }
    printf("%lld %lld\n",minimum,s);
    }

}
