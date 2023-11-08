#include "Player.hpp"

        Player::Player(){
           
            score_ = 0;
            opponent_ = nullptr;
            actiondeck_ = nullptr;
            pointdeck_ = nullptr;
           
           
        }
      
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

        /**
         * @post: Play a given action card
         * @param: an Actioncard object
         * Begin the function by reporting the instruction of the card:
         * PLAYING ACTION CARD: [instruction]
         */
        void Player::play(ActionCard&& card){
            std::cout << "PLAYING ACTION CARD: " << card.getInstruction() << std::endl;
            
             std::regex drawRegex("DRAW (\\w+)");
             std::regex playRegex("PLAY (\\w+)");
             std::smatch match;

          if(card.getInstruction() == "REVERSE HAND"){
                hand_.Reverse();
             }
        if(card.getInstruction() == "SWAP HAND WITH OPPONENT"){
               if( opponent_ != nullptr){
                Hand temp;
                temp = opponent_->hand_;
                opponent_->hand_ = hand_;
                hand_ = temp;
                
               }

             }
        if( std::regex_search(card.getInstruction(), match, drawRegex)){
            
            std::string str = match[1];


            int times = std::stoi(str);
            
            for(int i = 0; i < times ; i++){
               drawPointCard(); 
            }
            
        }
        if (std::regex_search(card.getInstruction(), match, playRegex)){
            std::string str = match[1];

             
            int times = std::stoi(str);
            
            for(int i = 0; i < times ; i++){
               playPointCard(); 
            }

        }
            
        }

        /**
         * @post: Draw a point card and place it in the player's hand
         */
        void Player::drawPointCard(){
         std::cout << "Draw" << std::endl; // FIX THIS
          pointdeck_->Draw();

        }
        /**
         * @post: Play a point card from the player's hand and update the player's score
         */
        void Player::playPointCard(){
          int x = getScore();
          x + hand_.PlayCard();
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
