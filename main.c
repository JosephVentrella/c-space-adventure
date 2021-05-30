#include <stdio.h>
#include <string.h>
#include "functions.h"
char name[25];
void greetingResponse();
void readName();
void travelToPlanet();
void chooseOwnPlanet();
void choosePlanet();


int main(int argc, char** argv){
	displayGreeting();
	readName();
	greetingResponse();
	choosePlanet();
	return 0;
}

void greetingResponse(){
	printf("Nice to meet you, %s. My name is Eliza, I'm an old friend of Alexa.\n", name);
	printf("Should I randomly choose a planet for you to visit? (Y or N)\n");
}
void readName(){
	fgets(name, 25, stdin);
	name[strcspn(name, "\n")] = 0;
}
void travelToPlanet(){
	printf("Traveling to Jupiter...\n");
	printf("Arrived at Jupiter, look at those rings.\n");
}
void chooseOwnPlanet(){
	char planetSelection[7];
	fgets(planetSelection, 7, stdin);
	name[strcspn(planetSelection, "\n")] = 0;
}
void choosePlanet(){
	char yesOrNo[2];
	fgets(yesOrNo, 25, stdin);
	yesOrNo[strcspn(yesOrNo, "\n")]=0;
	printf("You picked %s\n", yesOrNo);
	if (yesOrNo[0] == 'y'|| yesOrNo[0] =='Y'){
		travelToPlanet();
	}
	else {
		chooseOwnPlanet();
		travelToPlanet();
	}
}