void register_car(Car& car) {
    if (!(carCount < MAX_CARS)) {
        cout << "Car list is full." <<endl;
        return;
    }

    cout << "Enter car ID: ";
    getline(cin, car.carID);

    cout << "Enter car model: ";
    getline(cin, car.carModel);

    cout << "Enter daily value: ";
    cin >> car.dailyValue;
    cin.ignore();

    cout << "Enter plate number: ";
    getline(cin, car.plateNo);

    car.occupied = false;

    bool valid = validate_car(car);
    if (!valid) {
        cout << "Car registration failed." <<endl;
        return;
    }

    int index = carCount;
    cars[index] = car;
    carCount = index + 1;
    cout << "Car registered successfully." <<endl;
}