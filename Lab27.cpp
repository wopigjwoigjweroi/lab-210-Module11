#include <iostream>
#include <string>
#include <map>
#include <tuple>
using namespace std;

void display(const map<string, tuple<int, string, string>>& villagerInfo);
void add(map<string, tuple<int, string, string>>& villagerInfo); 
void deleteVillage(map<string, tuple<int, string, string>>& villagerInfo); 
void friendshipIncrease(map<string, tuple<int, string, string>>& villagerInfo); 
void friendshipDecrease(map<string, tuple<int, string, string>>& villagerInfo); 
void search(map<string, tuple<int, string, string>>& villagerInfo); 

void add(map<string, tuple<int, string, string>>& villagerInfo) {

    int friendship; 

    string name, species, catchphrases; 

    cout << "Villager Name: "; 
    cin >> name; 

    cout << "Friendship Level: "; 
    cin >> friendship; 

    cout << "Species: "; 
    cin >> species;

    cout << "Catchphrase: "; 
    cin >> catchphrases; 

    cin.ignore();

    getline(cin, catchphrases); 

    villagerInfo[name] = make_tuple(friendship, species, name, catchphrases); 

    cout << name << " added." << endl; 

}

void deleteVillage(map<string, tuple<int, string, string>>& villagerInfo) {

    string name; 

    cout << "Enter villager name: "; 
    cin >> name; 

    if (villagerInfo.erase(name)) {

        cout << name << " is deleted\n"; 
    } else {
        
        cout << "Name not found.\n";
    }

}

void friendshipIncrease(map<string, tuple<int, string, string>>& villagerInfo) {

    string name; 

    cout << "Enter villager name for friendship increase: ";
    cin >> name; 

    auto a = villagerInfo.find(name); 

        if (a != villagerInfo.end()) {

            int& friendship = get<0>(a->second);

            if (friendship < 10) {

                friendship++; 

                cout << "Friendship level increased to: " << friendship << endl; 
                
            } else {

                cout << "Friendship level has reached it's maximum.\n"; 
         } 
            
            } else {

                cout << name << " doesn't exist.\n"; 
        }
}

void friendshipDecrease(map<string, tuple<int, string, string>>& villagerInfo) {

    
}

int main() {
  

    return 0;
}
