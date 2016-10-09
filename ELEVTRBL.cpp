#include <bits/stdc++.h>
using namespace std;
#define type pair<int,int>
int state[1000006];
void bfs(int f,int s,int de,int u,int d)
{
    queue<type > q;
    type t;
    int up;
    int dn;
    int flag;
    flag = 0;
    q.push(type (s,0));
    state[s] = 1;

    while(!q.empty()) {
        t = q.front();
        state[t.first] = 1;

        if(t.first == de) {
            printf("%d\n",t.second);
            flag = 1;
            break;
        }

        q.pop();

        up = t.first + u;
        dn = t.first - d;

        if(up <= f) {
            if(state[up] == 0) {
                q.push(type (up,t.second+1));
                state[up] = 1;
            }
        }

        if(dn >= 1) {
            if(state[dn] == 0) {
                q.push(type (dn,t.second+1));
                state[dn] = 1;
            }
        }

    }

    if(flag == 0) {
        printf("use the stairs\n");
    }
}
int main()
{
    int f;
    int de;
    int u;
    int d;
    int s;
    int i;

    scanf("%d%d%d%d%d",&f,&s,&de,&u,&d);

    for(i = 0; i <= f; i++) {
        state[i] = 0;
    }

    bfs(f,s,de,u,d);


}
