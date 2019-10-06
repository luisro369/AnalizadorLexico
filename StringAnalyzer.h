#include <string>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;

template<typename Out>
void separar(const string &s, char delim, Out result) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        *(result++) = item;
    }
}

vector<string> Separar(const string &s, char delim) {
    vector<string> elems;
    separar(s, delim, back_inserter(elems));
    return elems;
}
