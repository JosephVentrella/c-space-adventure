#include <stdio.h>
#include <string.h>
#include "functions.h"
#include <stdlib.h>
#include <time.h>
#include <json-c/json.h>
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
void chooseOwnPlanet(){
	int planet = 0;
	char planetSelection[8];
	fgets(planetSelection, 8, stdin);
	name[strcspn(planetSelection, "\n")] = 0;
	if(strcmp(planetSelection, "Mercury") == 0){
		planet = 0;
	}
	else if(strcmp(planetSelection, "Venus\n")== 0){
		planet = 1;
	}
	else if(strcmp(planetSelection, "Earth\n") == 0){
		planet = 2;
	}
	else if(strcmp(planetSelection, "Mars\n") == 0){
		planet = 3;
	}
	else if(strcmp(planetSelection, "Jupiter") == 0){
		planet = 4;
	}
	else if(strcmp(planetSelection, "Saturn\n") == 0){
		planet = 5;
	}
	else if(strcmp(planetSelection, "Uranus\n") == 0){
		planet = 6;
	}
	else if(strcmp(planetSelection, "Neptune") == 0){
		planet = 7;
	}
	else if(strcmp(planetSelection, "Pluto\n") == 0){
		planet = 8;
	}
	//destinationPicker(planet);
	jsonHandler(planet);
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
	int planet = rand() % 9;
	jsonHandler(planet);
}

void jsonHandler(int planetNumber){
	FILE *fp;
	char buffer[1024];
	struct json_object *parsed_json;
	struct json_object *planets;
	struct json_object *planet;
	struct json_object *descriptions;
	struct json_object *description;
	size_t n_planets;

	fp = fopen("planetarySystem.json","r");
	fread(buffer, 1024, 1, fp);
	fclose(fp);
	parsed_json = json_tokener_parse(buffer);
	json_object_object_get_ex(parsed_json, "planets", &planets);
	json_object_object_get_ex(parsed_json, "descriptions", &descriptions);
	n_planets = json_object_array_length(planets);
	planet = json_object_array_get_idx(planets, planetNumber);
	description = json_object_array_get_idx(descriptions, planetNumber);
	printf("Traveling to %s...\n", json_object_get_string(planet));
	printf("%s\n", json_object_get_string(description));
}