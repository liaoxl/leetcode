/*
 * n_queens2.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(int row, int* place)  
    {  
        for (int i = 0; i < row; ++i)  
        {  
            int diff = abs(place[i] - place[row]);  
            if (diff == 0 || diff == row - i)  
                return false;  
        }  
        return true;  
    }  
      
    void placeQueens(int row, int n, int &count, int* place,
                     vector<vector<string> > &result)  
    {  
        if (row == n)  
        {
            vector<string> tmp;
            for (int i = 0; i < row; ++i)
            {
                string str(n, '.');
                str[place[i]] = 'Q';
                tmp.push_back(str);
            }
            result.push_back(tmp);
            return;  
        }  
          
        for (int i = 0; i < n; ++i)  
        {  
            place[row] = i;  
            if (check(row, place))  
                placeQueens(row+1, n, count, place, result);  
        }  
    }  
    int totalNQueens(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int* place = new int[n];  
        int count = 0;  
        vector<vector<string> > result;
        placeQueens(0, n, count, place, result); 
        return result.size();
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

