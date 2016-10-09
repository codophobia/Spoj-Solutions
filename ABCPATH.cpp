#include <bits/stdc++.h>
using namespace std;
int dx[] = {0,-1,0,1,-1,-1,1,1};
int dy[] = {-1,0,1,0,-1,1,1,-1};
typedef pair<pair<int,int>,int > type;
int state[60][60];
char a[60][60];
int bfs(int n,int m)
{
    int i;
    int j;
    int k;
    int x;
    int y;
    int sf;
    int ss;
    int st;
    int flag;
    int max;
    max = 0;
    flag = 0;

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(a[i][j] == 'A') {


    type t,t1;
    queue<type > q;
    t.first.first = i;
    t.first.second = j;
    t.second = 1;
    q.push(t);
    state[t.first.first][t.first.second] = 1;


    while(!q.empty()) {
        t = q.front();

        sf = t.first.first;
        ss = t.first.second;
        st = t.second;
        state[sf][ss] = 1;

        if(st > max) {
            max = st;
        }





        for(k = 0; k < 8; k++) {
            x = sf + dx[k];
            y = ss + dy[k];

            if(x >= 0 && y >= 0 && x < n && y < m && state[x][y] < 8 && (int)a[x][y] == (int)a[sf][ss] + 1) {

                    t.first.first = x;
                    t.first.second = y;
                    state[x][y]++;
                    t.second = st + 1;
                    q.push(t);
            }
        }

        q.pop();
    }
            }
        }
    }



    return max;
}


int main()
{

    int t;
    int n;
    int m;
    int i;
    int j;
    int k;
    int p;
    p = 0;
    int max;






        scanf("%d%d",&n,&m);
        memset(state,0,sizeof(state));
        while(n != 0 && m != 0) {
            p++;


        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                scanf(" %c",&a[i][j]);
            }
        }

        max = bfs(n,m);

        printf("Case %d: %d\n",p,max);
        scanf("%d%d",&n,&m);
    }

    return 0;



}























