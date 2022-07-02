

using namespace std;

string const MENU {
    "Main menu.\n"
    "Options:\n"
    "* 'a' - add movie\n"
    "* 's' - search for movie\n"
    "* 'd' - delete movie\n"
    "* 'l' - list whole collection\n"
    "* 'q' - quit the menu"
};

string get_title() {
    string title;
    cout << "Enter title of movie to search for: ";
    cin >> title;
    capitalize(title);
    return title;
}

map<string,string> get_movie() {
    map<string,string> new_movie { {"title", ""}, {"author", ""}, {"year", ""} };

    cout << "Enter movie name: ";
    cin >> new_movie["title"];
    capitalize(new_movie["title"]);

    cout << "\nEnter movie author: ";
    cin >> new_movie["author"];
    capitalize(new_movie["author"]);

    cout << "\nEnter movie release year: ";
    cin >> new_movie["year"];

    cout << endl;
    return new_movie;
}

void menu(MovieCollection *collection) {
    string linebreak = "---------------";
    cout << "Hello!" << endl;
    cout << linebreak << endl;
    char user_choice;

    while (true) {
        cout << MENU << endl;
        cout << "Enter choice: " << endl;

        cin >> user_choice;

        if (user_choice == 'q') break;
        else if (user_choice == 'l') {  // print collection
            collection->print_collection();
        }
        else if (user_choice == 'a') {  // add movie
            map<string,string> new_movie = get_movie();

            if (collection->search_movie(new_movie["title"])) {
                cout << "Movie with that title is already in collection." << endl;
            }
            else {
                collection->add_movie(new_movie);
                cout << "Movie added." << endl;
            }
            cout << linebreak << endl;
        }
        else if (user_choice == 's') {  // search for movies
            string title = get_title();
            if (collection->search_movie(title)) {
                cout << "Movie '" << title << "' is in your collection. Its additional info: " << endl;
                map<string,string> movie = collection->return_movie(title);
                cout << "Author: " << movie["author"] << endl;
                cout << "Year: " << movie["year"] << endl;
            }
            else {
                cout << "Movie '" << title << "' is not found in your collection." << endl;
            }
            cout << linebreak << endl;
        }
        else if (user_choice == 'd') {  // delete movie
            string title = get_title();
            if (collection->search_movie(title)) {
                collection->delete_movie(title);
                cout << "Movie '" << title << "' is deleted from your collection." << endl;
            }
            else {
                cout << "Movie '" << title << "' is not found in collection." << endl;
            }
            cout << linebreak << endl;
        }
    }

    cout << linebreak << endl;
    cout << "Good luck!" << endl;
}