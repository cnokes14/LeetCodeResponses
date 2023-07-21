// solution to: https://leetcode.com/problems/median-of-two-sorted-arrays/description/
//

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    unsigned short int iii = 0, jjj = 0, kkk = 0;
    unsigned short int is_odd = (nums1Size + nums2Size) & 0x01;
    unsigned short int midpoint = ((nums1Size + nums2Size) >> 1);
    int arr[midpoint+1];
    while(kkk <= midpoint){
        if(jjj >= nums2Size || (iii < nums1Size && nums1[iii] < nums2[jjj])){
            arr[kkk] = nums1[iii++];
        }
        else {
            arr[kkk] = nums2[jjj++];
        }
        kkk++;
    }
    if(is_odd){
        return arr[kkk-1];
    } 
    return (arr[kkk-1] + arr[kkk-2]) / 2.0;
}
