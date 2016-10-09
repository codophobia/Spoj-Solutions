#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    string s;
    scanf("%d",&t);
    getline(cin,s);





    while(t--) {
        set<string> sub;



        set<string>::iterator it;
        getline(cin,s);


        stringstream ss(s);


        while(ss) {
            string a;
            ss>>a;
            sub.insert(a);
        }



        cout<<sub.size()-1<<endl;
        sub.clear();









    }
    return 0;
}
