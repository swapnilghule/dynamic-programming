#include<bits/stdc++.h>
using namespace std;

int t[1001][1001];

int MCM(int a[],int i,int j)
{
	int min1=INT_MAX;
	if(i>=j)
	return 0;
	
	if(t[i][j]!=-1)
	return t[i][j];
	
	for(int k=i;k<=j-1;k++)
	{
		
		int temp=MCM(a,i,k) + MCM(a,k+1,j) + (a[i-1]*a[j]*a[k]);
		if(temp<min1)
		min1=temp;
	}
	
	return t[i][j]=min1 ;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	memset(t,-1,sizeof(t));
	
	
	int k=MCM(a,1,n-1);
	
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			cout<<t[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<k;
	
	return 0;
	
}
