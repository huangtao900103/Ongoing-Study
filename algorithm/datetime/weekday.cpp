// 2018-03-29T20:18+08:00
#include <cassert>
#include <iostream>


const int DAYS_IN_MONTH[] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int DAYS_BEFORE_MONTH[] = { -1, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };


inline bool IsLeapYear(int year)
{
    assert(year > 0);
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


inline int DaysBeforeYear(int year)
{
    assert(year > 0);
    year -= 1;
    return year * 365 + (year / 4 - year / 100) + year / 400;
}


inline int DaysInMonth(int year, int month)
{
    assert(year > 0);
    assert(month >= 1 && month <= 12);

    if (month == 2 && IsLeapYear(year))
        return 29;

    return DAYS_IN_MONTH[month];
}


inline int DaysBeforeMonth(int year, int month)
{
    assert(year > 0);
    assert(month >= 1 && month <= 12);

    return DAYS_BEFORE_MONTH[month] + (month > 2 && IsLeapYear(year));
}


inline int Ymd2Ordinal(int year, int month, int day)
{
    assert(year > 0);
    assert(month >= 1 && month <= 12);
    assert(day >= 1 && day <= DaysInMonth(year, month));
    return DaysBeforeYear(year) + DaysBeforeMonth(year, month) + day;
}


int main()
{
    assert(Ymd2Ordinal(2018, 3, 27) - Ymd2Ordinal(2000, 1, 1) == 6660);
    std::cout << Ymd2Ordinal(2016, 3, 1) - Ymd2Ordinal(2016, 2, 29) << std::endl;
    return 0;
}

// References:
// https://www.zhihu.com/question/270085921
