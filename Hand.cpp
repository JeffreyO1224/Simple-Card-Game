/**
 * @file Hand.cpp
 * @author Jeffrey Oyuela
 * @email jeffrey.oyuela39@myhunter.cuny.edu
 * @date 2023-11-08
 */

#include "Hand.hpp"

// Big Five and constructor
/**
 * @post: Construct a new Hand object
 */
Hand::Hand(){
  std::deque<PointCard> cards_ = {};
}
/**
 * @post: Destroy the Hand object
 */
Hand::~Hand(){
  //std::cout << "Destructing Hand...\n";
  cards_.clear();
  //std::cout << "Destructed!\n\n";
  
}
/**
 * Copy Constructor
 * @param: other Hand object
 */
Hand::Hand(const Hand& other){
  cards_ = other.getCards();
}
/**
 * Copy Assignment Operator
 * @param: other Hand object
 * @return this Hand 
 */
Hand& Hand::operator=(const Hand& other){
  cards_ = other.getCards();
  return *this;
}
/**
 * Move Constructor
 * @param: other Hand object
 */
Hand::Hand(Hand&& other){
  cards_ = other.cards_;
  other.cards_.clear();
  //other.getCards().clear();
}
/**
 * Move assignment operator
 * @param: other Hand object
 * @return this Hand
 */
Hand& Hand::operator=(Hand&& other){
  cards_ = other.cards_;
  other.cards_.clear();

  //other.getCards()
  return *this;
}

/**
 * @return Hand
 */
const std::deque<PointCard>& Hand::getCards() const{
  return cards_;
}

/**
 * @post: Add a card to the hand
 * @param PointCard object
 */
void Hand::addCard(PointCard&& card){
  //std::cout << "Drawing card...\n";
  card.setDrawn(true);
  //std::cout << "Drawn!" << std::endl;
  //card.Print();

  //std::cout << "Adding card...\n";
  cards_.push_back(card);
  //std::cout << "Added!\n\n";
}
  


/**
 * @return true if hand is empty, false otherwise
 */
bool Hand::isEmpty() const{
  return cards_.empty();
}

/**
 * @post: Reverse the hand
 */
void Hand::Reverse(){
  if(isEmpty()){
    return;
  }
  //std::cout << "Reversing...\n";
  std::deque<PointCard> cards = cards_;

  //cards.back().Print();
  cards_.clear();
  
  for(int i = cards.size()-1; i>=0; i--){
    cards_.push_back(cards[i]);
    cards.pop_back();
  }
  //std::cout << "Reversed!\n\n";
  
}

/**
 * @post: Play the card at the front of the hand, removing it from the hand
 * Throws an exception if the hand is empty or the card is not playable
 * If the card is not playable, the card is removed from the hand
 * @return the points earned from playing the card
 */
int Hand::PlayCard(){
  if(isEmpty()){
    throw std::runtime_error("Error: Hand is Empty");
    //return -1;
  }
    
  else if(!cards_.front().isPlayable()){
    cards_.pop_front();
    throw std::runtime_error("Error: Card is not Playable");
    
    //return -1;
  }

  else{
    int i = stoi(cards_.front().getInstruction());
    cards_.pop_front();
    return i;
  }
}