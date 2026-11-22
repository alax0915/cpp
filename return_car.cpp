void return_car(Rent& rent, Car& car) {
    string customerID, rentID, carID;

    cout << "Enter Customer ID: ";
    getline(cin, customerID);

    if (!customer_id_exists(customerID)) {
        cout << "Error: Customer ID does not exist." <<endl;
        return;
    }

    int custIndex = -1;
    int cIdx = 0;
    while (cIdx < customerCount) {
        if (customers[cIdx].customerID == customerID) {
            custIndex = cIdx;
            break;
        }
        ++cIdx;
    }

    Customer& activeCustomer = customers[custIndex];

    if (activeCustomer.rentCount <= 0) {
        cout << "Error: This customer has no active rentals." <<endl;
        return;
    }

    cout << "Enter Rent ID: ";
    getline(cin, rentID);

    int rentIndex = -1;
    for (int rIdx = 0; rIdx < activeCustomer.rentCount; ++rIdx) {
        bool sameRentID = (activeCustomer.rent[rIdx].rentID == rentID);
        bool isActive = (activeCustomer.rent[rIdx].rentStatus == "Active");
        if (sameRentID && isActive) {
            rentIndex = rIdx;
            break;
        }
    }

    if (rentIndex < 0) {
        cout << "Error: Active Rent ID not found for this customer." <<endl;
        return;
    }

    cout << "Enter Car ID to return: ";
    getline(cin, carID);

    string rentedCarID = activeCustomer.rent[rentIndex].rentedCar.carID;
    if (rentedCarID != carID) {
        cout << "Error: Car ID does not match the car associated with this rental." <<endl;
        return;
    }

    int carIndex = -1;
    for (int kIdx = 0; kIdx < carCount; ++kIdx) {
        if (cars[kIdx].carID == carID) {
            carIndex = kIdx;
            break;
        }
    }

    if (carIndex < 0) {
        cout << "Error: Car ID not found in system record." <<endl;
        return;
    }

    cars[carIndex].occupied = false;
    car = cars[carIndex];

    Rent& targetRent = activeCustomer.rent[rentIndex];
    targetRent.rentStatus = "Completed";
    rent = targetRent;

    int shiftPos = rentIndex;
    int lastPos = activeCustomer.rentCount - 1;
    while (shiftPos < lastPos) {
        activeCustomer.rent[shiftPos] = activeCustomer.rent[shiftPos + 1];
        ++shiftPos;
    }
    activeCustomer.rentCount = lastPos;

    cout << "Car successfully returned and status updated!" <<endl;
}
