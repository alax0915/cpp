#include "function.cpp"

int main() {
    string choice;

    while (true) {
        system("cls");
        system("color 9");
        cout << "========= CAR RENTAL AGENCY =========" <<endl
             << "1. Register Customer" <<endl
             << "2. Register Car" <<endl
             << "3. Create Rental" <<endl
             << "4. Return Car" <<endl
             << "5. Display customers" <<endl
             << "6. Display Cars" <<endl
             << "0. Exit" <<endl
             << "Enter choice: ";
        cin >> choice;

        system("cls");

        bool shouldExit = false;

        if (choice == "1") {
            Customer customer;
            register_customer(customer);
        } else if (choice == "2") {
            Car car;
            register_car(car);
        } else if (choice == "3") {
            Customer customer;
            create_rent(customer);
        } else if (choice == "4") {
            Rent rent;
            Car car;
            return_car(rent, car);
        } else if (choice == "5") {
            display_all_customers();
        } else if (choice == "6") {
            display_all_cars();
        } else if (choice == "0") {
            cout << "Goodbye" <<endl;
            shouldExit = true;
        } else {
            cout << "User entered non existing number from the menu" <<endl;
        }

        system("pause");
        if (shouldExit) break;
    }

    return 0;
}