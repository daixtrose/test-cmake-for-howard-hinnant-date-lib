// See how we use the <library_name>/<header-file>.h pattern
#include "date/date.h" 
#include "date/iso_week.h"
// #include "date/islamic.h" has an issue with C++11
#include "date/date.h"
#include "date/ios.mm"
#include "date/tz.h"
#include "date/julian.h"
#include "date/chrono_io.h"
#include "date/ios.h"
#include "date/tz_private.h"


#include <type_traits>

static_assert(date::days{1} == std::chrono::hours{24}, "");

static_assert(date::weeks{1} == date::days{7}, "");

static_assert(date::months{12} == date::years{1}, "");
static_assert(date::days{30} < date::months{1} && date::months{1} < date::days{31}, "");
static_assert(date::weeks{4} < date::months{1} && date::months{1} < date::weeks{5}, "");

static_assert(date::years{400} == date::days{146097}, "");
static_assert(date::days{365} < date::years{1} && date::years{1} < date::days{366}, "");
static_assert(date::weeks{52} < date::years{1} && date::years{1} < date::weeks{53}, "");

static_assert(std::is_same<date::sys_days::duration, date::days>{}, "");

int
main()
{
}