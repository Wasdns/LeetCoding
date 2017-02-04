//
//  main.cpp
//  Median of Two Sorted Arrays
//
//  Created by wasdns on 17/2/4.
//  Copyright © 2017年 wasdns. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>


int* UnionTwoArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) { // UnionTwoArrays
    int* ans;
    ans = (int*)malloc((nums1Size+nums2Size+1) * sizeof(int));
    
    int p1 = 0, p2 = 0, p = 0;
    for (int i = 0; i < nums1Size+nums2Size; i++) {
        if (p1 >= nums1Size) { // if out of bound
            ans[p] = nums2[p2]; p2++; p++; continue;
        } else if (p2 >= nums2Size) {
            ans[p] = nums1[p1]; p1++; p++; continue;
        }
        
        if (nums1[p1] < nums2[p2]) { // normal judge
            ans[p] = nums1[p1]; p1++; p++;
        } else {
            ans[p] = nums2[p2]; p2++; p++;
        }
    }
    
    return ans;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int* unionarrays = (int*)malloc((nums1Size+nums2Size+1) * sizeof(int));
    unionarrays = UnionTwoArrays(nums1, nums1Size, nums2, nums2Size);
    
    double ans = 0; int index = (nums1Size+nums2Size)/2;
    if ((nums1Size+nums2Size)%2 == 0) {
        ans = (unionarrays[index]+unionarrays[index-1])*1.0/2;
    } else {
        ans = unionarrays[index];
    }
    
    return ans;
}

void PrintArrays(int* p, int n) { // Print Arrays
    for (int i = 0; i < n; i++)
        printf("%d ", p[i]); printf("\n");
}

int main() {
    int n1, n2;
    scanf("%d%d", &n1, &n2);
    
    int* p1; int* p2;
    p1 = (int*)malloc(n1*(sizeof(int)));
    p2 = (int*)malloc(n2*(sizeof(int)));
    
    for (int i = 0; i < n1; i++) {
        scanf("%d", &p1[i]);
    }
    for (int i = 0; i < n2; i++) {
        scanf("%d", &p2[i]);
    }
    
    PrintArrays(p1, n1);
    PrintArrays(p2, n2);
    
    PrintArrays(UnionTwoArrays(p1, n1, p2, n2), n1+n2);
    
    printf("%lf\n", findMedianSortedArrays(p1, n1, p2, n2));
    
    return 0;
}
