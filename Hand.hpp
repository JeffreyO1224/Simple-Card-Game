#include "PointCard.hpp"
#include "ActionCard.hpp"
#include <deque>

class Hand{
    public:
        Hand();
        ~Hand();

        void reverse();


    private:
        std::deque<PointCard> cards_;

};