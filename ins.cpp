#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class Sorting{
public:
    int insertion_sort(vector<int>& nums){
        int size = nums.size(), count_comp=0, count_shifts=0;
        for(int i=1;i<size;i++){
            int key = nums[i];
            int j = i-1;
            count_comp++;
            while(j>=0 && nums[j]>key){
                nums[j+1] = nums[j];
                j=j-1;
                count_shifts++;
            }
            nums[j+1] = key;
        }
        cout << "Comparisons count = " << count_comp << " and shifts is " << count_shifts << endl;
    }
};
int main(){
    vector<int> nums;
    int range;
    cout << "Enter range of array : ";
    cin >> range;
    for(int i=0;i<range;i++){
        int num;
        cout << "Enter a number : ";
        cin >> num;
        nums.push_back(num);
    }
    cout << "Provided array is :" << endl;
    for(int i : nums){
        cout << "Element is " << i << endl;
    }
    Sorting sort;
    int count = sort.insertion_sort(nums);
    cout << "Sorted array is :" << endl;
    for(int i : nums){
        cout << "Element is " << i << endl;
    }
    cout << "The no. of comparison and shift is " << count << endl;
}