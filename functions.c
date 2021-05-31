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
	int planet = 0;
	char planetSelection[8];
	fgets(planetSelection, 8, stdin);
	name[strcspn(planetSelection, "\n")] = 0;
	if(strcmp(planetSelection, "Mercury") == 0){
		planet = 1;
	}
	else if(strcmp(planetSelection, "Venus\n")== 0){
		planet = 2;
	}
	else if(strcmp(planetSelection, "Earth\n") == 0){
		planet = 3;
	}
	else if(strcmp(planetSelection, "Mars\n") == 0){
		planet = 4;
	}
	else if(strcmp(planetSelection, "Jupiter\n") == 0){
		planet = 5;
	}
	else if(strcmp(planetSelection, "Saturn\n") == 0){
		planet = 6;
	}
	else if(strcmp(planetSelection, "Uranus\n") == 0){
		planet = 7;
	}
	else if(strcmp(planetSelection, "Neptune\n") == 0){
		planet = 8;
	}
	else if(strcmp(planetSelection, "Pluto\n") == 0){
		planet = 9;
	}
	destinationPicker(planet);
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
		printf("Choose a planet: ");
		chooseOwnPlanet();
	}
}
void travelToRandomPlanet(){
	time_t t;
	srand((unsigned) time(&t));
	int planet = rand() % 10;
	if(planet == 0){
		planet += 1;
	}
	destinationPicker(planet);
}
void destinationPicker(int planetNumber){
	switch(planetNumber){
		case 1://Mercury
			printf("Traveling to Mercury.\n");
			printf("Arrived at Mercury.\n");
			printf("Look how big the sun looks from here.\n");
			break;
		case 2://Venus
			printf("Traveling to Venus.\n");
			printf("Arrived at Venus.\n");
			printf("Its hard to breathe with all the clouds here.\n");
			break;
		case 3://Earth
			printf("Traveling to Earth.\n");
			printf("Arrived at Earth.\n");
			printf("This place looks familiar.\n");
			break;
		case 4://Mars
			printf("Traveling to Mars.\n");
			printf("Arrived at Mars.\n");
			break;
		case 5://Jupiter
			printf("Traveling to Jupiter...\n");
			printf("Arrived at Jupiter, look at those rings.\n");
			break;
		case 6://Saturn
			printf("Traveling to Saturn.\n");
			printf("Arrived at Saturn.\n");
			printf("I dont know anything about this planet.\n");
			break;
		case 7://Uranus
			printf("Traveling to Uranus.\n");
			printf("Arrived at Uranus.\n");
			printf("No jokes please.\n");
			break;
		case 8://Neptune
			printf("Traveling to Neptune.\n");
			printf("Arrived at Neptune.\n");
			printf("Brrrrr its cold.\n");
			break;
		case 9://Pluto
			printf("Traveling to Pluto.\n");
			printf("Arrived at Pluto.\n");
			printf("I dont care what they say it is definitely a planet.\n");
			break;
	}
}