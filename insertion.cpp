#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v;
	int n,i,data,j,temp;
	cout<<"size of array";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>data;
		v.push_back(data);
	}
	for(i=1;i<=n-1;i++)
	{
		temp = v[i];
		j = i;
		while(v[j-1] > temp && j>=1)
		{
			v[j] = v[j-1];
			j--;
		}
		v[j] = temp;
	}
	for(i=0;i<n;i++)
	{
		cout<<v[i]<<" ";
	}
	return 0;
}