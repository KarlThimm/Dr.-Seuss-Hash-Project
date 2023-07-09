/*
 * MakeSeuss.hpp
 *
 *  Created on: Oct 31, 2022
 *      Author: karlthimm
 */

#ifndef MAKESEUSS_HPP_
#define MAKESEUSS_HPP_


#include "HashMap.hpp"
#include <iostream>
using namespace std;

class makeSeuss {
	hashMap *ht;
	string fn;
	string newfile;
	bool hashfn;
	bool collfn;
public:
	makeSeuss(string file,string newf, bool hash1, bool coll1);
	void readFile();
	void writeFile();

};




#endif /* MAKESEUSS_HPP_ */

