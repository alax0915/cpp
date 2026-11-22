bool validate_customer(Customer& customer) {
    if (customer.customerID.empty()) {
        cout << "Error: ID cannot be empty" <<endl;
        return false;
    }

    int idx = 0;
    while (idx < customerCount) {
        if (customers[idx].customerID == customer.customerID) {
            cout << "Error: ID already exists" <<endl;
            return false;
        }
        ++idx;
    }

    if (customer.customerName.empty()) {
        cout << "Error: name cannot be empty" <<endl;
        return false;
    }

    for (size_t pos = 0; pos < customer.phoneNumber.length(); ++pos) {
        char ch = customer.phoneNumber[pos];
        bool isDigit = (ch >= '0' && ch <= '9');
        if (!isDigit) {
            cout << "Error: phone must contain digits only" <<endl;
            return false;
        }
    }

    return true;
}