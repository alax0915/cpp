#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
#include "car.cpp"
#include "rent.cpp"
#include "customer.cpp"
const int MAX_CUSTOMERS = 1000;
Customer customers[MAX_CUSTOMERS];
int customerCount = 0;
const int MAX_CARS = 1000;
Car cars[MAX_CARS];
int carCount = 0;
#include "validate_car.cpp"
#include "validate_customer.cpp"
#include "validate_rent.cpp"
#include "register_car.cpp"
#include "register_customer.cpp"
#include "return_car.cpp"
#include "display_car.cpp"
#include "display_customer.cpp"
#include "create_rental.cpp"