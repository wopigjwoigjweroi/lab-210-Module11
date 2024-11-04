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
void preform_op(const vector<string> &v, const list<string> &l, const set<string> &s); 

void load_data(const string& filename, vector<string>& v, list<string>& l, set<string> s) {

    fstream file("codes.txt");

    string sa; 

    auto start = high_resolution_clock::now(); 

    while (getline(file, sa)) {

        v.push_back(sa); 
    }

    auto end = high_resolution_clock::now(); 

    auto v_duration = duration_cast<milliseconds>(end - start).count();

    cout << "Read - Vector: " << v_duration.count() << "ms\n"; 

    file.clear();

    file.seekg(0); 

    start = high_resolution_clock::now(); 

    while (getline(file, sa)) {

        l.push_back(sa);
    }

    end = high_resolution_clock::now(); 

    auto l_duration = duration_cast<milliseconds>(end - start).count();

    cout << "Read - List: " << l_duration.count() << "ms\n"; 

    file.clear(); 

    file.seekg(0); 

    start = high_resolution_clock::now(); 

    while (getline(file, sa)) {

        s.insert(sa);
    }

    end = high_resolution_clock::now(); 

    auto s_duration = duration_cast<milliseconds>(end - start).count(); 

    cout << "Read - Set: " << s_duration.count() << "ms\n"; 

    file.close(); 
}

void preform_op(const vector<string> &v, const list<string> &l, const set<string> &s) {

    vector<string> v_cop = v; 

    auto start = high_resolution_clock::now();

    sort(v_cop.begin(), v_cop.end());

    auto end = high_resolution_clock::now(); 

    auto vc_duration = duration_cast<milliseconds>(end - start); 

    cout << "Sort - Vector: " << vc_duration.count() << "ms\n"; 

    list<string> l_cop = l;

    start = high_resolution_clock::now(); 

    l_cop.sort();

    end = high_resolution_clock::now(); 

    auto ls_duration = duration_cast<milliseconds>(end - start); 

    cout << "Sort - List: " << ls_duration.count() << "ms\n"; 

    cout << "Sort - Set: -1 ms" << endl; 

    start = high_resolution_clock::now(); 

    v_cop.insert(v_cop.begin() + v_cop.size() / 2, "TESTCODE");

    end = high_resolution_clock::now();

    auto vc_ins = duration_cast<milliseconds>(end - start);

    cout << "Insert - Vector: " << vc_ins.count() << "ms\n"; 

    start = high_resolution_clock::now(); 

    auto lc = l_cop.begin(); 

    advance(lc, l_cop.size() / 2); 

    l_cop.insert(lc, "TESTCODE");

    end = high_resolution_clock::now(); 

    auto lc_ins = duration_cast<milliseconds>(end - start); 

    cout << "Insert - List: " << lc_ins.count() << "ms\n"; 

    set<string> s_cop = s; 

    start = high_resolution_clock::now(); 

    s_cop.insert("TESTCODE"); 

    end = high_resolution_clock::now(); 

    auto sc_ins = duration_cast<milliseconds>(end - start); 

    cout << "Insert - Set: " << sc_ins.count() << "ms\n";

    start = high_resolution_clock::now(); 

    v_cop.erase(v_cop.begin() + v_cop.size() / 2); 

    end = high_resolution_clock::now(); 

    auto vector_delete = duration_cast<milliseconds>(end - start); 

    cout << "Delete - Vector: " << vector_delete.count() << "ms\n"; 

    start = high_resolution_clock::now(); 

    lc = l_cop.begin(); 

    advance(lc, l_cop.size() / 2); 

    l_cop.erase(lc);

    end = high_resolution_clock::now(); 

    auto list_delete = duration_cast<milliseconds>(end - start); 

    cout << "Delete - List: " << list_delete.count() << "ms\n"; 

    start = high_resolution_clock::now();

    s_cop.erase(s_cop.find("TESTCODE"));

    end = high_resolution_clock::now(); 

    auto set_delete = duration_cast<milliseconds>(end - start); 

    cout << "Delete - Set: " << set_delete.count() << "ms\n";
}

int main() {

    vector<string> vs; 

    list<string> ls; 

    set<string> ss; 

    load_data(FILENAME, vs, ls, ss); 

    preform_op(vs, ls, ss); 

    return 0;
}
