#include<bits/stdc++.h>
using namespace std;


int t[200][2002];

int LPS(string x,string y,int m,int n)
{
	for(int i=1;i<m+1;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			if(x[i-1]==y[j-1])
			t[i][j]= 1 + t[i-1][j-1];
			else
			t[i][j]= max(t[i][j-1], t[i-1][j]);
		}
	}
	
	return t[m][n];
}
int main()
{
	string x,y,z;
	cin>>z;
	int j=0;

	x=z;
    reverse(z.begin(),z.end());
    y=z;
    
   // cout<<x<<"\t"<<y<<"\t"<<z;
	int n=y.length();	
	
	int m=x.length();	

	
	
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			if(i==0||j==0)
			t[i][j]=0;
		}
	}
	
	int k=LPS(x,y,m,n);
	
	cout<<k;
	return 0;
}
