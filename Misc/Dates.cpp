/**
 * Author: 
 * Date: 2025-11-14
 * License: CC0
 * Source: 
 * Description: Provides functions to convert between Gregorian calendar dates and Julian Day numbers.
 *  - `dateToInt(y, m, d)`: Converts a date (year, month, day) to its corresponding Julian Day number.
 *  - `intToDate(jd, y, m, d)`: Converts a Julian Day number back to a Gregorian date.
 *  - `intToDay(jd)`: Returns the day of the week (0 = monday, 5 = Saturday) from a Julian Day number.
 * Usage:
 *  int jd = dateToInt(2025, 11, 14);
 *  int y, m, d;
 *  intToDate(jd, y, m, d);
 *  int weekday = intToDay(jd);
 * Time: O(1) for all functions
 * Memory: O(1) for all functions
 * Status: 
 */
#pragma once

int intToDay(int jd) { return jd % 7; }
int dateToInt(int y, int m, int d) {
  return 1461 * (y + 4800 + (m - 14) / 12) / 4 +
    367 * (m - 2 - (m - 14) / 12 * 12) / 12 -
    3 * ((y + 4900 + (m - 14) / 12) / 100) / 4 +
    d - 32075; 
}
void intToDate(int jd, int &y, int &m, int &d) {
  int x, n, i, j;
  x = jd + 68569;
  n = 4 * x / 146097;
  x -= (146097 * n + 3) / 4;
  i = (4000 * (x + 1)) / 1461001;
  x -= 1461 * i / 4 - 31;
  j = 80 * x / 2447;
  d = x - 2447 * j / 80;
  x = j / 11;
  m = j + 2 - 12 * x;
  y = 100 * (n - 49) + i + x; 
}
