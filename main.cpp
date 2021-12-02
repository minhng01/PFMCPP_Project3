/*
Project 3 - Part 1d / 5
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

    The goal of this step is to get you to think about breaking down an object into smaller and smaller objects, 
    until the smallest object is made of up only C++ primitives and std::string. 

    Continuing the previous example:  Cell Phone

    A Cell Phone is made up of the following 5 properties/sub-objects and 3 actions:
        Display
        Memory
        CPU
        Radio
        Applications
    3 actions:
        make a call
        send a text
        run an application.

    These 5 properties can be broken down into their own sub-objects and properties. 

    If we break down the first property 'Display' into its 5 properties we get:
        brightness
        amount of power consumed.
        pixels
        width in cm
        height in cm

    the Display's brightness can be represented with a Primitive, such as a double. 

    The amount of power consumed can also be represented with a Primitive, such as a float or integer (i.e. 250mWa)
    
    The 'pixels' property must be represented with an array of Pixel instances, as the screen has more than 1 row of pixels.
        Arrays have not been discussed and can't be used in this project.
        Instead, we can use an Integer primitive to store the Number of Pixels:

    Display:
        Number of Pixels
        Amount of Power consumed (milliwatt-hours)
        Brightness
        width in cm
        height in cm
************************

1) Fill in #5 - #9 with plain-english UDTs for the 5 properties you created for UDT #10
    example: 
        If #10's first property was 'Engine', then your `Thing 5)` will be `Engine`
        you will need to provide 5 properties and 3 member functions of that Engine object in plain English
        Remember to pick properties that can be represented with 'int float double bool char std::string'
2) write the name of the primitive type you'll be using after each property
    pick properties that can be represented with 'int float double bool char std::string'
    example: 
        Display:
            Number of Pixels (int)
            Amount of Power consumed (milliwatt-hours) (float)
            Brightness (double)
            width in cm (int)
            height in cm (int)

3) move Thing 5-9 to between your Thing 4 and Thing 10.
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
