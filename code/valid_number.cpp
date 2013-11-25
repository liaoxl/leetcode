/*
 * valid_number.cpp
 * Copyright (C) 2013 moondark <liaoxl2012@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (s == NULL)
             return false;
             
         while(isspace(*s))
             s++;
             
         if (*s == '+' || *s == '-')
             s++;
             
         bool eAppear = false;
         bool dotAppear = false;
         bool firstPart = false;
         bool secondPart = false;
         bool spaceAppear = false;
         while(*s != '\0')
         {
             if (*s == '.')
             {
                 if (dotAppear || eAppear || spaceAppear)
                     return false;
                 else
                     dotAppear = true;
             }
             else if (*s == 'e' || *s == 'E')
             {
                 if (eAppear || !firstPart || spaceAppear)
                     return false;
                 else
                     eAppear = true;
             }
             else if (isdigit(*s))
             {
                 if (spaceAppear)
                     return false;
                     
                 if (!eAppear)
                     firstPart = true;
                 else
                     secondPart = true;
             }
             else if (*s == '+' || *s == '-')   // behind of e/E
             {
                 if (spaceAppear)
                     return false;
                     
                 if (!eAppear || !(*(s-1) == 'e' || *(s-1) == 'E'))
                     return false;
             }
             else if (isspace(*s))
                 spaceAppear = true;
             else
                 return false;
                 
             s++;            
         }
         
         if (!firstPart) {
             return false;
         }  else if (eAppear && !secondPart) {
             return false;
         } 
         return true;  
    }
};

int main(int argc, char* argv[])
{
	
	return 0;
}

