#include <iostream>
#include <utility>
#include <string>
#include <tuple>
#include <map>
#include <vector>

template <typename T>
struct sum {
    T value;

    template <typename ... Ts>
    sum(Ts&& ... values) : value{(values + ...)} {}
};

template <typename ... Ts>
sum(Ts&& ... values) -> sum<std::common_type_t<Ts...>>;

int main(int argc, char* argv[])
{
    sum s {1,2.0f,3u};
    std::cout << s.value << std::endl;
    return 0;
}