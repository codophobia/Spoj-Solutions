#include <bits/stdc++.h>
using namespace std;
int a[100005];
int p[100005];
int r[100005];
int c[100005];
vector<int> v[100005];
void create(int x) //create new set with single element
{
    p[x] = x;
    r[x] = 0;
    c[x] = 0;
}
int find(int x) //find the parent of x and store the parents of its children
{
    if(p[x] == x) {
        return x;
    }
    p[x] = find(p[x]);
    return p[x];
}
void merge(int x,int y)
{
    int px = find(x);
    int py = find(y);
    if(px == py) {
        return;
    }
    if(r[px] < r[py]) {
        swap(px,py);
    }
    p[py] = px;
    if(r[px] == r[py]) {
        r[px] += 1;
    }
}
int main()
{
    int n;
    int m;
    int i;
    int x;
    int y;
    int q;
    int ch;

    scanf("%d",&n);
    for(i = 1; i <= n; i++) {
        create(i);
    }
    for(i = 1; i <= n-1; i++) {
        scanf("%d%d",&x,&y);
        x++;
        y++;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    scanf("%d",&q);
    while(q--) {
        scanf("%d%d%d",&ch,&x,&y);
        if(ch == 1) {
            x++;
            c[x] = y;
            for(i = 0; i < v[x].size(); i++) {
                if(c[v[x][i]] == c[x]) {
                    merge(v[x][i],x);
                    //cout<<v[x][i]<<' '<<x<<endl;
                }
            }
        }
        else {
            x++;
            y++;
            if(find(x) == find(y)) {
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }
        }
    }

}

