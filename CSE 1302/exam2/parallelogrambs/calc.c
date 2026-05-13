#include <stdio.h>

// Structure definition
struct parallelogram {
    float base;
    float height;
};

// Set base
void setbase(struct parallelogram *p, float b) {
    p->base = b;
}

// Set height
void setheight(struct parallelogram *p, float h) {
    p->height = h;
}

// Calculate area
float area(struct parallelogram *p) {
    return p->base * p->height;
}

// Calculate perimeter
float perimeter(struct parallelogram *p) {
    return 2 * p->base + 2 * p->height;
}

// Display details
void show(struct parallelogram *p) {
    printf("Base: %.2f\n", p->base);
    printf("Height: %.2f\n", p->height);
    printf("Area: %.2f\n", area(p));
    printf("Perimeter: %.2f\n\n", perimeter(p));
}

// Compare areas
int samearea(struct parallelogram *p1, struct parallelogram *p2) {
    if (area(p1) == area(p2)) {
        return 1;
    }
    return 0;
}

int main() {
    struct parallelogram p1, p2;

    // Set initial values
    setbase(&p1, 5);
    setheight(&p1, 2.5);

    setbase(&p2, 5);
    setheight(&p2, 18.9);

    // Show both
    printf("First parallelogram:\n");
    show(&p1);

    printf("Second parallelogram:\n");
    show(&p2);

    // Compare areas
    if (samearea(&p1, &p2)) {
        printf("They have the same area.\n\n");
    } else {
        printf("They have different areas.\n\n");
    }

    // Update first parallelogram
    setbase(&p1, 15);
    setheight(&p1, 6.3);

    // Show again
    printf("After updating first parallelogram:\n");

    printf("First parallelogram:\n");
    show(&p1);

    printf("Second parallelogram:\n");
    show(&p2);

    if (samearea(&p1, &p2)) {
        printf("They have the same area.\n\n");
    } else {
        printf("They have different areas.\n\n");
    }

    return 0;
}