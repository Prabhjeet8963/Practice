#include <iostream>
#include <cstring>
using namespace std;

const int MAX_CATEGORIES = 10;
const int MAX_PRODUCTS = 50;
const int MAX_TRANSACTIONS = 100;
const int MAX_NAME_LENGTH = 50;

class Category {
public:
    char name[MAX_NAME_LENGTH];

    Category() { name[0] = '\0'; }

    Category(const char* n) {
        strncpy(name, n, MAX_NAME_LENGTH);
        name[MAX_NAME_LENGTH - 1] = '\0';
    }
};

class Product {
public:
    char name[MAX_NAME_LENGTH];
    double price;
    char category[MAX_NAME_LENGTH];
    int stock;

    Product() : price(0.0), stock(0) {
        name[0] = category[0] = '\0';
    }

    Product(const char* n, double p, const char* c, int s)
        : price(p), stock(s) {
        strncpy(name, n, MAX_NAME_LENGTH);
        name[MAX_NAME_LENGTH - 1] = '\0';
        strncpy(category, c, MAX_NAME_LENGTH);
        category[MAX_NAME_LENGTH - 1] = '\0';
    }
};

class Transaction {
public:
    char productName[MAX_NAME_LENGTH];
    int quantity;
    double totalPrice;

    Transaction() : quantity(0), totalPrice(0.0) {
        productName[0] = '\0';
    }

    Transaction(const char* p, int q, double t)
        : quantity(q), totalPrice(t) {
        strncpy(productName, p, MAX_NAME_LENGTH);
        productName[MAX_NAME_LENGTH - 1] = '\0';
    }
};

class InventoryManagementSystem {
private:
    Category categories[MAX_CATEGORIES];
    Product products[MAX_PRODUCTS];
    Transaction transactions[MAX_TRANSACTIONS];
    int categoryCount = 0;
    int productCount = 0;
    int transactionCount = 0;

public:
    void addCategory(const char* name) {
        if (categoryCount < MAX_CATEGORIES)
            categories[categoryCount++] = Category(name);
        else
            cout << "Maximum number of categories reached!" << endl;
    }

    void addProduct(const char* name, double price, const char* category, int stock) {
        if (productCount < MAX_PRODUCTS)
            products[productCount++] = Product(name, price, category, stock);
        else
            cout << "Maximum number of products reached!" << endl;
    }

    void displayCategories() const {
        for (int i = 0; i < categoryCount; ++i)
            cout << "Category: " << categories[i].name << endl;
    }

    void displayProducts() const {
        for (int i = 0; i < productCount; ++i)
            cout << "Product: " << products[i].name
                 << ", Price: " << products[i].price
                 << ", Category: " << products[i].category
                 << ", Stock: " << products[i].stock << endl;
    }

    void restockProduct(const char* name, int quantity) {
        for (int i = 0; i < productCount; ++i) {
            if (strcmp(products[i].name, name) == 0) {
                products[i].stock += quantity;
                cout << "Restocked " << name << " by " << quantity
                     << " units. New stock: " << products[i].stock << endl;
                return;
            }
        }
        cout << "Product not found!" << endl;
    }

    void processSale(const char* name, int quantity) {
        for (int i = 0; i < productCount; ++i) {
            if (strcmp(products[i].name, name) == 0) {
                if (products[i].stock >= quantity) {
                    products[i].stock -= quantity;
                    double totalPrice = products[i].price * quantity;
                    if (transactionCount < MAX_TRANSACTIONS)
                        transactions[transactionCount++] = Transaction(name, quantity, totalPrice);
                    cout << "Processed sale of " << quantity << " units of " << name
                         << ". Total price: " << totalPrice << endl;
                } else {
                    cout << "Insufficient stock!" << endl;
                }
                return;
            }
        }
        cout << "Product not found!" << endl;
    }

    void displayTransactions() const {
        for (int i = 0; i < transactionCount; ++i)
            cout << "Product: " << transactions[i].productName
                 << ", Quantity sold: " << transactions[i].quantity
                 << ", Total price: " << transactions[i].totalPrice << endl;
    }
};

int main() {
    InventoryManagementSystem ims;

    int numCategories;
    cout << "Enter the number of categories: ";
    cin >> numCategories;

    for (int i = 0; i < numCategories; ++i) {
        char categoryName[MAX_NAME_LENGTH];
        cout << "Enter category name: ";
        cin >> categoryName;
        ims.addCategory(categoryName);
    }

    int numProducts;
    cout << "Enter the number of products: ";
    cin >> numProducts;

    for (int i = 0; i < numProducts; ++i) {
        char productName[MAX_NAME_LENGTH], category[MAX_NAME_LENGTH];
        double price;
        int stock;

        cout << "Enter product name: ";
        cin >> productName;
        cout << "Enter price: ";
        cin >> price;
        cout << "Enter category: ";
        cin >> category;
        cout << "Enter stock: ";
        cin >> stock;

        ims.addProduct(productName, price, category, stock);
    }

    ims.displayCategories();
    ims.displayProducts();

    char restockProductName[MAX_NAME_LENGTH];
    int restockQuantity;
    cout << "Enter product name to restock: ";
    cin >> restockProductName;
    cout << "Enter quantity to restock: ";
    cin >> restockQuantity;
    ims.restockProduct(restockProductName, restockQuantity);

    char saleProductName[MAX_NAME_LENGTH];
    int saleQuantity;
    cout << "Enter product name to sell: ";
    cin >> saleProductName;
    cout << "Enter quantity to sell: ";
    cin >> saleQuantity;
    ims.processSale(saleProductName, saleQuantity);

    ims.displayTransactions();

    return 0;
}