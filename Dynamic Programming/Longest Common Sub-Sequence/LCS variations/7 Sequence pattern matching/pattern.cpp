#include<bits/stdc++.h>
using namespace std;

int t[200][2000];

bool LCS_TD(string x,string y,int m,int n)
{
	for(int i=1;i<m+1;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			if(x[i-1]==y[j-1])
			t[i][j] = 1+ t[i-1][j-1];
			else
			t[i][j] = max(t[i][j-1],t[i-1][j]);
		}
	}
	int LCS=t[m][n];
	if(x.length() == LCS )
	return true;
	else
	return false;
}
int main()
{
	string x,y;
	cin>>x>>y;
	
	int m=x.length();
	int n=y.length();
	
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			if(i==0 || j==0)
			t[i][j]=0;
		}
	}	
	
	
	bool k=LCS_TD(x,y,m,n);
	
	cout<<"\n";
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
		//	if(i==0 || j==0)
			cout<<t[i][j]<<"\t";
		}
		cout<<"\n";
	}	
	cout<<k;
	return 0;
}
