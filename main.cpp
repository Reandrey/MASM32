#include <iostream>
#include <utility>
#include <functional>
#include <type_traits>


#define FWD(...) \
    std::forward<decltype(__VA_ARGS__)>(__VA_ARGS__)

#define LIFT(...) \
    [](auto&&... args) noexcept(noexcept(__VA_ARGS__(FWD(args)...))){ \
        return __VA_ARGS__(FWG(args)...);              \
    }

template <typename F, typename... Args>
requires std::invocable<F,Args...>
constexpr auto curry(F&& f, Args&&... args) noexcept(noexcept(std::invoke(std::forward<F>(f), std::forward<Args>(args)...))) {
    return std::invoke(std::forward<F>(f), std::forward<Args>(args)...);
}


template <typename F, typename... Args>
constexpr auto curry(F&& f, Args&&... args) {
    return std::bind_front(LIFT(curry), std::forward<F>(f), std::forward<Args>(args)...);
}
constexpr int sum(int x, int y) noexcept{
    return x + y;
}
int main() {
    static_assert(curry(sum, 1,2) == 3);
    std::cout << "Hello, Tom!" << std::endl;
    return 0;
}
