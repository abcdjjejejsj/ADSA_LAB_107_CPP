#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>nums={0,1,2,0,1,2,3,0,0};
    int end=nums.size()-1,temp;

    // for(int i=0;i<nums.size();i++)
    // {
    //     if(end<=i)
    //     {
    //         break;
    //     }
    //     while(nums[end]==0)
    //     {
    //         end--;
    //     }
    //     if(nums[i]==0)
    //     {
    //         temp=nums[i];
    //         nums[i]=nums[end];
    //         nums[end]=temp;
    //     }
    // }


    vector<int>nums2;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]!=0)
        {
            nums2.push_back(nums[i]);
        }
    }
    for(int i=nums2.size()-1;i<nums.size();i++)
    {
        nums2.push_back(0);+
    }
    nums=nums2;
    cout<<"final array : ";
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }
}