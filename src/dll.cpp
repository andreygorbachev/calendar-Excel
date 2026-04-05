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

#include "parse.h"
#include "as_of_date.h"
#include "error_codes.h"

#include <period.h>

#include <static_data.h>

using namespace gregorian::util;
using namespace gregorian::static_data;



// Dates are passed in as strings in ISO 8601 format
// Functions return 0 if successful, otherwise -1.
// Output is via the last parameter (e.g. result) passed by pointer.



extern "C" __declspec(dllexport) int SetAsOfDate(const char* date) noexcept
{
	try
	{
		SetAsOfDate(ToYearMonthDay(date));
	}
	catch (...)
	{
		return Failure;
	}

	return Success;
}


extern "C" __declspec(dllexport) int IsBusinessDay(
	const char* date,
	const char* calendar,
	int* result
) noexcept
{
	try
	{
		const auto dt = ToYearMonthDay(date);
		const auto& cal = locate_calendar(calendar, GetAsOfDate());

		*result = ToInt(cal.is_business_day(dt)); // we assume that bool is not a good idea in DLL
	}
	catch (...)
	{
		return Failure;
	}

	return Success;
}


extern "C" __declspec(dllexport) int CountBusinessDays(
	const char* from,
	const char* until,
	const char* calendar,
	int* result
) noexcept
{
	try
	{
		const auto period = days_period{ ToYearMonthDay(from), ToYearMonthDay(until) };
		const auto& cal = locate_calendar(calendar, GetAsOfDate());

		*result = ToInt(cal.count_business_days(period)); // we assume that unsigned is not a good idea in DLL
	}
	catch (...)
	{
		return Failure;
	}

	return Success;
}
