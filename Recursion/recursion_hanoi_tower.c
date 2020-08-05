//
//  recursion_hanoi_tower.c
//  Recursion
//
//  Created by seunghwan Lee on 2020/08/06.
//  Copyright © 2020 LSH. All rights reserved.
//

#include <stdio.h>

void hanoi_tower(int n, char from, char tmp, char to) {
    if (n == 1) {
        printf("원판 1을 %c에서 %c로 이동 \n", from, to);
    } else {
        hanoi_tower(n-1, from, to, tmp);
        printf("원판 %d을 %c에서 %c로 이동 \n", n, from, to);
        hanoi_tower(n-1, tmp, from, to);
    }
}

int main(void) {
    hanoi_tower(10, 'A', 'B', 'C');
    return 0;
}
