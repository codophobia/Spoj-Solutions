#include <bits/stdc++.h>
using namespace std;
struct digit
{
    int d;
    int ps;
    int pr;
};
int vis[1005][1005];
digit dp[1005][1005];
void bfs(int n)
{
    int i;
    int s;
    int r;
    int cs;
    int cr;
    memset(vis,0,sizeof(vis));
    queue<pair<int,int> > q;
    pair<int,int> p;
    p.first = 0;
    p.second = 0;
    q.push(p);
    vis[0][0] = 1;


    while(!q.empty()) {
        p = q.front();
        if(p.first == n && p.second == 0) {
            break;
        }
        q.pop();
        for(i = (p.first?0:1); i < 10; i++) {
            cs = p.first + i;
            cr = (10*p.second + i) % n;
            if(cs > n) {
                break;
            }
            if(vis[cs][cr] == 0) {
                dp[cs][cr].d = i;
                dp[cs][cr].ps =  p.first;
                dp[cs][cr].pr = p.second;
                vis[cs][cr] = 1;
                q.push(make_pair(cs,cr));
            }
        }
    }


}
int main()
{
    int t;
    int n;
    int i;
    int x;
    int y;
    int k;
    int a[10000];

    cin>>t;
    while(t--) {
        scanf("%d",&n);
        if(n < 10) {
            printf("%d\n",n);
            continue;
        }
        bfs(n);
        x = n;
        y = 0;
        i = 0;
        while(1) {
            a[i++] = dp[x][y].d;
            int s = dp[x][y].ps;
            int r = dp[x][y].pr;
            x = s;
            y = r;
            if(x == 0) {
                break;
            }
        }
        for(k = i-1; k >= 0; k--) {
            printf("%d",a[k]);
        }
        printf("\n");
    }

}
