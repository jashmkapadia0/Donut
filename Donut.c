#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    float A = 0, B = 0;
    float i, j;
    float z[1760];
    char b[1760];
    printf("\x1b[2J");  // clear screen

    for (;;) {
        memset(b, 32, 1760);
        memset(z, 0, sizeof(z));
        for (j = 0; j < 6.28; j += 0.07) {
            for (i = 0; i < 6.28; i += 0.02) {
                float c = sin(i), d = cos(j), e = sin(A), f = sin(j);
                float g = cos(A), h = d + 2;
                float D = 1 / (c * h * e + f * g + 5);
                float l = cos(i), m = cos(B), n = sin(B);
                float t = c * h * g - f * e;
                int x = 40 + 30 * D * (l * h * m - t * n);
                int y = 12 + 15 * D * (l * h * n + t * m);
                int o = x + 80 * y;
                int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);

                if (22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }

        printf("\x1b[H");  // move cursor to home
        for (int k = 0; k < 1760; k++) {
            putchar(k % 80 ? b[k] : '\n');
        }

        A += 0.04;
        B += 0.02;

#ifdef _WIN32
        Sleep(30);
#else
        usleep(30000);
#endif
    }

    return 0;
}
