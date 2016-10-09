#include <bits/stdc++.h>
using namespace std;
#define type pair<int,int>
int dx[]= {0,-1,0,1};
int dy[]= {-1,0,1,0};
char a[1001][1001];
int state[1001][1001];
int d[1001][1001];
int rootx;
int rooty;
int bfs(type &s,int n,int m)
{
    int i;
    int max;
    int x;
    int y;
    max = 0;
    queue<type > q;
    memset(d,0,sizeof(d));
    memset(state,0,sizeof(state));
    q.push(s);
    state[s.first][s.second] = 1;
    d[s.first][s.second] = 0;


    while(!q.empty()) {
        s = q.front();



        state[s.first][s.second] = -1;
        q.pop();



        for(i = 0; i < 4 ; i++) {
            x = s.first + dx[i];
            y = s.second + dy[i];
            // cout<<x<<' '<<y<<endl;

            if(x >= 0 && y >= 0 && x < n && y < m && state[x][y] == 0 && a[x][y] == '.') {
                q.push(type (x,y));
                state[x][y]=1;
                //cout<<x<<' '<<y<<endl;
                d[x][y] = d[s.first][s.second] + 1;
                if(d[x][y] > max) {
                    max = d[x][y];
                    //cout<<max<<endl;
                    rootx = x;
                    rooty = y;
                }
            }
        }
    }

    //cout<<p.first<<' '<<p.second<<endl;

    return max;
}

int main()
{

    int m;
    int n;
    int t;
    int i;
    int j;
    int flag;
    int max;


    scanf("%d",&t);

    while(t--) {
        scanf("%d%d",&m,&n);
        type p,s;
        flag = 0;

        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                cin>>a[i][j];
               if(a[i][j] == '.' && flag == 0) {
                    s.first = i;
                    s.second = j;
                    flag = 1;
               }
            }
        }



        max = bfs(s,n,m);
        s.first = rootx;
        s.second = rooty;
        max = bfs(s,n,m);
        //cout<<p.first<<' '<<p.second<<endl;

        printf("Maximum rope length is %d.\n",max);




    }
}









