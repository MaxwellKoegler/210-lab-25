//Maxwell Koegler | COMSC 210 | lab 25
#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <iterator>

using namespace std;


int main() {
    vector<string> v;
    list<string> l;
    set<string> s;
    string code;

    long times[4][3];

    chrono::high_resolution_clock::time_point start;
    chrono::high_resolution_clock::time_point end;

    ifstream fin("codes.txt");

    start = chrono::high_resolution_clock::now();
    
    while(fin >> code) {
        v.push_back(code);
    }

    end = chrono::high_resolution_clock::now();
    times[0][0] == chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    fin.close();

    fin.open("codes.txt");

    start = chrono::high_resolution_clock::now();

    while(fin >> code) {
        l.push_back(code);
    } 

    end = chrono::high_resolution_clock::now();
    times[0][1] = chrono::duration_cast<chrono::nanoseconds>(end-start).count();

    fin.close();




    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/