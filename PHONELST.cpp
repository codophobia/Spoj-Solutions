#include <bits/stdc++.h>
using namespace std;
struct node {
	int wordcount;
	int precount;
	struct node *child[10];
};
struct node *initialise()
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->wordcount = 0;
	newnode->precount = 0;
	for(int i = 0; i < 10; i++) {
		newnode->child[i] = NULL;
	}
	return newnode;
}
struct node *addword(string s,struct node *root)
{
	int i;
	int ch;
	struct node *temp = root;
	struct node *newnode = NULL;

	for(i = 0; i < s.size(); i++) {
		ch = s[i]-'0';
		if(temp->child[ch] == NULL) {
			newnode = initialise();
			newnode->precount = 1;
			temp->child[ch] = newnode;
			temp = temp->child[ch];
		}
		else {
			temp->child[ch]->precount += 1;
			temp = temp->child[ch];
		}
	}
	temp->wordcount += 1;
	return root;
}
int prefixcount(string s,struct node *root)
{
	int i;
	int ch;
	struct node *temp = root;

	for(i = 0; i < s.size(); i++) {
		ch = s[i] - '0';
		if(temp->child[ch] == NULL) {
			return 0;
		}
		else {
			temp = temp->child[ch];
		}
	}
	return temp->precount;
}
int main()
{
	string s[10005];
	int n;
	int q;
	int i;
	int t;
	int flag;

	cin>>t;
	while(t--) {
		cin>>n;
		flag = 0;
		struct node *root = initialise();
		for(i = 0; i < n; i++) {
			cin>>s[i];
			root = addword(s[i],root);
		}
		for(i = 0; i < n; i++) {
			if(prefixcount(s[i],root) > 1) {
				flag = 1;
				break;
			}
		}
		if(flag == 0) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
	}

	


}
