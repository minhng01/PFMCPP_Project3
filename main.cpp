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
