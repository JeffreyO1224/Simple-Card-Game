#include "Card.hpp"

/**
* Destructor
* @post: Destroy the Card object
*/
Card::~Card(){}

/**
* Copy Constructor
* @post: Construct a new Card object
* @param: const reference to a Card object
*/
Card::Card(const Card& rhs){

}

/**
* Copy Assignment Operator
* @param const reference to a Card object
* @return this Card object
*/
Card& Card::operator=(const Card& rhs){

}

/**
* Move Constructor
* @param: rvalue reference to a Card object
*/
Card::Card(Card&& rhs){

}

/**
* Move assignment operator
* @param: rvalue reference to a Card object
* @return this card object
*/
Card& Card::operator=(Card&& rhs){

}

/**
* Default Constructor
* @post: Construct a new Card object
*/
Card::Card(){
    
}

/**
* @return the string representation of the card type
*/
std::string Card::getType() const{
    return type_;
}

/**
* @post: set the card type
* @param const reference to a CardType object
*/
void Card::setType(const CardType& type){
    type_ = type;
}

/**
* @return the string representation of the card instruction
*/
const std::string& Card::getInstruction() const{
    return instruction_;
}

/**
* @post: set the card instruction
* @param: const reference to an instruction
*/
void Card::setInstruction(const std::string& instruction){
    instruction_ = instruction;
}

/**
* @return the image data
*/
const int* Card::getImageData() const{
    return image_data_;
}

/**
* @post: Set the image data
* @param pointer to an array of integers
*/
void Card::setImageData(int* data){
  image_data_ = data;
}

/**
* @return the drawn status of the card
*/
bool Card::getDrawn() const{
  return drawn_;  //Return the drawn status
}

/**
* @post: set the drawn status of the card
*
* @param: const reference to a boolean
*/
void Card::setDrawn(const bool& drawn){
  drawn_ = drawn;  //set drawn_ to the drawn
}