#include <bits/stdc++.h>
#include <string>
#include <strings.h>

void revString(std::string &s) {
    int len = s.length();
    char *rev;
    rev = new char[len+1];
    char temp;
    for(int i=0; i < len; i++){
        rev[i] = s[len-i-1];
    }
    s = rev;
};

int main(){

    std::string str = "Hello Martha";
    std::cout<<str<<std::endl;
    revString(str);
    std::cout<<str;
    return 0;

}
