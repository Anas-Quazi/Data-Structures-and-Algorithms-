// pointers in cpp

#include <iostream>
#include <vector>

int main()
{
    int a = 10;       //^ variable
    int *ptr = &a;    //^ pointer
    int **p2p = &ptr; //^ pointer to pointer

    std ::cout << "value of a : " << a << std ::endl;
    std ::cout << "address of a:  " << &a << std ::endl;
    std ::cout << "value of pointer : " << ptr << std ::endl;
    std ::cout << "value at ptr : " << *ptr << std ::endl;
    std ::cout << "address of pointer : " << &ptr << std ::endl;

    std ::cout << "pointer to pointer value : " << p2p << std ::endl;       //* same as address of ptr
    std ::cout << "address of pointer to pointer : " << &p2p << std ::endl; //* p^3

    // strings in cpp

    // character array
    char str[] = {'r', 'a', 'z', 'v', 'i'};

    std ::cout << "string: ";
    for (char i : str)
    {
        std ::cout << i;
    }

    std ::cout << str[2];

    return 0;
}
