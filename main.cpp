#include "main-libraries.h"

using namespace std;

int main() {
    MovieCollection* collection = new MovieCollection(movie_path);
    menu(collection);
    save_collection(*collection, movie_path);
    return 0;
}
