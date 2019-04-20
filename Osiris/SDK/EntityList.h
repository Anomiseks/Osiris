#pragma once

#include "Utils.h"

class Entity;

class EntityList {
public:
    constexpr auto getEntity(int index) noexcept
    {
        return callVirtualFunction<Entity*, int>(this, 3)(this, index);
    }

    constexpr auto getEntityFromHandle(int handle) noexcept
    {
        return callVirtualFunction<Entity*, int>(this, 4)(this, handle);
    }

    constexpr auto getHighestEntityIndex() noexcept
    {
        return callVirtualFunction<int>(this, 6)(this);
    }
};
