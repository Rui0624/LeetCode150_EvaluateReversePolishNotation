//
//  main.cpp
//  LeetCode150_EvaluateReversePolishNotation
//
//  Created by Rui on 1/9/18.
//  Copyright © 2018 Rui. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 1) return (atoi(tokens[0].c_str())); // if the token only have one element, return it directly
        
        stack<int> s;//create a new stack to store the elements.
        
        for(int i = 0; i < tokens.size(); i++)//go throught the all units in the tokens
        {
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")//if the element is a number
            {
                s.push(atoi(tokens[i].c_str())); //push it into the stack
            }else{
                int m = s.top();
                s.pop(); //get the top value in stack and pop out the top value
                int n = s.top();
                s.pop();
                
                if(tokens[i] == "+")
                    s.push(m + n);//do the caculate between last two value in stack
                if(tokens[i] == "-")
                    s.push(m - n);
                if(tokens[i] == "*")
                    s.push(m * n);
                if(tokens[i] == "/")
                    s.push(n / m);
            }
            
        }
        
        return s.top;
    }
};
