#include <iostream>
#include <utility>
#include <string>
#include <tuple>
#include <map>
#include <vector>
#include <type_traits>
#include <variant>
#include <cassert>

#include "sorts.h"

template <typename T>
class addable
{
    T _value;
public:
    addable(T v) : _value{v} {}
    
//     template <typename U>
//     T add(U x) const {
//         return _value + x;
//     }

//     template <typename U>
//     T add(U x) {
//         auto copy(_value);
//         for (auto& n : copy ) {
//             n += x;
//         }
//         return copy;
//     }

    template <typename U>
    T add(U x) {
        if constexpr ( std::is_same_v<T, std::vector<U>> ) {
            auto copy(_value);
            for (auto& n : copy ) {
                n += x;
            }
            std::cout << "Vector: " << std::endl;
            for (const auto& n : copy)
                std::cout << n << std::endl;
            return copy;
        }
        else {
            std::cout << "Value: " << (_value + x) << std::endl;
            return _value + x;
        }
    }

};

struct SomeStruct
{
    std::vector<int> _someVec {1,2,3};
};

SomeStruct foo() {
    return SomeStruct{};
}

int main(int argc, char* argv[])
{
    // addable<int>{1}.add(2);
    // addable<std::vector<int>>{ std::vector<int> {1,2,3} }.add(10);

    // SomeStruct ss;
    // for (const auto& val : ss._someVec)
    // std::cout << val << std::endl;

    for (const auto& obj: foo()._someVec)
        std::cout << obj << std::endl;

    std::cout << "---" << std::endl;

    std::variant<int, float> _someVariant {1};
    // try
    // {
    //     std::get<float>(_someVariant);
    // }
    // catch(const std::bad_variant_access& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
    auto _var = std::get<0>(_someVariant); 
    std::cout << _var << std::endl;

const char* s1 = R"foo(
Hello
  World
)foo";
    std::cout << R"foo("Hi")foo" << std::endl;

    int arr_bubble[] {5,2,1,4,2,3};
    std::cout << "-----" << std::endl; 
    for(const auto& val : arr_bubble)
        std::cout << val << " "; 
    BubbleSort(arr_bubble, std::size(arr_bubble));
    std::cout << std::endl;
    for(const auto& val : arr_bubble)
        std::cout << val << " ";
    std::cout << std::endl;

    int arr_selection[] {5,2,1,4,3,2};
    std::cout << "-----" << std::endl; 
    for(const auto& val : arr_selection)
        std::cout << val << " "; 
    SelectionSort(arr_selection, std::size(arr_selection));
    std::cout << std::endl;
    for(const auto& val : arr_selection)
        std::cout << val << " ";
    std::cout << std::endl;

    int arr_insertion[] {5,2,1,4,3,2};
    std::cout << "-----" << std::endl; 
    for(const auto& val : arr_insertion)
        std::cout << val << " "; 
    InsertionSort(arr_insertion, std::size(arr_insertion));
    std::cout << std::endl;
    for(const auto& val : arr_insertion)
        std::cout << val << " ";
    std::cout << std::endl;

    int arr_quick[] {4,7,2,5,9,4,3,2};
    std::cout << "-----" << std::endl; 
    for(const auto& val : arr_quick)
        std::cout << val << " "; 
    QuickSortHoara(arr_quick, std::size(arr_quick));
    std::cout << std::endl;
    for(const auto& val : arr_quick)
        std::cout << val << " ";
    std::cout << std::endl;

    int arr_quick_l[] {4,7,2,5,9,4,3,2};
    std::cout << "-----" << std::endl; 
    for(const auto& val : arr_quick_l)
        std::cout << val << " "; 
    QuickSortLomuto(arr_quick_l, std::size(arr_quick_l));
    std::cout << std::endl;
    for(const auto& val : arr_quick_l)
        std::cout << val << " ";
    std::cout << std::endl;

    return 0;
}