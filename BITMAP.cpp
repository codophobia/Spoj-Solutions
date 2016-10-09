#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> type;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int n;
int m;

int state[200][200];
int dis[200][200];
char a[200][200];
void bfs()
{
    queue<type > q;
    int j;

    memset(state,0,sizeof(state));



    type t;
    int i;
    int x;
    int y;
    int min;
    int xc;
    int yc;





    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(a[i][j]-48 == 1) {
                t.first = i;
                t.second = j;
                q.push(t);
                state[i][j] = 1;
                dis[i][j] = 0;
            }
        }

    }

    while(!q.empty()) {
        t = q.front();
        x = t.first;
        y = t.second;


        q.pop();
        state[x][y] = -1;

        for(i = 0; i < 4; i++) {
            xc = dx[i] + x;
            yc = dy[i] + y;

            if(state[xc][yc] == 0 && xc >= 0 && yc >= 0 && xc < n && yc < m) {
                //cout<<xc<<' '<<yc<<endl;
                dis[xc][yc] = dis[x][y]+1;
                t.first = xc;
                t.second = yc;
                q.push(t);
                state[xc][yc] = 1;
            }
        }

    }


}


int main()
{

    int t;

    int i;
    int j;

    scanf("%d",&t);

    while(t--) {
        scanf("%d%d",&n,&m);

        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                scanf(" %c",&a[i][j]);

            }
        }
        bfs();

        for(i = 0 ; i < n; i++) {
            for(j = 0; j < m; j++) {
                printf("%d ",dis[i][j]);
            }
            printf("\n");
        }




    }

    return 0;
}











