/*******
 * Buzzword
 *
 * A program to create amusing fake jargon
 *******/

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #include <errno.h>
 #include <limits.h>

 int main(int argc, const char * argv[]) {

   int numberOfPhrases = 0;

   if(argc != 2)
   {
     printf("\nUsage: BUZZWORD number_of_phrases\nWhere number of phrases is a whole number from 1 to %i", INT_MAX);
     return EXIT_FAILURE;
   } else {
     errno = 0;
     char * inputStr;
     long inputNum = strtol(argv[1], &inputStr, 10);

     if(errno == ERANGE || *inputStr != '\0' || inputNum < 1 || inputNum > INT_MAX) {
       printf("\nUsage: BUZZWORD number_of_phrases\nWhere number of phrases is a whole number from 1 to %i", INT_MAX);
       return EXIT_FAILURE;
     }

     numberOfPhrases = (int) inputNum;
   }

   printf("\nThe user asked for %i phrase(s)\n", numberOfPhrases);

   printf("Buzzword Generator\nBased on a programme from Creative Computing, Morristown, New Jersey\n\n\nThis programme prints highly acceptable phrases in 'educator-speak' that you can work into reports and speeches. Whenever a question mark is printed, type a 'Y' for another phrase or 'N' to quit.\n\n\nHere's the first phrase:\n");

   const char * adjectives1[] = {"ability", "basal", "behavioral", "child-centered", "differentiated", "discovery", "flexible", "heterogeneous", "homogenous", "manipulative", "modular", "tavistock", "individualized" };
   const char * adjectives2[] = {"learning", "evaluative", "objective", "cognitive", "enrichment", "scheduling", "humanistic", "integrated", "non-graded", "training", "vertical age", "motivational", "creative"};
   const char * nouns[] = {"grouping", "modification", "accountability", "process", "core curriculum", "algorithm", "performance", "reinforcement", "open classroom", "resource", "structure", "facility", "environment"};

   srand((unsigned int)time(NULL));
   printf("\n%s %s %s\n\n", adjectives1[rand() % 13], adjectives2[rand() % 13], nouns[rand() % 13]);

   return EXIT_SUCCESS;
 }
