#include "PointCard.hpp"



PointCard::PointCard(){
    setType(POINT_CARD);
}

bool PointCard::isPlayable() {
    if (getDrawn() == true){
        return false;
    } 
    if(!(std::stoi(getInstruction()) >= 1 && std::stoi(getInstruction()) <= 99)){
        return false;
    }
    return true;
} 

void PointCard::Print() const {
    std::cout << "Type: [" << getType() << "]" << std::endl;   
    std::cout << "Points: [" << getInstruction() << "]" << std::endl; 
    std::cout << "Card: " << std::endl;
    std::cout << "[";
    if (getImageData() == 0){
        std::cout << "No image data" << std::endl;
    }
    std::cout << getImageData()  <<  "]" << std::endl;

}
