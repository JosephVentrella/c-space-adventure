//This does nothing for now
#include <stdio.h>
int main(int argc, char** argv){
	printf("Welcome to the Solar System!\n");
	printf("There are 9 planets to explore.\n");
	printf("What is your name traveler?\n");
	char name[25];
	fgets(name, 25, stdin);
	printf("Nice to meet you, %s. My name is Eliza, I'm an old friend of Alexa.\n", name);
	printf("Should I randomly choose a planet for you to visit? (Y or N)\n");
	char randomPlanet[2];
	fgets(randomPlanet, 25, stdin);
	printf("Traveling to Jupiter...\n");
	printf("Arrived at Jupiter, look at those rings.\n");
	return 0;
}