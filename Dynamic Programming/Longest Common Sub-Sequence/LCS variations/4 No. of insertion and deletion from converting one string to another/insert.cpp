#include<bits/stdc++.h>


using namespace std;


int t[200][2000];

string LCS_Print(string x,string y,int m,int n)
{
	for(int i=1;i<m+1;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			if(x[i-1]==y[j-1])
			t[i][j]= 1+ t[i-1][j-1];
			else
			t[i][j]= max(t[i-1][j],t[i][j-1]);
		}
	}
	
	int i=m;
	int j=n;
	string s;
	cout<<"\n";
	for(int i=0;i<m+1;i++)
	{


		for(int j=0;j<n+1;j++)
		{
			
			cout<<t[i][j]<<"\t";
		}
		cout<<"\n";
	}
	
	while(i>0 && j>0)
	{
		if(x[i-1]==y[j-1])
		{
			s.push_back(x[i-1]);
			i--;
			j--;
		}
		else
		{
			if(t[i-1][j]>t[i][j-1])
			i--;
			else
			j--;
		}
	}
	
	reverse(s.begin(),s.end());
	
	return s;
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
			if(i==0 || j==0)
			t[i][j]=0;
		}
	}
	
	string s=LCS_Print(x,y,m,n);
	int insert = n - s.length();
	int dele = m - s.length();
	
	
	cout<<insert<<" "<<dele;
	
	return 0;
}
