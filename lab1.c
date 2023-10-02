#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
float x1, x2, px, a, b, c;
float x, F;
int n, k;
float func() {
if ((x + c < 0) && (b == 0)) {
F = (a + b) / log(x - c);
} else if ((x + c > 0) && (b != 0)) {
F = (sin(a) - x + 3) / pow(c, 2);
} else {
F = (4 * x + 8) / pow(a, 2) * x;
};
printf("%i: x = %.3f \t F = %.3f \n", n, x, F);
x = x + px;
}
int main() {
printf("Input x1: ");
scanf("%f", & x1);
printf("Input x2: ");
scanf("%f", & x2);
printf("Input px: ");
scanf("%f", & px);
printf("Input a: ");
scanf("%f", & a);
printf("Input b: ");
scanf("%f", & b);
printf("Input c: ");
scanf("%f", & c);
x = x1;
n = 0;
printf("\n Results : \n");
printf("\n 1. While \n");
while (x < x2) {
n = n + 1;
func(x);
}
printf("\n 2. For \n");
x = x1;
n = 0;
for (n = 1; x < x2; n++) {
func(x);
}
printf("\n 3. Do while \n");
x = x1;
n = 1;
do {
func();
n = n + 1;
} while (x < x2);
printf("\n 4. Goto \n");
x = x1;
n = 1;
start:
func(x);
n = n + 1;
if (x < x2) {
goto start;
}
getch();
return 0;
}