/*
 * mainHash.cpp
 *
 *  Created on: Oct 31, 2022
 *      Author: karlthimm
 */

#include <iostream>
#include "MakeSeuss.hpp"
#include <time.h>
#include <stdlib.h>

using namespace std;
int main() {
	//cout<<"This prints"<<endl;
	srand(time(NULL));
	//makeSeuss voice1("DrSeuss.txt","Seussout1.txt",true,true);
	cout<<"*********************End Hash1******************"<<endl;
	//makeSeuss voice2("DrSeuss.txt","Seussout2.txt",false,true);
	cout<<"*********************End Hash2******************"<<endl;
	//makeSeuss voice3("DrSeuss.txt","Seussout3.txt",true,false);
	cout<<"*********************End Hash3******************"<<endl;
	makeSeuss voice4("DrSeuss.txt","Seussout4.txt",false,false);
	cout<<"*********************End Hash4******************"<<endl;
	//Needed to do one at a time otherwise all stories are identical
//OR
	//makeSeuss voice5("GEChap1a.txt","GEout1.txt",true,true);
	//makeSeuss voice6("GEChap1a.txt","GEout2.txt",false,true);
	//makeSeuss voice7("GEChap1a.txt","GEout3.txt",true,false);
	//makeSeuss voice8("GEChap1a.txt","GEout4.txt",false,false);

	return 0;
}


