#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> v;
	int n,i,j,k,count=0,data;
	cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>data;
        v.push_back(data);
    }
    cout<<"enter the value for comaprison"<<endl;
    cin>>k;
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		if(i!=j)
    		{
    			if(v[i]+v[j] == k)
    			{
    				count++;
    			}
    		}
    	}
    }
    cout<<count/2;
	return 0;
}