#include "Deck.hpp"



Deck<CardType>::Deck(){
    std::cout << "Constructor" << std::endl;
}

       
Deck<CardType>::~Deck(){
    std::cout << "Destructor" << std::endl;
}


void Deck<CardType>::AddCard(const CardType& card){
    cards_.push_back(card);
}

CardType&& Deck<CardType>::Draw(){
    if(IsEmpty()){
        std::runtime_error("Deck is empty");
        return;
    }
    CardType&& drawnCard = std::move(cards_.back());
    cards_.pop_back();
    return std::move(drawnCard);
}

bool Deck<CardType>::IsEmpty() const{
    return cards_.empty();
}

void Deck<CardType>::Shuffle(){
    std::mt19937 seed(2028358904);
    std::shuffle(getDeck().begin(), getDeck().end(), seed);
}

int Deck<CardType>::getSize() const{
      return cards_.size();
}


std::vector<CardType> Deck<CardType>::getDeck() const{
    return cards_;
}
