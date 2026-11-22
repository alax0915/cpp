void create_rent(Customer& customer) {
    Rent newRent;
    string targetCustomerID, selectedCarID;

    cout << "Enter new rent ID: ";
    getline(cin, newRent.rentID);

    cout << "Enter customer ID: ";
    getline(cin, targetCustomerID);

    if (!customer_id_exists(targetCustomerID)) {
        cout << "Customer ID does not exist." << endl;
        return;
    }

    if (!validate_rent(newRent)) {
        cout << "Rental creation failed." << endl;
        return;
    }

    int custIndex = -1;
    int i = 0;
    while (i < customerCount) {
        if (customers[i].customerID == targetCustomerID) {
            custIndex = i;
            break;
        }
        i++;
    }

    if (customers[custIndex].rentCount > 2) {
        cout << "dear Customer you can only rent  3 active rentals." << endl;
        return;
    }

    display_all_cars();

    cout << "Enter Car ID from the available list ids above: ";
    getline(cin, selectedCarID);

    int carIndex = -1;
    for (int idx = 0; idx < carCount; ++idx) {
        bool matchesID = (cars[idx].carID == selectedCarID);
        bool isFree = !cars[idx].occupied;
        if (matchesID && isFree) {
            carIndex = idx;
            break;
        }
    }

    if (carIndex < 0) {
        cout << "incorrect selection can not continue." << endl;
        return;
    }

    Car& chosenCar = cars[carIndex];
    chosenCar.occupied = true;

    newRent.rentedCar = chosenCar;
    newRent.rentedCar.occupied = true;
    newRent.rentStatus = "Active";

    Customer& activeCustomer = customers[custIndex];
    int slot = activeCustomer.rentCount;
    activeCustomer.rent[slot] = newRent;
    activeCustomer.rentCount = slot + 1;
    customer = activeCustomer;

    cout << "Rental created successfully!" << endl;
}