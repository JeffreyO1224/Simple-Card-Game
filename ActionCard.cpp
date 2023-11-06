#include "ActionCard.hpp"

ActionCard(){}

/**
 * @return true if the card is playable, false otherwise
 * For a card to be playable, it has to be drawn and the instruction has to be valid
 * Valid instructions:
 * DRAW x CARD(S) : assume x is a positive integer
 * PLAY x CARD(S) : assume x is a positive integer
 * REVERSE HAND : reverse the order of the cards in the hand
 * SWAP HAND WITH OPPONENT : swap the hand with the opponent
*/
bool ActionCard::isPlayable(){
  
}

/**
 * @post: Print the ActionCard in the following format:
 * Type: [CardType]
 * Instruction: [Instruction]
 * Card: 
 * [ImageData]
 * 
 * Note: For [ImageData]: If there is no image data, print "No image data" instead
 */
void ActionCard::Print() const{
  std::cout << "Type: [" << getType() << "]\n";
  std::cout << "Instruction: [" << getInstruction() << "]\n";
  std::cout << "Card:\n" << getImageData() << std::endl;
}

bool ActionCard::isValid(){
  if(getDrawn() == true){
    
  }
}