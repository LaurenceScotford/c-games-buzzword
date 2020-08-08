/*******
 * Buzzword
 *
 * A program to create amusing fake jargon
 *******/

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #include <errno.h>

 // Function declarations
 void displayUsageAndExit();

 int main(int argc, const char * argv[]) {

   int numberOfPhrases = 0;

   if (argc == 1) {
     // There was no argument so default to one phrase
     numberOfPhrases = 1;
   } else if(argc != 2) {
     // An incorrect number of arguments was given, so quit with usage message
     displayUsageAndExit();
   } else {
     // A single argument was given, so attempt to convert it to an integer
     errno = 0;
     char * inputStr;
     long inputNum = strtol(argv[1], &inputStr, 10);

     if(errno == ERANGE || *inputStr != '\0' || inputNum < 1 || inputNum > 99) {
       // The argument could not be interpreted as an integer in the required range, so quit with usage message
       displayUsageAndExit();
     }

     numberOfPhrases = (int) inputNum;
   }

   // Temporary statement to check validation code by showing the number of phrase requested
   // printf("\nThe user asked for %i phrase(s)\n", numberOfPhrases);

   // Display the instructions
   printf("Buzzword Generator\nBased on a programme from Creative Computing, Morristown, New Jersey\n\n\nThis programme prints highly acceptable phrases in 'educator-speak' that you can work into reports and speeches. Whenever a question mark is printed, type a 'Y' for another phrase or 'N' to quit.\n\n\nHere's the first phrase:\n");

   // Create three lists of words
   const char * adjectives1[] = {"ability", "basal", "behavioral", "child-centered", "differentiated", "discovery", "flexible", "heterogeneous", "homogenous", "manipulative", "modular", "tavistock", "individualized" };
   const char * adjectives2[] = {"learning", "evaluative", "objective", "cognitive", "enrichment", "scheduling", "humanistic", "integrated", "non-graded", "training", "vertical age", "motivational", "creative"};
   const char * nouns[] = {"grouping", "modification", "accountability", "process", "core curriculum", "algorithm", "performance", "reinforcement", "open classroom", "resource", "structure", "facility", "environment"};

   // Seed the random number generator
   srand((unsigned int)time(NULL));

   // Display the number of randomly generated phrases requested by the user
   int i = 0;

   do {
     printf("\n%s %s %s\n\n", adjectives1[rand() % 13], adjectives2[rand() % 13], nouns[rand() % 13]);
     i++;
   } while (i < numberOfPhrases);

   return EXIT_SUCCESS;
 }

 void displayUsageAndExit() {
   printf("\nUsage: BUZZWORD number_of_phrases\nWhere number of phrases is a whole number from 1 to 99");
   exit(EXIT_FAILURE);
 }
