// Object Oriented Programming In C++

#include <iostream>
#include <string>

// main class
class Football_clubs
{ // encapsulation by wrapping up properties nd methods in a class

    // private access specifiers for some properties/methods
    // abstraction
private:
    float brand_value;

    // declaring properties and methods public
public:
    // // constructor (no parameter)
    // Football_clubs() {
    //     std :: cout << "the information about " << name << "are as follow : \n";
    // }

    // constructor overloading (polymorphism)

    // constructor (parameter)
    Football_clubs(std ::string name, std ::string league, std ::string manager, std ::string ground, float defence, float midfield, float attack)
    {

        // this pointer (on left) for object properties & parameters (on right)
        this->conf = "UEFA";
        this->name = name;
        this->league = league;
        this->manager = manager;
        this->ground = ground;

        this->defence = defence;
        this->midfield = midfield;
        this->attack = attack;
    }

    // custom copy constructor
    Football_clubs(Football_clubs &obj)
    { // pass by reference

        std ::cout << "custom copy constructor \n";
        this->name = obj.name;
        this->league = obj.league;
        this->manager = obj.manager;
        this->ground = obj.ground;

        this->defence = obj.defence;
        this->midfield = obj.midfield;
        this->attack = obj.attack;
    }

    // properties

    std ::string conf;
    std ::string name;
    std ::string league;
    std ::string manager;
    std ::string ground;
    std ::string type;

    float defence;
    float midfield;
    float attack;

    // member functions (methods)

    float overall_rating()
    {
        float overall = (defence + midfield + attack) / 3;

        return overall;
    }

    // function overloading (compile time polymorphism)

    std ::string playing_style()
    {
        if (attack > midfield && attack > defence)
            return "counter attacking team\n";
        if (midfield > attack && midfield > defence)
            return "possesion based team\n";
        else
            return "low block team\n";
    }

    // no. of parameter(s) are different
    std ::string playing_style(float overall)
    {
        if (overall > 8.5)
            return "top team\n";
        if (overall > 6)
            return "moderate team\n";
        else
            return "small team\n";
    }

    // datatype of parameter is different
    std ::string playing_style(std ::string manager)
    {
        if (manager == "amorim")
            return "3-4-2-1 style\n";
        else
            return "other formation\n";
    }

    void display_info() 
    {

        std ::cout << "\n\n";
        std ::cout << "conf : " << conf << "\n";
        std ::cout << "name : " << name << "\n";
        std ::cout << "league : " << league << "\n";
        std ::cout << "manager : " << manager << "\n";
        std ::cout << "ground : " << ground << "\n";

        std ::cout << "defence : " << defence << "\n";
        std ::cout << "midfield : " << midfield << "\n";
        std ::cout << "attack : " << attack << "\n";

        std ::cout << "overall rating : " << overall_rating() << "\n";
        std ::cout << "playing style : " << playing_style() << "\n";
        std ::cout << "\n\n";
    }

    void change_manager(std ::string new_manager)
    {
        manager = new_manager;
        std ::cout << new_manager << " replace " << manager << "\n";
    }

    // setter
    void set_brand_value(float val)
    {
        brand_value = val;
    }

    // getter
    float get_brand_value()
    {
        return brand_value;
    }
};

// inheritance
class Company
{

public:
    std ::string name;
    std ::string company_name = name; // operator overloading
    float brand_value;                // in billion usd
    std ::string ceo;
    std ::string country;

    // virtual functions
    virtual void random()
    {
        std ::cout << "parent class" << std ::endl;
    }

    // static keyword (variable)

    void increase_revenue()
    {
        static int revenue = 25; // using static keyword
        revenue += 5;
        std ::cout << "revenue : " << revenue << std ::endl;
    }

    // polymorphism (constructor overloading...) , compile time polymorphism

    // default constructor for company
    Company()
    {
        std ::cout << "non parametarized Company constructor called\n";
    }

    Company(std ::string name, float brand_value, std ::string ceo, std ::string country)
    {
        std ::cout << "parametrized Company constructor called\n";

        this->name = name;
        this->brand_value = brand_value;
        this->ceo = ceo;
        this->country = country;
    }

    ~Company()
    {
        std ::cout << "Company destructor called\n";
    }

    void display_company()
    {
        std ::cout << "\n\n";
        std ::cout << name;
        std ::cout << brand_value;
        std ::cout << ceo;
        std ::cout << country;
    }
};

class Tech_company : public Company
{

public:
    std ::string tech_sector;
    std ::string tech_products;
    std ::string language;
    float cyber_rating;

    // parametrized constructor
    Tech_company(std ::string name, std ::string ceo, std ::string country, float brand_value, std ::string tech_sector, std ::string tech_products, std ::string language, float cyber_rating) : Company(name, brand_value, ceo, country)
    {

        std ::cout << "Tech_company constructor called\n";

        this->name = name;
        this->ceo = ceo;
        this->country = country;
        this->brand_value = brand_value;

        this->tech_sector = tech_sector;
        this->tech_products = tech_products;
        this->language = language;
        this->cyber_rating = cyber_rating;
    }

    ~Tech_company()
    {
        std ::cout << "Tech company destructor called\n";
    }

    void display_company()
    {
        std ::cout << "\n\n";
        std ::cout << "name : " << name << "\n";
        std ::cout << "ceo : " << ceo << "\n";
        std ::cout << "country : " << country << "\n";
        std ::cout << "brand value : " << brand_value << "\n";

        std ::cout << "tech sector : " << tech_sector << "\n";
        std ::cout << "tech products : " << tech_products << "\n";
        std ::cout << "language : " << language << "\n";
        std ::cout << "cyber rating : " << cyber_rating << "\n";
    }

    // virtual
    void random()
    {
        std ::cout << "child class" << std ::endl;
    }
};

// multi-level inheritance
class AI_company : public Tech_company
{

public:
    std ::string API;
    std ::string AI_model;
    float AI_rating;

    // contructor
    AI_company(std ::string name, std ::string ceo, std ::string country, float brand_value, std ::string tech_products, std ::string language, float cyber_rating, std ::string API, std ::string AI_model, float AI_rating) : Tech_company(name, ceo, country, brand_value, "Artificial Intelligence", tech_products, language, cyber_rating)
    {
        std ::cout << "AI_company constructor called\n";

        this->name = name;
        this->ceo = ceo;
        this->country = country;
        this->brand_value = brand_value;

        this->tech_sector = tech_sector;
        this->tech_products = tech_products;
        this->language = language;
        this->cyber_rating = cyber_rating;

        this->API = API;
        this->AI_model = AI_model;
        this->AI_rating = AI_rating;
    }

    // destructor for AI_company
    ~AI_company()
    {
        std ::cout << "AI_company destructor called\n";
    }

    void AI_display()
    {

        std::cout << "name : " << name << "\n";
        std::cout << "ceo : " << ceo << "\n";
        std::cout << "country : " << country << "\n";
        std::cout << "brand value : " << brand_value << "\n";

        std ::cout << "tech sector : " << tech_sector << "\n";
        std ::cout << "tech products : " << tech_products << "\n";
        std ::cout << "language : " << language << "\n";
        std ::cout << "cyber rating : " << cyber_rating << "\n";

        std ::cout << "API : " << API << "\n";
        std ::cout << "AI model : " << AI_model << "\n";
        std ::cout << "AI rating : " << AI_rating << "\n";
    }
};

class F1_teams
{
public:
    // constructor
    F1_teams(std ::string name, std ::string engine_manf, std ::string drivers, float aerodynamics, float strategy, float driver_performance)
    {
        this->name = name;
        this->engine_manf = engine_manf;
        this->strategy = strategy;
        this->driver_performance = driver_performance;
        this->aerodynamics = aerodynamics;
    }

    // properties
    std ::string name;
    std ::string engine_manf;
    std ::string drivers;

    float aerodynamics;
    float strategy;
    float driver_performance;
    float performance;

    // methods

    float teams_performance()
    {
        performance = (aerodynamics + strategy + driver_performance) / 3;
        return performance;
    }

    std ::string team_type()
    {
        if (performance < 6)
            return "backmakers";
        if (performance < 8)
            return "rest of the best";
        else
            return "contenders";
    }

    void display()
    {

        std ::cout << "\n\n";
        std ::cout << "name : " << name << "\n";
        std ::cout << "engine manufacturer : " << engine_manf << "\n";
        std ::cout << "drivers : " << drivers << "\n";

        std ::cout << "aerodynamics : " << aerodynamics << "\n";
        std ::cout << "strategy : " << strategy << "\n";
        std ::cout << "driver performance : " << driver_performance << "\n";

        std ::cout << "overall rating : " << teams_performance() << "\n";
        std ::cout << "team type : " << team_type() << "\n";
        std ::cout << "\n\n";
    }
};

//^ multiple inheritence
class owner : public Football_clubs, public F1_teams
{
public:
    std ::string owner_name;
    std ::string company_name;
    float net_worth;

    //* contructor
    owner(std::string owner, std ::string company_name,
          std::string football_name, std::string league, std::string manager, std::string ground, float defence, float midfield, float attack,
          std::string f1_name, std::string engine_manf, std::string drivers, float aerodynamics, float strategy, float driver_performance)
        : Football_clubs(football_name, league, manager, ground, defence, midfield, attack),
          F1_teams(f1_name, engine_manf, drivers, aerodynamics, strategy, driver_performance),
          owner_name(owner), company_name(owner)
    {
    }

    void display_owner_info()
    {
        std ::cout << "\n\n";
        std ::cout << "owner : " << owner_name << "\n";
        std ::cout << "company : " << company_name << "\n";
        std ::cout << "net worth : " << net_worth << "\n";

        //! football info
        std ::cout << "Footbal club info : \n";
        display_info();

        //? f1 info
        std ::cout << "F1 team info : \n";
        display();
    }
};

// abstract class
class team
{
    virtual void assign_name() = 0; // pure virtual function (automatically abstract class)
};

class nba_team : public team
{
public:
    nba_team()
    {
        std ::cout << "constructor" << std ::endl;
    }

    ~nba_team()
    {
        std ::cout << "destructor" << std ::endl;
    }

    void assign_name()
    {
        std ::cout << "enter nba team name : \n";
        std ::string t_name;
        std ::cin >> t_name;

        std ::cout << t_name;
    }
};

// main function (driver's code)
int main()
{

    // creating objects

    Football_clubs man_utd("manchester united", "premier league", "amorim", "old trafford", 7.9, 7.8, 7.5);
    man_utd.display_info();

    Football_clubs real_madrid("real madrid", "la liga", "xabi alonso", "santiago bernebau", 8.2, 8.9, 8.5);
    real_madrid.display_info();

    // default copy constructor (shallow copy)
    Football_clubs red_devils(man_utd);
    red_devils.display_info();

    // creating objects for other

    F1_teams red_bull("red bull", "ford rbpt", "max and no one", 8.6, 9.0, 8.2);
    red_bull.display();

    F1_teams mercedes("mercedes", "merc", "ruseel & kimi", 8.4, 8.5, 8.2);
    mercedes.display();

    F1_teams aston_martin("aston martin", "honda", "chadlonso & lance the goat", 8.2, 8.0, 7.7);
    aston_martin.display();

    F1_teams merc(mercedes);
    merc.display();

    //! function overriding (child class override parent class)
    Tech_company microsoft("MicroSoft", "bill gates", "USA", 35, "operating system", "windows", "c++", 9.2);
    microsoft.display_company();
    microsoft.random();

    Company tata("tata", 25, "ratan tata", "india");
    tata.random();

    tata.increase_revenue();
    tata.increase_revenue();
    tata.increase_revenue();

    AI_company perplexity("perplexity", "arvind srivastav", "usa/india", 18, "ai chatbot", "Python, R", 8.4, "Perplexity API", "sonar 4", 8.5);
    perplexity.AI_display();

    owner ineos("Jim Ratcliff", "INEOS", "Man Utd", "PL", "Amorim", "OT", 8.2, 8.6, 7.8, "Merc", "Merc", "Kimi nd George", 8.7, 8.3, 8.2);
    ineos.display_owner_info();

    // non-parametarized contructor will be called
    Company oracle;

    // parametarized constructor will be called
    Company tcs("TCS", 5, "tata", "india");

    // function overloading

    // 2nd one is called
    std ::cout << man_utd.playing_style(8.1);

    // 1st one is called
    std ::cout << man_utd.playing_style();

    // 3rd one is called
    std ::cout << man_utd.playing_style("amorim");

    nba_team lakers;
    lakers.assign_name();

    std ::cout << "\n\n\nend of the program!";

    return 0;
}
