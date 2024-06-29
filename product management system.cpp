#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void displayMenu();
void addProduct();
void searchProduct();
void deleteProduct();


struct Product {
    string name;
    string type;
    float price;
    int quantity;
};

int main() {
    int choice;

    do {
        displayMenu();
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                searchProduct();
                break;
            case 3:
                deleteProduct();
                break;
            case 4:
               
                cout << "Program Exit." << endl;
                return 0;
            default:
                cout << "Choice Invalid." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    cout << "\n Product Management System " << endl;
    cout << "1. Add Product" << endl;
    cout << "2. Search for Product" << endl;
    cout << "3. Delete Product" << endl;
    cout << "4. Exit" << endl;
}

void addProduct() {
    ofstream file;
    file.open("product.txt", ios::app);  

    Product newProduct;

    cout << "\n Add a Product " << endl;
    cout << "Name: ";
    cin.ignore();
    getline(cin, newProduct.title);

    cout << "Type: ";
    getline(cin, newType.author);

    cout << "Price: ";
    cin >> newBook.price;

    cout << "Quantity: ";
    cin >> newBook.quantity;

    file << newBook.title << "," << newBook.author << "," << newBook.price << "," << newBook.quantity << endl;

    file.close();
    cout << "Book added successfully!" << endl;
}

void searchBook() {
    ifstream file;
    file.open("books.txt");

    string keyword;
    cout << "\n Search for a Book " << endl;
    cout << "Enter keyword: ";
    cin.ignore();
    getline(cin, keyword);

    string line;
    bool found = false;

    while (getline(file, line)) {
        size_t foundIndex = line.find(keyword);
        if (foundIndex != string::npos) {
            cout << line << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No books found." << endl;
    }

    file.close();
}

void deleteBook() {
    ifstream inFile;
    inFile.open("books.txt");

    ofstream outFile;
    outFile.open("temp.txt");

    string keyword;
    cout << "\n Delete a Book " << endl;
    cout << "Enter title of the book to delete: ";
    cin.ignore();
    getline(cin, keyword);

    string line;
    bool found = false;

    while (getline(inFile, line)) {
        size_t foundIndex = line.find(keyword);
        if (foundIndex == string::npos) {
            outFile << line << endl;
        } else {
            found = true;
        }
    }

    inFile.close();
    outFile.close();

   
    remove("books.txt");
    rename("temp.txt", "books.txt");

    if (found) {
        cout << "Book deleted successfully!" << endl;
    } else {
        cout << "No books found with the given title." << endl;
    }
}

