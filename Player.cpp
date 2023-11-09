#include "Player.hpp"
#include <regex>

        //Constructor
        Player::Player(){
            hand_ = Hand();
            score_ = 0;
            opponent_ = nullptr;
            actiondeck_ = nullptr;
            pointdeck_ = nullptr;   
        }
        //Destructor
        Player::~Player(){

            delete opponent_;
            delete actiondeck_;
            delete pointdeck_;
            opponent_ = nullptr;
            actiondeck_ = nullptr;
            pointdeck_ = nullptr;    
        }

       const Hand& Player::getHand() const{
          return hand_;
        }

        void Player::setHand(const Hand& hand){
            hand_ = hand;
        }

        int Player::getScore() const{
            return score_;
        }

        void Player::setScore(const int& score){
            score_ = score;
        }

       //Plays an action card and implements its action. It can reverse hand, swap hand, draw, or play the card.
        void Player::play(ActionCard&& card){
            std::cout << "PLAYING ACTION CARD: " << card.getInstruction() << std::endl;
            
             std::regex drawRegex("DRAW (\\w+)");
             std::regex playRegex("PLAY (\\w+)");
             std::smatch match;

          if(card.getInstruction() == "REVERSE HAND"){ //use the reverse function from hand if the ActionCard has the Reverse Hand instruction.
                hand_.Reverse();
             }
        if(card.getInstruction() == "SWAP HAND WITH OPPONENT"){ // if the ActionCard instruction is to Swap Hands then I used the swap functino to swap the opponent hand and the players hands
              std::swap(opponent_->hand_,hand_);

             }
        if( std::regex_search(card.getInstruction(), match, drawRegex)){ //takes the instruction and uses regex to search for the second word 
            
            std::string str = match[1]; // match[1] gets the word after Draw
            int times = std::stoi(str);
            
            for(int i = 0; i < times ; i++){ // uses a for loop to draw the point card the amount of times instructed
               drawPointCard(); 
            }
            
        }
        if (std::regex_search(card.getInstruction(), match, playRegex)){ //takes the instruction and uses regex to search for the second word 
            std::string str2 = match[1]; // match[1] gets the word after Play
            int times2 = std::stoi(str2);
            
            for(int i = 0; i < times2 ; i++){ // uses a for loop to play the point card the amount of times instructed.
               playPointCard(); 
            }

        }
            
        }
        //draws point card if the pointdeck is not pointing to a PointDeck.
        void Player::drawPointCard(){ 
            if (pointdeck_ != nullptr)  {
           auto card = pointdeck_->Draw(); 
         hand_.addCard(std::move(card));
            }
        }
        // If the hand is not empty, the players score is increased by the value of the Point Card
        void Player::playPointCard(){
            if(hand_.isEmpty()){
                return;
            }
          int x = getScore();
          score_ += hand_.PlayCard();
        }


        void Player::setOpponent(Player* opponent){
            opponent_ = opponent;
        }

        Player* Player::getOpponent(){
            return opponent_;
        }

   
        void Player::setActionDeck(Deck<ActionCard>* actiondeck){
            actiondeck_ = actiondeck;
        }
       
        Deck<ActionCard>* Player::getActionDeck(){
            return actiondeck_;
        }

        void Player::setPointDeck(Deck<PointCard>* pointdeck){
            pointdeck_ = pointdeck;
        }
     
        Deck<PointCard>* Player::getPointDeck(){
            return pointdeck_;
        }
