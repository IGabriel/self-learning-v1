#pragma once

template<typename T>
T double_current_value(const T value)
{
    return value * 2;
}

template<typename T>
T power(T input, const int times)
{
    T rc = input;
    for(int index = 0; index < times - 1; index ++)
    {
        rc = rc * input;
    }
    return rc;
}