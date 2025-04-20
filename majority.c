#include <stdio.h>

int majorityElement(int* nums, int numsSize) {
    int candidate = nums[0];
    int count = 0;

    // Phase 1: Find the candidate
    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            candidate = nums[i];
        }
        count += (nums[i] == candidate) ? 1 : -1;
    }

    return candidate;
}

int main(int argc, char *argv[]) {
    // Test case 1
    int nums1[] = {3, 2, 3};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Majority element in nums1: %d\n", majorityElement(nums1, size1));

    // Test case 2
    int nums2[] = {2, 2, 1, 1, 1, 2, 2};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Majority element in nums2: %d\n", majorityElement(nums2, size2));

    return 0;
}
