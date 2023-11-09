#include "ActionCard.hpp"

  ActionCard::ActionCard(){
    setType(ACTION_CARD);  //Constructor
   
  }

   bool ActionCard::isPlayable() {
      if (getDrawn() == false || getInstruction().size() < 11 ){ // Checks if the ActionCard is drawn
        return false;
      }
     if (getInstruction() == "REVERSE HAND" || getInstruction() == "SWAP HAND WITH OPPONENT" || getInstruction().substr(0,4) == "DRAW" || getInstruction().substr(0,4) == "PLAY"){ // Checks for the first word of the instruction.
        return true;
     }
     else{
        return false;
     }
     
  }

// Prints out the information for the ActionCard
    void ActionCard::Print() const {
      std::cout << "Type: " << getType() << std::endl; // Prints Card Type
      std::cout << "Instruction: " << getInstruction()  << std::endl; // Prints Instruction
      std::cout << "Card: " << std::endl;
    // Gets image data
      const int* data = getImageData();
      if (getImageData() == nullptr){ // if theres no image data then print out No image date
        std::cout << "No image data" << std::endl;
      }
      else{
        for(int i = 0; i < sizeof(getImageData()); i++){  // prints the numbers in the Image Data
          std::cout << data[i] << std::endl;
      }
      
    }
   
  }
