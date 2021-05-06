//File ini cuma buat coret-coretan; buat debugging dan testing

#include <iostream>
#include <string>

int main(){
    int a = 9;
    int c = 300;
    std::string b = "";
    b = "0" + std::to_string(a);
    b += std::to_string(c) + std::to_string(a);
    std::cout << b << std::endl;
    return 0;
}