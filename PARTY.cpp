#include <bits/stdc++.h>
using namespace std;
int b[2005][2005];

int main()
{
    int w[2005];
    int p[2005];
    //int b[2005][2005];
    int n;
    int m;
    int t;
    int i;
    int j;




        cin>>m>>n;

        while(n != 0 && m != 0) {
        for(i = 1; i <= n; i++) {

            cin>>w[i];
            cin>>p[i];
        }
        memset(b,0,sizeof(b));

        for(i = 1; i <= n; i++) {
            for(j = 1; j <= m; j++) {
                    //cout<<b[i-1][j] + w[j]<<' ';
                if(w[i] <= j) {
                    b[i][j] = max(b[i-1][j],b[i-1][j-w[i]] + p[i]);

                }
                else {
                    b[i][j] = b[i-1][j];

                }

               // cout<<b[i][j]<<' ';
            }
           // cout<<endl;
        }

        int maxfun = b[n][m];
        int maxcost;

        for(i = 0; i <= m; i++) {
            if(b[n][i] == maxfun) {
               maxcost = i;
               break;
            }
        }



        cout<<maxcost<<' '<<maxfun<<endl;
        cin>>m>>n;
        }



}
