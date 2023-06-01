/*
    Christian Chacon | 5/31/2023

    NO Validation Used!!!

    oneTicket - individual ticket
    oneOrderTickets - a group of tickets which are grouped together
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
    std::string getSelectedTime(){return(selectedTime);}
    std::string getMovieName(){return("xxxx");}//use number to get movie name from vector of names.
    double getPrice(){return(price);}

    //utility fn
    void calcPrice(){
        if(selectedTime.at(0) < '5'){
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
    std::vector <Ticket> oneOrderTickets;

public:
    //non-default fn
    Order(std::vector <Ticket> ticketList):totalDue(0.00), oneOrderTickets(ticketList){
        //tbf
    }

    //accessor
    std::string getTotalDue(double totalDue){return(std::to_string(totalDue));}
    
    //utility fn
    double calcTotalDue(){
        double price = 0.00;
        for(Ticket oneTicket : oneOrderTickets){
            price = oneTicket.getPrice();
            totalDue += price;
        }
        return totalDue;
    }
    std::string printOneOrder(){
        return("You have selected " + std::to_string(oneOrderTickets.size()) + " to see " + oneOrderTickets[0].getMovieName() + " with a start time of " + oneOrderTickets[0].getSelectedTime());
    }
};//- - - - - - - End Order Class - - - - - - - 

//fn prototypes
void loadMovieChoices(std::vector <Movies> listMovies);
short int selectMovie();
short int startTimeChoice();
Ticket purchaseTicket();

int main(){
    std::vector <Movies> listMovies;

    loadMovieChoices(listMovies);

    return 0;
}

void loadMovieChoices(std::vector <Movies> listMovies){
    std::vector <std::string> pgMovies = {"12:00 PM","2:30 PM","4:00 PM","6:30 PM","8:00 PM"};
    std::vector <std::string> pg13Movies = {"1:30 PM","3:00 PM","5:30 PM","7:00 PM","9:30 PM"};

    listMovies.push_back(Movies("Ant-Man and the Wasp", "(PG-13)", pg13Movies));
    listMovies.push_back(Movies("80 for Brady", "(PG-13)", pg13Movies));
    listMovies.push_back(Movies("MEGAN", "(PG-13)", pg13Movies));
    listMovies.push_back(Movies("Avatar: The way of water", "(PG-13)", pg13Movies));
    listMovies.push_back(Movies("Lego Movie", "(PG)", pgMovies));
    listMovies.push_back(Movies("Space Jam", "(PG)", pgMovies));
}

short int selectMovie(){

}

short int startTimeChoice(){

}

Ticket purchaseTicket(){

}