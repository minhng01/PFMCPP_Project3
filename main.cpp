/*
Project 3 - Part 1c / 5
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

1) write the 10th UDT
    come up with an object that is made of 5 smaller parts.
    These parts will not be defined using Primitives, but instead will be their own UDTs you'll define in Part 1d
    
    Here is an example:
    Cell Phone

    A Cell Phone is made up of the following 5 properties:
        Display
        Memory
        CPU
        Radio
        Applications

    A Cell Phone has 3 things it can do:
        make a call
        send a text
        run an application.

    Notice that I did not use "has a display" or "Has memory" or "has a cpu" as one of the properties of the CellPhone
    
    Writing 'has a ___" checks whether or not your object **has the ability to do something**.
    Instead, I wrote "Display" or "CPU".  These are specific objects or amounts. 
    
    In C++ terms, this means to I want you to avoid using 'bool' (has a) as a member variable type.
    Instead, prefer the other primitive types.

    When you choose your 5 smaller parts, remember that each of these 5 Sub Objects will need 
    to be defined with 5 primitive properties and 3 actions EACH.  

2) write the name of the primitive type you'll be using after each property in UDTs 1-4:
    pick properties that can be represented with 'int float double bool char std::string'
    example: 
        Display:
            Number of Pixels (int)
            Amount of Power consumed (milliwatt-hours) (float)
            Brightness (double)
            area in cm2 (int)
            brand (std::string)

3) Move the Thing 10 pseudo-code to after your Thing1-4 in the project.
*/

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
