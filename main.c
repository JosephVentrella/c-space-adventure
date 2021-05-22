#include <stdio.h>
#include <string.h>
char name[25];
void displayGreeting(){
	printf("Welcome to the Solar System!\n");
	printf("There are 9 planets to explore.\n");
	printf("What is your name traveler?\n");
}
void readName(){
	fgets(name, 25, stdin);
	name[strcspn(name, "\n")] = 0;
}
int main(int argc, char** argv){
	displayGreeting();
	readName();
	printf("Nice to meet you, %s. My name is Eliza, I'm an old friend of Alexa.\n", name);
	printf("Should I randomly choose a planet for you to visit? (Y or N)\n");
	char randomPlanet[2];
	fgets(randomPlanet, 25, stdin);
	randomPlanet[strcspn(randomPlanet, "\n")]=0;
	printf("You picked %s\n", randomPlanet);
	printf("Traveling to Jupiter...\n");
	printf("Arrived at Jupiter, look at those rings.\n");
	return 0;
}