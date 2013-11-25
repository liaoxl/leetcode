/*
 * longest_substring_without_repeating_characters.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        	int n = s.length();
          int i = 0, j = 0;
          int maxLen = 0;
          bool exist[256] = { false };
          while (j < n) {
            if (exist[s[j]]) {
              maxLen = max(maxLen, j-i);
              while (s[i] != s[j]) {
                exist[s[i]] = false;
                i++;
              }
              i++;
              j++;
            } else {
              exist[s[j]] = true;
              j++;
            }
          }
          maxLen = max(maxLen, n-i);
          return maxLen;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

