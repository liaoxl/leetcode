/*
 * unique_paths2.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) return 0;
        
        vector<int> dp(m+1,0);
        int j = m-1;
        while(j>=0 && obstacleGrid[n-1][j] == 0)
            dp[j--] = 1;
        
        j = n-1;
        while(--j >= 0)
        {
            for(int k = m-1;k>=0;k--)
                dp[k] = (obstacleGrid[j][k] == 0)?dp[k] + dp[k+1]:0;
        }
        
        return dp[0];
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

