#include "../../../include/animal/ave/ave.hpp"

Ave::Ave(bool voa):
                voa(voa){}

Ave::~Ave(){}

bool Ave::getVoa() const {
    return this->voa;
}