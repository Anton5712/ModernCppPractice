#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char* argv[])
{
    std::string helloWorldSTr = "Hello world from feature";
    std::cout  << helloWorldSTr << std::endl;

    std::stringstream ss;
    ss << "One " << "2 " << 3;
    std::cout << ss.str() << std::endl;
    return 0;
}