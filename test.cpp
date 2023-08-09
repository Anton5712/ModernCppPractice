#include <iostream>
#include <utility>
#include <string>
#include <tuple>
#include <map>
#include <vector>
#include <type_traits>

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
        return copy;
        }
        else {
            return _value + x;
        }
    }

};

int main(int argc, char* argv[])
{
    addable<int>{1}.add(2);
    return 0;
}