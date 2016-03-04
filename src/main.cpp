#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include "oolua.h"

int getRanValue()
{
    return rand()%10+1;
}

void luaPrint(char *msg)
{
    std::cout << msg;
}
int main(int argc, char *argv[])
{
    srand(time(NULL));


    return 0;
}
