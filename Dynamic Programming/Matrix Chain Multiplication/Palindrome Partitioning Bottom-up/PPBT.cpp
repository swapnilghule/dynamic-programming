#include<bits/stdc++.h>
using namespace std;
 int static t[1001][1001];


int ispalindrome(string str)
{
	int h=0;
	int l=str.length() -1;
	
	while(l > 1)
	{
		if(str[h++] != str[l--] )
		return 0;
	}
	
	return 1;
}
int solve(string x,int i,int j)
{
	int min1=INT_MAX;
	if(i>=j)
	return 0;
	
	if(ispalindrome(x)==1)
	return 0;
	
	if(t[i][j]!=-1)
	return t[i][j];
	
	for(int k=i;k<=j-1;k++)
	{
		int temp = 1 + solve(x,i,k) + solve(x,k+1,j);
		
		if(min1>temp)
		min1=temp;
	}
	
	return t[i][j]=min1;
}
int main()
{
	string x;
	cin>>x;
	
	int n= x.length();
	memset(t,-1,sizeof(t));
	
	int k = solve(x,0,n-1);
	cout<<k;
	
	return 0;
}
