/*
Mehmet Celebi
0323916
VLSI Circuit Systems Design
C Programming Project
University of Rome "Tor Vergata"
*/


/*including necessary library
stdio.h for standard of input output library
*/
#include <stdio.h>



/* Structure is data type allows group together different variables
String implementation is failed. Since char used for name.
*/
struct Course {
    char name[100];
    int cfu;
    int grade;
    int withLode;
};

int main() {
    // index value of loop data gathering.
    int numCourses = 0;

    //courses array for Course structure. This array has size of 20
    struct Course courses[20];

    //defining variables will used in main
    int totalGrade = 0; //total obtained Grade*CFU for each course
    int totalCFU = 0; //total obtained CFU (credits)
    int totalLodes = 0; //total LodePoints - method explained below
    int nineLodes = 0; //total number of courses with 9 or 12 CFU
    int sixLodes = 0; //total number of courses with 6 CFU


    /*
    While instruction used for creating loop for gathering informations
    we use condition 1-TRUE to create endless-loop so loop can only trigger
    with user input
    */
    while (0) {

        /*
        endless loop will count numCourses (index of array) each turn and gets input
        from user for name (as char), CFU, Grade and Lode status.

        First loop has exit algorithm to allow user delete current input and
        finish entering input.

        otherwise array will end in 21th input.
        */

        printf("Enter the course name: "); //printing text to terminal
        scanf(" %s", courses[numCourses].name); //scanning inputs of user for name.
                                                //" %s" argument continues scanning until space " "  input

        printf("Enter the CFU: "); //printing text to terminal
        scanf("%d", &courses[numCourses].cfu); //" %d" format specifier for defining integer.

        while (1) {
            /* Second while loop to create another loop sequence. Since in Tor Vergata maximum score is 30
               and scores lower than 18 is not written to the system. If user tries to enter these values
               program will give output and ask user to enter again.
            */
            printf("Enter the grade: "); //printing text to terminal
            scanf("%d", &courses[numCourses].grade); // format specifier for integers

            if (courses[numCourses].grade >= 18 && courses[numCourses].grade <= 30) {
                //if grade is in normal range. we break while loop to continue program.
                break;
            }  else if (courses[numCourses].grade < 18) { // lower than 18
                printf("Not Passed \\n");
            }
            else { // since there is no other option. we use else command to specify other errors.
                printf("Invalid grade input. Please enter a grade between 1 and 30.\\n");
            }
        }

        if (courses[numCourses].grade == 30) { // e Lode is honour system if student have extraordinary performance.
            // e Lode is given only with 30 points so we add this condition to decrease unnecessary input requests.
            printf("Enter 1 if with Lode (Honour), 0 otherwise: "); // we used integer since we will have arithmetic
            scanf("%d", &courses[numCourses].withLode);             // operation after.
        }

        numCourses++;
        /*While loop preferred rather than for loop since counter increase and decrease instructions can be given in
        anywhere of the code*/


        /*
        algorithm for deleting current course.
        Resetting structure variable did not preferred since scanf instruction directly access to memory
        & notation in scanf retrieves memory address and directly changes data itself than having
        reference from memory.
        */
        char deleteCourse;
        printf("Would you like to delete the last course added? (y/n): ");
        scanf(" %c", &deleteCourse); //%c format specifier defines character.
        if (deleteCourse == 'y' || deleteCourse == 'Y') { //when user presses y or Y in keyboard
            numCourses--; //index number was increased in line 90 but now it returned current phase
        }                 //in next iteration same index value will be processed

        /*
        algorithm for exiting loop.
        Same approach with deleting algorithm.
        */
        char moreCourses;
        printf("Add another course? (y/n): ");
        scanf(" %c", &moreCourses); // direct access to memory with &
        if (moreCourses != 'y' && moreCourses != 'Y') {
            break; // breaks the main loop
        }
    }

    printf("All notes entered: \n");

    for (int i = 0; i < numCourses; i++) { //prints all courses between 0 to last numCourses
        // since we are no longer changing data of array. Direct access & is no longer needed.
        // We can process our values with reference from memory
        printf("Course Name: %s     || ", courses[i].name);
        printf("CFU: %d     || ", courses[i].cfu);
        printf("Grade: %d   || ", courses[i].grade);

        // only prints Lode if grade is 30 to avoid lost data and clearer terminal
        if (courses[i].grade == 30) {
            printf("With Lode: %s ", courses[i].withLode ? "e Lode" : " ");
        }

        //summing CFU and total weighted grade of each course
        totalCFU = totalCFU + courses[i].cfu;
        totalGrade = totalGrade + (courses[i].cfu*courses[i].grade);

        printf("\n"); //prints new line

    }
    //we use float since weighted grade can be decimal.

    // Weighted Grade = Sum of (grade*CFU of each class) / total CFU
    float weightedGrade = (float)totalGrade / totalCFU; // converts grade to float since it is integer
    printf("Weighted Grade: %.4f \n", weightedGrade); //%.2f prints float as .XX format

    /*
    Tor Vergata Mechatronics Engineering Department gives 2 extra point for graduation score for following criteria
    1 point for one 9 CFU OR 12 CFU.
    1 point for two 6 CFU
    Each point can be obtained once to total two point maximum.
    */

    for (int i = 0; i < numCourses; i++) { //runs each cell of array until final one
        if ((courses[i].cfu == 9 || courses[i].cfu == 12) && courses[i].withLode == 1) {
            // searches for credits 9 OR (||) 12 CFU with withLode argument 1
            nineLodes++; //counts each time condition success
            if (nineLodes == 1){ // catches 1st Lode possible
                totalLodes++; // increases total lode 1. We use increasing count rather than assign since we use this argument below also
            }
        }
        if ((courses[i].cfu == 6) && courses[i].withLode == 1) {
            // searches for credits with 6 CFU with withLode argument 1
            sixLodes++;
            if (sixLodes == 2){// condition is TWO 6 CFU with lode.
                totalLodes++; // increases total lode 1. so if there is also 9 CFU Lode. total will be maximum 2
            }
        }
    }

    // argument for calculating how much CFU is needed to graduate
    int neededCFU = 0;
    //Total CFU of Mechatronics is 120. Subtracting taken CFU's gives us required CFU
    neededCFU = 120 - totalCFU;

    //We dont use 120 but we use 108 since 12 credits is thesis and will considered later simulation.
    if (totalCFU < 108){

        // states required CFU to graduate.
        printf("%d CFU needed for graduation \n ", neededCFU);

        // returns total Lode bonus.
        printf("\nYou have %d extra bonus for Lode \n ", totalLodes);

    }

    /* 108 is maximum CFU can be taken before Thesis since thesis is 12 CFU.
       when totalCFU is 108 this means that user eligible to graduate after giving
       Thesis. This sequence of algorithm calculates extra points of graduation with
       thesis points to output graduation score, possible Cum Laude status.

       If thesis is not given yet program gives output of required thesis note to:
       graduate or if its possible; obtain Cum Laude.
    */
    if (totalCFU == 108){
        printf("You completed all CFU can be obtained from exams. System will continue with thesis calculation to obtain your Graduation Grade. ");

        //graduation score with bonuses included
        float GradAvg = 0;

        //final weighted average with thesis score included
        float finalAVG = 0;

        //status of student if is in normal study year. we didnt use boolean since it has 1 point value already.
        int intime = 0;

        //thesis score out of 7
        int thesis = 0;

        // constant thesis CFU is 12.
        int thesisCFU = 0;

        printf("\n --------------------------------------- \n"); //d ivider

        printf("Student graduated in time?: (1 for yes, 0 for no)");
        scanf("%d", &intime); // memory access to asset point of 0-1

        printf("Write score of Thesis: (out of 7. if not presented input 0) ");
        scanf("%d", &thesis);
        // Lode bonus
        printf("you have total Lode Bonus: %d \n", totalLodes);

        /* this condition is for thesis is not 0 means it presented successfully.
        for this reason thesis CFU will be 12 since this CFU is obtained.
        */
        if (thesis != 0){
            thesisCFU = 12; //thesis CFU is 12. We dont want to directly change memory data since we will use it in other conditions.

            //Final Average = Weighted Average*TotalCFU (108) + thesis (7 point) * 30/7 (conversion to 30)*thesisCFU / 120 CFU
            finalAVG = ((weightedGrade*totalCFU) + (thesis*30*thesisCFU/7)) / (totalCFU + thesisCFU);
            printf("Your final weighted average with thesis, excluding bonuses: %.2f  \n", finalAVG); // .XX format float
            // we use float because float uses 4 bytes of memory, double uses 8 byte of memory


            //Graduation Score: WeightedAverage * 110/30 (conversion to 110) + Lode Bonus (2 max) + Graduated in 2 year (1 point) + thesis (7 max)
            GradAvg = finalAVG*110/30 + totalLodes + intime + thesis;
            printf("Your final score with thesis, included bonuses: %.2f  \n \n", GradAvg);


            /* gives status of Cum Laude with graduation score.
               In Mechatronics 110+ rewards as Cum Laude
               If student gets 104 or higher Board can give a Cum Laude to student
               If score is lower than 66 student cannot graduate with that Score
            */

            // Score between 104 and 109
            if (GradAvg < 110 && GradAvg > 103){
                printf("You are eligible to graduate with Cum Laude by Board decision.\n");
                printf("Grade points higher than 104 MAY given Cum Laude with decision of Board.\n");
            }
            // Score higher than or equal to 110
            if (GradAvg >= 110){
                printf("You are eligible to graduate with Cum Laude\n");
            }

            // minimum grade for graduation is 66
            if (GradAvg >= 66 && GradAvg < 104){
                printf("You are eligible to graduate\n");
            }

            // Score lower than 66
            if (GradAvg < 66){
                printf("You are not eligible to graduate\n");
            }

        }
        /* this condition is for thesis is 0 means it will present in future.
            for this reason thesis CFU will be 0 since not obtained.
            this section calculates approximate thesis score needed to get different statuses
        */
        if (thesis == 0){
            // thesis CFU set to 0
            thesisCFU = 0;
            // final average is not changed.
            finalAVG = weightedGrade;

            //Graduation Score: WeightedAverage * 110/30 (conversion to 110) + Lode Bonus (2 max) + Graduated in 2 year (1 point) + thesis (7 max)
            //thesis is not included since thesis score is 0.
            GradAvg = finalAVG*110/30 + totalLodes + intime + thesis;

            // gives warning to the requirement of thesis and prints current graduation mark.
            printf("You need to finish your thesis to graduate. Your graduation mark without thesis: %.2f  \n", GradAvg);
            printf("\n --------------------------------------- \n \n"); //divider

            // Score between 103 and 97 have possibility to reach or surpass 104 threshold for Board decision
            if ( GradAvg < 104 && GradAvg >= 97){
                printf("In order to graduate with Cum Laude by board decison you need minimum: %.2f thesis score \n \n", 104 - GradAvg); //this gives minimum thesis score needs to be obtained
                printf("Grade points higher than or equal to 104 MAY given Cum Laude with decision of Board.\n\n");
            }

            // Score between 109 and 103 since thesis score can be maximum 7.
            if (110 - GradAvg <= 7 && GradAvg < 110){
                printf("In order to graduate with Cum Laude with 110+ marking you need minimum: %.2f thesis score \n \n", 110 - GradAvg);
                printf("Grade points higher than or equal to 104 MAY given Cum Laude with decision of Board.\n\n");

            }
            // Score between 59 and 65 since these scores are only scores can thesis surpass.
            if (GradAvg >= 59 && GradAvg < 66){
                printf("In order to graduate you need minimum: %.2f thesis score \n \n", 66 - GradAvg);

            }

            // Scores between 66 to 96 which has zero possibility to reach 104
            if (GradAvg >= 66 && GradAvg < 97){
                printf("you are eligible to graduate. \nNo possibility of Cum Laude detected regarding your grade.\nMinimum 104 required for Cum Laude.\n");
                printf("maximum score you can get: %.2f  \n \n", GradAvg + 7);

            }
            // scores which have zero possibility to pass 66 limit
            if(GradAvg < 59){
                printf("you are not eligible to graduate.");

            }
        }
    }
    return 0; // program terminated normally.
}
