//
//  main.cpp
//  Add_Two_Numbers
//
//  Created by wasdns on 17/1/30.
//  Copyright © 2017年 wasdns. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* IniNode(int val)
{
    struct ListNode* l = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    l -> val = val;
    
    return l;
}

struct ListNode* CreatList(int len)
{
    struct ListNode* head = IniNode(0);
    
    struct ListNode* p = head;
    
    for (int i = 1; i <= len; i++)
    {
        struct ListNode* p1 = IniNode(0);
        
        p -> next = p1;
        
        p = p1;
        
        scanf("%d", &p->val);
    }
    
    p -> next = NULL;
    
    return head->next;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int carry = 0;
    
    struct ListNode* newlist = IniNode(0);
    
    struct ListNode* p = newlist;
    struct ListNode* newp;
    
    struct ListNode* p1 = l1;
    struct ListNode* p2 = l2;
    
    int flag = 0;
    
    while (true)
    {
        // BreakJudging
        
        if (p1 == NULL && p2 == NULL) {
            flag = 3; break;
        }
        
        else if (p1 == NULL) {
            flag = 2; break;
        }
        
        else if (p2 == NULL) {
            flag = 1; break;
        }
        
        // New node, calculate its val and carry value.
        
        int newval = (p1->val+p2->val+carry) % 10;
        
        newp = IniNode(newval);
        
        carry = (p1->val+p2->val+carry) / 10;
        
        // connect p and newp, then move p to newp's pla.
        
        p -> next = newp;
        
        p = newp;
        
        // move the p1 and p2
        
        p1 = p1 -> next;
        
        p2 = p2 -> next;
        
    }
    
    // LengthJudging
    
    if (flag == 1)          // l1's length > l2's length
    {
        while (p1 != NULL)
        {
            int newval = (p1->val+carry) % 10;
            
            newp = IniNode(newval);
            
            carry = (p1->val+carry) / 10;
            
            p->next = newp;
            
            p = newp;
            
            p1 = p1->next;
        }
    }
    
    else if (flag == 2)     // l1's length < l2's length
    {
        while (p2 != NULL)
        {
            int newval = (p2->val+carry) % 10;
            
            newp = IniNode(newval);
            
            carry = (p2->val+carry) / 10;
            
            p->next = newp;
            
            p = newp;
            
            p2 = p2->next;
        }
    }
    
    if (carry != 0)         // exceeded
    {
        newp = IniNode(1);
            
        p->next = newp;
            
        p = newp;
    }
        
    p->next = NULL;
    
    return newlist->next;
}

void PrintList(struct ListNode* l)
{
    struct ListNode* p = IniNode(0);
    
    p = l;
    
    while (p != NULL)
    {
        printf("%d ", p->val);
        
        p = p->next;
    }
    
    printf("\n");
}

int main()
{
    int len1, len2;
    
    scanf("%d%d", &len1, &len2);
    
    struct ListNode* l1;
    struct ListNode* l2;
    
    l1 = CreatList(len1);
    PrintList(l1);
    
    l2 = CreatList(len2);
    PrintList(l2);
    
    struct ListNode* l;
    
    l = addTwoNumbers(l1, l2);
    PrintList(l);
    
    return 0;
}
