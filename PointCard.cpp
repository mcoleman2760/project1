#include "PointCard.hpp"



PointCard::PointCard(){
    std::cout << "Constructor for PointCard" << std::endl;
}

bool PointCard::isPlayable() {
    if ((getDrawn() == true) && (std::stoi(getInstruction()) >= 1 && std::stoi(getInstruction()) <= 99 )){
        return true;
    }
    return false;
} 

void PointCard::Print() const {
    std::cout << "Type: [PointCard]\nInstruction:[";
    std::cout << getInstruction() + "]\nCard:\n[";
    if (getImageData() == 0){
        std::cout << "No image data" << std::endl;
    }
    std::cout << getImageData() << std::endl;

}
