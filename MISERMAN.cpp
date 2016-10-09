#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[105][105];
    int n;
    int maximum;
    int m;
    int ans;
    int t;
    int i;
    int j;


            maximum = 1000000000;
        scanf("%d%d",&n,&m);
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                scanf("%d",&a[i][j]);
            }
        }

        for(i = 1; i < n; i++) {
            for(j = 0; j < m; j++) {
                if(j == 0) {
                    ans = max(a[i-1][j],a[i-1][j+1]);
                    a[i][j] += ans;
                }
                else if(j == m-1) {
                    ans = min(a[i-1][j-1],a[i-1][j]);
                    a[i][j] += ans;
                }
                else {
                    ans = min(a[i-1][j],a[i-1][j+1]);
                    ans = min(ans,a[i-1][j-1]);
                    a[i][j] += ans;
                }
            }
        }

        i = n - 1;

        for(j = 0; j < m; j++) {
           if(a[i][j] < maximum) {
            maximum = a[i][j];
           }

        }

        cout<<maximum<<endl;


}
