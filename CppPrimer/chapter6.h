#ifndef CHAPTER6
#define CHAPTER6

#include <stdexcept>

using std::runtime_error;

int fact(int v)
{
    if(v<0)
    {
        runtime_error err("Input cannot be a negative number");
        std::cout << err.what() << std::endl;
    }
    return v > 1 ? v*fact(v-1) : 1;
}

// 6.7

int func(void)
{
    static int i;
    return i++;
}

// 6.21
int new_func(int i, const int *j)
{
    return i > *j ? i : *j;
}

// 6.22
void swap(const int *p1, const int *p2)
{
    int temp = *p2;
    *p2 = *p1;
    *p1 = temp;
    return;
}

#endif // CHAPTER6

