// The MIT License (MIT)
//
// Copyright (c) 2026 Andrey Gorbachev
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <chrono>

// Process-wide "as of" date initialized to today's date.
// Single-threaded usage assumed (no locks).

inline std::chrono::year_month_day g_as_of_date = [](){
    const auto today = std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now());
    return std::chrono::year_month_day{ std::chrono::sys_days{ today } };
}();

inline std::chrono::year_month_day GetAsOfDate() noexcept
{
    return g_as_of_date;
}

inline void SetAsOfDate(std::chrono::year_month_day d) noexcept
{
    g_as_of_date = d;
}
