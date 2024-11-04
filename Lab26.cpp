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

    auto v_duration = duration_cast<nanoseconds>(end - start).count(); 

    file.clear();

    file.seekg(0); 

    start = high_resolution_clock::now(); 

    while (getline(file, sa)) {

        l.push_back(sa);
    }

    end = high_resolution_clock::now(); 

    auto l_duration = duration_cast<nanoseconds>(end - start).count();

    file.clear(); 

    file.seekg(0); 

    start = high_resolution_clock::now(); 

    while (getline(file, sa)) {

        s.insert(sa);
    }

    end = high_resolution_clock::now(); 

    auto s_duration = duration_cast<nanoseconds>(end - start).count();  

    file.close(); 
}

void preform_op(const vector<string> &v, const list<string> &l, const set<string> &s, long long a[4][3]) {

    vector<string> v_cop = v; 

    auto start = high_resolution_clock::now();

    sort(v_cop.begin(), v_cop.end());

    auto end = high_resolution_clock::now(); 

    a[0][1] = duration_cast<nanoseconds>(end - start).count(); 

    list<string> l_cop = l;

    start = high_resolution_clock::now(); 

    l_cop.sort();

    end = high_resolution_clock::now(); 

    a[1][1] = duration_cast<nanoseconds>(end - start).count();  

    start = high_resolution_clock::now(); 

    for (int i = 0; i < 1000; ++i) {

        v_cop.insert(v_cop.begin() + v_cop.size() / 2, "TESTCODE" + to_string(i));
    }

    end = high_resolution_clock::now();

    a[2][0] = duration_cast<nanoseconds>(end - start).count(); 

    start = high_resolution_clock::now(); 

    for (int i = 0; i < 1000; ++i) {

        auto lc = l_cop.begin();

        advance(lc, l_cop.size() / 2);

        l_cop.insert(lc, "TESTCODE" + to_string(i)); 
    }

    end = high_resolution_clock::now(); 

    a[2][1] = duration_cast<nanoseconds>(end - start).count();  

    set<string> s_cop = s; 

    start = high_resolution_clock::now(); 

    for (int i = 0; i < 1000; ++i) {

        s_cop.insert("TESTCODE" + to_string(i));
    } 

    end = high_resolution_clock::now(); 

    a[2][2] = duration_cast<nanoseconds>(end - start).count(); 

    start = high_resolution_clock::now(); 

    for (int i = 0; i < 1000; ++i) {

        v_cop.erase(v_cop.begin() + v_cop.size() / 2);
    } 

    end = high_resolution_clock::now(); 

    a[3][0] = duration_cast<nanoseconds>(end - start).count();  

    start = high_resolution_clock::now(); 

    for (int i = 0; i < 1000; ++i) {

        auto lc = l_cop.begin(); 

        advance(lc, l_cop.size() / 2);

        l_cop.erase(lc); 
    }

    end = high_resolution_clock::now(); 

    a[3][1] = duration_cast<nanoseconds>(end - start).count();  

    start = high_resolution_clock::now();

    for (int i = 0; i < 1000; ++i) {

        s_cop.erase(s_cop.find("TESTCODE" + to_string(i)));
    }

    end = high_resolution_clock::now(); 

    a[3][2] = duration_cast<nanoseconds>(end - start).count(); 
}

int main() {

    long long a[4][3][NUM]; 

    for (int i = 0; i < NUM; ++i) {

        vector<string> vs; 

        list<string> ls; 

        set<string> ss; 
        
        load_data(FILENAME, vs, ls, ss);

        long long temp_a[4][3]; 

        preform_op(vs, ls, ss, temp_a);

    for (int j = 0; j < 4; ++j) {

        for (int k = 0; k < 3; ++k) {

            a[j][k][i] = temp_a[j][k]; 

        } 
    }

    } 

    cout << "Number of simualtions: " << NUM << endl << "Operation   Vector   List   Set\n";  

    const char* operation[4] = {"Read", "Sort", "Insert", "Delete"}; 

    for (int j = 0; j < 4; ++j) {

        cout << setw(10) << operation[j];

            for (int k = 0; k < 3; ++k) {

            long long sum = 0; 

            for (int i = 0; i < NUM; ++i) {

                sum += a[j][k][i];
            }

            long long average = sum / NUM; 

            cout << setw(12) << (average == -1 ? 0 : average);

        }
            cout << endl; 
    }

    return 0;
}
