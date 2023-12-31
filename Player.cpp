/**
 * @file Player.cpp
 * @author Jeffrey Oyuela
 * @email jeffrey.oyuela39@myhunter.cuny.edu
 * @date 2023-11-08
 */

#include "Player.hpp"
/**
     * @post: Construct a new Player object
     */
    Player::Player(){
      //Initialize all of our variables
      score_ = 0;
      opponent_ = nullptr;
      actiondeck_ = nullptr;
      pointdeck_ = nullptr;
    }

    /**
     * @post: Destroy the Player object
     */
    Player::~Player(){
      delete opponent_;
      opponent_ = nullptr;

      delete actiondeck_;
      actiondeck_ = nullptr;

      delete pointdeck_;
      pointdeck_ = nullptr;
    }

    /**
     * @return the player's hand
     */
    const Hand& Player::getHand() const{
      return hand_;
    }
    /**
     * @post: Set the player's hand
     * @param const reference to a hand object
     */
    void Player::setHand(const Hand& hand){
      hand_ = hand;
    }

    /**
     * @return the Player's current score
     */
    int Player::getScore() const{
      return score_;
    }
    /**
     * @post: Set the player's score
     * @param: score 
     */
    void Player::setScore(const int& score){
      score_ = score;
    }

    /**
     * @post: Play a given action card
     * @param: an Actioncard object
     * Begin the function by reporting the instruction of the card:
     * PLAYING ACTION CARD: [instruction]
     */
    void Player::play(ActionCard&& card){
      std::string instruction = card.getInstruction();
      std::cout << "PLAYING ACTION CARD: " << instruction << std::endl;
      std::regex regexRule("[0-9]+");
      std::smatch num;
      regex_search(instruction, num, regexRule);

      
      if (instruction == "REVERSE HAND"){
        hand_.Reverse();
      }

      else if (instruction == "SWAP HAND WITH OPPONENT"){
        Hand temp = hand_;
        //std::swap(hand_, opponent_->getHand());
        hand_ = opponent_->getHand();
        opponent_->setHand(temp);
      }

      else if(card.getInstruction().substr(0,4) == "DRAW"){
        for(int i = 0; i < std::stoi(num.str()); i++){
          drawPointCard();
        }
      }

      else if(card.getInstruction().substr(0,4) == "PLAY"){
        for(int i = 0; i < std::stoi(num.str()); i++){
          playPointCard();
        }
      }

        //  * DRAW x CARD(S) : assume x is a positive integer
        //  * PLAY x CARD(S) : assume x is a positive integer
        //  * REVERSE HAND : reverse the order of the cards in the hand
        //  * SWAP HAND WITH OPPONENT : swap the hand with the opponent
    }

    /**
     * @post: Draw a point card and place it in the player's hand
     */
    void Player::drawPointCard(){
      if (pointdeck_ != nullptr){
        hand_.addCard(std::move(pointdeck_->Draw()));
      }
    }
    /**
     * @post: Play a point card from the player's hand and update the player's score
     */
    void Player::playPointCard(){
      if(!hand_.isEmpty()){
        score_ += hand_.PlayCard();
      }

    }

    /**
     * @post: Set the opponent of the player
     * @param a pointer to a Player opponent 
     */
    void Player::setOpponent(Player* opponent){
      opponent_ = opponent;
    }
    /**
     * @return: a pointer to the player's opponent
     */
    Player* Player::getOpponent(){
      return opponent_;
    }

    /**
     * @post: set the action deck of the player 
     * @param: A pointer to a deck holding Action cards 
     */
    void Player::setActionDeck(Deck<ActionCard>* actiondeck){
      actiondeck_ = actiondeck;
    }
    /**
     * @return a pointer to the player's action deck
     */
    Deck<ActionCard>* Player::getActionDeck(){
      //std::cout << "Retrieving Deck...\n";
      return actiondeck_;
    }

    /**
     * @post: set the point deck of the player
     * @param: A pointer to a deck holding Point cards
     */
    void Player::setPointDeck(Deck<PointCard>* pointdeck){
      pointdeck_ = pointdeck;
    }
    /**
     * @return: a pointer to the player's point deck
     */
    Deck<PointCard>* Player::getPointDeck(){
      return pointdeck_;
    }

/*private:
    Hand hand_;   // The player's hand
    int score_;  // The player's score
    Player* opponent_; // A pointer to another player opponent
    Deck<ActionCard> * actiondeck_; // A pointer to a deck
    Deck<PointCard> * pointdeck_; // A pointer to a deck*/