//
//  main.cpp
//  Longest Substring Without Repeating Characters
//
//  Created by wasdns on 17/2/3.
//  Copyright © 2017年 wasdns. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int hashmap[505]; // using hashmap record the character's pla

int lengthOfLongestSubstring(string s) {
    int ans = 0, start = 0;
    
    memset(hashmap, -1, sizeof(hashmap));
    
    if (s.length() == 0) return 0;
    if (s.length() == 1) return 1;
    
    for (int i = 0; i < s.length(); i++) {
        int index = int(s[i]);
        
        // refresh start
        if (hashmap[index] != -1 && hashmap[index]+1 > start)
            start = hashmap[index]+1;
        
        if (i-start > ans) ans = i-start;
        
        // refresh character's pla in hashmap(using ASCII index)
        hashmap[index] = i;
    }
    
    return ans+1;
}

int main() {
    string input;
    
    cin >> input;
    cout << lengthOfLongestSubstring(input) << endl;
    
    return 0;
}

// ifcodingthenhappy


/*
 
 O(n^2) solution:
 
 bool hashmapjudge(string s, int l, int r) {
    bool ans = true;
 
    memset(hashmap, 0, sizeof(hashmap));
 
    for (int i = l; i <= r; i++) {
        int index = int(s[i]);
 
        if (hashmap[index] == 1) {
            ans = false; break;
        }
        else hashmap[index] = 1;
    }
 
    return ans;
 }
 
 int lengthOfLongestSubstring(string s) {
    int ans = 0;
 
    if (s.length() == 1) return 1;
 
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < s.length(); j++) {
            if (hashmapjudge(s, i, j)) {
                if (j-i+1 > ans) ans = j-i+1;
            }
        }
    }
 
    return ans;
 }
 */
