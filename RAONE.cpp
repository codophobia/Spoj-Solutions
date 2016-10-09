#include <bits/stdc++.h>
using namespace std;
vector<int> v;
void sumdif()
{
    int i;
    int k;
    k = 0;
    for(i = 10; i <= 100000000; i = i + 11) {
        v.push_back(i);
    }
    //printf("%d\n",k);

}
int main()
{

    sumdif();
    int t;
    int a;
    int b;

    vector<int>::iterator up,low;

    scanf("%d",&t);

    while(t--) {
        scanf("%d%d",&a,&b);
        low = lower_bound(v.begin(),v.end(),a);
        up = upper_bound(v.begin(),v.end(),b);
        cout<<(up - v.begin())-(low-v.begin())<<endl;

    }


}
