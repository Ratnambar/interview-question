#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> v;
	vector<int> v1;
	int n,i,j,count,data;
	bool flag = false;
	cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>data;
        v.push_back(data);
    }
    for(i=0;i<n;i++)
    {
    	count=0;
    	for(j=0;j<n;j++)
    	{
    		if(i!=j)
    		{
    			if(v[i] == v[j])
    			{
    				count++;
    			}
    		}
    	}
    	if(count == 0)
    	{
    		v1.push_back(v[i]);
    	}
    }
    for(i=0;i<v1.size();i++)
    {
    	cout<<v1[i]<<" ";
    }
	return 0;
}