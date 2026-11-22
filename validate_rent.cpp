bool customer_id_exists(const string& custID) {
    int pos = 0;
    while (pos < customerCount) {
        if (customers[pos].customerID == custID) {
            return true;
        }
        pos++;
    }
    return false;
}

bool validate_rent(Rent& rent) {
    if (rent.rentID.empty()) {
        cout << "Rent ID cannot be empty." <<endl;
        return false;
    }

    for (int cIdx = 0; cIdx < customerCount; ++cIdx) {
        const Customer& currentCustomer = customers[cIdx];
        int rIdx = 0;
        while (rIdx < currentCustomer.rentCount) {
            if (currentCustomer.rent[rIdx].rentID == rent.rentID) {
                cout << "Rent ID already exists." << '\n';
                return false;
            }
            ++rIdx;
        }
    }

    return true;
}