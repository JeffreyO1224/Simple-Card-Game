#include <iostream>
#include <vector>
#include <string>

class Card{
    public:
        Card(std::string type, std::string value, std::vector<int> image);
        ~Card();
        
        virtual void play() = 0;


    private:
        std::string type_;
        std::string value_;
        std::vector<int> image_;

};