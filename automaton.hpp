//
//  automaton.hpp
//
//
//  Created by Jes'us Fuentes on 12/4/16.
//
//  http://www.fvnts.ch
//

#ifndef automaton_hpp
#define automaton_hpp

//  --------------------

#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <cstdio>
#include <ctime>
#include <math.h>

using namespace std;

//  --------------------

#define on  '1'
#define off '0'

#define bitsHead 3      // bitsHead = 2^n - 1, n >= 1
#define bitsRule 8      // bitsRule = 2^bitsHead

//  --------------------

int     main(int , char*  []);
int     rule(int, unsigned int, unsigned int , unsigned int);

void    randomize(unsigned int n, char *x);
void    initialize(unsigned int n, char *x);

string  vector (char , char , char);

//  --------------------

#endif /* automaton_hpp */

//  --------------------
//  eof
//  --------------------
