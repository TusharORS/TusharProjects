# TusharProjects
Working on one of the Assignment for Target , the requirement is as below 

You have a farm of 400m by 600m where coordinates of the field are from (0, 0) to (399, 599). A portion of the farm is barren, and all the barren land is in the form of rectangles. Due to these rectangles of barren land, the remaining area of fertile land is in no particular shape. An area of fertile land is defined as the largest area of land that is not covered by any of the rectangles of barren land. Read input from STDIN. Print output to STDOUT Input You are given a set of rectangles that contain the barren land. These rectangles are defined in a string, which consists of four integers separated by single spaces, with no additional spaces in the string. Thefirst two integers are the coordinates of the bottom left corner in the given rectangle, and the last two integers are the coordinates of the top right corner. Output Output all the fertile land area in square meters, sorted from smallest area to greatest, separated by a space.

SampleTest1
-----------
input  {“0 292 399 307”} 
oputput 116800  116800

SampleTest2
-----------
input {“48 192 351 207”, “48 392 351 407”, “120 52 135 547”, “260 52 275 547”} 
output 22816 192608

Description :

Compile main.cpp - it will add all dependent file and compile them

How to run the program to find fertile land in Ascending order : 
------------------------------------------------------------------
CFarm farm;
farm.showBarrenLand();

1) This will accept input from user 
2) Parse the input
3) If there is any error in the input will throw error and exit app. 
   Note : Input should be intergers 
          Inputs should be in multiple of 4
          Enter in the order "Bottom left Top right"
          Condition : 0 <= left < right < 600    &&     0 < bottom < top < 400  
          {},"". can be added as delimeter , which will be considered as separator and will be ignored
          If input is invalid : Exception will be shown in UI and code will exit.
          If input is correct , code will find out the barren land and display the same in UI in ascending order , with time taken to    execute the order
          

How to run the integration test :
------------------------------------
CFarm farm1;
farm1.runTestSuite1();   // Will take input as SampleTest1 and check whether the output is expected. 

CFarm farm2;
farm2.runTestSuite2();   // Will take input as SampleTest2 and check whether the output is expected. 

If those test cases passes, user can see the same in UI else he will get error.



          
          
