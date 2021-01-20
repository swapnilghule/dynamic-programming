#include<bits/stdc++.h>
using namespace std;


bool t[100][2000];


int knapsack(int a[],int range,int n)
{
	vector<int> v;
	vector<int> ::iterator i1;
	
	
for(int i=1;i<n+1;i++)
{
	for(int j=1;j<range+1; j++)
	{
		if(a[i-1]<=j)
		t[i][j]= t[i-1][j-a[i-1]] || t[i-1][j];
		else
		t[i][j]=t[i-1][j];
	}
}
/*cout<<"\n";
for(int i=0;i<n+1;i++)
{
	for(int j=0;j<range+1; j++)
	{
       cout<<t[i][j]<<"\t";
	}
	cout<<"\n";
}
*/
	for(int i=1;i<(range/2)+1;i++)
	{
	 if(t[n][i])
	 v.push_back(i);
	}
	cout<<"\n ";
/*	for(i1=v.begin();i1<v.end();i1++)
	{
		cout<<" "<<*i1<<" ";
	}
	
*/	int mn=*min_element(v.begin(),v.end());
	
	return mn;
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	int range=accumulate(a,a+n,0);
	
//	cout<<"\n"<<range;
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<range+1;j++)
		{
			if(i==0)
			t[i][j]=0;
			if(j==0)
			t[i][j]=1;
		}
	}
	
	
	
	int r=knapsack(a,range,n);
	cout<<"\n";
	cout<<r;
	
	
	return 0;
}
