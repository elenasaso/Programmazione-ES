#include <iostream>

int main ()
    {
        int num;
        std::cin >> num;
        int r = num % 2;
        bool result = r == 0;
        
        
        
        std::cout << std::boolalpha << result << '\n';
    }