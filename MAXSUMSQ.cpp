#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    int n;
    int a[100005];
    int count[100005];
    int i;
    long long int max;
    long long int total;
    int s[100005];

    scanf("%d",&t);

    while(t--) {
        scanf("%d",&n);
        max = -1000000000;
        total = 0;

        for(i = 0; i < n; i++) {
            scanf("%d",&a[i]);
        }

        s[0] = a[0];
        count[0] = 1;

        for(i = 1; i < n; i++) {
            if(s[i-1]+a[i] == a[i]) {
                s[i] = a[i];
                count[i] = count[i-1] + 1;
            }
            else if(s[i-1]+a[i] > a[i]) {
                s[i] = s[i-1] + a[i];
                count[i] = count[i-1];
            }
            else{
                s[i] = a[i];
                count[i] = 1;
            }
        }

        for(i = 0; i < n; i++) {
            if(s[i] > max) {
                max = s[i];
            }
        }

        for(i = 0; i < n; i++) {
            if(s[i] == max) {
                total = total + count[i];
            }
        }

        printf("%lld %lld\n",max,total);




        }
    }

