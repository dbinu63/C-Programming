#include <stdio.h>
#include <locale.h>
#include <wchar.h>

#define SINGLE_H  0x2500   // ─
#define SINGLE_V  0x2502   // │
#define SINGLE_TL 0x250C   // ┌
#define SINGLE_TR 0x2510   // ┐
#define SINGLE_BL 0x2514   // └
#define SINGLE_BR 0x2518   // ┘

#define DOUBLE_H  0x2550   // ═
#define DOUBLE_V  0x2551   // ║
#define DOUBLE_TL 0x2554   // ╔
#define DOUBLE_TR 0x2557   // ╗
#define DOUBLE_BL 0x255A   // ╚
#define DOUBLE_BR 0x255D   // ╝

void print_box(wchar_t h, wchar_t v, wchar_t tl, wchar_t tr, wchar_t bl, wchar_t br) {
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 10; col++) {
            if (row == 0 && col == 0)
                wprintf(L"%lc", tl);

            else if (row == 0 && col == 9)
                wprintf(L"%lc", tr);

            else if (row == 4 && col == 0)
                wprintf(L"%lc", bl);

            else if (row == 4 && col == 9)
                wprintf(L"%lc", br);
            else if (row == 0 || row == 4)
                wprintf(L"%lc", h);
            else if (col == 0 || col == 9)
                wprintf(L"%lc", v);
            else
                wprintf(L" ");
        }
        wprintf(L"\n");
    }
}



int main() {

    setlocale(LC_ALL, "");

    for (wchar_t i = 0x2500; i <= 0x257F; i++) {
        wprintf(L"%04X : %lc\n", i, i);
    }

    printf("\nSingle Line Box:\n");
    print_box(
        SINGLE_H,
        SINGLE_V,
        SINGLE_TL,
        SINGLE_TR,
        SINGLE_BL,
        SINGLE_BR
    );


    printf("\nDouble Line Box:\n");
    print_box(
        DOUBLE_H,
        DOUBLE_V,
        DOUBLE_TL,
        DOUBLE_TR,
        DOUBLE_BL,
        DOUBLE_BR
    );

    return 0;
}