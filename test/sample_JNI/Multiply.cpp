#include "Multiply.h"

JNIEXPORT jint JNICALL Java_Multiply_multiply(JNIEnv *, jclass, jint base, jint rate)
{
    return base * rate;
}
