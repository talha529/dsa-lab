#include <iostream>
#include <string>
using namespace std;

class Movie {
public:
    string title;
    Movie* next;

    Movie(string name) {
        title = name;
        next = NULL;
    }
};

class Watchlist {
private:
    Movie* head;

    string toLower(string str) {
        for (int i = 0; i < str.length(); i++) {
            str[i] = tolower(str[i]);
        }
        return str;
    }

    bool movieExists(string title) {
        Movie* temp = head;
        while (temp != NULL) {
            if (toLower(temp->title) == toLower(title)) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

public:
    Watchlist() {
        head = NULL;
    }

    void addMovie(string title) {
        if (movieExists(title)) {
            cout << "\n'" << title << "' is already in your watchlist!\n";
            return;
        }

        Movie* newMovie = new Movie(title);
        newMovie->next = head;
        head = newMovie;

        cout << "\n'" << title << "' has been added to the top of your watchlist.\n";
    }

    void showWatchlist() {
        if (head == NULL) {
            cout << "\nYour watchlist is currently empty.\n";
            return;
        }

        cout << "\nHere's your current watchlist (top = next to watch):\n";
        Movie* temp = head;
        int count = 1;
        while (temp != NULL) {
            cout << count << ". " << temp->title << endl;
            temp = temp->next;
            count++;
        }
    }

    void countMovies() {
        int count = 0;
        Movie* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        if (count == 0)
            cout << "\nNo movies in your list yet.\n";
        else if (count == 1)
            cout << "\nYou have 1 movie in your watchlist.\n";
        else
            cout << "\nYou have " << count << " movies in your watchlist.\n";
    }
};

int main() {
    Watchlist myWatchlist;
    int choice;
    string input;

    cout << "Welcome to your Personal Movie Watchlist!\n";

    do {
        cout << "\n-----------------------------\n";
        cout << "1. Add a Movie\n";
        cout << "2. View Watchlist\n";
        cout << "3. Count Movies\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";

        getline(cin, input);

        if (input.length() == 1 && isdigit(input[0])) {
            choice = input[0] - '0';
        } else {
            cout << "\nInvalid input. Please enter a number (1-4).\n";
            continue;
        }

        switch (choice) {
            case 1: {
                string movieName;
                cout << "\nEnter the movie title: ";
                getline(cin, movieName);
                myWatchlist.addMovie(movieName);
                break;
            }
            case 2:
                myWatchlist.showWatchlist();
                break;
            case 3:
                myWatchlist.countMovies();
                break;
            case 4:
                cout << "\nExiting... Enjoy your movies!\n";
                break;
            default:
                cout << "\nInvalid choice. Please enter a number between 1 and 4.\n";
        }

    } while (choice != 4);

    return 0;
}

