#include "Card.hpp"



Card::~Card() {
    std::cout << "Destructor" << std::endl;
}


Card::Card(const Card& rhs){

}
        /**
         * Copy Assignment Operator
         * @param const reference to a Card object
         * @return this Card object
         */
        Card& Card::operator=(const Card& rhs){

        }
  
        Card::Card(Card&& rhs){
            cardType_ = std::move(rhs.cardType_);
            instruction_ = std::move(rhs.instruction_);
            drawn_ = std::move(rhs.drawn_);
            bitmap_ = std::move(rhs.bitmap_);

            rhs.cardType_= POINT_CARD;
            rhs.instruction_.clear();
            rhs.bitmap_= nullptr;
            rhs.drawn_= false;
        }
        /**
         * Move assignment operator
         * @param: rvalue reference to a Card object
         * @return this card object
        */
        Card& Card::operator=(Card&& rhs){
            
        }
        /**
         * Default Constructor
         * @post: Construct a new Card object 
         */
        Card::Card(){

        }


std::string Card::getType() const{
    if(cardType_ == POINT_CARD){
        return "POINT_CARD";
    }
    if(cardType_ == ACTION_CARD){
        return "ACTION_CARD";
    }
}

 void Card::setType(const CardType& type){
    cardType_ = type;
 }

const std::string& Card::getInstruction() const{
    return instruction_;
}

void Card::setInstruction(const std::string& instruction){
    instruction_ == instruction;
}

const int* Card::getImageData() const{
    return bitmap_;
}

void Card::setImageData(int* data){
    bitmap_ = data;
}

bool Card::getDrawn() const{
    return drawn_;
}

void Card::setDrawn(const bool& drawn){
    drawn_ = drawn;
}

