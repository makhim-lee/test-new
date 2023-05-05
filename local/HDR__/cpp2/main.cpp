#include <iostream>
#include <string>

int main(){
    std::string name;
    std::cout << "input your name : ";
    std::cin >> name;

    std::string greeting = "hello, "; + name + "!";

    std::cout << greeting << std::endl;
    return 0;
}