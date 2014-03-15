#include <iostream>
#include <string>

long long fibonacci(std::size_t n);

int main()
{
    std::cout << fibonacci(4) << std::endl;
    std::cout << fibonacci(5) << std::endl;

}


long long fibonacci(std::size_t n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    long long fib_result = 0;
    long long fib_min_one = 1;
    long long fib_min_two = 0;

    for(std::size_t ix = 2; ix <= n; ++ix)
    {
        fib_result = fib_min_one + fib_min_two;
        fib_min_two = fib_min_one;
        fib_min_one = fib_result;
    }
    return fib_result;
}

    
