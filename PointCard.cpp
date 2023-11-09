/**
 * @file PointCard.cpp
 * @author Jeffrey Oyuela
 * @email jeffrey.oyuela39@myhunter.cuny.edu
 * @date 2023-11-08
 */

#include "PointCard.hpp"

/**
 * @post: Construct a new Point Card object
 */
PointCard::PointCard(){
  setType(POINT_CARD);
}

/**
 * @return true if the card is playable, false otherwise
 * For a card to be playable, it has to be drawn and the instruction has to be a valid number
*/
bool PointCard::isPlayable(){
  if(!getDrawn()){
    return false;
  }
  // for(char c : getInstruction()){
  //   if (!isdigit(c)){
  //     return false;
  //   }
  // }
  
  return isValidInstruction();
}

/**
 * @post: Print the Point Card in the following format:
 * Type: [CardType]
 * Points: [Instruction]
 * Card: 
 * [ImageData]
 * 
 * Note: For [ImageData]: If there is no image data, print "No image data" instead
 */
void PointCard::Print() const{
  std::cout << "Type: " << getType() << std::endl;
  std::cout << "Points: " << getInstruction() << std::endl;
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

bool PointCard::isValidInstruction(){
  for(char c : getInstruction()){
    if (!isdigit(c)){
      return false;
    }
  }
  if (std::stoi(getInstruction()) < 1 || std::stoi(getInstruction()) > 99){
    return false;
  }
  
  return true;
}