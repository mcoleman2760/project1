 /* #include "Deck.hpp"




template <typename CardType>
Deck<CardType>::Deck(){
    cards_.clear();
}


template <typename CardType>       
Deck<CardType>::~Deck(){
   while (this->cards_.size() > 0){
    this->cards_.pop_back();
   }
}


template <typename CardType>
void Deck<CardType>::AddCard(const CardType& card){
    cards_.push_back(card);
}

template <typename CardType>
CardType&& Deck<CardType>::Draw(){
    if(IsEmpty() == true){
      throw std::out_of_range("Deck is empty");
       
    }
    else {
        cards_.back().setDrawn(true);
        CardType&& drawnCard = std::move(cards_.back());
        cards_.pop_back();
        return std::move(drawnCard);
    }
}

template <typename CardType>
bool Deck<CardType>::IsEmpty() const{
    return (cards_.size() == 0);
}

template <typename CardType>
void Deck<CardType>::Shuffle(){
    std::mt19937 seed(2028358904);
    std::shuffle(cards_.begin(), cards_.end(), seed);
}

template <typename CardType>
int Deck<CardType>::getSize() const{
      return this->cards_.size();
}

template <typename CardType>
std::vector<CardType> Deck<CardType>::getDeck() const{
    return cards_;
}

*/
