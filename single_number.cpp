#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int x=0;
        int flag=0;
        int tmp=0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(A[i]-A[j]==0)
                {
                    tmp=A[i+1];
                    A[i+1]=A[j];
                    A[j]=tmp;
                    i+=1;
                    flag=1;
                    break;
                }
            }
            if(!flag)
            {
                x=A[i];
            }
            flag=0;
        }
        return x;
    }
};

int main()
{
	return 0;
}
