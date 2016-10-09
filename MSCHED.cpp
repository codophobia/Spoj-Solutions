#include <bits/stdc++.h>
using namespace std;
struct cows
{
    int amnt;
    int time;
};
cows  a[10005];



int main()
{
    int n;
    int i;
    int a;
    int b;

    int t[10005];
    int sum;
    sum = 0;
    memset(t,0,sizeof(t));
    vector< pair<int,int> > v;

    scanf("%d",&n);

    for(i = 0; i < n; i++) {
        scanf("%d%d",&a,&b);
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end());

    /*for(i = 0; i < n; i++) {
        cout<<a[i].amnt<<' '<<a[i].time<<endl;
    }*/

    for(i = v.size()-1; i >= 0; i--) {

        int d = v[i].second;

        while(d) {
            if(!t[d]) {
                t[d] = 1;
                sum = sum + v[i].first;
                break;
            }
            else {
                d--;
            }
        }



    }

    printf("%d\n",sum);




}
