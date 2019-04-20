#pragma once

#include "Utils.h"

class Surface final {
public:
    constexpr void setDrawColor(int r, int g, int b, int a) noexcept
    {
        callVirtualFunction<void, int, int, int, int>(this, 15)(this, r, g, b, a);
    }

    constexpr void setDrawColor(float color[3], int a) noexcept
    {
        callVirtualFunction<void, int, int, int, int>(this, 15)(this, static_cast<int>(color[0]), static_cast<int>(color[1]), static_cast<int>(color[2]), a);
    }

    constexpr void drawFilledRect(int x0, int y0, int x1, int y1) noexcept
    {
        callVirtualFunction<void, int, int, int, int>(this, 16)(this, x0, y0, x1, y1);
    }

    constexpr void drawLine(int x0, int y0, int x1, int y1) noexcept
    {
        callVirtualFunction<void, int, int, int, int>(this, 19)(this, x0, y0, x1, y1);
    }

    constexpr void setTextFont(unsigned font) noexcept
    {
        callVirtualFunction<void, unsigned>(this, 23)(this, font);
    }

    constexpr void setTextColor(int r, int g, int b, int a) noexcept
    {
        callVirtualFunction<void, int, int, int, int>(this, 25)(this, r, g, b, a);
    }

    constexpr void setTextPosition(int x, int y) noexcept
    {
        callVirtualFunction<void, int, int>(this, 26)(this, x, y);
    }

    constexpr void printText(const std::wstring_view text, int drawType = 0) noexcept
    {
        callVirtualFunction<void, const wchar_t*, int, int>(this, 28)(this, text.data(), text.length(), drawType);
    }

    auto getScreenSize() noexcept
    {
        int width, height;
        callVirtualFunction<void, int&, int&>(this, 44)(this, width, height);
        return std::make_pair(width, height);
    }

    constexpr unsigned createFont() noexcept
    {
        return callVirtualFunction<unsigned>(this, 71)(this);
    }

    constexpr bool setFontGlyphSet(unsigned font, const char* fontName, int tall, int weight, int blur, int scanlines, int flags, int rangeMin = 0, int rangeMax = 0) noexcept
    {
        return callVirtualFunction<bool, unsigned, const char*, int, int, int, int, int, int, int>(this, 72)(this, font, fontName, tall, weight, blur, scanlines, flags, rangeMin, rangeMax);
    }
};
