#include<bits/stdc++.h>
using namespace std;
struct Bill {
    double total;
    string paymentMethod;
};

bool login() {
    string username, password;
    map<string, string> credentials = {
        {"admin", "password"},
        {"vivek", "ares07"}
    };
    cout << "\n----------------------------------------"<<endl;
    cout << "WELCOME TO SUPERMARKET BILLING SYSTEM!"<<endl;
    cout << "1. Login\n2. Exit\n";
    cout << "----------------------------------------\n"<<endl;
    int choice;
    cin >> choice;

    if (choice == 2) {
        cout << "Exiting the program." << endl;
        exit(0); 
    }

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (credentials.find(username) != credentials.end() && credentials[username] == password) {
        cout << "Login successful!" << endl;
        return true;
    } else {
        cout << "Invalid username or password. Please try again." << endl;
        return false;
    }
}

double calculateDiscount(double total) {
    double discount = 0.0;

    if (total < 1000) {
        discount = 0.0; 
    } else if (total > 2000) {
        discount = total * 0.05; 
    } else if (total > 3000) {
        discount = total * 0.10; 
    } else if (total > 6000) {
        discount = total * 0.15; 
    } else if (total > 12000) {
        discount = total * 0.20;
    }

    return discount;
}

void billingSystem(vector<Bill>& previousBills, double& totalSales) {
    cout << "\n----------------------------------------\n"<<endl;
    cout << "\nWelcome to the Supermarket Billing System!\n" << endl;
    cout << "\n----------------------------------------\n"<<endl;

    double total = 0.0;
    string item;
    double price;
    int n;

    cout << "Enter the number of items you want to add: ";
    cin >> n;
    cin.ignore(); 
    for (int i = 0; i < n; ++i) {
        cout << "Enter item name: ";
        getline(cin, item); 
        cout << "Enter price for " << item << ": ";
        cin >> price;
        cin.ignore(); 
        total += price; 
    }

    string paymentMethod;
    cout << "\nEnter payment method (credit card/UPI/cash): \n";
    getline(cin, paymentMethod);

    double discount = calculateDiscount(total);
    
    if (paymentMethod == "credit card") {
        discount += total * 0.05; 
    } else if (paymentMethod == "UPI") {
        discount += total * 0.02; 
    }
    double finalTotal = total - discount;

    previousBills.push_back({finalTotal, paymentMethod});
    totalSales += finalTotal; 
    cout << "\n--------------------------------\n"<<endl;
    cout << "\nSUPERMARKET BILL\n"<<endl;
    cout << "Total before discount: RS." << total << endl;
    cout << "Discount applied: RS." << discount << endl;
    cout << "Total after discount: RS." << finalTotal << endl;
    cout << "Payment method used: " << paymentMethod << endl;
    cout << "\nThank you for shopping with us!\n" << endl;
    cout << "\n--------------------------------\n"<<endl;
}

void showPreviousBills(const vector<Bill>& previousBills) {
    if (previousBills.empty()) {
        cout << "No previous bills available." << endl;
        return;
    }

    cout << "Previous Bills:" << endl;
    for (const auto& bill : previousBills) {
        cout << "Total: RS." << bill.total << ", Payment Method: " << bill.paymentMethod << endl;
    }
}

void showTotalSales(double totalSales) {
    cout << "Total sales for the day: RS." << totalSales << endl;
}
int main() {
    vector<Bill> previousBills; 
    double totalSales = 0.0; 
    while (!login()) {
    }

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Items\n";
        cout << "2. Show Previous Bills\n";
        cout << "3. Show Total Sales for Today\n"; 
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                billingSystem(previousBills, totalSales); 
                break;
            case 2:
                showPreviousBills(previousBills); 
                break;
            case 3:
                showTotalSales(totalSales); 
                break;
            case 4:
                cout << "\nExiting the program. Thank you for using the Supermarket Billing System!\n" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4); 
    return 0; 
}