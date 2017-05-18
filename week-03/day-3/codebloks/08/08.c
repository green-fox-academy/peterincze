#include <stdio.h>

struct RectangularCuboid {
    double a;
    double b;
    double c;
};


// TODO:
// Write a function called "GetSurface" that takes a RectangularCuboid
// and returns it's surface

double GetSurface(struct RectangularCuboid param) {
    double result_sf=2*(param.a*param.b+param.a*param.c+param.b*param.c);
    return result_sf;
}

// TODO:
// Write a function called "GetVolume" that takes a RectangularCuboid
// and returns it's volume

double GetVolume(struct RectangularCuboid param) {
    double result_v=param.a*param.b*param.c;
    return result_v;
}

int main() {
    struct RectangularCuboid parameters;
        parameters.a=10;
        parameters.b=20;
        parameters.c=30;

    printf("%1f\n",parameters.b);

    double surface= GetSurface(parameters);
    double volume= GetVolume(parameters);

    printf("%1f\n", surface);
    printf("%1f\n", volume);

    return 0;
}
