#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int amount[100];
    int cat[100];     // store category number instead of text
    int count = 0;
    int total = 0;
    int choice;

    do {
        cout << "\n--- Expense Tracker ---\n";
        cout << "1. Add Expenses\n";
        cout << "2. Search Expenses by Category\n";
        cout << "3. Search Expense by Amount\n";
        cout << "4. Show Total Expenses\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        // ================= ADD EXPENSES =================
        if (choice == 1) {
            char addMoreCategory;

            do {
                int selectedCat;

                cout << "\nSelect Category:\n";
                cout << "1. Food\n";
                cout << "2. Transport\n";
                cout << "3. Study\n";
                cout << "4. Misc\n";
                cout << "Enter category number: ";
                cin >> selectedCat;

                char moreExpense;
                do {
                    cout << "Enter expense amount: ";
                    cin >> amount[count];

                    cat[count] = selectedCat;
                    total += amount[count];
                    count++;

                    cout << "Add more expenses in this category? (y/n): ";
                    cin >> moreExpense;

                } while (moreExpense == 'y' || moreExpense == 'Y');

                cout << "Add expenses in another category? (y/n): ";
                cin >> addMoreCategory;

            } while (addMoreCategory == 'y' || addMoreCategory == 'Y');
        }

        // ================= SEARCH BY CATEGORY =================
        else if (choice == 2) {
            int searchCat;
            bool found = false;

            cout << "\nSearch Category:\n";
            cout << "1. Food\n";
            cout << "2. Transport\n";
            cout << "3. Study\n";
            cout << "4. Misc\n";
            cout << "5. All Categories\n";
            cout << "Enter option: ";
            cin >> searchCat;

            cout << "\nExpenses:\n";
            for (int i = 0; i < count; i++) {
                if (searchCat == 5 || cat[i] == searchCat) {
                    cout << "Amount: " << amount[i] << endl;
                    found = true;
                }
            }

            if (!found)
                cout << "No expenses found.\n";
        }

        // ================= SEARCH BY AMOUNT =================
        else if (choice == 3) {
            int key;
            bool found = false;

            cout << "Enter amount to search: ";
            cin >> key;

            for (int i = 0; i < count; i++) {
                if (amount[i] == key) {
                    cout << "Found -> Amount: " << amount[i]
                         << " | Category: ";
                    
                    if (cat[i] == 1) cout << "Food";
                    else if (cat[i] == 2) cout << "Transport";
                    else if (cat[i] == 3) cout << "Study";
                    else cout << "Misc";

                    cout << endl;
                    found = true;
                }
            }

            if (!found)
                cout << "No expense found.\n";
        }

        // ================= TOTAL =================
        else if (choice == 4) {
            cout << "Total Expense: " << total << endl;
        }

    } while (choice != 5);

    cout << "\nProgram exited successfully.\n";
    return 0;
}
