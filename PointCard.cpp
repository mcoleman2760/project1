#include "PointCard.hpp"


PointCard::PointCard(){
    setType(POINT_CARD);
}
//Checks if the Card is Playable
bool PointCard::isPlayable() {
    if (getDrawn() == false || getInstruction().size() > 2){ // Checks if the PointCard is Drawn 
        return false;
    } 
 
    if(std::stoi(getInstruction()) < 1 || std::stoi(getInstruction()) > 99){ // Checks if the PointCard is between values 1 and 99
        return false;
    }

    return true;
} 
// Prints the information on the PointCard
void PointCard::Print() const {
    std::cout << "Type: " << getType()  << std::endl;   
    std::cout << "Points: " << getInstruction() << std::endl; 
    std::cout << "Card: " << std::endl;
    const int* imgd = getImageData();
    if (imgd != nullptr){
        for (int i = 0; i < sizeof(imgd); i++){
            std::cout << imgd[i];
        }
    }
    else{
    std::cout << "No image data" << std::endl;
    }
    

}
