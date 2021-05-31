#include <stdio.h>
#include <string.h>
#include "functions.h"
#include <stdlib.h>
#include <time.h>
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
		travelToRandomPlanet();
	}
	else {
		chooseOwnPlanet();
		travelToPlanet();
	}
}
void travelToRandomPlanet(){
	time_t t;
	srand((unsigned) time(&t));
	int planet = rand() % 10;
	switch(planet){
		case 1:
			printf("Traveling to Mercury.\n");
			printf("Arrived at Mercury.\n");
			printf("Look how big the sun looks from here.\n");
			break;
		case 2:
			printf("Traveling to Venus.\n");
			printf("Arrived at Venus.\n");
			printf("Its hard to breathe with all the clouds here.\n");
			break;
		case 3:
			printf("Traveling to Earth.\n");
			printf("Arrived at Earth.\n");
			printf("This place looks familiar.\n");
			break;
		case 4:
			printf("Traveling to Mars.\n");
			printf("Arrived at Mars.\n");
			break;
		case 5:
			printf("Traveling to Jupiter...\n");
			printf("Arrived at Jupiter, look at those rings.\n");
			break;
		case 6:
			printf("Traveling to Saturn.\n");
			printf("Arrived at Saturn.\n");
			printf("I dont know anything about this planet.\n");
			break;
		case 7:
			printf("Traveling to Uranus.\n");
			printf("Arrived at Uranus.\n");
			printf("No jokes please.\n");
			break;
		case 8:
			printf("Traveling to Neptune.\n");
			printf("Arrived at Neptune.\n");
			printf("Brrrrr its cold.\n");
			break;
		case 9:
			printf("Traveling to Pluto.\n");
			printf("Arrived at Pluto.\n");
			printf("I dont care what they say it is definitely a planet.\n");
			break;


	}
}