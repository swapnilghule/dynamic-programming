#include<bits/stdc++.h>
using namespace std;

int t[200][2000];

int LCS(string x,string y,int m,int n)
{
	if(n==0 || m==0)
	return 0;
	
	if(t[m][n]!= -1)
	return t[m][n];
	
	if(x[m-1]==y[n-1])
	return t[m][n]=1+LCS(x,y,m-1,n-1);
	else
	return t[m][n]= max(LCS(x,y,m,n-1),LCS(x,y,m-1,n));
}
int main()
{
	string x,y;
	cin>>x;
	cin>>y;
	int m=x.length();
	int n=y.length();
	
	memset(t,-1,sizeof(t));
	
	int k=LCS(x,y,m,n);
	cout<<k;
	return 0;
}
