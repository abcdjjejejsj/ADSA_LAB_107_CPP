//PROBLEM:-move the 0's to the last of the array
/*
 Logic: Find the index of each zero in the array, then reverse the elements between each pair of zeros (excluding the zeros themselves). Finally, concatenate all segments and keep zeros at their original
 positions.
*/
#include <iostream>
#include <vector>
using namespace std;

void combine(vector<int> &arr, int start, int end, int mid)
{
    vector<int> temp;
    int s = start, m = mid;

    while (s < mid && m <= end)
    {
        if (arr[s] != 0)
        {
            temp.push_back(arr[s]);
            s++;
        }
        else
        {
            temp.push_back(arr[m]);
            m++;
        }
    }

    while (s < mid)
    {
        temp.push_back(arr[s]);
        s++;
    }

    while (m <= end)
    {
        temp.push_back(arr[m]);
        m++;
    }

    int cnt = 0;
    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[cnt];
        cnt++;
    }
}

void merge(vector<int> &arr, int start, int end)
{
    if (start == end)
        return;

    int mid = (start + end) / 2;
    merge(arr, start, mid);
    merge(arr, mid + 1, end);
    combine(arr, start, end, mid + 1);
}

int main()
{
    vector<int> arr = {2, 0, 5, 0, 1, 3, 0, 7, 4, 8};

    merge(arr, 0, arr.size() - 1);

    cout << "Final array with 0s at end:\n";
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}
