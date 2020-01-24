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
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(v[j] > v[j+1])
			{
				temp = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;
			}
		}
	}

	for(i=0;i<n;i++)
	{
		cout<<v[i]<<" ";
	}

	return 0;
}