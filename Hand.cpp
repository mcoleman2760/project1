#include "Hand.hpp"

        Hand::Hand(){
        }
        
        Hand::~Hand(){
        }
     
        Hand::Hand(const Hand& other){
            other;
        }
        /**
         * Copy Assignment Operator
         * @param: other Hand object
         * @return this Hand 
         */
        Hand& Hand::operator=(const Hand& other){

        }


        /**
         * Move Constructor
         * @param: other Hand object
         */
        Hand::Hand(Hand&& other){}
           
            
        
        /**
         * Move assignment operator
         * @param: other Hand object
         * @return this Hand
         */
        Hand& Hand::operator=(Hand&& other){
           

        }

     
        const std::deque<PointCard>& Hand::getCards() const{
            return cards_;
        }
        
        /**
         * @post: Add a card to the hand
         * @param PointCard object
         */
        void Hand::addCard(PointCard&& card){
            card;
        }

       
        bool Hand::isEmpty() const{
            if (getCards().empty()){
                return true;
            }
            return false;
        }

        /**
         * @post: Reverse the hand
         */
        void Hand::Reverse(){
            
        }

        /**
         * @post: Play the card at the front of the hand, removing it from the hand
         * Throws an exception if the hand is empty or the card is not playable
         * If the card is not playable, the card is removed from the hand
         * @return the points earned from playing the card
         */
        int PlayCard();
