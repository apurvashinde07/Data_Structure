#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> &arr, int tar){
    int st = 0, end = arr.size()-1;

    while(st <= end){
        int mid = st +(end - st)/2;
        if(arr[mid] == tar){
            return mid;
        }else if(arr[mid] < tar){
            st = mid + 1;   
        }else{
            end = mid - 1;
        }
        
    }
    return -1;

}

int main(){
    vector<int> arr = {4, 3, 7, 6, 9, 2};
    int tar = 9;

    int result = binarySearch(arr, tar);
    if(result == -1){
        cout<<"element is not found";
    }else{
        cout<<"element is found at index: "<<result;
    }
    
    return 0;
}