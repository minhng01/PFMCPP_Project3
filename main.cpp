 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
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
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have warnings about 'unused parameter', you aren't using one of your function parameters in your implementation.
    use the parameter in your implementation.
    If you have warnings about 'overshadow', a local variable in the function has the same name as a class member.
    change the name of your local variable so it is different from the class member's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */





struct OvenStove
{
    std::string brandName = "GE";
    int numberOfBurner = 4;
    int numberOfRack = 2;
    float ovenCapacity = 5.0f;
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

    void broilFood(FoodItem food, int temperature, int durationInMinute);
    void bakeFood(FoodItem food, int temperature, int durationInMinute, int rackId, bool preHeat);
    void lightUp(bool lightStatus);

    FoodItem mainIngredient;
};

struct Laptop
{
    std::string modelName = "Thinkpad";
    float screenDisplay = 15.6f;
    int RAMSize = 32;
    int storageSize = 2000;
    float weight = 6.2f;

    void connectToWifi(bool connectionStatus = false);
    std::string checkAvailableOSUpdate(int currentOSId);
    void playAudio(int audioFileId = 0, int volume = 50, std::string playMode = "Headphones");
};

struct FruitTree
{
    std::string name = "Apple Tree";
    float height = 10.5f;
    double barkThicknessDiameter = 2.456;
    std::string fruitColor = "Red";
    std::string harvestSeason = "September";

    void produceOxygen(int currentDayTimeInHour = 7);
    void absorbCarbonDioxide(int currentDayTimeInHour = 21);
    int produceFruit(std::string currentSeason = "December");
};

struct Camera
{
    std::string brandName = "Canon";
    float resolution = 26.7f;
    int numberOfShootingMode = 5;
    int numberOfWhiteBalanceMode = 5;
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

    void shootPhoto(Lens currentLens, char shootingMode = 'A');
    void recordVideo(Lens currentLens, int durationInSecond);
    void playFlash(bool lowLightIntensity = true);

    Lens includedLens;
};

struct Cooktop
{
    int numberOfBurner = 4;
    std::string surfaceMaterial = "Stainless steel";
    int cooktopVoltageRequirement = 120;
    float width;
    float depth;

    void burnFood();
    double consumeElectric(bool isConnectedToSource = true);
    void boilWater(int burnerId, int durationInSecond);
};

struct Oven
{
    int numberOfRack = 2;
    double ovenCapacity = 5.5;
    std::string doorMaterial = "Glass";
    int numberOfLightBulb = 2;
    std::string temperatureSensorType;

    void broil(int temperatureInFarenheit, int durationInMinute);
    void bake(int rackId, int temperatureInFarenheit, int durationInMinute);
    void selfClean();
};

struct Control
{
    int numberOfBurnerKnob = 4;
    std::string clockType = "Digital";
    int numberOfOvenCookingOption = 3;
    std::string ovenPowerOnLightColor = "Orange";
    float infoDisplaySize;

    int adjustOvenTemperature(int currentTemperature, int numberOfUpButtonClick, int numerOfDownButtonClick);
    int changeCookingTimer(int currentTimer, int numberOfUpButtonClick, int numerOfDownButtonClick);
    void turnOnOven(bool isOvenOn = false);
};

struct RangeHood
{
    float chimneyHeight = 30.5f;
    float hoodHeight = 5.0f;
    int numberOfFanStrengthLevel = 5;
    std::string material = "Steel";
    std::string lightType = "LED";

    void suckSmoke(int fanStrengthLevel);
    void turnLightOn();
    int controlFanStrength(int currentStrengthIndicator, int numberOfCounterClockwiseTurn, int numberOfClockWiseTurn);
};

struct UnderStoveStorage
{
    std::string drawerColor = "Grey";
    std::string handleColor = "White";
    float lengthOfSlidingRail;
    std::string material = "Steel";
    double capacity;

    void slideOut();
    void slideIn();
    void containBakeware(std::string bakewareName = "Baking pan", bool isFull = false);
};

struct KitchenRange
{
    Cooktop cookTop;
    Oven oven;
    Control panelControl;
    RangeHood rangeHood;
    UnderStoveStorage drawer;

    void bakeFood(int foodId, int rackId, int temperatureInFarenheit, int durationInMinute);
    void lightUp(int lightIntensity = 1);
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
