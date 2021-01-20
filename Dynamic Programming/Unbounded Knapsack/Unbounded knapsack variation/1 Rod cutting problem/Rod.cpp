#include<bits/stdc++.h>
using namespace std;

int t[2002][202];
int knapsack(int l[],int p[],int w)
{
	for(int i=1;i<w+1;i++)
	{
		for(int j=1;j<w+1;j++)
		{
			if(l[i-1]<=j)
			t[i][j]=max((p[i-1]+t[i][j-l[i-1]]), (t[i-1][j]));
			else
			t[i][j]=t[i-1][j];
		}
	}
	
	return t[w][w];
}
int main()
{
	int length;
	cin>>length;
	int l[length],p[length];
    	
	for(int i=0;i<length;i++)
	{
		cin>>l[i];
        cin>>p[i];	
	}
	
	for(int i=0;i<length+1;i++)
	{
		for(int j=0;j<length+1;j++)
		{
			if(i==0||j==0)
			t[i][j]=0;
		}
	}
	
	int k=knapsack(l,p,length);
	
	cout<<k;
	return 0;
}
