/*
 * gas_station.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int sum = 0;
  int total = 0;
  int j = -1;
  for(int i = 0; i < gas.size() ; ++i){
    sum += gas[i]-cost[i];
    total += gas[i]-cost[i];
    if(sum < 0){
      j=i; sum = 0; 
    }
  }
  return total>=0? j+1 : -1;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

