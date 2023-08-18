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
#include "trees.h"

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

static void print(int n)
{
    if (n < 0)
        return;
    std::cout << " " << n;
  
    // The last executed statement is recursive call
    print(n - 1);
}

int main(int argc, char* argv[])
{
    std::cout << "Test tree" << std::endl;
    auto root = std::make_shared<Node>(7,7);
    InsertNode(root,5,5);
    InsertNode(root,4,4);
    InsertNode(root,8,8);
    InsertNode(root,6,6);
    PrintTree(root);
    auto found = Search(root, 106);
    if (found)
        std::cout << "found: value = " << found->_value << "; key = " << found->_key << std::endl;
    else
        std::cout << "No element" << std::endl;

    DeleteNode(root, 5);
    PrintTree(root);

    // auto findMax = GetMaxNode(root);
    // auto findMin = GetMinNode(root);

    // if (findMax)
    //     std::cout << "findMax = " << findMax->_key << std::endl;
    // else
    //     std::cout << "No max" << std::endl;

    // if (findMin)
    //     std::cout << "findMin = " << findMin->_key << std::endl;
    // else
    //     std::cout << "No min" << std::endl;
    
    print(5);

    return 0;
}