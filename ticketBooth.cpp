/*
    Christian Chacon | 5/31/2023

    NO Validation Used!!!
*/

#include <iostream>
#include <string>
#include <limits>
#include <vector>

//classes
class Movies{
private:
    std::string name;
    std::string rating;
    std::vector <std::string> showTimes;

public:
    //default constructor
    Movies(){
        this->name = name;
        this->rating = rating;
        this->showTimes = showTimes;
    }

    //non-default constructor
    Movies(std::string name, std::string rating, std::vector <std::string> showTimes){
        this->name = name;
        this->rating = rating;
        this->showTimes = showTimes;
    }

    //accessor fn
    std::string getMovieName(){return name;}

    //utility fns
    void displayMovieInfo(){
        std::cout<<"Display Movies";
    }
    void displayShowTimes(){
        for(std::string oneTime : showTimes){
            std::cout<<"Movie Time: "<<std::endl;
        }
    }
};//- - - - - - - End Movies Class - - - - - - - 

class Ticket{
private:
    short int age;
    double price;
    short int movieSelect;
    std::string selectedTime;
    bool matinee;//time before 5pm

public:
    //non-default fn
    Ticket(short int movieSelect, std::string selectedTime){
        this->movieSelect = movieSelect;
        this->selectedTime = selectedTime;
        price = 0;
        matinee = false;
    }

    //mutator fn
    void setAge(short int age){this->age = age;}

    //accessor fn - time, movie name, price
    std::string getTime(std::string selectedTime){return(selectedTime);}
    std::string getMovieName(short int movieSelect){return("x");}//use number to get movie name from vector of names.
    std::string getPrice(){return(std::to_string(price));}

    //utility fn
    void calcPrice(){
        if(matinee){
            price = 5.50;
            matinee = true;
        }
        else{
            //var   (      condition      ) if [true] [false]
            price = (age < 12 || age >= 65)  ? 7.00 : 10.50;
        }
    }
};//- - - - - - - End Ticket Class - - - - - - - 

class Order{
private:
    double totalDue;
    std::vector <Ticket> oneOrder;

public:
    //non-default fn
    Order(std::vector <Ticket> oneOrder){
        
        totalDue = 0.00;
    }

};//- - - - - - - End Order Class - - - - - - - 

//fn prototypes
void loadMovieChoices();
short int selectMovie();
short int startTimeChoice();
Ticket purchaseTicket();


int main(){

    return 0;
}

void loadMovieChoices(){

}

short int selectMovie(){

}

short int startTimeChoice(){

}

Ticket purchaseTicket(){

}
