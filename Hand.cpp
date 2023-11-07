#include "Hand.hpp"

        Hand::Hand(){
        }
        
        Hand::~Hand(){
        }
     
        Hand::Hand(const Hand& other){
             cards_= other.cards_;
        }
        
        Hand& Hand::operator=(const Hand& other){
             if( this != &other) {
            cards_.clear();
            }
            return *this;
        }


        Hand::Hand(Hand&& other)  {
            cards_ = std::move(other.cards_);
        }
           

        Hand& Hand::operator=(Hand&& other){
            if(this != &other){
                cards_.clear();
                cards_ = std::move(other.cards_);
                
            }
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
            if (getCards().empty()){
                return true;
            }
            return false;
        }

        void Hand::Reverse(){
             std::reverse(cards_.begin(), cards_.end());
            
        }

        /**
         * @post: Play the card at the front of the hand, removing it from the hand
         * Throws an exception if the hand is empty or the card is not playable
         * If the card is not playable, the card is removed from the hand
         * @return the points earned from playing the card
         */
        int PlayCard(){

        }
