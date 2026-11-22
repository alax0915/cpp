void register_customer(Customer& customer) {
    if (!(customerCount < MAX_CUSTOMERS)) {
        cout << "Customer list is full" <<endl;
        return;
    }

    cout << "Enter customer ID: ";
    getline(cin, customer.customerID);

    cout << "Enter customer name: ";
    getline(cin, customer.customerName);

    cout << "Enter phone number: ";
    getline(cin, customer.phoneNumber);

    customer.rentCount = 0;

    bool validCustomer = validate_customer(customer);
    if (!validCustomer) {
        cout << "Registration failed" <<endl;
        return;
    }

    int pos = customerCount;
    customers[pos] = customer;
    customerCount = pos + 1;

    cout << "Customer registered successfully" <<endl;
}
