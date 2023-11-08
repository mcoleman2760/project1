#include "PointCard.hpp"



PointCard::PointCard(){
    setType(POINT_CARD);
}

bool PointCard::isPlayable() {
    if (getDrawn() == true || getInstruction().size() > 2){
        return false;
    } 
    if(!(std::stoi(getInstruction()) < 1 || std::stoi(getInstruction()) > 99)){
        return false;
    }
    return true;
} 

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
