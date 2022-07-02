#include "movies.h"

using namespace std;

struct MovieCollection {
    explicit MovieCollection(vector<map<string,string>> &collection): collection(collection) {};
    explicit MovieCollection(string const &str) {
        ifstream movies_file(str);
        if (movies_file.is_open()) {
            string line;
            while (getline(movies_file, line)) {
                string title, author, year;
                map<int,string> buffer = { {0, title}, {1, author}, {2, year} };
                int counter = 0;

                std::stringstream ss(line);
                for (char c; ss >> c;) {
                    buffer[counter] += c;
                    if (ss.peek() == ',') {
                        counter++;
                        ss.ignore();
                    }
                    else if (ss.peek() == ' ') {
                        buffer[counter] += ' ';
                    }
                }
                this->collection.push_back({ {"title", buffer[0]},
                                             {"author", buffer[1]},
                                             {"year", buffer[2]} });
            }
        }
    }

    void print_collection() {
        if (this->collection.empty()) {
            cout << "Collection is empty." << endl;
        }
        else {
            string linebreak = "---------------";
            cout << linebreak << endl;
            int counter = 1;
            for (auto i: this->collection) {
                cout << counter << ". Movie: " << i["title"] << "\n   Author: " << i["author"]
                << "\n   Year: " << i["year"] << endl;
                counter++;
            }
            cout << linebreak << endl;
            cout << endl;
        }
    }

    int search_movie(string const &title) {
        for (auto movie: this->collection) {
            if (movie["title"] == title) return 1;
        }
        return 0;
    }

    map<string,string> return_movie(string const &title, string const &author = "") {
        if (author.empty()) {
            for (auto movie: this->collection) {
                if (movie["title"] == title) return movie;
            }
        }
        else {
            for (auto movie: this->collection) {
                if (movie["title"] == title and movie["author"] == author) return movie;
            }
        }
        throw invalid_argument("No such movie.");
    }

    void add_movie(map<string,string> const &movie) {
        this->collection.push_back(movie);
    }

    size_t find_movie_index(string const &title) {
        for (size_t i = 0; i < title.size(); i++) {
            if (this->collection[i]["title"] == title) return i;
        }
        throw invalid_argument("Movie is not found.");
    }

    void delete_movie(string const &title) {
        unsigned int index = find_movie_index(title);
        this->collection.erase(this->collection.begin() + index);
    }

    vector<map<string,string>> collection;
};