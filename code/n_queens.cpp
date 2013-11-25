/*
 * n_queens.cpp
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
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int* place = new int[n];  
        int count = 0;  
        vector<vector<string> > result;
        placeQueens(0, n, count, place, result); 
        return result;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

