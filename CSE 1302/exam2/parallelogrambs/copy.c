/*
void setbase
void setheight
float area
float peri
void show
int same array
*/



#include <stdio.h>

struct parallelogram {
    float base;
    float height;
};

void setbase(struct parallelogram *p, float b) {
    p->base = b;
};
void setheight(struct parallelogram *p, float h) {
    p->height = h;
};

float area(struct parallelogram *p) {
    return p->base * p->height;
};
float perimeter(struct parallelogram *p) {
    return p->base * 2 + p->height * 2;
};

void show(struct parallelogram *p) {
    printf("Base: %f\n", p->base);
    printf("Height: %f\n", p->height);
    printf("Perimeter: %f\n", perimeter(p));
    printf("Area: %f\n", area(p));
};

int samearea(struct parallelogram *p1, struct parallelogram *p2) {
    if (area(p1) == area(p2)) {
        return 1;
    };
    return 0;
};

int main() {
    struct parallelogram p1, p2;

    setbase(&p1, 5);
    setbase(&p2, 5);

    setheight(&p1, 2.5);
    setheight(&p2, 18.9);

    show(&p1);
    show(&p2);

    if (samearea(&p1, &p2)) {
        printf("The two parallelograms have the same area. \n");
    } else {
        printf("The two parallelograms have different areas. \n");
    };
};