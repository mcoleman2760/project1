#include "ActionCard.hpp"

  ActionCard::ActionCard(){
    setType(ACTION_CARD);
   
  }

   bool ActionCard::isPlayable() {
     if (getDrawn() == false){
        return false;
     }
     if (getInstruction() != "REVERSE HAND" || getInstruction() != "SWAP HAND WITH OPPONENT" || getInstruction().substr(0,4) != "DRAW" || getInstruction().substr(0,4) != "PLAY"){
     return false;
     }
     return true;
  }


   void ActionCard::Print() const {
    std::cout << "Type: [" << getType() << "]" << std::endl;
    std::cout << "Instruction: [" << getInstruction() << "]" << std::endl;
    std::cout << "Card: " << std::endl;
    std::cout << "[";
    if (getImageData() == 0){
        std::cout << "No image data]" << std::endl;
    }
    std::cout << getImageData() <<  "]" <<std::endl;


  }
