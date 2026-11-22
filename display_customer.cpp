void display_customer(const Customer& customer) {
    cout << "Customer ID   : " << customer.customerID <<endl
         << "Customer Name : " << customer.customerName <<endl
         << "Phone Number  : " << customer.phoneNumber <<endl
         << "Active Rents  : " << customer.rentCount <<endl;
}

void display_all_customers() {
    if (customerCount <= 0) {
        cout << "No customers registered yet." <<endl;
        return;
    }

    cout << "========= REGISTERED CUSTOMERS =========" <<endl;
    int pos = 0;
    while (pos < customerCount) {
        const Customer& entry = customers[pos];
        cout << (pos + 1) << ". "
             << "ID: " << entry.customerID
             << " | Name: " << entry.customerName
             << " | Phone: " << entry.phoneNumber <<endl;
        ++pos;
    }
}