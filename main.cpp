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

    fin.open("codes.txt");

    start = chrono::high_resolution_clock::now();

    while(fin >> code) {
        s.insert(code);
    }

    end = chrono::high_resolution_clock::now();
    times[0][2] = chrono::duration_cast<chrono::nanoseconds>(end-start).count();

    fin.close();

    start = chrono::high_resolution_clock::now();

    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i] > v[j]) {
                string temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }

    end = chrono::high_resolution_clock::now();
    times[1][0] = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    start = chrono::high_resolution_clock::now();
    l.sort();
    end = chrono::high_resolution_clock::now();
    times[1][1] = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    times[1][2] = -1;

    start = chrono::high_resolution_clock::now();
    v.insert(v.begin() + v.size() / 2, "test");
    end = chrono::high_resolution_clock::now();
    times[2][0] = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    list<string>::iterator li = l.begin();
    advance(li, l.size() / 2);
    start = chrono::high_resolution_clock::now();
    l.insert(li, "test");
    end = chrono::high_resolution_clock::now();
    times[2][1] = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    start = chrono::high_resolution_clock::now();
    s.insert("test");
    end = chrono::high_resolution_clock::now();
    times[2][2] = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    start = chrono::high_resolution_clock::now();

    v.erase(v.begin() + v.size() / 2);

    end = chrono::high_resolution_clock::now();
    times[3][0] = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    li = l.begin();
    advance(li, l.size() / 2);

    start = chrono::high_resolution_clock::now();

    l.erase(li);

    end = chrono::high_resolution_clock::now();
    times[3][1] = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    set<string>::iterator si = s.begin();
    advance(si, s.size() / 2);

    start = chrono::high_resolution_clock::now();

    s.erase(si);

    end = chrono::high_resolution_clock::now();
    times[3][2] = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    

    return 0;
}