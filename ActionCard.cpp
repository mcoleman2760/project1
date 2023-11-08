#include "ActionCard.hpp"

  ActionCard::ActionCard(){
    setType(ACTION_CARD);
   
  }

   bool ActionCard::isPlayable() {
     if (getDrawn() == false || getInstruction().size() < 11 ){
        return false;
     }
     if (getInstruction() == "REVERSE HAND" || getInstruction() == "SWAP HAND WITH OPPONENT" || getInstruction().substr(0,4) == "DRAW" || getInstruction().substr(0,4) == "PLAY"){
     return true;
     }
     else{
      return false;
     }
     
  }


   void ActionCard::Print() const {
    std::cout << "Type: [" << getType() << "]" << std::endl;
    std::cout << "Instruction: [" << getInstruction() << "]" << std::endl;
    std::cout << "Card: " << std::endl;
    
    const int* data = getImageData();
    if (getImageData() == nullptr){
        std::cout << "No image data" << std::endl;
    }
    else{

      for(int i = 0; i < sizeof(getImageData()); i++){
        std::cout << data[i] << std::endl;
      }
      
    }
    
  }
