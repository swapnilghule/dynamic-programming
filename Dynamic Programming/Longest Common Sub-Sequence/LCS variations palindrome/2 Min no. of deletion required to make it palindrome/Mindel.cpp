#include<bits/stdc++.h>
using namespace std;


int t[202][2002];

int LPS_MinDel(string x,string y,int m,int n)
{
	for(int i=1;i<m+1;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			if(x[i-1]==y[j-1])
            t[i][j] = 1 + t[i-1][j-1];
			else
			t[i][j]= max(t[i-1][j] , t[i][j-1]);			
		}
	}
	
	int lenLPs= t[m][n];
	 return m - lenLPs;
	
}
int main()
{
	string x,y,z;
	cin>>z;
	
	x=z;
	reverse(z.begin(),z.end());
    y=z;
    
    
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
	
	
	int k = LPS_MinDel(x,y,m,n);
	
	cout<<k;
	return 0;
}
