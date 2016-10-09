#include <bits/stdc++.h>
using namespace std;
vector<int> v[10005];
int chk[10005];
int n;
stack<int> a;
int state[10005];
int flag = 0;

int dfs(int s)
{
    int i;
    a.push(s);



    while(!a.empty()) {
        s = a.top();
        a.pop();
        chk[s]--;


        if(state[s] == 0) {
            state[s] = 1;
            //cout<<s<<' ';
        }

        for(i = 0; i < v[s].size(); i++) {
            if(state[v[s][i]] == 0) {
                chk[v[s][i]]++;
                if(chk[v[s][i]] == 2) {
                    flag = 1;


                }
                a.push(v[s][i]);

            }

        }

        if(flag == 1) {
            break;
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

    scanf("%d",&n);
    scanf("%d",&e);

    for(i = 0; i < e; i++) {
        scanf("%d%d",&s,&d);
        v[s].push_back(d);
        v[d].push_back(s);
    }

    if(e != n - 1) {
        printf("NO\n");
    }
    else {
        dfs(1);
        for(i = 1; i <= n; i++) {
            if(state[i] == 0) {
                flag = 1;
                //cout<<1<<endl;
                break;
            }
        }

        if(flag == 1) {
            printf("NO\n");
        }
        else {
            printf("YES\n");
        }
    }







}















