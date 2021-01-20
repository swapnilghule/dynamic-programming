#include<bits/stdc++.h>
using namespace std;

int t[200][2000];

int LCSub(string x,string y,int m,int n)
{
	int max=0;
	for(int i=1;i<m+1;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			if(x[i-1]==y[j-1])
			t[i][j]= 1+ t[i-1][j-1];
			else
			t[i][j]=0;
		}
	}
	
	
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			if(max<t[i][j])
			{
				max=t[i][j];
			}
		}
	}
	
	return max;
}
int main()
{
	string x,y;
	cin>>x>>y;
	
	int m= x.length();
	int n= y.length();
	
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			if(i==0||j==0)
			t[i][j]=0;
		}
	}
	
	int k=LCSub(x,y,m,n);

	
	cout<<k;
	return 0;
}
