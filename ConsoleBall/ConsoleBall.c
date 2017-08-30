#include <math.h>
#include <stdio.h>

int main() {
    float x, y;
    for (y = 1; y >= -1; y -= 0.05f, putchar('\n'))
        for (x = -1; x <= 1; x += 0.025f)
            putchar(x * x + y * y > 1 ? 'M' : "@@%#*+=;:. "[(int)(
                ((x + y + sqrt(1 - (x * x + y * y))) * 0.5773502692f + 1)
                * 5.0f + 0.5f)]);
}