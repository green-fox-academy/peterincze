#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct rectangular_cuboid {
    double a;
    double b;
    double c;
};

// TODO:
// Write a function called "GetSurface" that takes a RectangularCuboid
// and returns it's surface
double get_surface(struct rectangular_cuboid ex)
{
    double value = 2 * ex.a * ex.b + 2 * ex.a * ex.c + 2 * ex.b * ex.c;
    return value;
}

// TODO:
// Write a function called "GetVolume" that takes a RectangularCuboid
// and returns it's volume

double get_volume(struct rectangular_cuboid ex)
{
    double value = ex.a * ex.b * ex.c;
    return value;
}

int main()
{
    struct rectangular_cuboid example;
    example.a = 10;
    example.b = 20;
    example.c = 30;
    printf("%1f\n", get_surface(example));
    printf("%1f", get_volume(example));
    return 0;
}
