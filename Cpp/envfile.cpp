#include <iostream> 

// Các biến môi trường
// environment block

extern char** environ; 
int main()
{
    for(int i = 0; environ[i] != nullptr; i++)
    {
        std::cout << environ[i] << std::endl;
    }
    return 0 ; 
}