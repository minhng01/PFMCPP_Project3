/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            bar.num += 1;                    //2a)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()






struct OvenStove
{
    std::string brandName;
    int numberOfBurner;
    int numberOfRack;
    float ovenCapacity;
    int warrantyDuration;

    struct FoodItem
    {
        std::string type;
        std::string name;
        float weight;
        bool isSeasoned;
        int expirationDayRemain;

        FoodItem();

        void storeInFridge(int dayRemain, int expirationDuration);
        void clean(std::string cleaningType = "Salted water");
        void season(std::string mainCondiment = "Pepper");
        void cut(int numberOfPortion = 3, std::string tool = "Long knife");
    };

    OvenStove();

    void cookFoodOnBurner(int threshold, int numberOfAvailableBurner);
    void broilFood(FoodItem food, int temperature, int durationInMinute);
    void bakeFood(FoodItem food, int temperature, int durationInMinute, int rackId, bool preHeat);
    void lightUp(bool lightStatus);

    FoodItem mainIngredient;
};

OvenStove::OvenStove() : brandName("GE"),
                        numberOfBurner(4),
                        numberOfRack(2),
                        ovenCapacity(5.0f),
                        warrantyDuration(12)
{
    std::cout << "----------constructing OvenStove----------" << "\n";
}

OvenStove::FoodItem::FoodItem() : type("Poultry"),
                                name("Chicken breast"),
                                weight(1.0f),
                                isSeasoned(false),
                                expirationDayRemain(7)
{
    std::cout << "----------constructing FoodItem----------" << "\n";
}

void OvenStove::FoodItem::storeInFridge(int threshold, int expirationDuration){
    expirationDayRemain = expirationDuration;
    
    while (expirationDayRemain > threshold)
    {
        std::cout << "There are " << expirationDayRemain << " days till expired. Keep in fridge.\n";
        expirationDayRemain--;
        
        if (expirationDayRemain <= threshold)
        {
            std::cout << "WARNING: Food is expired soon.\n";
            return;
        }
    }
}

void OvenStove::FoodItem::clean(std::string cleaningType)
{
    if (expirationDayRemain <= 0)
    {
        std::cout << "Expired food!" << std::endl;
        return;
    }

    std::cout << "Days till expiration date: " << expirationDayRemain << "\n";

    std::cout << "Cleaning with " + cleaningType << std::endl;
}

void OvenStove::FoodItem::season(std::string mainCondiment)
{
    if (expirationDayRemain <= 0)
    {
        std::cout << "Expired food!" << std::endl;
        return;
    }

    std::cout << "Days till expiration date: " << expirationDayRemain << "\n"; 

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

    std::cout << "Days till expiration date: " << expirationDayRemain << "\n";

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

void OvenStove::cookFoodOnBurner(int threshold, int totalBurner)
{
    numberOfBurner = totalBurner;
    
    while (numberOfBurner > threshold)
    {
        std::cout << "Cook food on burner no." << numberOfBurner << std::endl;
        numberOfBurner--;
        if (numberOfBurner <= threshold)
        {
            std::cout << "No burner left to cook food.\n";
            return;
        }
    }
}

void OvenStove::broilFood(OvenStove::FoodItem food, int temperature, int durationInMinute)
{
    std::cout << "Broiling " + food.name 
                    + " at " + std::to_string(temperature) + "F"
                    + " in " + std::to_string(durationInMinute) + " minutes" + "\n";
}

void OvenStove::bakeFood(OvenStove::FoodItem food, int temperature, int durationInMinute, int rackId, bool preHeat)
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
                    + " in " + std::to_string(durationInMinute) + " minutes" + "\n";
}

void OvenStove::lightUp(bool lightStatus)
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
    std::string modelName;
    float screenDisplay;
    int RAMSize;
    int storageSize;
    float weight;

    Laptop();

    int numberOfFileOnDisk(int eachFileSize, int storageSizeLeft, int storageForOS, int maxNumOfFile);
    void connectToWifi(bool connectionStatus = false);
    std::string checkAvailableOSUpdate(int currentOSId);
    void playAudio(int audioFileId = 0, int volume = 50, std::string playMode = "Headphones");
};

Laptop::Laptop() : modelName("Thinkpad"),
                screenDisplay(15.6f),
                RAMSize(32),
                storageSize(2000),
                weight(6.2f)
{
    std::cout << "----------constructing Laptop----------" << "\n";
}

int Laptop::numberOfFileOnDisk(int eachFileSize, int availableDiskStorage, int storageForOS, int maxNumOfFile)
{
    storageSize = availableDiskStorage;
    
    std::cout << "There is " << availableDiskStorage << "GB storage in total.\n";
    std::cout << "How many " << eachFileSize << "GB files that can be stored given that " 
                << storageForOS << " GB should be left for system operation and only "
                << maxNumOfFile << " maximum files that can be stored?\n";
    
    int numberOfFile = 0;
    for (int i = 1; i <= ((availableDiskStorage - storageForOS) / eachFileSize); i++)
    {
        if (i > maxNumOfFile)
            return numberOfFile;

        storageSize -= eachFileSize;
        numberOfFile = i;
        std::cout << "Store file no." << i << ". Available storage left: " << storageSize << std::endl;
    }

    return numberOfFile;
}

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
    std::cout << "Storage size: " << storageSize << "GB\n";
    if (currentOSId < 10) // assume 10 is the latest OS id
    {
        return "Available update: Update OS version 10 \n";
    }

    return "OS up to date! \n";
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

    std::cout << "Playing audio file number " + std::to_string(audioFileId) 
                + " in mode: " + playMode 
                << std::endl; 
}

struct FruitTree
{    
    std::string name;
    float height;
    double barkThicknessDiameter;
    std::string fruitColor;
    std::string harvestSeason;

    FruitTree();

    double treeGrowTrack(int currentAge, int lifeSpan, double maxSize);
    void produceOxygen(int currentDayTimeInHour = 7);
    void absorbCarbonDioxide(int currentDayTimeInHour = 21);
    int produceFruit(std::string currentSeason = "December");
};

FruitTree::FruitTree() : name("Apple Tree"),
                        height(10.5f),
                        barkThicknessDiameter(2.456),
                        fruitColor("Red"),
                        harvestSeason("September")
{
    std::cout << "----------constructing FruitTree----------" << "\n";
}

double FruitTree::treeGrowTrack(int currentAge, int lifeSpan, double maxSize)
{
    std::cout << "Current age: " << currentAge << "\n";
    std::cout << "Current barkThicknessDiameter: " << barkThicknessDiameter << "\n";
    std::cout << "Max life span (year): " << lifeSpan << "\n";

    for (int i = currentAge; i <= lifeSpan; i++)
    {
        if ((barkThicknessDiameter + 0.5) > maxSize)
            return barkThicknessDiameter;
        
        barkThicknessDiameter += 0.5;
        std::cout << "Age: " << i << ". barkThicknessDiameter: " << barkThicknessDiameter << "\n";
    }
    
    return barkThicknessDiameter;
}

void FruitTree::produceOxygen(int currentDayTimeInHour)
{
    if (currentDayTimeInHour > 5 && currentDayTimeInHour < 18) // from 6:00 to 17:59
    {
        std::cout << "Day time! ";
        std::cout << name << " is producing oxygen \n" ;
    }
}

void FruitTree::absorbCarbonDioxide(int currentDayTimeInHour)
{
    if (currentDayTimeInHour > 5 && currentDayTimeInHour < 18) // from 6:00 to 17:59
    {
        std::cout << "Day time! ";
        std::cout << name << " is absorbing carbon dioxide \n";
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
    int currentWhiteBalanceMode = 1;
    float weight = 2.2f;

    struct Lens
    {
        std::string model = "Canon EF-S";
        int maxFocalLengthInMM = 300;
        int minFocalLengthInMM = 55;
        int currentFocalLengthInMM = 150;
        int filterDiameterInMM = 58;
        float weightInOz = 13.2f;
        
        Lens();
        
        void adjustFocalLength(int target);
        void cover();
        void zoom(float zoomMode = 1.0f);
        void getFocus(double distanceToObject);
    };

    Camera();
    
    void adjustWhiteBalanceMode(int target);
    void shootPhoto(Lens currentLens, char shootingMode = 'A', bool lowLight = false);
    void recordVideo(Lens currentLens, int durationInSecond);
    void playFlash(bool lowLightIntensity = true);

    Lens includedLens;
};

Camera::Lens::Lens()
{
    std::cout << "----------constructing Lens----------" << "\n";
}

Camera::Camera()
{
    std::cout << "----------constructing Camera----------" << "\n";
}

void Camera::Lens::adjustFocalLength(int target)
{
    while (currentFocalLengthInMM != target) //adjust in step of 5 unit. Assuming the focal length is product of 5
    {
        if (currentFocalLengthInMM >= maxFocalLengthInMM)
        {
            currentFocalLengthInMM =  maxFocalLengthInMM;
            return;
        }
        
        if (currentFocalLengthInMM <= minFocalLengthInMM)
        {
            currentFocalLengthInMM =  minFocalLengthInMM;
            return;
        }

        if (currentFocalLengthInMM < target)
        {   
            std::cout << "Increased current focal length: " << currentFocalLengthInMM << std::endl;
            currentFocalLengthInMM += 5;
        }
        else if (currentFocalLengthInMM > target)
        {
            std::cout << "Increased current focal length: " << currentFocalLengthInMM << std::endl;
            currentFocalLengthInMM -= 5;
        }
    }

    std::cout << "Current focal length: " << currentFocalLengthInMM << "\n";
}

void Camera::Lens::cover()
{
    std::cout << model << ": covering lens..." << "\n";
}

void Camera::Lens::zoom(float zoomMode)
{
    std::cout << "Focal length: " << minFocalLengthInMM << "mm-" << maxFocalLengthInMM << "mm\n";

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
        std::cout << "Focus ready..." << std::endl;
    }
}

void Camera::adjustWhiteBalanceMode(int target)
{
    while (currentWhiteBalanceMode != target) //adjust in step of 5 unit. Assuming the focal length is product of 5
    {
        if (currentWhiteBalanceMode >= numberOfWhiteBalanceMode)
        {
            currentWhiteBalanceMode = numberOfWhiteBalanceMode;
            return;
        }
        
        if (currentWhiteBalanceMode < 1)
        {
            currentWhiteBalanceMode = 1;
            return;
        }

        if (currentWhiteBalanceMode < target)
        {   
            std::cout << "Current white balance mode: " << currentWhiteBalanceMode << std::endl;
            currentWhiteBalanceMode++;
        }
        else if (currentWhiteBalanceMode > target)
        {
            std::cout << "Current white balance mode: " << currentWhiteBalanceMode << std::endl;
            currentWhiteBalanceMode--;
        }
    }

    std::cout << "Current white balance mode: " << currentWhiteBalanceMode << "\n";
}

void Camera::shootPhoto(Camera::Lens currentLens, char shootingMode, bool lowLight)
{
    currentLens.getFocus(50); // assume default value 50 for photo
    
    std::cout << "Resolution: " << resolution << "px\n";

    if (shootingMode == 'A')
    {
        std::cout << "Taking photo in auto mode \n";
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
    std::cout << "Recording...";
    // record video
    std::cout << " duration: " + std::to_string(durationInSecond) + " seconds \n"; 
}

void Camera::playFlash(bool lowLightIntensity)
{
    if (lowLightIntensity == true)
    {
        std::cout << "Playing flash..." << "\n";
    }
}


struct Cooktop
{
    int numberOfBurner;
    int numberOfBurnerInUse;
    std::string surfaceMaterial;
    int cooktopVoltageRequirement;
    float width;
    float depth;
    
    Cooktop();
    
    void turnOnBurner(int target);
    void burnFood();
    double consumeElectric(bool isConnectedToSource = true);
    void boilWater(int burnerId, int durationInSecond);
};

Cooktop::Cooktop() : numberOfBurner(4),
                    numberOfBurnerInUse(0),
                    surfaceMaterial("Stainless steel"),
                    cooktopVoltageRequirement(120),
                    width(30.0f),
                    depth(25.0f)
{
    std::cout << "----------constructing Cooktop----------" << "\n";
}

void Cooktop::turnOnBurner(int target)
{
    std::cout << "Number of burners in use: " << numberOfBurnerInUse << std::endl;
    for (int i = numberOfBurnerInUse; i <= target; i++)
    {
        std::cout << i << " burner is turned on/in use.\n";
        
        if (i > numberOfBurner || i > target)    
            return;

        numberOfBurnerInUse = i;
    }
}

void Cooktop::burnFood()
{
    std::cout << "Warning: Hot surface! \n";
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
    std::cout << "Total number of burners: " << numberOfBurner;
    std::cout << ". Boiling water at burner no." + std::to_string(burnerId)
                + " in " + std::to_string(durationInSecond) + " seconds \n";
}


struct Oven
{
    int numberOfRack;
    double ovenCapacity;
    std::string doorMaterial;
    int numberOfLightBulb;
    std::string temperatureSensorType;

    Oven();

    void turnOnLight(int target);
    void broil(int temperatureInFarenheit, int durationInMinute);
    void bake(int rackId, int temperatureInFarenheit, int durationInMinute);
    void selfClean();
};

Oven::Oven() : numberOfRack(2),
            ovenCapacity(5.5),
            doorMaterial("Glass"),
            numberOfLightBulb(2),
            temperatureSensorType("Thermocouple")
{
    std::cout << "----------constructing Oven----------" << "\n";
}

void Oven::turnOnLight(int target)
{
    int numberOfLightOn = 0;
    while (numberOfLightOn <= target && numberOfLightOn <= numberOfLightBulb)
    {
        std::cout << "Turning " << numberOfLightOn << " oven light bulbs on.\n";
        numberOfLightOn++;
    }
}

void Oven::broil(int temperatureInFarenheit, int durationInMinute)
{
    std::cout << "Broiling in " + std::to_string(durationInMinute) 
                    + " minutes at " + std::to_string(temperatureInFarenheit) + "F \n";
}

void Oven::bake(int rackId, int temperatureInFarenheit, int durationInMinute)
{
    if (rackId < 0 || rackId >= numberOfRack)
    {
        return;
    } 
    if (durationInMinute > 300)
    {
        std::cout << "Warning: Too long. Might need to shorten time. \n";
    }
    if (temperatureInFarenheit > 450)
    {
        std::cout << "Max temperature.\n";
        temperatureInFarenheit = 450;
    }

    std::cout << "Total number of racks available: " << numberOfRack << "\n";
    std::cout << "Baking at " + std::to_string(temperatureInFarenheit)+ "F ...\n";
}

void Oven::selfClean()
{
    std::cout << "Self-cleaning...\n";
}


struct Control
{
    int numberOfBurnerKnob = 4;
    int numberOfTurnedBurnerKnob = 0;
    std::string clockType = "Digital";
    int numberOfOvenCookingOption = 3;
    std::string ovenPowerOnLightColor = "Orange";
    float infoDisplaySize = 5.5f;

    Control();

    void turnBurnerKnob(int target);
    int adjustOvenTemperature(int currentTemperature, int numberOfUpButtonClick, int numerOfDownButtonClick);
    int changeCookingTimer(int currentTimer, int numberOfUpButtonClick, int numerOfDownButtonClick);
    void turnOnOven(bool isOvenOn = false);
};

Control::Control()
{
    std::cout << "----------constructing Control----------" << "\n";
}

void Control::turnBurnerKnob(int target)
{
    std::cout << "Number of knobs turned: " << numberOfTurnedBurnerKnob << std::endl;
    for (int i = numberOfTurnedBurnerKnob; i <= target; i++)
    {
        std::cout << i << " burner knobs is turned.\n";
        
        if (i > numberOfBurnerKnob || i > target)    
            return;

        numberOfTurnedBurnerKnob = i;
    }
}

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
        std::cout << "Turning on...\n";
        std::cout << "There are total of " << numberOfOvenCookingOption << " cooking options. Please choose one and cooking timer.\n";
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
    
    RangeHood();

    void turnOnFan(int target);
    void suckSmoke(int fanStrengthLevel);
    void turnLightOn();
    int controlFanStrength(int currentStrengthIndicator, int numberOfCounterClockwiseTurn, int numberOfClockWiseTurn);
};

RangeHood::RangeHood()
{
    std::cout << "----------constructing RangeHood----------" << "\n";
}

void RangeHood::turnOnFan(int targetFanLevel)
{
    int currentFanLevel = 2;
    while (currentFanLevel <= targetFanLevel && currentFanLevel <= numberOfFanStrengthLevel)
    {
        std::cout << "Adjusted current fan level: " << currentFanLevel << ".\n";
        currentFanLevel++;
    }
}

void RangeHood::suckSmoke(int fanStrengthLevel)
{
    if (fanStrengthLevel < (numberOfFanStrengthLevel - 1)) // from 0 to number of level
    {
        std::cout << "Fan is ON.\n";
        std::cout << "There are " << numberOfFanStrengthLevel << " fan levels. Please choose one. Default is 1.";
    }
}

void RangeHood::turnLightOn()
{
    std::cout << lightType << " light is ON.\n";
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
    float lengthOfSlidingRail = 20.0f;
    std::string material = "Steel";
    int capacity = 5;

    UnderStoveStorage();

    void putPanIn(int numberOfPan);
    void slideOut();
    void slideIn();
    void containBakeware(std::string bakewareName = "Baking pan", bool isFull = false);
};

UnderStoveStorage::UnderStoveStorage()
{
    std::cout << "----------constructing UnderStoveStorage----------" << "\n";
}

void UnderStoveStorage::putPanIn(int numberOfPan)
{
    for (int i = 1; i <= numberOfPan; i++)
    {
        if (capacity <= 0)
        {
            std::cout << "Storage is FULL!\n";
            capacity = 0;
            return;
        }

        std::cout << "Storing " << i << " pans in storage.\n";
        capacity--;
    }
}

void UnderStoveStorage::slideOut()
{
    std::cout << "Sliding out.\n";
}

void UnderStoveStorage::slideIn()
{
    std::cout << "Sliding in.\n";
}

void UnderStoveStorage::containBakeware(std::string bakewareName, bool isFull)
{
    if (isFull == true)
    {
        return;
    }

    std::cout << "Capacity: " << capacity << "\n";
    std::cout << "Put " + bakewareName + " in.\n";
}


struct KitchenRange
{    
    Cooktop cookTop;
    Oven oven;
    Control panelControl;
    RangeHood rangeHood;
    UnderStoveStorage drawer;

    KitchenRange();

    void cookTime(int cookTimeLeft, int notifyThreshold);
    void bakeFood(int foodId, int rackId, int temperatureInFarenheit, int durationInMinute);
    void lightUp();
    void ventSmoke();
};

KitchenRange::KitchenRange()
{
    std::cout << "----------constructing KitchenRange----------" << "\n";
}

void KitchenRange::cookTime(int cookTimeLeft, int notifyThreshold)
{
    while (cookTimeLeft >= 0)
    {
        if (cookTimeLeft == notifyThreshold)
            std::cout << "Watch out: " << cookTimeLeft << " hours left on cooking timer.\n";

        std::cout << cookTimeLeft << " hours left on cooking timer.\n";
        cookTimeLeft--;
    }
}

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
    Example::main();
    std::cout << "\n";

    OvenStove::FoodItem chicken;
    std::cout << "Food item name: " << chicken.name << "\n";
    chicken.storeInFridge(1, 5);
    std::cout << "Expiration day remain: " << chicken.expirationDayRemain << std::endl;
    chicken.clean("Water");
    chicken.season("Salt");
    chicken.cut(4, "knife");
    std::cout << "\n";

    OvenStove oldOvenStove;
    std::cout << "Oven stove brand name: " << oldOvenStove.brandName << "\n";
    oldOvenStove.cookFoodOnBurner(0, 4);
    std::cout << "Number of burner available to use: " << oldOvenStove.numberOfBurner << std::endl;
    oldOvenStove.broilFood(chicken, 375, 5);
    oldOvenStove.bakeFood(chicken, 275, 60, 0, true);
    oldOvenStove.lightUp(false);
    std::cout << "\n";

    Laptop laptop;
    std::cout << "Brand model name: " << laptop.modelName << "\n";
    std::cout << laptop.numberOfFileOnDisk(10, 200, 11, 15) << " files stored\n";
    std::cout << "Available storage left: " << laptop.storageSize << std::endl;
    laptop.connectToWifi(false);
    std::cout << laptop.checkAvailableOSUpdate(3);
    laptop.playAudio(2, 30, "Stereo speaker");
    std::cout << "\n";

    FruitTree appleTree;
    std::cout << "Harvest season: " << appleTree.harvestSeason << "\n";
    appleTree.treeGrowTrack(1, 2, 5);
    appleTree.produceOxygen(10);
    appleTree.absorbCarbonDioxide(10);
    std::cout << "Number of fruits tree produced: " << appleTree.produceFruit("September") << "\n";
    std::cout << "\n";

    Camera::Lens myLens;
    std::cout << "Lens model: " << myLens.model << "\n";
    myLens.adjustFocalLength(180);
    myLens.cover();
    myLens.zoom(0.5f);
    myLens.getFocus(50);
    std::cout << "\n";

    Camera camera;
    std::cout << "Camera brand name: " << camera.brandName << "\n";
    camera.adjustWhiteBalanceMode(3);
    camera.shootPhoto(myLens, 'A', false);
    camera.recordVideo(myLens, 40);
    camera.playFlash(true);
    std::cout << "\n";

    Cooktop cooktop;
    std::cout << "Number of burners: " << cooktop.numberOfBurner << "\n";
    cooktop.turnOnBurner(3);
    std::cout << "Number of burners in use: " << cooktop.numberOfBurnerInUse << "\n";
    cooktop.burnFood();
    std::cout << "Electric: " << cooktop.consumeElectric() << "\n";
    cooktop.boilWater(2, 20);
    std::cout << "\n";

    Oven oven;
    std::cout << "Number of racks: " << oven.numberOfRack << "\n";
    oven.turnOnLight(2);
    oven.broil(400, 3);
    oven.bake(1, 300, 120);
    oven.selfClean();
    std::cout << "\n";

    Control rangeControl;
    std::cout << "Clock type: " << rangeControl.clockType << "\n";
    rangeControl.turnBurnerKnob(3);
    std::cout << "Number of burner knobs turned: " << rangeControl.numberOfTurnedBurnerKnob << "\n";
    std::cout << "Adjusted oven temperature: " << rangeControl.adjustOvenTemperature(300, 10, 0) << "\n";
    std::cout << "Cooking timer: " << rangeControl.changeCookingTimer(30, 2, 1) << "\n";
    rangeControl.turnOnOven(false);
    std::cout << "\n";

    RangeHood rangeHood;
    std::cout << "Material: " << rangeHood.material << "\n";
    rangeHood.suckSmoke(2);
    std::cout << "\n";
    rangeHood.turnLightOn();
    std::cout << "Fan strength: " << rangeHood.controlFanStrength(2, 0, 0) << "\n";
    rangeHood.turnOnFan(5);
    std::cout << "\n";

    UnderStoveStorage drawer;
    std::cout << "Drawer handle color: " << drawer.handleColor << "\n";
    drawer.slideOut();
    drawer.slideIn();
    drawer.containBakeware("Pan", false);
    drawer.putPanIn(3);
    std::cout << "Capacity left: " << drawer.capacity << "\n";

    KitchenRange kitchenRange;
    kitchenRange.bakeFood(1, 1, 350, 80);
    kitchenRange.lightUp();
    kitchenRange.ventSmoke();
    kitchenRange.cookTime(5, 1);
    std::cout << "\n";

    std::cout << "good to go!" << std::endl;
}
