class Solution {
public:
vector<vector<int>>result;
    void twoSum(vector<int> & nums, int target, int i, int j){
        while(i<j){
            if(nums[i]+nums[j]>target)  j--;
            else if(nums[i]+nums[j]<target)  i++;
            else{
                //we will remove duplicate from either end i &j
                while(i<j && nums[i]==nums[i+1])  i++;
                while(i<j && nums[j]==nums[j-1])  j--;
                result.push_back({-target, nums[i], nums[j]});
                i++;
                j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
         int n = nums.size();
        if(n<3){
            return{};
        }
        result.clear();
        //sort
        sort(begin(nums), end(nums));
        //fixing one element n1
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int n1=nums[i];
            int target=-n1;
            twoSum(nums, target, i+1,n-1 );  //it will find out the n2 & n3 : {n1, n2, n3}
        }
        return result;
    }
};



// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n = nums.size();
//         set<vector<int>> st;

//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 for(int k=j+1;k<n;k++){
//                     if(nums[i]+nums[j]+nums[k]==0){
//                         vector<int>temp={nums[i],nums[j],nums[k]};
//                         sort(temp.begin(),temp.end());
//                         st.insert(temp);
//                     }
//                 }
//             }
//         }
//         vector<vector<int>> result(st.begin(),st.end());
//         return result;
//     }
// };



// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n=nums.size();
//         set<vector<int>> st;

//         for(int i=0;i<n;i++){
//             unordered_set<int>hashSet;
//             for(int j=i+1;j<n;j++){
//                 int third=-(nums[i]+nums[j]);
//                 if(hashSet.find(third)!=hashSet.end()){
//                     vector<int>temp={nums[i],nums[j],third};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//                 hashSet.insert(nums[j]);
//             }
//         }
//         return vector<vector<int>>(st.begin(),st.end());
//     }
// };