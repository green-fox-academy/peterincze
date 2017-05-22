#include <stdio.h>
#include <stdlib.h>

#include <string.h>


/* Write a car register!
 * You should store the following data in a structure, called "car":
 *  - the manufacturer's name (which is shorter than 256 characters)
 *  - the price of the car (in euros, stored as a floating point number)
 *  - the year of manufacture
 *  - the type of the transmission (as a custom type, see below)
 */

enum Transmiss {manual, automatic, CVT, semi-automatic, dual-clutch};


 struct Car{
    char mf_name [256];
    float price;
    int manufacture_year;
    enum Transmiss transmission;
 };


 /* You should store the transmission type in an enumeration ("transmission"),
 * the valid types are:
 *  - manual
 *  - automatic
 *  - CVT
 *  - semi-automatic
 *  - dual-clutch
 */


 /* The "car"-s are stored in an array.
 *
 * Write the following functions:
 *  - get_older_cars_than(struct car* array, int age)
 *      - it returns the count of the older cars than "age"
 *  - get_transmission_count(struct car* array, enum transmission trnsm)
 *      - it returns the count of cars which has "trnsm" transmission
 */

 int get_older_cars_than(struct car* array, int age){
     int len = sizeof(array)/sizeof(type);
     int b=0;
     for(int i=0; i<len  ; i++){
        if(manufactured_year[i]-2017 > age){
            b++;
        }
     }

return b;
 }

int get_transmission_count(struct car* array, enum transmission trnsm){
    int len = sizeof(array)/sizeof(type);
    int c=0;
     for(int i=0; i< len  ; i++){
        if(trnsm == Transmiss transmission[i]){
            c++;
        }
     }

 return c;
 }


int main() {

    struct Car car1;

    car1.mf_name= Ford;
    car1.price = 2100;
    car1.manufacture_year=2000;
    Transmiss.automatic;


    return 0;
}
