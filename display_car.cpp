void display_car(const Car& car) {
    if (car.occupied) return;

    cout << "Car ID       : " << car.carID <<endl
         << "Car Model    : " << car.carModel <<endl
         << "Daily Value  : " << car.dailyValue <<endl
         << "Plate Number : " << car.plateNo <<endl;
}

void display_all_cars() {
    if (carCount <= 0) {
        cout << "No cars registered yet." <<endl;
        return;
    }

    cout << "========= AVAILABLE CARS =========" <<endl;
    int availableCount = 0;

    for (int idx = 0; idx < carCount; ++idx) {
        const Car& item = cars[idx];
        if (item.occupied) continue;

        cout << (++availableCount) << ". "
             << "ID: " << item.carID
             << " | Model: " << item.carModel
             << " | Daily Value: " << item.dailyValue
             << " | Plate No: " << item.plateNo <<endl;
    }

    if (!availableCount) {
        cout << "No available cars right now (all cars are occupied)." <<endl;
    }
}