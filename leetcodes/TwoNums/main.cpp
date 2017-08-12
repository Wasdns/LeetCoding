//
//  main.cpp
//  TwoNums
//
//  Created by wasdns on 17/1/28.
//  Copyright © 2017年 wasdns. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

int dist[1005];

/*
    Function: 
        Copynums
    Explanation:
        The function is used to judging whether a number is in nums or not.
 */

int* Copynums(int* nums, int numsSize, int maxn, int minn)
{
    int i;
    
    int* cpnums;
    
    cpnums = (int*)malloc((maxn-minn+1) * sizeof(int));
    
    for (i = 0; i < maxn-minn; i++)
    {
        *(cpnums+i) = 0;
    }
    
    for (i = 0; i < numsSize; i++)
    {
        cpnums[nums[i]-minn] = 1;
    }
    
    // Debug
    /*
    for (i = 0; i < maxn-minn+1; i++) {
        printf("%d ", cpnums[i]);
    }
    printf("\n");
    */
    
    return cpnums;
}

bool* numsjudge(int* nums, int numsSize, int target)
{
    int i;
    
    bool* ifnums = (bool*)malloc(numsSize * sizeof(bool));
    
    for (i = 0; i < numsSize; i++)
    {
        *(ifnums+i) = true;
    }
    
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] > target) ifnums[i] = false;
        
        else ifnums[i] = true;
    }
    
    // Debug
    /*
    for (i = 0; i < numsSize; i++) {
        if (ifnums[i]) printf("1 ");
        else printf("0 ");
    }
    printf("\n");
    */
    
    return ifnums;
}

int* twoSum(int* nums, int numsSize, int target)
{
    int* ans;
    
    ans = (int*)malloc(5*sizeof(int));
    
    int i, j;
    
    int maxn = 0, minn = 0;
    int pla1 = 0, pla2 = 0;
    
    maxn = nums[0];
    minn = nums[0];
    
    for (i = 1; i < numsSize; i++)
    {
        if (nums[i] > maxn) maxn = nums[i];
        if (nums[i] < minn) minn = nums[i];
    }
    
    int* cpnums = (int*)malloc((maxn-minn+1) * sizeof(int));
    
    cpnums = Copynums(nums, numsSize, maxn, minn);
    
    //bool* ifnums = (bool*)malloc(numsSize * sizeof(bool));
    
    //ifnums = numsjudge(nums, numsSize, target);
    
    for (i = 0; i < numsSize; i++)
    {
        int wanna = target - nums[i];
        
        bool flag = false;
        
        if (cpnums[wanna-minn] == 1)
        {
            for (j = 0; j < numsSize; j++)
            {
                if (nums[j] == wanna && i != j) // 3 + 3 = 6
                {
                    flag = true;
                    
                    pla1 = i;
                    pla2 = j;
                    
                    break;
                }
            }
        }
        
        if (flag) break;
    }
    
    ans[0] = pla1;
    ans[1] = pla2;
    
    return ans;
}

void Print(int* nums)
{
    printf("%d %d\n", nums[0], nums[1]);
}

int main()
{
    int n, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &dist[i]);	
    }
    
    int t;
    
    scanf("%d", &t);
    
    int* ans;
    
    ans = twoSum(dist, n, t);
    
    Print(ans);
    
    return 0;
}

/*
 
 Wrong Answer:
 
 3
 3 2 4
 6
 0 0
 
 4
 -3 4 3 90
 0
 
 */