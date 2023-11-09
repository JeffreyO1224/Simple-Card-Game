/**
 * @file ActionCard.cpp
 * @author Jeffrey Oyuela
 * @email jeffrey.oyuela39@myhunter.cuny.edu
 * @date 2023-11-08
 */

#include "ActionCard.hpp"

ActionCard::ActionCard(){
  setType(ACTION_CARD);
}

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
  if(!getDrawn()){
    return false;
  }
  return isValid();
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
  std::cout << "Type: " << getType() << std::endl;
  std::cout << "Instruction: " << getInstruction() << std::endl;
  std::cout << "Card: " << std::endl;
  
  if(getImageData() == nullptr){
    std::cout << "No image data" << std::endl;
  }

  else{
    for(int i = 0; i < 80; i++){
      std::cout << getImageData()[i] << " ";
    }
    std::cout << std::endl;
  }
  
}

bool ActionCard::isValid(){
  std::regex regexRule("^(DRAW|PLAY) [0-9]+ CARD\\(S\\)$");
  //std::cout << regex_match(getInstruction(), regexRule) << std::endl;
  if(regex_match(getInstruction(), regexRule) || getInstruction() == "REVERSE HAND" || getInstruction() == "SWAP HAND WITH OPPONENT"){
    return true;
  }
  else{
    return false;  
  }
}