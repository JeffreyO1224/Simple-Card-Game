#include "PointCard.hpp"
#include "ActionCard.hpp"
#include <deque>

class Hand{
    public:
        Hand();
        ~Hand();

        void reverse();
        bool playCard();


    private:
        std::deque<PointCard> cards_;
        bool reversed_;

};