#pragma once

#include <vector>
#include <list>
#include <string>

class Scanner {
public:
    Scanner(std::string input):_input(input) {}

    std::string next() {       
        if(isDone()) { throw "Already points to the end position"; }
        
        while(pos != _input.length()) {
            for(auto token: tokenList) {
                if(_input.compare(pos, token.length(), token) == 0) {
                    pos = pos + token.length();

                    std::cout << token <<std::endl;
                    return token;
                }
            }
            pos ++;
        }

        return "";
    }

    double nextDouble() {
        std::string result = "";
        bool startFindDouble = false, startFindDot = false;

        while(pos != _input.length()) {
            if(!startFindDouble) {
                if(_input[pos] <= '9' && _input[pos] >= '0') {
                    result += _input[pos];
                    startFindDouble = true;
                }
            }else{
                if((_input[pos] <= '9' && _input[pos] >= '0')) {
                    result += _input[pos];
                }else if(_input[pos] == '.' && !startFindDot){
                    result += _input[pos];
                    startFindDot = true;
                }else{
                    break;
                }           
            }
            pos ++;
        }

        std::cout << result <<std::endl;
        return std::stod(result);
    }

    bool isDone() { 
        while(_input[pos] == ' ' || _input[pos] == '\n' || _input[pos] == '\t') {
            pos ++;
        }

        return pos == _input.length();
    }

private:
    const std::vector<std::string> tokenList = {"Circle", "Rectangle", "Triangle", "CompoundShape", "(", ")", "[", "]", "{", "}", ","};
    std::string _input;
    std::string::size_type pos = 0;
};