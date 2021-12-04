/*
Project 3 - Part 1e / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
    if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

/*
 example:  

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function whose parameter has a default value.
        //the parameter name is related to the work the function will perform.
        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar(Car carA); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior(Car carB);
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  

    /*
    Pay attention to the member functions that take an instance of 'Car'
    Notice that there is a member variable of the same type.

    It makes sense to pass a Car to the function 'washAndWaxCar' because car washes service MANY cars
    However, they only service ONE car at a time.
    the carBeingServiced's value would change every time you wash and wax the car. 

    I see many students who write code emulating this format, but their usage does not make logical sense.  
    Consider the following snippet:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        // train their skills
        void trainPlayerSkills(Manager managerA);
    
        Manager teamManager;
    };

    It does not make sense to pass in a new Manager whenever you are going to train your team players.
    Soccer teams have ONE manager.

    a much more relevant usage would be adding a member function that hires a new manager:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        void hireNewManager(Manager newManager);
    
        Manager teamManager;
    };

    We can safely assume that the 'Manager' instance that is being passed in will be replacing the current 'teamManager' variable without looking at any other code.
    This is because the function name and function argument clearly indicate what they are/what they do.

    Your function names and parameter names should make LOGICAL SENSE.
    Readers of your code should be able to INTUITIVELY understand what your function implementations will do without actually seeing the implementations.

    Keep this in mind when you define your UDTs in this project part.
    */
};




/*
Thing 1) kitchen range (oven stove)
5 properties:
    1) brand name (std::string)
    2) number of burner (int)
    3) number of oven rack (int)
    4) oven capacity (float)
    5) warranty duration in month (int)
3 things it can do:
    1) broil food
    2) oven bake food
    3) light up
 */
struct OvenStove
{
    // brand name
    std::string brandName = "GE";
    // number of burner
    int numberOfBurner = 4;
    // number of oven rack
    int numberOfRack = 2;
    // oven capacity
    float ovenCapacity = 5.0f;
    // warranty duration in month
    int warrantyDuration = 12;

    struct FoodItem
    {
        std::string type = "Poultry";
        std::string name = "Chicken breast";
        float weight = 1.0f;
        bool isSeasoned = false;
        int expirationDayRemain = 7;

        void clean(std::string cleaningType = "Salted water");
        void season(std::string mainCondiment = "Pepper");
        void cut(int numberOfPortion = 3, std::string tool = "Long knife");
    };

    // broil food
    void broilFood(FoodItem food, int temperature, int durationInMinute);
    // oven bake food
    void bakeFood(FoodItem food, int temperature, int durationInMinute, int rackId, bool preHeat);
    // light up
    void lightUp(bool lightStatus);

    FoodItem mainIngredient;
};

/*
Thing 2) laptop
5 properties:
    1) model name (std::string)
    2) screen display size in inch (float)
    3) RAM size in GB (int)
    4) storage size in GB (int)
    5) weight in lbs (float)
3 things it can do:
    1) connect to Wifi
    2) check available OS update
    3) play audio
 */
struct Laptop
{
    // model name
    std::string modelName = "Thinkpad";
    // screen display size in inch
    float screenDisplay = 15.6f;
    // RAM size in GB
    int RAMSize = 32;
    // storage size in GB
    int storageSize = 2000;
    // weight in lbs
    float weight = 6.2f;

    // connect to Wifi
    void connectToWifi(bool connectionStatus = false);
    // check available OS update
    std::string checkAvailableOSUpdate(int currentOSId);
    // play audio
    void playAudio(int audioFileId = 0, int volume = 50, std::string playMode = "Headphones");
};

/*
Thing 3) fruit tree
5 properties:
    1) name (std::string)
    2) height (float)
    3) bark thickness diameter (double)
    4) fruit color (std::string)
    5) harvest season (std::string)
3 things it can do:
    1) produce oxygen
    2) absorb carbon dioxide
    3) produce fruit
 */
struct FruitTree
{
    // name
    std::string name = "Apple Tree";
    // height
    float height = 10.5f;
    // bark thickness diameter
    double barkThicknessDiameter = 2.456;
    // fruit color
    std::string fruitColor = "Red";
    // harvest season
    std::string harvestSeason = "September";

    // produce oxygen
    void produceOxygen(int currentDayTimeInHour = 7);
    // absorb carbon dioxide
    void absorbCarbonDioxide(int currentDayTimeInHour = 21);
    // produce fruit
    int produceFruit(std::string currentSeason = "December");
};

/*
Thing 4) camera
5 properties:
    1) brand name (std::string)
    2) resolution in megapixel (float)
    3) number of shooting mode (int)
    4) number of white balance mode (int)
    5) weight in lbs (float)
3 things it can do:
    1) shoot photo
    2) record video
    3) play flash
 */
struct Camera
{
    // brand name
    std::string brandName = "Canon";
    // resolution in megapixel
    float resolution = 26.7f;
    // number of shooting mode
    int numberOfShootingMode = 5;
    // number of white balance mode
    int numberOfWhiteBalanceMode = 5;
    // weight in lbs
    float weight = 2.2f;

    struct Lens
    {
        std::string model = "Canon EF-S";
        int maxFocalLengthInMM = 300;
        int minFocalLengthInMM = 55;
        int filterDiameterInMM = 58;
        float weightInOz = 13.2f;

        void cover();
        void zoom(float zoomMode = 1.0f);
        void getFocus(double distanceToObject);
    };

    // shoot photo
    void shootPhoto(Lens currentLen, char shootingMode = 'A');
    // record video
    void recordVideo(Lens currentLen, int durationInSecond);
    // play flash
    void playFlash(bool lowLightIntensity = true);

    Lens includedLen;
};

/*
Thing 5) Cooktop
5 properties:
    1) number of burner (int)
    2) surface material (std::string)
    3) cooktop voltage requirement (int)
    4) width (float)
    5) depth (float)
3 things it can do:
    1) burn food
    2) consume electric
    3) boil water
 */
struct Cooktop
{
    // number of burner
    int numberOfBurner = 4;
    // surface material
    std::string surfaceMaterial = "Stainless steel";
    // cooktop voltage requirement
    int cooktopVoltageRequirement = 120;
    // width
    float width;
    // depth
    float depth;

    // burn food
    void burnFood();
    // consume electric
    double consumeElectric(bool isConnectedToSource = true);
    // boil water
    void boilWater(int burnerId, int durationInSecond);
};

/*
Thing 6) Oven
5 properties:
    1) number of racks (int)
    2) oven capacity (double)
    3) door material (std::string)
    4) number of light bulbs (int)
    5) temperature sensor type (std::string)
3 things it can do:
    1) broil
    2) bake
    3) self-clean
 */ 
struct Oven
{
    // number of racks
    int numberOfRack = 2;
    // oven capacity
    double ovenCapacity = 5.5;
    // door material
    std::string doorMaterial = "Glass";
    // number of light bulbs
    int numberOfLightBulb = 2;
    // temperature sensor type
    std::string temperatureSensorType;

    // broil
    void broil(int temperatureInFarenheit, int durationInMinute);
    // bake
    void bake(int rackId, int temperatureInFarenheit, int durationInMinute);
    // self-clean
    void selfClean();
};

/*
Thing 7) Controls
5 properties:
    1) number of burner knobs (int)
    2) clock type (std::string)
    3) number of oven cooking option (int)
    4) oven power on light color (std::string)
    5) information display size (float)
3 things it can do:
    1) adjust oven temperature
    2) change cooking timer
    3) turn on oven
 */
struct Control
{
    // number of burner knobs
    int numberOfBurnerKnob = 4;
    // clock type
    std::string clockType = "Digital";
    // number of oven cooking option
    int numberOfOvenCookingOption = 3;
    // oven power on light color
    std::string ovenPowerOnLightColor = "Orange";
    // information display size
    float infoDisplaySize;

    // adjust oven temperature
    int adjustOvenTemperature(int currentTemperature, int numberOfUpButtonClick, int numerOfDownButtonClick);
    // change cooking timer in minutes
    int changeCookingTimer(int currentTimer, int numberOfUpButtonClick, int numerOfDownButtonClick);
    // turn on oven
    void turnOnOven(bool isOvenOn = false);
};

/*
Thing 8) Range hood
5 properties:
    1) chimmney height (float)
    2) hood height (float)
    3) number of fan strength levels (int)
    4) material (std::string)
    5) light type (std::string)
3 things it can do:
    1) suck smoke
    2) light on
    3) control fan strength
 */
struct RangeHood
{
    // chimmney height
    float chimneyHeight = 30.5f;
    // hood height
    float hoodHeight = 5.0f;
    // number of fan strength levels
    int numberOfFanStrengthLevel = 5;
    // material
    std::string material = "Steel";
    // light type
    std::string lightType = "LED";

    // suck smoke
    void suckSmoke(int fanStrengthLevel);
    // light on
    void turnLightOn();
    // control fan strength
    int controlFanStrength(int currentStrengthIndicator, int numberOfCounterClockwiseTurn, int numberOfClockWiseTurn);
};

/*
Thing 9) Under stove storage
5 properties:
    1) drawer color (std::string)
    2) handle color (std::string)
    3) length of sliding rail (float)
    4) material (std::string)
    5) capacity (double)
3 things it can do:
    1) slide out
    2) slide in
    3) contain bakeware
 */
struct UnderStoveStorage
{
    // drawer color
    std::string drawerColor = "Grey";
    // handle color
    std::string handleColor = "White";
    // length of sliding rail
    float lengthOfSlidingRail;
    // material
    std::string material = "Steel";
    // capacity
    double capacity;

    // slide out
    void slideOut();
    // slide in
    void slideIn();
    // contain bakeware
    void containBakeware(std::string bakewareName = "Baking pan", bool isFull = false);
};

/*
Thing 10) Kitchen range
5 properties:
    1) Cooktop
    2) Oven
    3) Controls
    4) Range hood
    5) Under stove storage
3 things it can do:
    1) Bake food
    2) Light up
    3) Suck smoke
 */
struct KitchenRange
{
    // Cooktop
    Cooktop cookTop;
    // Oven
    Oven oven;
    // Controls
    Control panelControl;
    // Range hood
    RangeHood rangeHood;
    // Under stove storage
    UnderStoveStorage drawer;

    // Bake food
    void bakeFood(int foodId, int rackId, int temperatureInFarenheit, int durationInMinute);
    // Light up
    void lightUp(int lightIntensity = 1);
    // Suck smoke
    void ventSmoke();
};

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
