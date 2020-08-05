//
//  recursion_power.c
//  Recursion
//
//  Created by seunghwan Lee on 2020/08/06.
//  Copyright © 2020 LSH. All rights reserved.
//

#include <stdio.h>

// 반복문을 이용한 거듭제곱 (느린 방법)

double slow_power(double x, int n) {
    double r = 1.0;
    for(int i=0; i <n; i++){
        r = r*x;
    }
    return r;
}

// 순환호출을 이용한 거듭제곱 (효율적인 방법)

double power(double x, int n) {
    if (n == 0) {
        return 1;
    } else if (n % 2 == 1) {
        return x*power(x*x, (n-1)/2);
    } else {
        return power(x*x, n/2);
    }
}

int main(void) {

    printf("slow_power result: %f \n", slow_power(5,10));
    printf("power result: %f \n", power(5,10));
    return 0;
}
