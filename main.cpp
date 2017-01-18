//
//  automaton.cpp
//
//
//  Created by Jes'us Fuentes on 12/4/16.
//
//  http://www.fvnts.ch
//

/*

    to be compiled with
    clang++ -std=c++11 -stdlib=libc++
 
*/

#include "automaton.hpp"

//  --------------------
//  main()
//  --------------------

int main(int argc, char* argv[])
{
    std::string::size_type sz;
    
    if (argc < 2)
    {
        cerr <<  "RULE_NUMBER WIDTH STEPS RANDOM_TRUE" << endl;
    }
    else
    {
        rule(stoi(argv[1], &sz),
             stoi(argv[2], &sz) + 2,
             stoi(argv[3], &sz),
             stoi(argv[4], &sz)
            );
    }

    return 0;
    
}

//  --------------------
//  rule()
//  --------------------

int rule(int code, unsigned int n, unsigned int step, unsigned int opt)
{
    
    int i;
    int j;
    char *x;
    char *y;
    char *z;
    
    unsigned long dec;
    
    string   set;
    ofstream myfile("automaton.dat");
    
    //  --------------------
    
    x   = (char *) malloc( (n + 2) * sizeof(char) );
    y   = (char *) malloc( (n + 2) * sizeof(char) );
    z   = (char *) malloc(bitsRule * sizeof(char) );
    
    //  --------------------
    //  decoding
    //  --------------------
    
    string  binOut = bitset<bitsRule> (code).to_string();
    strcpy(z, binOut.c_str());
    
    //  --------------------
    //  initial data
    //  --------------------
    
    switch (opt)
    {
        case 1:
            randomize(n, x);
            break;
            
        default:
            initialize(n, x);
            break;
    }
    
    //  --------------------
    //  ENGINE
    //  --------------------
    
    if (myfile.is_open())
    {
        for (i = 1; i <= n; i++)
        {
            myfile << x[i] << ' ';
        }
        myfile << endl;
    
        //  --------------------
        //  EVOLUTION
        //  --------------------
    
        for (j = 1; j <= step; j++)
        {

            //  --------------------
            //  auxiliar array
            //  --------------------
        
            for (i = 0; i <= n + 1; i++)
            {
                y[i] = x[i];
            }
        
            //  --------------------
            //  inner points
            //  --------------------
        
            for (i = 1; i <= n; i++)
            {
                set = vector(y[i-1], y[i], y[i+1]);
                dec = std::bitset<bitsHead> (set).to_ulong();
            
                if (z[ (bitsRule-1) - dec ] == on)
                {
                    x[i] = on;
                }
                else
                {
                    x[i] = off;
                }
            }
        
            //  --------------------
            //  boundaries
            //  --------------------
        
            x[0]     = x[n + 1];
            x[n + 1] = x[0];
            
            for (i = 1; i <= n; i++)
            {
                myfile << x[i] << ' ';
            }
            myfile << endl;
        }
        myfile.close();
    }
    else
    {
        cout << "unable to open file" << endl;
    }
    
    free(x);
    free(y);
    
    return 0;
    
}

//  --------------------
//  vector()
//  --------------------

string vector(char a, char b, char c)
{
    string x = {a,b,c};
    return x;
}

//  --------------------
//  randomize()
//  --------------------

void randomize(unsigned int n, char *x)
{
    srand(time_t(NULL));
    
    for (int i = 0; i <= n + 1; i++)
    {
        if (rand() % 2)
        {
            x[i] = on;
        }
        else
        {
            x[i] = off;
        }
    }
}

//  --------------------
//  initialize()
//  --------------------

void initialize(unsigned int n, char *x)
{
    for (int i = 0; i <= n + 1; i++)
    {
        x[i] = off;
    }
    x[ (int) floor(n/2) ] = on;
}

//  --------------------
//  eof
//  --------------------
