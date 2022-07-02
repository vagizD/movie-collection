

using namespace std;

vector<map<string,string>> create_collection(string const &path) {
    vector<map<string, string>> collection;

    ifstream movies_file(path);
    if (movies_file.is_open()) {
        string line;
        while (getline(movies_file, line)) {
            string title, author, year;
            map<int, string> buffer = {{0, title},
                                       {1, author},
                                       {2, year}};
            int counter = 0;
            std::stringstream ss(line);
            for (char c; ss >> c;) {
                buffer[counter] += c;
                if (ss.peek() == ',') {
                    counter++;
                    ss.ignore();
                } else if (ss.peek() == ' ') {
                    buffer[counter] += ' ';
                }
            }
            collection.push_back({{"title",  buffer[0]},
                                  {"author", buffer[1]},
                                  {"year",   buffer[2]}});
        }
    }
    return collection;
}

void save_collection(MovieCollection &collection, string const &path) {
    ofstream output_file(path);
    for (auto movie:collection.collection) {
        output_file << movie["title"] << ", " << movie["author"] << ", " << movie["year"] << endl;
    }
    output_file.close();
}