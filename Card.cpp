/**
 * @file Card.cpp
 * @author Jeffrey Oyuela
 * @email jeffrey.oyuela39@myhunter.cuny.edu
 * @date 2023-11-08
 */

#include "Card.hpp"

/**
 * Destructor
 * @post: Destroy the Card object
 */
Card::~Card() {
  delete[] bitmap_;
  bitmap_ = nullptr;
}

/**
 * Copy Constructor
 * @post: Construct a new Card object
 * @param: const reference to a Card object
 */
Card::Card(const Card &rhs) {
  bitmap_ = rhs.bitmap_;
  cardType_ = rhs.cardType_;
  instruction_ = rhs.instruction_;
  drawn_ = rhs.drawn_;
}

/**
 * Copy Assignment Operator
 * @param const reference to a Card object
 * @return this Card object
 */
Card &Card::operator=(const Card &rhs) {
  //std::cout << "Copying card...\n";
  //std::cout << "Copy Assignment!\n";
  if(this != &rhs){
    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;
    bitmap_ = rhs.bitmap_;
    drawn_ = rhs.drawn_;
  }
  return *this;
}

/**
 * Move Constructor
 * @param: rvalue reference to a Card object
 */
Card::Card(Card &&rhs) {
  //std::cout << "Moving card...\n";
  //std::cout << "Move Constructor!\n";
  //delete[] bitmap_;
  cardType_ = std::move(rhs.cardType_);
  instruction_ = std::move(rhs.instruction_);
  bitmap_ = std::move(rhs.bitmap_);
  drawn_ = std::move(rhs.drawn_);

  rhs.drawn_ = false;
  rhs.bitmap_ = nullptr;
  rhs.instruction_ = "";
  //std::cout << "Moved!\n\n";
}

/**
 * Move assignment operator
 * @param: rvalue reference to a Card object
 * @return this card object
 */
Card &Card::operator=(Card &&rhs) {
  //std::cout << "Moving card...\n";
  if(this != &rhs){  
    //std::cout << "Move Assignment Constructor!\n";
    delete[] bitmap_;
    cardType_ = std::move(rhs.cardType_);
    instruction_ = std::move(rhs.instruction_);
    bitmap_ = rhs.bitmap_;
    drawn_ = std::move(rhs.drawn_);
  }

  rhs.drawn_= false;
  rhs.bitmap_ = nullptr;
  rhs.instruction_ = "";
  //std::cout << "Moved!\n\n";

  return *this;
}

/**
 * Default Constructor
 * @post: Construct a new Card object
 */
Card::Card() {
  //std::cout << "Default Constructor!\n";
  instruction_ = "";
  bitmap_ = nullptr;
  drawn_ = false;
}

/**
 * @return the string representation of the card type
 */
std::string Card::getType() const { 
  if (cardType_ == POINT_CARD){
    return "POINT_CARD";
  }
  else{
    return "ACTION_CARD";
  }
}

/**
 * @post: set the card type
 * @param const reference to a CardType object
 */
void Card::setType(const CardType &type) { cardType_ = type; }

/**
 * @return the string representation of the card instruction
 */
const std::string &Card::getInstruction() const { return instruction_; }

/**
 * @post: set the card instruction
 * @param: const reference to an instruction
 */
void Card::setInstruction(const std::string &instruction) {
  instruction_ = instruction;
}

/**
 * @return the image data
 */
const int *Card::getImageData() const { return bitmap_; }

/**
 * @post: Set the image data
 * @param pointer to an array of integers
 */
void Card::setImageData(int *data) {
  delete[] bitmap_;
  bitmap_ = data;
}

/**
 * @return the drawn status of the card
 */
bool Card::getDrawn() const {return drawn_;}

/**
 * @post: set the drawn status of the card
 *
 * @param: const reference to a boolean
 */
void Card::setDrawn(const bool &drawn) {drawn_ = drawn;}