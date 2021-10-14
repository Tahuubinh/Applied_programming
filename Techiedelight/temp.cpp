#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+9;
string s;
int l,r,st[MAX],t=1,cnt[MAX],ans;
int main()
{
	cin>>s;
	s+='s';
	for (int i=s.size();i>=1;i--) s[i]=s[i-1];
	s[0]=' ';
	for (int i=1;i<s.size();i++)
	{
		cnt[i]=cnt[i-1]+(s[i]=='[');
		if (s[i]=='[' || s[i]=='(') st[t++]=i;	else
		if (s[i]==']' && s[st[t-1]]!='[' || s[i]==')' && s[st[t-1]]!='(') t=0,st[t++]=i; else
		{
			t--;
			if (ans<cnt[i]-cnt[st[t-1]]) ans=cnt[i]-cnt[st[t-1]],l=st[t-1],r=i;
		}
	}
	cout<<ans<<'\n'<<s.substr(l+1,r-l);
}