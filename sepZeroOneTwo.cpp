#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> v;
	int n,i,temp,left,right,mid,data;
	cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>data;
        v.push_back(data);
    }
    left = 0;
    right = n-1;
    mid = 0;
    while(left<=right)
    {
    	switch(v[mid])
    	{
    		case 0:temp = v[left];
		    		v[left] = v[mid];
		    		v[mid] = temp;
		    		left++;
		    		mid++;
		    		break;

		    case 1:mid++;
		    	  break;

		    case 2:temp = v[mid];
				    v[mid] = v[right];
				    v[right] = temp;
				    right--;
				    break;

			default:cout<<"invalid choice";
    	}
    }
	
	for(i=0;i<n;i++)
	{
		cout<<v[i]<<" ";
	}

	return 0;
}