/*
    Christian Chacon | 5/31/2023

    NO Validation Used!!!
*/

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <iomanip>

//classes
class Movies{
private:
    std::string name;
    std::string rating;
    std::vector <std::string> showTimes;

public:
    //non-default constructor
    Movies(std::string name, std::string rating, std::vector <std::string> showTimes){
        this->name = name;
        this->rating = rating;
        this->showTimes = showTimes;
    }

    //default constructor
    Movies(){
    }

    //accessor fn
    std::string getMovieName(){return name;}

    //utility fns
    void displayMovieInfo(){
        std::cout<<name<<"  "<<rating<<std::endl;
    }
    void displayShowTimes(){
        for(std::string oneTime : showTimes){
            std::cout<<oneTime<<std::endl;
        }
    }
};//- - - - - - - End Movies Class - - - - - - - 

class Ticket{
private:
    short int age;
    float price;
    Movies selectedMovie;
    std::string selectedTime;
    bool matinee;//time before 5pm

public:
    //non-default fn
    Ticket(Movies selectedMovie, std::string selectedTime){
        this->selectedMovie = selectedMovie;
        this->selectedTime = selectedTime;
        price = 0;
        matinee = false;
    }

    //mutator fn
    void setAge(short int age){this->age = age;}

    //accessor fn - time, movie name, price
    std::string getSelectedTime(){return(selectedTime);}
    std::string getMovieName(){return(selectedMovie.getMovieName());}//use number to get movie name from vector of names.
    float getPrice(){return(price);}

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
    float totalDue;
    std::vector <Ticket> allTickets;

public:
    //non-default fn
    Order(std::vector <Ticket> allTickets){
        this->allTickets = allTickets;
        this->totalDue = 0.00;
    }

    //accessor
    float getTotalDue(){return(totalDue);}
    
    //utility fn
    float calcTotalDue(){
        for(Ticket oneTicket : allTickets){
            oneTicket.calcPrice();//tell the computer to calc the price
            totalDue += oneTicket.getPrice();//tell the computer to get price
        }
        return totalDue;
    }
    std::string printOneOrder(){
        return("You have selected " + std::to_string(allTickets.size()) + " tickets to see " + allTickets[0].getMovieName() + " with a start time of " + allTickets[0].getSelectedTime());
    }
};//- - - - - - - End Order Class - - - - - - - 

//fn prototypes
void loadMovieChoices(std::vector <Movies> &listMovies);
short int selectMovie(std::vector <Movies> listMovies);
std::string startTimeChoice(Movies oneMovie);
Ticket purchaseTicket(Movies selectedMovie, std::string startTime, int x);

int main(){
    std::vector <Movies> listMovies;
    std::vector <Ticket> allTickets;
    std::string startTime;
    short int movieSelection, buyTickets;
    int totalTickets = 0;
    char addAnother = 'Y';
    float totalSales = 0;

    loadMovieChoices(listMovies);

    std::cout<<"Welcome to the movie theaters!"<<std::endl;

    while(addAnother != 'N'){
        allTickets.clear();//clear vector so another order can be placed
        movieSelection = selectMovie(listMovies);
        startTime = startTimeChoice(listMovies.at(movieSelection));

        std::cout<<"How many tickets would you like to purchase? ";
            std::cin>>buyTickets;
            totalTickets += buyTickets;

        for(int x = 0; x < buyTickets; x++){
            //Class name     = fn call   send(movie selection,             , time,   increment counter)  
            Ticket oneTicket = purchaseTicket(listMovies.at(movieSelection), startTime, x+1);
            allTickets.push_back(oneTicket);//add new ticket
        }

        std::cout<<" - - - - - - - - - - - - - - - - - - "<<std::endl;

        Order oneOrder(allTickets);//send filled tickets to Order which counts totalPrice
        oneOrder.calcTotalDue();
        std::cout<<oneOrder.printOneOrder()<<std::endl;
        totalSales += oneOrder.getTotalDue();
        std::cout<<"Total Ticket Price: $"<<oneOrder.getTotalDue()<<std::endl;

        std::cout<<"Is there another customer? (Y/N) ";
            std::cin>>addAnother;
            addAnother = toupper(addAnother);
    }

    std::cout<<" - - - - - - - - - - - - - - - - - - "<<std::endl;

    std::cout<<"Overview of Daily Sales"<<std::endl;
    std::cout<<"Total Tickets Sold:    "<<totalTickets<<std::endl;
    std::cout<<"Total Sales Amount: $ "<<totalSales<<std::endl;

    return 0;
}
//reference vector because you are making changes to it
void loadMovieChoices(std::vector <Movies> &listMovies){
    std::vector <std::string> pgMovies = {"12:00 PM","2:30 PM","4:00 PM","6:30 PM","8:00 PM"};
    std::vector <std::string> pg13Movies = {"1:30 PM","3:00 PM","5:30 PM","7:00 PM","9:30 PM"};

    Movies movie1("Ant-Man and the Wasp", "(PG-13)", pg13Movies);
    Movies movie2("80 for Brady", "(PG-13)", pg13Movies);
    Movies movie3("MEGAN", "(PG-13)", pg13Movies);
    Movies movie4("Avatar: The way of water", "(PG-13)", pg13Movies);
    Movies movie5("Lego Movie", "(PG)", pgMovies);
    Movies movie6("Space Jam", "(PG)", pgMovies);

    listMovies.push_back(movie1);
    listMovies.push_back(movie2);
    listMovies.push_back(movie3);
    listMovies.push_back(movie4);
    listMovies.push_back(movie5);
    listMovies.push_back(movie6);
}

short int selectMovie(std::vector <Movies> listMovies){
    short int x = 1;
    short int movieSelection;

    std::cout<<"Please choose what movie you would like to see: \n";
    for(Movies oneMovie : listMovies){
        std::cout<<"  "<<x<<": ";
        oneMovie.displayMovieInfo();
        x++;
    }
    std::cout<<"->";
        std::cin>>movieSelection;
            while(std::cin.fail() || (movieSelection < 1 || movieSelection > 6)){
                std::cout<<"\n  Invalid. Please Choose 1-6.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout<<"Please choose what movie you would like to see: ";
                for(Movies oneMovie : listMovies){
                    std::cout<<x<<": ";
                    oneMovie.displayMovieInfo();
                    std::cout<<std::endl;
                    x++;
                }
                std::cout<<"->";
                    std::cin>>movieSelection;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return movieSelection-1;
}

std::string startTimeChoice(Movies oneMovie){
    std::string selectedTime;

    std::cout<<"Please choose a time: "<<std::endl;
    oneMovie.displayShowTimes();
    std::cout<<"->";
    getline(std::cin, selectedTime);

    return selectedTime;
}

Ticket purchaseTicket(Movies selectedMovie, std::string startTime, int x){
    Ticket oneTicket(selectedMovie, startTime);//send movie and time to ticket class
    short int age;

    std::cout<<"Enter the age for ticket #"<<x<<":  ";
        std::cin>>age;

    oneTicket.setAge(age);
    oneTicket.calcPrice();
    
    return oneTicket;
}