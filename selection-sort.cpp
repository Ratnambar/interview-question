#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> v;
	int n,i,data,j,temp,min;
	cout<<"size of array";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>data;
		v.push_back(data);
	}
	for(i=0;i<n-1;i++)
	{
		min = i;
		for(j = i+1;j<n;j++)
		{
			if(v[j] < v[min])
			{
				min = j;
			}
		}
		temp = v[i];
		v[i] = v[min];
		v[min] = temp;

	}

	for(i=0;i<n;i++)
	{
		cout<<v[i]<<" ";
	}

	return 0;
}