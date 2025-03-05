#include <cmath>    
#include <cstdio>

const double pi = acos(-1);
const double pi_ = 2.0 * acos(0);
const double pi__ = 4.0 * atan(1);

int main() {
    // 모두 <cmath> 헤더 필요
    printf("%lf\n", M_PI);   // #1(GNU ok, MSVC는 #define _USE_MATH_DEFINES 선언 후 사용)
    printf("%lf\n", pi);     // #2
    printf("%lf\n", pi_);    // #3
    printf("%lf\n", pi__);    // #4
}
