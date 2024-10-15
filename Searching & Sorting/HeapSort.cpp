class Solution {
public:
    void heapify(vector<int>&arr,int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right <n && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }

}
    vector<int> sortArray(vector<int>& nums) {
        int size=nums.size();
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(nums, size, i);
        }

      for (int i = size - 1; i > 0; i--) {
            // Move current root to the end
            swap(nums[0], nums[i]);
            
            // Call heapify on the reduced heap
            heapify(nums, i, 0);
        }
        return nums;
    }
};
