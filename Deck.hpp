#include "PointCard.hpp"
#include "ActionCard.hpp"

template <class T>
class Deck{
    public:
        Deck();
        ~Deck();

        bool AddCard()
        bool shuffle();
        T draw();

    private:
        std::vector<T> deck_;

};