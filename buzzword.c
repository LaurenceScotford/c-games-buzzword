/*******
 * Buzzword
 *
 * A program to create amusing fake jargon
 *******/

 #include <stdio.h>

 int main(int argc, const char * argv[])
 {
   printf("Buzzword Generator\nBased on a programme from Creative Computing, Morristown, New Jersey\n\n\nThis programme prints highly acceptable phrases in 'educator-speak' that you can work into reports and speeches. Whenever a question mark is printed, type a 'Y' for another phrase or 'N' to quit.\n\n\nHere's the first phrase:\n");

   const char * adjectives1[] = {"ability", "basal", "behavioral", "child-centered", "differentiated", "discovery", "flexible", "heterogeneous", "homogenous", "manipulative", "modular", "tavistock", "individualized" };
   const char * adjectives2[] = {"learning", "evaluative", "objective", "cognitive", "enrichment", "scheduling", "humanistic", "integrated", "non-graded", "training", "vertical age", "motivational", "creative"};
   const char * nouns[] = {"grouping", "modification", "accountability", "process", "core curriculum", "algorithm", "performance", "reinforcement", "open classroom", "resource", "structure", "facility", "environment"};

   return 0;
 }
