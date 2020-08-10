# c-games-buzzword
A conversion to C of the Buzzword game from David Ahl's *Basic Computer Games*. Buzzword prints highly acceptable phrases in 'educator-speak' that you can work into reports and speeches.
## How to compile the program
Buzzword consists of a single file, *buzzword.c*. Simply compile this to create an executable.
## How to use Buzzword
Buzzword takes an optional command line argument, an integer between 1 and 99 that indicates how many phrases you would like to generate. For example, if you compiled the program to create an executable called "buzzword", you could generate 5 phrases with:
```
buzzword 5
```
If you run the program without a command line argument, it will display a single phrase and then display a question mark and wait for your input. Entering **y** or **Y** then hitting the enter or return key will display another phrase. Entering any other character and hitting enter or return will end the program.
