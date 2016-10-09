#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int a[105];
    int i;
    int j;
    int t;
    int x;


        scanf("%d%d",&x,&n);
        int s[x+1];

        for(i = 0; i < n; i++) {
            scanf("%d",&a[i]);
        }

        for(i = 1; i < n; i++) {
            a[i] = a[i-1] + a[i];
        }



        for(i = 0; i <= x; i++) {
            s[i] = 10000000;
        }

        s[0] = 0;

        for(i = 1; i <= x; i++) {
            for(j = 0; j < n; j++) {
                if(i >= a[j] && s[i-a[j]]+1 < s[i]) {
                    s[i] = s[i-a[j]]+1;
                }
            }
        }

        if(s[x] == 10000000) {
            printf("NO\n");
        }
        else {
            printf("YES\n");
        }



}
