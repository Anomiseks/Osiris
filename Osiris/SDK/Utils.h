#pragma once

#include <cstdint>

template<typename T, typename ...Args>
constexpr auto callVirtualFunction(void* classBase, int index) noexcept
{
    return reinterpret_cast<T(__thiscall*)(void*, Args...)>((*reinterpret_cast<uintptr_t**>(classBase))[index]);
}
