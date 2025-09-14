#include <iostream>
#include <string>
using namespace std;

class LibraryItem {
private:
    string title, author, dueDate;

public:
    LibraryItem(string t, string a) : title(t), author(a), dueDate("") {}
    virtual ~LibraryItem() {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getDueDate() const { return dueDate; }
    void setDueDate(string d) { dueDate = d; }

    virtual void checkOut(string d) = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;
};

// Book
class Book : public LibraryItem {
public:
    Book(string t, string a) : LibraryItem(t, a) {}
    void checkOut(string d) override {
        setDueDate(d);
        cout << "Book checked out. Due date: " << getDueDate() << endl;
    }
    void returnItem() override {
        setDueDate("");
        cout << "Book returned.\n";
    }
    void displayDetails() const override {
        cout << "[Book] " << getTitle() << " by " << getAuthor();
        cout << (getDueDate() == "" ? " (Available)" : " (Due: " + getDueDate() + ")") << endl;
    }
};

// DVD
class DVD : public LibraryItem {
public:
    DVD(string t, string a) : LibraryItem(t, a) {}
    void checkOut(string d) override {
        setDueDate(d);
        cout << "DVD checked out. Due date: " << getDueDate() << endl;
    }
    void returnItem() override {
        setDueDate("");
        cout << "DVD returned.\n";
    }
    void displayDetails() const override {
        cout << "[DVD] " << getTitle() << " directed by " << getAuthor();
        cout << (getDueDate() == "" ? " (Available)" : " (Due: " + getDueDate() + ")") << endl;
    }
};

// Magazine
class Magazine : public LibraryItem {
public:
    Magazine(string t, string a) : LibraryItem(t, a) {}
    void checkOut(string d) override {
        setDueDate(d);
        cout << "Magazine checked out. Due date: " << getDueDate() << endl;
    }
    void returnItem() override {
        setDueDate("");
        cout << "Magazine returned.\n";
    }
    void displayDetails() const override {
        cout << "[Magazine] " << getTitle() << " edited by " << getAuthor();
        cout << (getDueDate() == "" ? " (Available)" : " (Due: " + getDueDate() + ")") << endl;
    }
};

// Main
int main() {
    const int MAX = 10;
    LibraryItem* items[MAX];
    int count = 0, choice;

    do {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add Book\n2. Add DVD\n3. Add Magazine\n";
        cout << "4. List Items\n5. Checkout Item\n6. Return Item\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string t, a;
            cout << "Title: "; getline(cin, t);
            cout << "Author: "; getline(cin, a);
            items[count++] = new Book(t, a);
        }
        else if (choice == 2) {
            string t, a;
            cout << "Title: "; getline(cin, t);
            cout << "Director: "; getline(cin, a);
            items[count++] = new DVD(t, a);
        }
        else if (choice == 3) {
            string t, a;
            cout << "Title: "; getline(cin, t);
            cout << "Editor: "; getline(cin, a);
            items[count++] = new Magazine(t, a);
        }
        else if (choice == 4) {
            for (int i = 0; i < count; i++) {
                cout << i << ". ";
                items[i]->displayDetails();
            }
        }
        else if (choice == 5) {
            int idx;
            string d;
            cout << "Enter index: "; cin >> idx; cin.ignore();
            cout << "Due date: "; getline(cin, d);
            if (idx >= 0 && idx < count) items[idx]->checkOut(d);
        }
        else if (choice == 6) {
            int idx;
            cout << "Enter index: "; cin >> idx;
            if (idx >= 0 && idx < count) items[idx]->returnItem();
        }
    } while (choice != 7);

// delete
    for (int i = 0; i < count; i++) delete items[i];
    return 0;
}
