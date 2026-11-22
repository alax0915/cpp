bool validate_car(const Car& car) {
    bool validID = !car.carID.empty();
    if (!validID) {
        cout << "Car ID cannot be empty." <<endl;
        return false;
    }

    bool validModel = !car.carModel.empty();
    if (!validModel) {
        cout << "Car model cannot be empty." <<endl;
        return false;
    }

    bool validRate = (car.dailyValue > 0);
    if (!validRate) {
        cout << "Daily value must be greater than 0." <<endl;
        return false;
    }

    bool validPlate = !car.plateNo.empty();
    if (!validPlate) {
        cout << "Plate number cannot be empty." <<endl;
        return false;
    }

    return true;
}