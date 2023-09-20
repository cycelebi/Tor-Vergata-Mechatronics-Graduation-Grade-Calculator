
[![en](https://img.shields.io/badge/lang-english-white.svg)](https://github.com/cycelebi/Tor-Vergata-Mechatronics-Graduation-Grade-Calculator/blob/main/README.md)
[![it](https://img.shields.io/badge/lang-italiano-green.svg)](https://github.com/cycelebi/Tor-Vergata-Mechatronics-Graduation-Grade-Calculator/blob/main/README.it.md)
[![tr](https://img.shields.io/badge/lang-türkçe-red.svg)](https://github.com/cycelebi/Tor-Vergata-Mechatronics-Graduation-Grade-Calculator/blob/main/README.tr.md)
[![ru](https://img.shields.io/badge/lang-русский-blue.svg)](https://github.com/cycelebi/Tor-Vergata-Mechatronics-Graduation-Grade-Calculator/blob/main/README.ru.md)


# Tor Vergata Mechatronics Engineering Graduation Grade Calculator

## Introduction

This C programming project was developed by Mehmet Celebi for the VLSI Circuit Systems Design course at the University of Rome "Tor Vergata". The project focuses on creating a program that allows users to enter and calculate grades and credits for their courses, as well as determine their graduation status.

## Program Structure

The program is structured as follows:

-   The program starts by including the necessary library, `stdio.h`, for standard input and output.
-   The program defines a structure called `Course`, which represents a course and contains attributes such as the course name, credit hours (CFU), grade, and lode status.
-   The main function initializes variables and an array of structures to store course information.
-   The program enters a while loop to gather information about each course from the user. The loop allows the user to add or delete courses as needed.
-   Inside the loop, the program prompts the user to enter the course name, CFU, grade, and lode status. It validates the inputs and stores them in the corresponding structure.
-   After gathering all the course information, the program calculates the total weighted grade, total CFU, and total lode bonuses.
-   The program then outputs the course details, including the course name, CFU, grade, and lode status.
-   Finally, the program calculates the weighted average grade, checks for additional bonuses, and determines the graduation status.

## Calculations and Formulas

The program performs the following calculations:

-   Weighted Grade: The program calculates the weighted grade for each course by multiplying the grade by the CFU and summing the results. The total weighted grade is then divided by the total CFU to obtain the overall weighted grade.
    
    Formula: `weightedGrade = totalGrade / totalCFU`
    
-   Lode Bonuses: The program checks for courses with 9 or 12 CFU and a lode status of 1 (with lode). It counts the number of courses meeting these criteria and grants a lode bonus accordingly.
    
-   Graduation Score: The program calculates the graduation score by multiplying the weighted average grade by a conversion factor of 110/30, adding the lode bonuses, the graduation in time status, and the thesis score (if applicable).
    
    Formula: `graduationScore = (weightedGrade * 110/30) + totalLodes + intime + thesis`
 
 - Formula obtained from [University of Rome Tor Vergata Website](http://mechatronics.uniroma2.it/wp-content/uploads/2021/02/Calculation-marks-for-the-Master.pdf). Changes may applied over time.

## Graduation Status

The program determines the graduation status based on the graduation score:

-   Cum Laude: If the graduation score is 110 or higher, the program declares the student eligible to graduate with Cum Laude.
-   Cum Laude by Board Decision: If the graduation score is between 104 and 109, the program states that the student may be eligible to graduate with Cum Laude by the decision of the Board.
-   Eligible to Graduate: If the graduation score is equal to or higher than 66, the program declares the student eligible to graduate.
-   Not Eligible to Graduate: If the graduation score is lower than 66, the program declares the student not eligible to graduate.

## Conclusion

This C programming project allows users to enter and calculate grades and credits for their courses, as well as determine their graduation status. It provides a comprehensive and efficient way to manage and evaluate academic performance.
