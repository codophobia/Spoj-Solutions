#include <bits/stdc++.h>
using namespace std;
int n;
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int state[30][30];
char a[30][30];
void bfs(pair<int,int> &s,pair<int,int> &d,int n,int m)
{
    int i;
    int x;
    int y;
    int flag;
    flag = 0;
    pair<int,int> t;
    queue<pair<int,int> > q;
    q.push(s);
    state[s.first][s.second] = 1;


    while(!q.empty()) {
        s = q.front();
        q.pop();
        state[s.first][s.second] = -1;

        if(s.first == d.first && s.second == d.second) {
            printf("valid\n");
            flag = 1;
            break;
        }

        for(i = 0; i < 4; i++) {
            x = s.first + dx[i];
            y = s.second + dy[i];

            if(x >= 0 && y >= 0 && x < n && y < m && state[x][y] == 0 && a[x][y] == '.') {
                    q.push(pair<int,int> (x,y));
                    state[x][y] = 1;


            }
        }
    }

    if(flag == 0) {
        printf("invalid\n");
    }
}

int corner(int x,int y,int n,int m)
{
    if(x == 0 || y == 0 || x == n || y == m) {
        return 1;
    }

    return 0;
}
int main()
{

    int t;
    int n;
    int m;
    int i;
    int j;
    int count;
    int flag;



    scanf("%d",&t);

    while(t--) {
        scanf("%d%d",&n,&m);
         pair<int,int> s,d;
        count = 0;
        flag = 0;

        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                scanf(" %c",&a[i][j]);
                state[i][j] = 0;
            }
        }

        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                if(corner(i,j,n-1,m-1) && a[i][j] == '.') {
                    count++;
                    if(flag == 0) {
                        s.first = i;
                        s.second = j;
                        flag = 1;
                    }
                    else {
                        d.first = i;
                        d.second = j;
                    }
                }
            }
            if(count > 2) {
                break;
            }
        }

        if(count != 2) {
            printf("invalid\n");
            continue;
        }



        bfs(s,d,n,m);
    }
}






















