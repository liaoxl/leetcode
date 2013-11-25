/*
 * pascals_triangle2.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getV(vector<int> t, int m)
    {
        vector<int> re;
        re.push_back(t[0]);
        for(int i=1; i<m-1; i++)
        {
            re.push_back(t[i-1]+t[i]);
        }
        re.push_back(t[m-2]);
        return re;
    }
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> tmp;
        if(rowIndex<0)
        {
            return tmp;
        }
        tmp.push_back(1);

        for(int i=2; i<=rowIndex+1; i++)
        {
            tmp=getV(tmp, i);
        }
        return tmp;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

