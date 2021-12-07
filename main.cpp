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
struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;

    struct Foot
    {
        int size = 3;

        int stepSize()
        {
            return size;
        }

        void stepForward()
        {
            // do something
        }
    };

    Foot leftFoot;
    Foot rightFoot;

    void run(int howFast, bool startWithLeftFoot);
};

void Person::run(int howFast, bool startWithLeftFoot)
{
    if (startWithLeftFoot == true)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }

    distanceTraveled += (leftFoot.stepSize() + rightFoot.stepSize()) * howFast; // howFast indicates ratio of stepSize in this case
}


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

void OvenStove::FoodItem::clean(std::string cleaningType)
{
    if (expirationDayRemain <= 0)
    {
        std::cout << "Expired food!" << std::endl;
        return;
    }

    std::cout << "Cleaning with " + cleaningType << std::endl;
}

void OvenStove::FoodItem::season(std::string mainCondiment)
{
    if (expirationDayRemain <= 0)
    {
        std::cout << "Expired food!" << std::endl;
        return;
    }

    if (isSeasoned == false)
    {
        std::cout << "Season with " + mainCondiment << std::endl;
        isSeasoned = true;
    }

}

void OvenStove::FoodItem::cut(int numberOfPortion, std::string tool)
{
    if (expirationDayRemain <= 0)
    {
        std::cout << "Expired food!" << std::endl;
        return;
    }

    if (numberOfPortion > 1)
    {
        std::cout << "Cut the food into " 
                + std::to_string(numberOfPortion) 
                + " with " 
                + tool 
                << std::endl;
    }
    else
    {
        std::cout << "Do nothing" << std::endl;
    }
}

void OvenStove::broilFood(OvenStove::FoodItem food, int temperature, int durationInMinute)
{
    std::cout << "Broiling " + food.name 
                    + " at " + std::to_string(temperature) + "F"
                    + " in " + std::to_string(durationInMinute) + "minutes";
}

void bakeFood(OvenStove::FoodItem food, int temperature, int durationInMinute, int rackId, bool preHeat)
{
    if (rackId < 0)
    {
        std::cout << "ERROR!" << std::endl;
        return;
    }

    if (preHeat == false)
    {
        std::cout << "Please pre heat oven before start!" << std::endl;
        return;
    }

    std::cout << "Baking " + food.name 
                    + " at " + std::to_string(temperature) + "F"
                    + " in " + std::to_string(durationInMinute) + "minutes";
}

void lightUp(bool lightStatus)
{
    if (lightStatus == false)
    {
        std::cout << "Light ON" << std::endl;
        lightStatus = true;
    }
    else
    {
        std::cout << "Do NOTHING" << std::endl;
    }
}

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

void Laptop::connectToWifi(bool connectionStatus)
{
    if (connectionStatus == false)
    {
        connectionStatus = true;
    }
    std::cout << "You are connected to the Internet" << std::endl;
}

std::string Laptop::checkAvailableOSUpdate(int currentOSId)
{
    if (currentOSId < 10) // assume 10 is the latest OS id
    {
        return "Update version 10.";
    }

    return "Up to date!";
}

void Laptop::playAudio(int audioFileId, int volume, std::string playMode)
{
    if (audioFileId < 0 || audioFileId > 99) // assume there is 100 audio files 
    {
        return;
    }

    if (volume > 70)
    {
        std::cout << "Warning: audio too loud!" << std::endl;
    }

    std::cout << "Playing audio " + std::to_string(audioFileId) 
                + "at channel " + playMode 
                << std::endl; 
}

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

void FruitTree::produceOxygen(int currentDayTimeInHour)
{
    if (currentDayTimeInHour > 5 && currentDayTimeInHour < 18) // from 6:00 to 17:59
    {
        std::cout << "Day time!" << std::endl;
        std::cout << name << "is producing oxygen.";
    }
}

void FruitTree::absorbCarbonDioxide(int currentDayTimeInHour)
{
    if (currentDayTimeInHour > 5 && currentDayTimeInHour < 18) // from 6:00 to 17:59
    {
        std::cout << "Day time!" << std::endl;
        std::cout << name << "is absorbing carbon dioxide.";
    }
}

int FruitTree::produceFruit(std::string currentSeason)
{
    if (currentSeason == harvestSeason)
    {
        return 1000;
    }

    return 0;
}


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

    void shootPhoto(Lens currentLens, char shootingMode = 'A', bool lowLight = false);
    void recordVideo(Lens currentLens, int durationInSecond);
    void playFlash(bool lowLightIntensity = true);

    Lens includedLens;
};

void Camera::Lens::cover()
{
    // do something to cover
}

void Camera::Lens::zoom(float zoomMode)
{
    if (zoomMode < 1.0f)
    {
        std::cout << "Zoom OUT" << std::endl;
    }
    else if (zoomMode > 1.0f)
    {
        std::cout << "Zoom IN" << std::endl;
    }
    else
    {
        std::cout << "Original" << std::endl;
    }
}

void Camera::Lens::getFocus(double distanceToObject)
{
    if (distanceToObject < 1)
    {
        std::cout << "Too close. Please move further." << std:: endl;
    }
    else if (distanceToObject > 100)
    {
        std::cout << "Too far. Please move closer." << std:: endl;
    }
    else
    {
        // get focus on object
        std::cout << "Ready." << std::endl;
    }
}

void Camera::shootPhoto(Camera::Lens currentLens, char shootingMode, bool lowLight)
{
    currentLens.getFocus(50); // assume default value 50 for photo
    if (shootingMode == 'A')
    {
        std::cout << "Auto mode";
        playFlash(lowLight); // auto mode play flash if low light
    }
    else if (shootingMode == 'M')
    {
        std::cout << "Please choose shutter speed" << std::endl;
        std::cout << "Flash option";
    }
}

void Camera::recordVideo(Camera::Lens currentLens, int durationInSecond)
{
    currentLens.getFocus(70); // assume default value 70 for video
    std::cout << "Recording..." << std::endl;
    // record video
    std::cout << "Duration: " + std::to_string(durationInSecond) + " Seconds"; 
}

void Camera::playFlash(bool lowLightIntensity)
{
    if (lowLightIntensity == true)
    {
        // turn on Flash
    }
}


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

void Cooktop::burnFood()
{
    std::cout << "Warning: Hot surface.";
}

double Cooktop::consumeElectric(bool isConnectedToSource)
{
    if (isConnectedToSource)
    {
        return 120; //assume value
    }
    return 0;
}

void Cooktop::boilWater(int burnerId, int durationInSecond)
{
    if (burnerId < 0 || burnerId >= numberOfBurner) 
    {
        return;
    }
    std::cout << "Boiling water at burner no." + std::to_string(burnerId)
                + " in " + std::to_string(durationInSecond) + " seconds.";
}


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

void Oven::broil(int temperatureInFarenheit, int durationInMinute)
{
    std::cout << "Broiling in " + std::to_string(durationInMinute) 
                    + " at " + std::to_string(temperatureInFarenheit) + "F";
}

void Oven::bake(int rackId, int temperatureInFarenheit, int durationInMinute)
{
    if (rackId < 0 || rackId >= numberOfRack)
    {
        return;
    } 
    if (durationInMinute > 300)
    {
        std::cout << "Warning: Too long. Might need to shorten time.";
    }
    if (temperatureInFarenheit > 450)
    {
        std::cout << "Max temperature.";
        temperatureInFarenheit = 450;
    }
    std::cout << "Baking at " + std::to_string(temperatureInFarenheit)+ "F ...";
}

void Oven::selfClean()
{
    std::cout << "Self-cleaning...";
}


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

int Control::adjustOvenTemperature(int currentTemperature, int numberOfUpButtonClick, int numberOfDownButtonClick)
{
    return (currentTemperature + 5 * (numberOfUpButtonClick - numberOfDownButtonClick)); // up and down in the unit of 5 degree
}

int Control::changeCookingTimer(int currentTimer, int numberOfUpButtonClick, int numberOfDownButtonClick)
{
    return (currentTimer + numberOfUpButtonClick - numberOfDownButtonClick);
}

void Control::turnOnOven(bool isOvenOn)
{
    if (isOvenOn == false)
    {
        std::cout << "Turning on...";
        ovenPowerOnLightColor = "Orange";
    }
}


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

void RangeHood::suckSmoke(int fanStrengthLevel)
{
    if (fanStrengthLevel < (numberOfFanStrengthLevel - 1)) // from 0 to number of level
    {
        std::cout << "Fan is ON.";
    }
}

void RangeHood::turnLightOn()
{
    std::cout << "Light is ON.";
}

int RangeHood::controlFanStrength(int currentStrengthIndicator, int numberOfCounterClockwiseTurn, int numberOfClockWiseTurn)
{
    if (currentStrengthIndicator == 0)
    {
        return (currentStrengthIndicator + numberOfClockWiseTurn);
    }
    if (currentStrengthIndicator == numberOfFanStrengthLevel - 1)
    {
        return (currentStrengthIndicator - numberOfCounterClockwiseTurn);
    }
    return (currentStrengthIndicator - numberOfCounterClockwiseTurn + numberOfClockWiseTurn);
}


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

void UnderStoveStorage::slideOut()
{
    std::cout << "Sliding out.";
}

void UnderStoveStorage::slideIn()
{
    std::cout << "Sliding in.";
}

void UnderStoveStorage::containBakeware(std::string bakewareName, bool isFull)
{
    if (isFull == true)
    {
        return;
    }
    std::cout << "Put " + bakewareName + "in.";
}



struct KitchenRange
{
    Cooktop cookTop;
    Oven oven;
    Control panelControl;
    RangeHood rangeHood;
    UnderStoveStorage drawer;

    void bakeFood(int foodId, int rackId, int temperatureInFarenheit, int durationInMinute);
    void lightUp();
    void ventSmoke();
};

void KitchenRange::bakeFood(int foodId, int rackId, int temperatureInFarenheit, int durationInMinute)
{
    if (foodId < 0 || foodId > 9) // assume only have 10 food items
    {
        return;
    }
    std::cout << "Start baking food item " + std::to_string(foodId) + " now."<< std::endl;
    oven.bake(rackId, temperatureInFarenheit, durationInMinute);
}

void KitchenRange::lightUp()
{
    rangeHood.turnLightOn();
}

void KitchenRange::ventSmoke()
{
    rangeHood.suckSmoke(1); // default of fan strength level is 1
}

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
