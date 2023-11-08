#include "Card.hpp"



        Card::~Card() {
        delete bitmap_;
        std::cout << "Destructor" << std::endl;
        }


        Card::Card(const Card& rhs){
            bitmap_= rhs.bitmap_;
            cardType_ = rhs.cardType_;
            instruction_ = rhs.instruction_;
            drawn_ = rhs.drawn_;

        }
        /**
         * Copy Assignment Operator
         * @param const reference to a Card object
         * @return this Card object
         */
        Card& Card::operator=(const Card& rhs){
            if( this != &rhs) {
            *bitmap_= *rhs.bitmap_;
            cardType_ = rhs.cardType_;
            instruction_ = rhs.instruction_;
            drawn_ = rhs.drawn_;
            }
            return *this;

        }
  
        Card::Card(Card&& rhs) :  Card {rhs }{
            rhs.instruction_ = nullptr;
            rhs.bitmap_ = nullptr;
        }
        /**
         * Move assignment operator
         * @param: rvalue reference to a Card object
         * @return this card object
        */
        Card& Card::operator=(Card&& rhs){
            if (this != &rhs){
                delete[] bitmap_;

            instruction_ = std::move(rhs.instruction_);
            cardType_ = std::move(rhs.cardType_);
            bitmap_ = rhs.bitmap_;
            drawn_ = rhs.drawn_;

            rhs.bitmap_ = nullptr;
            }
            return *this;
        }
        /**
         * Default Constructor
         * @post: Construct a new Card object 
         */
        Card::Card(){
            instruction_ = "";
            drawn_ = false;
            bitmap_ = nullptr;
        }


    std::string Card::getType() const{
    if(cardType_ == POINT_CARD){
        return "POINT_CARD";
    }
        return "ACTION_CARD";
    }

 void Card::setType(const CardType& type){
    cardType_ = type;
 }

const std::string& Card::getInstruction() const{
    return instruction_;
}

void Card::setInstruction(const std::string& instruction){
    instruction_ = instruction;
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

