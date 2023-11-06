#include "ActionCard.hpp"

  ActionCard::ActionCard(){
   
  }

   bool ActionCard::isPlayable() {
     if ((getDrawn() == true) && (getInstruction() == "REVERSE HAND" || "SWAP HAND WITH OPPONENT" || "DRAW x CARD(S)" || "PLAY x CARD(S)")){
     return true;
     }
     return false;
  }


   void ActionCard::Print() const {
    std::cout << "Type: [ActionCard]\nInstruction:[";
    std::cout << getInstruction() + "]\nCard:\n[";
    if (getImageData() == 0){
        std::cout << "No image data" << std::endl;
    }
    std::cout << getImageData() << std::endl;


  }
