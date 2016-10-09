#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    int n;
    string str;
    int i;
    stack<int> s;

    scanf("%d",&t);

    while(t--) {
        map<string,int> m;
        map<string,int>::iterator it;
        scanf("%d",&n);
        cin>>str;

        for(i = 0; i < 38; i++) {
            m[str.substr(i,3)]++;
        }

        printf("%d ",n);
        printf("%d ",m["TTT"]);
        printf("%d ",m["TTH"]);
        printf("%d ",m["THT"]);
        printf("%d ",m["THH"]);
        printf("%d ",m["HTT"]);
        printf("%d ",m["HTH"]);
        printf("%d ",m["HHT"]);
        printf("%d ",m["HHH"]);
        printf("\n");









    }
}
