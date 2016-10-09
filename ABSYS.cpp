#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4,s5;
int convert(string s)
{
    int num;
    num = 0;
    int i;

    for(i = 0; i < s.length(); i++) {
        if(!isdigit(s[i])) {
            return -1;
        }

        num = (num * 10) + (s[i] - '0');
    }
    return num;
}
int main()
{
   int v1;
   int v2;
   int v3;
   int t;

   cin>>t;




   while(t--) {


   cin>>s1>>s2>>s3>>s4>>s5;

   v1 = convert(s1);
   v2 = convert(s3);
   v3 = convert(s5);

   if(v1<0) v1=v3-v2;
    if(v2<0) v2=v3-v1;
    if(v3<0) v3=v1+v2;

    cout<<v1<<" + "<<v2<<" = "<<v3<<endl;


   }

   return 0;



}
