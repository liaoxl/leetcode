#include <iostream>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n==0)
        {
            return;
        }
        if(m==0)
        {
            for(int i=0; i<n; i++)
            {
                A[i]=B[i];
            }
            return;
        }
        int* t=new int[m];
        for(int i=0; i<m; i++)
        {
            t[i]=A[i];
        }
        int ind=0;
        int aid=0,bid=0;
        while(ind<m+n)
        {
            if(aid<m && t[aid]<=B[bid])
            {
                A[ind]=t[aid];
                ind++;
                aid++;
				continue;
            }
            else if(bid<n && t[aid]>B[bid])
            {
                A[ind]=B[bid];
                ind++;
                bid++;
				continue;
            }
            else if(aid==m)
            {
                A[ind]=B[bid];
                ind++;
                bid++;
				continue;
            }
			else if(bid=n)
            {
                A[ind]=t[aid];
                ind++;
                aid++;
				continue;
            }
        }
        delete [] t;
    }
};

int main()
{
	int A[8]={1,2,4,5,6};
	int B[2]={3};
	Solution s;
	s.merge(A,5,B,1);

	for(int i=0; i< 6; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	return 0;
}
