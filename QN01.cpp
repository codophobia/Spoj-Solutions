#include <bits/stdc++.h>
using namespace std;
struct trie
{
    long long int val;
    int pos;
    struct trie *left;
    struct trie *right;
};
struct trie *root;
int maxsize = 32;
struct trie *initialise()
{
    struct trie *node;
    node = new trie();
    node->val = -1;
    node->pos = -1;
    node->left = NULL;
    node->right = NULL;
    return node;
};
void insert(long long int n,int m)
{
    struct trie *node;
    node = root;
    int i;

    for(i = maxsize - 1; i >= 0; i--) {
        if(n&(1 << i)) {
            if(node->right == NULL) {
                node->right = initialise();
            }
            node = node->right;
        }
        else {
            if(node->left == NULL) {
                node->left = initialise();
            }
            node = node->left;
        }
    }
    node->val = n;
    node->pos = m;
}
pair<long long  int,int> query(long long int n)
{
    int i;
    struct trie *node;
    node = root;

    for(i = maxsize - 1; i >= 0; i--) {
        if(n & (1 << i)) {
            if(node->left != NULL) {
                node = node->left;
            }
            else {
                node = node->right;
            }
        }
        else {
            if(node->right != NULL) {
                node = node->right;
            }
            else {
                node = node->left;
            }
        }
    }

    return make_pair(node->val,node->pos);
}



int main()
{
    long long int n;
    long long int a[100005];
    int i;
    map<long long int,int> m;
    int l;
    int r;
    pair<long long int,int> t;
    long long int y;
    long long int x;

    long long int max;
    int count;



     root = initialise();
    cin>>n;
    max = -1;
    count = 0;
    for(i = 1; i <= n; i++) {
        cin>>a[i];

    }



    insert(0,0);
    m[0] = 1;
    l = 1000000;

    x = 0;

    for(i = 1; i <= n; i++) {
        x = x ^ a[i];
        if(m[x] == 0) {
         insert(x,i);
         m[x] = 1;
        }


        t = query(x);
        t.first = t.first ^ x;
        if(t.first > max) {
            max = t.first;
            r = i;
           //cout<<t.second<<endl;

            l = t.second + 1;


        }

        if (t.first == max && t.second + 1 < l) {
            r = i;
            l = t.second + 1;
        }
    }
    cout<<max<<endl;
    cout<<l<<' '<<r<<endl;



}
