#include "Hand.hpp"
#include <algorithm>
        // Constructor
        Hand::Hand(){
           cards_.clear();
        }
        //Destructor
        Hand::~Hand(){
           while (this->cards_.size() > 0){
            this->cards_.pop_back();
        }
        }
        // Copy Constructor
        Hand::Hand(const Hand& other){
             cards_= other.cards_;
        }
        //Copy Assignment Constructor
        Hand& Hand::operator=(const Hand& other){
             if( this != &other) {
            cards_= other.cards_;
            }
            return *this;
        }
        //Move Constructor
        Hand::Hand(Hand&& other)  {
            cards_ = std::move(other.cards_);
        }
           

        Hand& Hand::operator=(Hand&& other){
            cards_ = std::move(other.cards_);
            
        return *this;
        }

     
        const std::deque<PointCard>& Hand::getCards() const{
            return cards_;
        }
        
        /**
         * @post: Add a card to the hand
         * @param PointCard object
         */
        void Hand::addCard(PointCard&& card){
            cards_.push_back(card); 
        }

       
        bool Hand::isEmpty() const{
            if (getCards().empty() ){ // checks if the Hand is is empty
                return true;
            }
            else{
            return false;
            }
        }

        void Hand::Reverse(){ // reverses the hand
             std::reverse(cards_.begin(), cards_.end());
            
        }

        /**
         * @post: Play the card at the front of the hand, removing it from the hand
         * Throws an exception if the hand is empty or the card is not playable
         * If the card is not playable, the card is removed from the hand
         * @return the points earned from playing the card
         */
        int Hand::PlayCard(){
        PointCard card = std::move(cards_.front());
        if (isEmpty()) {  
            throw std::runtime_error("Hand is empty.");   
        }

        if (card.isPlayable() ){
            cards_.pop_front();
            return 0;
        }
            
        else{
            std::string  instruction = card.getInstruction();
              int sz = instruction.size();
             std::string part = instruction.substr(0,sz);
           int fin = std::stoi(card.getInstruction());
          cards_.pop_front();
          return fin;
        }
        }
         
     
         


        
