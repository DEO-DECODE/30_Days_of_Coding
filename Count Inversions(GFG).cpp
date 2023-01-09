//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    long long int merge(long long  arr[], int s, int mid, int e)
{
    long long int inv = 0;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *first = new int[len1];
    int *second = new int[len2];
    // Copying value
    int mainArrayIndex = s;
    for (int i = 0; i < len1; ++i)
    {
        first[i] = arr[mainArrayIndex++];
    }
    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; ++i)
    {
        second[i] = arr[mainArrayIndex++];
    }
    mainArrayIndex = s;
    int index1 = 0, index2 = 0;
    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] <= second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            
            arr[mainArrayIndex++] = second[index2++];
            inv += (len1 - index1);
        }
    }
    while (index1 < len1)
    {
        /* code */
        arr[mainArrayIndex++] = first[index1++];
    }
    while (index2 < len2)
    {
        /* code */
        arr[mainArrayIndex++] = second[index2++];
    }
    return inv;
}
long long int mergeSort(long long arr[], int s, int e)
{

    long long int inv = 0;
    if(s<e){
    int mid = (s + e) / 2;

    inv += mergeSort(arr, s, mid);
    inv += mergeSort(arr, mid + 1, e);
    inv += merge(arr, s, mid, e);
    }
    return inv;
}
    long long int inversionCount(long long arr[], long long N)
    {
        int low = 0;
        int high = (int)(N-1);
        return mergeSort(arr,low,high);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends
