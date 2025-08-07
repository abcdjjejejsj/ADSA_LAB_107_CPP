//to count the number of 0's  in giver integer array in which 0's are follwed by 1's. Example input=[1,1,1,1,0,0,0]  output=3

/*
 Logic:- split the array in two halves then check the mid if
 1)at mid '0' is there then check left side if 1 is present at the mid-1 then the 0 at mid is 1st zero means before 0 all are 1 and after 0 all re 0 now 
 finally calcuate the no.of 0 by size-mid
 2))at mid '0' is there then check left side if 0 is present at the mid-1 means the 0 we got is not the first 0 then repeat the process till 1st condition gets true 
 3)at mid 1 is found then check right if 0 is present then we found the last 1 means after that 0 are started so calculate size-mid+1
 4)at mid 1 and right also 1 then repeat the process till 3rd condition get true
 
*/

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>nums={1, 1, 1, 1,0,0};
    int low=0,high=nums.size()-1,mid;
    if(nums[nums.size()-1]==1)
    {
        cout<<"No.of 0's : 0"<<endl;
    }else if(nums[0]==0){
        cout<<"No.of 0's : "<<nums.size();
    }else{
        while(low<=high)
        {
            mid=(low+high)/2;
            if(nums[mid]==0)
            {
                if(nums[mid-1]==1)
                {
                    break;
                }else{
                    high=mid;
                }
            }else{
                if(nums[mid+1]==0)
                {
                    mid=mid+1;
                    break;
                }else{
                    low=mid;
                }
            }
        }
        cout<<"No.of 0's : "<<nums.size()-mid<<endl;
        
    }
}

