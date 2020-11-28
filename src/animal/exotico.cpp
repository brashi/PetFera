#include "exotico.hpp"

using std::cout;
using std::cin;

Exotico::Exotico(string local):
                local(local){}

Exotico::~Exotico(){}

string Exotico::getLocal() const {
    return this->local;
}

bool Exotico::setLocal() {
    string s;
    cout << endl << "Habitat do animal: " << endl;
    getline(cin, s);

    if(s.size() == 0)
        return false;
    else
        local = s;
    
    return true;
}