#include <bits/stdc++.h>
#define infinity 1000000000
using namespace std;
double a[101][101];
int main()
{
    int i;
    int j;
    int k;
    int n;
    int m1;
    int s;
    int d;
    int w;
    int test;
    map<string,int> m;
    int x;
    string s1,s2;
    double val;
    int t;


    for(test = 1; ; test++) {
        cin>>n;
        memset(a,0,sizeof(a));
        m.clear();
        if(n == 0) {
            break;
        }
        for(i = 1; i <= n; i++) {
            cin>>s1;
            m[s1] = i;
        }
        cin>>m1;
        for(i = 0; i < m1; i++) {
            cin>>s1>>val>>s2;
            a[m[s1]][m[s2]] = val;
        }
        for(k = 1; k <= n; k++) {
            for(i = 1; i <= n; i++) {
                for(j = 1; j <= n; j++) {
                    a[i][j] = max(a[i][j],a[i][k]*a[k][j]);
                }
            }
        }
        int flag = 0;
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                if((a[i][j]-1) > 0.0000000001 && (i == j)) {
                    flag = 1;
                }
                
            }
           
        }
        if(flag == 1) {
            printf("Case %d: Yes\n",test);
        }
        else {
            printf("Case %d: No\n",test);
        }
    }

}

