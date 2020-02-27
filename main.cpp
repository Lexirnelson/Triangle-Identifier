/* CSCI 261 Assignment 2
 *Triangles
 *
 * Authors: Alexa Nelson
 *
 *this program takes 2 real number inputs and a randomly generated number
 * and determines if they can form a triangle if true, it also lets
 * the user know what type of triangle it is and what its area is
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    double sideOne;
    double sideTwo;
    double sideThree;
    double perimeter; //perimeter of triangle
    double s;// half the perimeter
    double area;
    const double TOLERANCE = 0.0001;
    double a;//used to determine the length of each for the hypotenuse
    double b;
    double c;
    bool triangle;
    double max;
    double min;
    double range;
    double randInt;

    a = 0;
    b = 0;
    c = 0;

    cout << "Enter 2 real values" << endl;
    cin >> sideOne >> sideTwo;

    max = sideOne + sideTwo;
    min = fabs(sideOne - sideTwo);
    range = max - min;
    randInt = rand() % (RAND_MAX-2) + 1;
    sideThree = (range * (randInt/RAND_MAX)) + min;

    cout << sideThree;

    if (sideOne < (sideTwo +sideThree)){    //makes sure the triangle exists
        if (sideTwo < (sideOne + sideThree)){
            if (sideThree < (sideTwo + sideOne)){
                triangle = true;
            }else {
                triangle = false;
            }
        }else{
            triangle = false;
        }
    }else {
        triangle = false;
    }
    if (!triangle){
        cout << "This is not a triangle";
        exit(0);
    }

    double sides[3] = {sideOne, sideTwo, sideThree}; //list of sides
    int i;// initializes the loop


    for (i = 0; i < 3; ++i){ //determines the largest side with a loop
        if (sides[i] > c){
            c = sides[i];
        }
    }


    if (c == sideOne) { //compares sides 2 and 3 if side 1 is max
        if (sideTwo - sideThree > TOLERANCE) {
            b = sideTwo;
            a = sideThree;
        } else if (sideThree - sideTwo > TOLERANCE) {
            b = sideThree;
            a = sideTwo;
        } else if (abs(sideThree - sideTwo) <= TOLERANCE){
            b = sideThree;
            a = sideTwo;
        }
    } else if (c == sideTwo) { //compares 1 and 3 if 2 is max
        if (sideOne - sideThree > TOLERANCE) {
            b = sideOne;
            a = sideThree;
        } else if (sideThree - sideOne > TOLERANCE) {
            b = sideThree;
            a = sideOne;
        }else if (abs(sideThree - sideOne) <= TOLERANCE){
            b = sideThree;
            a = sideOne;
        }
    } else if (c == sideThree) { //compares 1 and 2 if 3 is max
        if (sideOne - sideTwo > TOLERANCE) {
            b = sideOne;
            a = sideTwo;
        } else if (sideTwo - sideOne > TOLERANCE) {
            b = sideTwo;
            a = sideOne;
        }else if (abs(sideTwo - sideTwo) <= TOLERANCE){
            b = sideTwo;
            a = sideTwo;
        }
    }


    if (fabs(pow(a,2)+ pow(b,2) - pow(c,2)) <= TOLERANCE){
        cout << "This is a right triangle" << endl;
    } else if (fabs(pow(a,2)+ pow(b,2) > pow(c,2))){
        cout << "This is an acute triangle" << endl;
    } else if (fabs(pow(a,2)+ pow(b,2) < pow(c,2))){
        cout << "This is an obtuse triangle" << endl;
    }

    cout <<"sides: "<< a << " " << b << " " << c << endl;
    perimeter = a + b + c;
    cout << "perimeter: " << perimeter<< endl;
    s = perimeter / 2;
    area = sqrt(s*(s-a)*(s-b)*(s-c));
    cout << "Area: " << area << endl;


    return 0;
}
