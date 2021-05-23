#include <stdio.h>
#include <string.h>
char name[25];
void displayGreeting(){
	printf("Welcome to the Solar System!\n");
	printf("There are 9 planets to explore.\n");
	printf("What is your name traveler?\n");
}
void greetingResponse(){
	printf("Nice to meet you, %s. My name is Eliza, I'm an old friend of Alexa.\n", name);
	printf("Should I randomly choose a planet for you to visit? (Y or N)\n");
}
void readName(){
	fgets(name, 25, stdin);
	name[strcspn(name, "\n")] = 0;
}

void chooseRandomPlanet(){
	char yesOrNo[2];
	fgets(yesOrNo, 25, stdin);
	yesOrNo[strcspn(yesOrNo, "\n")]=0;
	printf("You picked %s\n", yesOrNo);
}
int main(int argc, char** argv){
	displayGreeting();
	readName();
	greetingResponse();
	chooseRandomPlanet();
	printf("Traveling to Jupiter...\n");
	printf("Arrived at Jupiter, look at those rings.\n");
	return 0;
}