/*

    Name: Ryan Kilkenney
    Date: 8/29/2020
    Purpose: Make a program that can take in a number and find all prime numbers using that number by using the Sieve of Eratosthenes and ordered lists

*/

#include <iostream>
#include <list> 
#include <iterator> 
#include <math.h>

using namespace std;

int main(int argc, char *argv[]) {
    
    list <int> nlist; //list used to hold all the prime numbers 
    list <int> clist; //list used to hold all composite numbers 

    //this checks if a number was inputed when the program is started 
    if(argv[1] == NULL) {
        cout << "Missing argument" << endl;
        exit(0);
    }
    
    //converts user input to an interger
    int n = atoi(argv[1]);

    //checks if the int is actually an int 
    if(n == 0) {
        cout << "Nan" << endl;
        exit(0);
    }
    
    //checks if the int is in range
    if ((n < 2) || (n > 30000)) {
        cout << "Out of range" << endl;
        exit(0);
    }

    //populates nlist with numbers starting from two up until the input
    for (int i = 2; i <= n; i++) 
    { 
        nlist.push_back(i); 
        
    } 

    //runs through nlist, and uses the Sieve of Eratosthenes to find composite numbers. When a composite num is found, it is removed and added to clist
    list <int> :: iterator it; 
    int p = 2;
    while(!(p > floor(sqrt(n)))) {
        for(it = nlist.begin(); it != nlist.end(); it++) {
            
            if((*it % p == 0) && (*it != p)) {
                clist.push_back(*it);
                it = nlist.erase(it);
            }

        }
        p++;
    }

    //sorts clist into numerical order
    clist.sort();

    //outputs both lists to the screen in the required format 
    for(it = nlist.begin(); it != nlist.end(); it++) { 
        cout << *it << " ";
    }
    cout << endl;
    for(it = clist.begin(); it != clist.end(); it++) { 
        cout << *it << " ";
    }
    cout << endl;

    
}