#include <string>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;
/*con estas funciones soy capaz de transformar lineas de strings en palabras de strings en forma de vectores*/
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
