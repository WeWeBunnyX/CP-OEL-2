#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    int pyear;
    string genre;
};

void inputBookDetails(Book& book) {
    cout << "Enter the title of book: ";
    getline(cin, book.title);
    cout << "Enter the author of book: ";
    getline(cin, book.author);
    cout << "Enter the publication year of book: ";
    cin >> book.pyear;
    cin.ignore();

    while (true) {
        cout << "Enter the genre of book ( fiction (f) / non fiction (n) ): ";
        getline(cin, book.genre);
        if (book.genre == "f") {
            book.genre = "Fiction";
            break;
        } else if (book.genre == "n") {
            book.genre = "Non Fiction";
            break;
        } else {
            cout << "Invalid genre. Please enter 'f' for fiction or 'n' for non fiction." << endl;
        }
    }
}

void inputBooks(Book books[]) {
    for (int i = 0; i < 6; i++) {
        cout << "\nEnter details for Book " << i + 1 << endl;
        inputBookDetails(books[i]);
    }
}

void categorizeBooks(const Book books[], Book fictionBooks[], Book nonFictionBooks[], int& fCount, int& nCount) {
    fCount = 0;
    nCount = 0;

    for (int i = 0; i < 6; i++) {
        if (books[i].genre == "Fiction") {
            fictionBooks[fCount++] = books[i];
        } else if (books[i].genre == "Non Fiction") {
            nonFictionBooks[nCount++] = books[i];
        }
    }
}

Book EarliestBook(const Book books[], int size) {
    Book earliestBook = books[0];

    for (int i = 1; i < size; i++) {
        if (books[i].pyear < earliestBook.pyear) {
            earliestBook = books[i];
        }
    }

    return earliestBook;
}

void displayBooks(const Book books[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Book " << i + 1 << " details: " << endl;
        cout << "Title: " << books[i].title << endl;
        cout << "Author: " << books[i].author << endl;
        cout << "Publication Year: " << books[i].pyear << endl;
        cout << "Genre: " << books[i].genre << endl;
        cout << endl;
    }
}

int main() {
    Book books[6];
    Book fictionBooks[6];
    Book nonFictionBooks[6];

    inputBooks(books);

    int fictionCount, nonFictionCount;
    categorizeBooks(books, fictionBooks, nonFictionBooks, fictionCount, nonFictionCount);

    cout << "\nFiction Books: " << endl;
    displayBooks(fictionBooks, fictionCount);
    cout << endl;

    cout << "Non Fiction Books: " << endl;
    displayBooks(nonFictionBooks, nonFictionCount);
    cout << endl;

    Book earliestFictionBook = EarliestBook(fictionBooks, fictionCount);
    Book earliestNonFictionBook = EarliestBook(nonFictionBooks, nonFictionCount);

    cout << "Earliest Published Fiction Book: " << endl;
    displayBooks(&earliestFictionBook, 1);
    cout << endl;

    cout << "Earliest Published Non Fiction Book: " << endl;
    displayBooks(&earliestNonFictionBook, 1);

    return 0;
}
