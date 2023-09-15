#include "Card.hpp"


Card::Card(std::string type, std::string value, std::vector<int> image){
    type_ = type;
    value_ = value;
    image_ = image;
}

Card::~Card(){
    std::cout << "Destruction in progress...";
}

//template <class T>

