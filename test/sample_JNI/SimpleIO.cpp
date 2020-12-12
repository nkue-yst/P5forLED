#include "SimpleIO.h"
#include <iostream>
#include <string>

JNIEXPORT void JNICALL Java_SimpleIO_run(JNIEnv *, jclass)
{
    std::string str;
    std::cin >> str;
    std::cout << str << std::endl;
}
