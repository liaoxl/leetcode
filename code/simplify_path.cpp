/*
 * simplify_path.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isBeginWithCur(string path)
    {
        int n=path.length();
        if(n<1) return false;
        if(n==1 && path[0]=='.') return true;
        if(n>=2 && path[0]=='.' && path[1]=='/')
        {
            return true;
        }
        return false;
    }

    bool isBeginWithUp(string path)
    {
        int n=path.length();
        if(n<2) return false;
        if(path[0]=='.' && path[1]=='.')
        {
            return true;
        }
        return false;
    }
    int findNextSlash(string path)
    {
        int i=0;
        while(path[i]!='\0')
        {
            if(path[i]=='/')
            {
                return i+1;
            }
            i++;
        }
        return i;
    }

    string simplifyPath(string path) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        stack<string> mystack;
        mystack.push("/");

        int n=path.length();
        for(int i=0; i<n; )
        {
            string str=path.substr(i,n-i);
            int j=findNextSlash(str);
            if(i+j<n && (str).substr(0,j)=="/")
            {
                i++;
            }
            else if(isBeginWithCur(str))
            {
                i+=1;
            }
            else if(isBeginWithUp(str))
            {
                if(mystack.size()>1) mystack.pop();
                i+=2;
            }
            else if(i+j<=n)
            {
                mystack.push((str).substr(0,j));
                i+=j;
            }
            else
            {
                mystack.push(str);
                break;
            }
        }

        string res;
        while(!mystack.empty())
        {
            res.insert(0, mystack.top());
            mystack.pop();
        }
        int rlen=res.length();
        while(rlen>1 && (res[rlen-1]=='/'||res[rlen-1]=='.'))
        {
            rlen-=1;
            res.resize(rlen);
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

