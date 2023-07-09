/*
 * HashNode.cpp
 *
 *  Created on: Oct 31, 2022
 *      Author: karlthimm
 */

#include "HashMap.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;



hashNode::hashNode(string s){
	keyword = s;
	values = new string[100];
	valuesSize = 100;
	currSize = 0;
	srand(time(NULL));
}
hashNode::hashNode(){
	keyword = "";
	values = new string[100];
	valuesSize = 100;
	currSize = 0;
	srand(time(NULL));
}
hashNode::hashNode(string s, string v){
	keyword = s;
	values = new string[100];
	values[0] = v;
	valuesSize = 100;
	currSize = 1;
}
void hashNode::addValue(string v){
	currSize++;
	values[currSize-1] = v;

	if(currSize > valuesSize/2){
		dblArray();
	}
}
void hashNode::dblArray(){
	valuesSize *= 2;
	string *newValues = new string[valuesSize];
	for(int i = 0; i < currSize; i++){
		newValues[i] = values[i];
	}
	delete []values;
	values = newValues;
}

string hashNode::getRandValue(){
	return values[rand() % currSize];
}


