#include <bits/stdc++.h>
using namespace std;
vector<int> v[10005];
int chk[10005];
int dis[10005];
int n;
int rnode;
stack<int> a;
int state[10005];
int flag = 0;

int dfs(int s)
{
    int i;
    a.push(s);
    int max;
    max = 0;



    while(!a.empty()) {
        s = a.top();
        a.pop();



        if(state[s] == 0) {
            state[s] = 1;
            //cout<<s<<' ';
        }

        for(i = 0; i < v[s].size(); i++) {
            if(state[v[s][i]] == 0) {

                a.push(v[s][i]);
                dis[v[s][i]] = dis[s] + 1;
                if(dis[v[s][i]] > max) {
                    max = dis[v[s][i]];
                    rnode = v[s][i];
                }

            }

        }


    }


}
int main()
{

    int e; //total number of edges
    int i;
    int s;
    int d;
    int st; //starting vetex for traversal


    memset(state,0,sizeof(state));
    //memset(dis,0,sizeof(dis));

    scanf("%d",&n);
   // scanf("%d",&e);

    for(i = 0; i < n-1; i++) {
        scanf("%d%d",&s,&d);
        v[s].push_back(d);
        v[d].push_back(s);
    }

    dfs(1);
    memset(dis,0,sizeof(dis));
    memset(state,0,sizeof(state));

    dfs(rnode);

    sort(dis+1,dis+n+1);

    /*for(i = 1; i <= n; i++) {
        cout<<dis[i]<<endl;
    }*/

    cout<<dis[n]<<endl;



   // printf("%d\n",dis[n-1]+dis[n]);







}
















