// COMSC-210 | Lab-26 | Jeremiah Ortiz
#include <iostream>
#include <fstream>
#include <chrono>
#include <list>
#include <set>
#include <string>
#include <vector> 
#include <iomanip>
#include <algorithm> 

using namespace std;
using namespace std::chrono; 

const string FILENAME = "codes.txt"; 
const int NUM = 15; 

void load_data(const string& filename, vector<string>& v, list<string>& l, set<string> s); 
void preform_op(const vector<string> &v, const list<string> &l, const set<string> &s, long long a[4][3]); 

void load_data(const string& filename, vector<string>& v, list<string>& l, set<string> s) {

    fstream file("codes.txt");

    string sa; 

    auto start = high_resolution_clock::now(); 

    while (getline(file, sa)) {

        v.push_back(sa); 
    }

    auto end = high_resolution_clock::now(); 

    auto v_duration = duration_cast<milliseconds>(end - start).count(); 

    file.clear();

    file.seekg(0); 

    start = high_resolution_clock::now(); 

    while (getline(file, sa)) {

        l.push_back(sa);
    }

    end = high_resolution_clock::now(); 

    auto l_duration = duration_cast<milliseconds>(end - start).count();

    file.clear(); 

    file.seekg(0); 

    start = high_resolution_clock::now(); 

    while (getline(file, sa)) {

        s.insert(sa);
    }

    end = high_resolution_clock::now(); 

    auto s_duration = duration_cast<milliseconds>(end - start).count();  

    file.close(); 
}

void preform_op(const vector<string> &v, const list<string> &l, const set<string> &s, long long a[4][3]) {

    vector<string> v_cop = v; 

    auto start = high_resolution_clock::now();

    sort(v_cop.begin(), v_cop.end());

    auto end = high_resolution_clock::now(); 

    a[0][1] = duration_cast<milliseconds>(end - start).count(); 

    list<string> l_cop = l;

    start = high_resolution_clock::now(); 

    l_cop.sort();

    end = high_resolution_clock::now(); 

    a[1][1] = duration_cast<milliseconds>(end - start).count();  

    start = high_resolution_clock::now(); 

    v_cop.insert(v_cop.begin() + v_cop.size() / 2, "TESTCODE");

    end = high_resolution_clock::now();

    a[2][0] = duration_cast<milliseconds>(end - start).count(); 

    start = high_resolution_clock::now(); 

    auto lc = l_cop.begin(); 

    advance(lc, l_cop.size() / 2); 

    l_cop.insert(lc, "TESTCODE");

    end = high_resolution_clock::now(); 

    a[2][1] = duration_cast<milliseconds>(end - start).count();  

    set<string> s_cop = s; 

    start = high_resolution_clock::now(); 

    s_cop.insert("TESTCODE"); 

    end = high_resolution_clock::now(); 

    a[2][2] = duration_cast<milliseconds>(end - start).count(); 

    start = high_resolution_clock::now(); 

    v_cop.erase(v_cop.begin() + v_cop.size() / 2); 

    end = high_resolution_clock::now(); 

    a[3][0] = duration_cast<milliseconds>(end - start).count();  

    start = high_resolution_clock::now(); 

    lc = l_cop.begin(); 

    advance(lc, l_cop.size() / 2); 

    l_cop.erase(lc);

    end = high_resolution_clock::now(); 

    a[3][1] = duration_cast<milliseconds>(end - start).count();  

    start = high_resolution_clock::now();

    s_cop.erase(s_cop.find("TESTCODE"));

    end = high_resolution_clock::now(); 

    a[3][2] = duration_cast<milliseconds>(end - start).count(); 
}

int main() {

    long long a[4][3][NUM]; 

    for (int i = 0; i < NUM; i++) {

        vector<string> vs; 

        list<string> ls; 

        set<string> ss; 
        
        load_data(FILENAME, vs, ls, ss);

        long long temp_a[4][3]; 

        preform_op(vs, ls, ss, temp_a);

    } 

    load_data(FILENAME, vs, ls, ss); 

    preform_op(vs, ls, ss); 

    return 0;
}
