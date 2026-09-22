// brut forse
// O(n+n)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nums3[m + n];
        int i = 0, j = 0, k = 0;         //i=left, j=right, k=index

        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                nums3[k++] = nums1[i++];
            } else {
                nums3[k++] = nums2[j++];
            }
        }

        while (i < m) {
            nums3[k++] = nums1[i++];
        }

        while (j < n) {
            nums3[k++] = nums2[j++];
        }

        // 🔹 Your copy-back part (fixed)
        for (int i = 0; i < m + n; i++) {
            nums1[i] = nums3[i];
        }
    }
};



// OPtimal
// O(mlogm +mlogn)

// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int left = m - 1;
//         int right = 0;
//         while (left >= 0 && right < n) {
//             if (nums1[left] > nums2[right]) {
//                 swap(nums1[left], nums2[right]);
//                 left--;
//                 right++;
//             } else {
//                 break;
//             }
//         }
//         sort(nums1.begin(), nums1.begin() + m);
//         sort(nums2.begin(), nums2.begin() + n);
//         // copy nums2 into nums1
//         for (int i = 0; i < n; i++) {
//             nums1[m + i] = nums2[i];
//         }
//     }
// };
