#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
/*
989. 数组形式的整数加法

对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1, 2, 3, 1]。

给定非负整数 X 的数组形式 A，返回整数 X + K 的数组形式。

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/add-to-array-form-of-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
    int ksize = 0;
    int val_k = k;

    while (val_k)
    {
        ksize++;
        val_k /= 10;
    }
    int len = ksize > numSize ? ksize + 1 : numSize + 1;
    int ki = 0;
    int next = 0;
    int ret1 = 0;
    int reti = 0;
    int pm = numSize - 1;
    int* pa = (int*)malloc(sizeof(int) * len);
    int sum = 0;
    while (pm >= 0 || reti < ksize)
    {
        ret1 = 0;
        if (pm >= 0)
        {
            ret1 = num[pm--];
        }
        int ret2 = k % 10;
        k /= 10;
        sum = ret2 + ret1 + next;
        if (sum >= 10)
        {
            next = 1;
            sum -= 10;
        }
        else
            next = 0;
        pa[reti++] = sum;
    }
    if (next == 1)
        pa[reti++] = 1;
    int ret3 = reti;
    int right = ret3 - 1;
    int left = 0;
    while (left < right)
    {
        int tmp = pa[left];
        pa[left] = pa[right];
        pa[right] = tmp;
        left++;
        right--;
    }

    *returnSize = reti;
    return pa;

}

/*给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//
//int removeElement(int* nums, int numsSize, int val) {
//    int left = 0;
//    for (int right = 0; right < numsSize; right++)
//    {
//        if (val != nums[right])
//        {
//            nums[left] = nums[right];
//            left++;
//        }
//    }
//    return left;
//
//}

/*给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//
//int removeDuplicates(int* nums, int numsSize) {
//    if (0 == numsSize)
//    {
//        return 0;
//    }
//    int left = 0;
//    int right = 1;
//    while (right < numsSize)
//    {
//        if (nums[right] != nums[left])
//        {
//            nums[left + 1] = nums[right];
//            left++;
//        }
//        right++;
//    }
//    return left + 1;
//}

/*给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
//
//    int p1 = m - 1;
//    int p2 = n - 1;
//    int pm1 = m + n - 1;
//    int tmp = 0;
//
//    while (p1 >= 0 || p2 >= 0)
//    {
//        if (-1 == p1)
//        {
//            tmp = nums2[p2--];
//        }
//        else if (-1 == p2)
//        {
//            tmp = nums1[p1--];
//        }
//        else if (nums1[p1] > nums2[p2])
//        {
//            tmp = nums1[p1--];
//        }
//        else
//        {
//            tmp = nums2[p2--];
//        }
//
//        nums1[pm1--] = tmp;
//    }
//
//}
