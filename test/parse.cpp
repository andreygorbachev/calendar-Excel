// The MIT License (MIT)
//
// Copyright (c) 2023 Andrey Gorbachev
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

#include <parse.h>

#include <gtest/gtest.h>

#include <chrono>
#include <stdexcept>

using namespace std;
using namespace std::chrono;



TEST(parse, ToYearMonthDay)
{
	EXPECT_EQ(2023y / May / 1d, ToYearMonthDay("2023-05-01"));

	EXPECT_THROW(ToYearMonthDay("2023-05-"), invalid_argument);
	EXPECT_THROW(ToYearMonthDay("2023-05-01-01"), invalid_argument);
//	EXPECT_EQ(2023y / February / 30d, ToYearMonthDay("2023-02-30")); // not .ok() // should it be an exception?
}
