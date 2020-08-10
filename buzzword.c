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

  int numberOfPhrases = 1;  // The number of phrases to display

  // The mode of operation: 0 = single phrase then prompt for more, 1 = display number of phrases requested in the command line arg
  int mode = 1;

  if (argc == 1) {
     // There was no argument so set mode to single phrase with prompt
     mode = 0;
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

   // Display the introduction and instructions if required
   printf("Buzzword Generator\nBased on a programme from Creative Computing, Morristown, New Jersey\n\n\nThis programme prints highly acceptable phrases in 'educator-speak' that you can work into reports and speeches.");

   if (mode == 0) {
     printf(" Whenever a question mark is printed, type a 'Y' for another phrase or 'N' to quit.\n\n\nHere's the first phrase:\n");
   }
   else if (numberOfPhrases == 1) {
     printf("\n\n\nHere's your phrase:");
   } else {
     printf("\n\n\nHere are your %i phrases", numberOfPhrases);
   }

   // Create three lists of words
   const char * adjectives1[] = {"ability", "basal", "behavioral", "child-centered", "differentiated", "discovery", "flexible", "heterogeneous", "homogenous", "manipulative", "modular", "tavistock", "individualized" };
   const char * adjectives2[] = {"learning", "evaluative", "objective", "cognitive", "enrichment", "scheduling", "humanistic", "integrated", "non-graded", "training", "vertical age", "motivational", "creative"};
   const char * nouns[] = {"grouping", "modification", "accountability", "process", "core curriculum", "algorithm", "performance", "reinforcement", "open classroom", "resource", "structure", "facility", "environment"};

   // Seed the random number generator
   srand((unsigned int)time(NULL));

   char rawInput[80];  // This will hold the raw input entered by the user
   char input;   // This will store the character entered by the user

   // Display random phrases while user keeps requesting them
   do {
     for (int i = 0; i < numberOfPhrases; i++) {
       printf("\n%s %s %s\n\n", adjectives1[rand() % 13], adjectives2[rand() % 13], nouns[rand() % 13]);
     }

     if (mode == 0) {
       printf("?");
       fgets(rawInput, sizeof(rawInput) / sizeof(rawInput[0]), stdin);
       sscanf(rawInput, " %c", &input);
     }
   } while (mode == 0 && (input == 'y' || input == 'Y'));

   printf("Come back when you need help with another report!");

   return EXIT_SUCCESS;
 }

 void displayUsageAndExit() {
   printf("\nUsage: BUZZWORD number_of_phrases\nWhere number of phrases is an optional argument - a whole number from 1 to 99");
   exit(EXIT_FAILURE);
 }
