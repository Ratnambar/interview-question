#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> v;
    int n,i,data,x,j,left,right;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>data;
        v.push_back(data);
    }
    left=0;
    right = n-1;
    while(left<right)
    {
        while(v[left]%2 == 0 && left<right)
        {
            left++;
        }
        while(v[right]%2 == 1 && left<right)
        {
            right--;
        }
        if(left<right)
        {
            int temp = v[left];
            v[left] = v[right];
            v[right] = temp;
            left++;
            right--;
    }
    }
    
    for(i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    
    return 0;
}
