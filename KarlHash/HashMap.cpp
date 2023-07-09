/*
 * HashMap.cpp
 *
 *  Created on: Oct 31, 2022
 *      Author: karlthimm
 */

#include "HashMap.hpp"
#include "HashNode.hpp"
#include <iostream>
#include <math.h>
using namespace std;

hashMap::hashMap(bool hash1, bool coll1){
	collisions = 0; //set collisions to 0 at start since there are none to begin with
	hashcoll = 0;
	first = "";
	numKeys = 0;
	mapSize = 7; //Start mapsize at 7 (prime number to hash by)
	hashfn = hash1;
	collfn = coll1;
	map = new hashNode *[mapSize];
	for(int i = 0; i < mapSize; i++){
		map[i] = NULL; //Sets indexes to null
	}
}
void hashMap::addKeyValue(string k, string v){
	int index = getIndex(k);
	hashNode *indexnode = map[index];
	if(indexnode == NULL){ //If node is null crrate new create new node and add value
		map[index] = new hashNode(k);
		map[index]->addValue(v);
	}
	else if(indexnode->keyword == k){ //If index matches key add it to array
		map[index]->addValue(v);
	}
	numKeys++;
	if(((float)numKeys/(float)mapSize) > 0.7){ //If map is 70% full then we will rehash and double the array
		//rehash
		reHash();
	}
}

int hashMap::getIndex(string k){
	int index = hashfn ? calcHash1(k) : calcHash2(k); //? chooses which one to use and : is for "either hash1 or hash 2
	hashNode *indexnode = map[index];
	int count = 0;
	while(true){
		if(indexnode == NULL){
			return index; //Nothing there
		}
		else if(indexnode->keyword == k){
			return index; //If node is = to key
		}
		if(count == 0){
			hashcoll++;
		}
		index = collfn ? coll1(index, count, k) : coll2(index, count, k); //Chooses which collision to use
		indexnode = map[index];
		collisions++;
		count++;
	}
}

int hashMap::calcHash1(string k){
	int size = k.length();
	//if(size==0){ //If word has 0 letters (dont think i need it)
		//return ...;
	//}
	if(size == 1){ //if the word is 1 letter
		return (int)k[0]% mapSize;
	}
	else if(size == 2){ //if the word is 2 letters
		return ((int)k[0] + (int)k[1] * 27)%mapSize;
	}
	else{ //anything else use the first 3
		return ((int)k[0] + (int)k[1] * 27 + (int)k[2] * 27 * 27) % mapSize;
		//This uses the first 3 leters of the word to hash
		//We times by 27 for the 26 letters possible plus space
		//k[0] does not get multiplied bc its 27 raised to 0 which is multiplying by one
		//the next index gets multiplied by 27 to the first and 3rd is 27 squared
	}
}

int hashMap::calcHash2(string k){
	//cout<<"this works"<<endl;
	int h=0;
	int size = k.length(); //size set to length of hash
	for (int i = 0; i < size; i++){
		h = h + (int)k[i]; //Turns k index to  an integer
		//size is length of word so i indexes through each letter and adds its integer
	}
	return h % mapSize; //mod by prime
}

bool prime(int n){ //uses recursion in get closestprime to choose prime number
	if (n == 1){ //1 is a prime but not a good one
		return false;
	}
	for (int i = 2; i < n; i++){
		if (n % i == 0){
			return false;//Not prime
		}
	}
	return true; //True means prime number (returns true if both cases above are not ran otherwise false, not a prime)
}

void hashMap::getClosestPrime(){ //calls
	mapSize = mapSize * 2;
	while(true){ //true = prime number
		mapSize++;
		if(prime(mapSize)){ //Makes sure prime number is bigger than mapzise
			break; //Ends when a prime is found thats fits mapSize
		}
	}
}

void hashMap::reHash(){
	numKeys = 0;
	int oldSize = mapSize;
	hashNode **oldMap = map;
	getClosestPrime(); //Gets new mapSize prime number to rehash
	hashNode **newhashmap = new hashNode *[mapSize];
	map = newhashmap;
	for (int i = 0; i < mapSize; i++){
		map[i] = NULL;
	}
	for (int i = 0; i < oldSize; i++){
		if(oldMap[i] != NULL){ //If oldmap index is not a null we add that value to the new map
			for (int j = 0; j < oldMap[i]->currSize; j++){
				addKeyValue(oldMap[i]->keyword, oldMap[i]->values[j]); //J to add values to new map from indexes i on old map
			}
		}
	}
}

int hashMap::coll1(int h, int i, string k){
	return (h+i) % mapSize; //Linear probing function
}

int hashMap::coll2(int h, int i, string k){
	return (h+(i*i)) % mapSize; //Quadratic probing method
}

void hashMap::printMap(){
	cout << "In printMap()" << endl;
	for (int i = 0; i < mapSize; i++) {
		//cout << "In loop" << endl;
		if (map[i] != NULL){
			cout << map[i]->keyword << ": ";
			for (int j = 0; j < map[i]->currSize;j++){
				cout << map[i]->values[j] << ", ";
			}
			cout << endl;
		}
	}
}


