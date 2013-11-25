/*
 * letter_combination_of_a_phone_number.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * http://liaoxl.github.io/blog/20131121/leetcode-lcpn/
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void dfs(string digits, int i, string &picked, vector <string> &ret)
    {
        const static string key_maps[10]={
            "0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        if (i == digits.length()) {
            ret.push_back(picked);
            return;
        }
        int n = digits[i]  -'0';
        string keys = key_maps[n];
        for (int j=0;j<keys.length();j++) {
            picked.push_back(keys[j]);
            dfs(digits,i+1, picked, ret);
            picked.pop_back();
        }        
    }
public:    
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = digits.length();
        vector <string> ret;
        string picked;
        dfs(digits, 0, picked, ret);
        return ret;
    }    
};

int main(int argc, char* argv[])
{
	
	return 0;
}

