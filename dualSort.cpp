/*
 *Program Description:A program to sort a series of strings and scores from a file.
 *
 *Programmer:Timothy A. Gass
 *Date:01/17/17
*/

#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <vector>
#include <ctime>
#include <limits>

using namespace std;

void makeData(string, const int&, const int&);
void getData(vector<string>&, vector<int>&, string, const int&);
void swap(int&, int&);
void swapStr(string&, string&);
void sort(vector<string>&, vector<int>&, const int&);

int main(){
  srand(time(0));
  string fname = "/home/tim/dev/c++/chpt9/data.txt";
  vector<string> name;
  vector<int> score;
  const int SCORE_MAX_SIZE = 100;
  const int PEOPLE_NUM = 50;
  makeData(fname, SCORE_MAX_SIZE, PEOPLE_NUM);
  getData(name, score, fname, PEOPLE_NUM);
  sort(name, score, PEOPLE_NUM);
  cout << "The scores of the class from highest to lowest are: " << endl;
  for(int i = 0; i < PEOPLE_NUM; i++){
    cout << name[i] << endl;
    cout << score[i] << endl;
  }
  cout << "Press enter to exit." << endl;
  cin.ignore();
  return 0;
}

void makeData(string fname, const int& SCORE_MAX_SIZE, const int& PEOPLE_NUM){
  int rand1, rand2, rand3;
  ofstream make(fname);
  vector<string> firstNames = {
    "Gus",
    "Taneka",
    "Shane",
    "Rosella",
    "Bennett",
    "Filiberto",
    "Khadijah",
    "Mafalda",
    "Rusty",
    "Janiece",
    "Shavonne",
    "Azalee",
    "Enedina",
    "Heidy",
    "Lavelle",
    "Darleen",
    "Ashton",
    "Glynis",
    "Gale",
    "Norene",
    "Madaline",
    "Elvin",
    "Jacqueline",
    "Kristofer",
    "Zachary",
    "Lorretta",
    "Jim",
    "Shanelle",
    "Tonja",
    "Alethia",
    "Kasha",
    "Katheleen",
    "Joyce",
    "Kirstin",
    "Neil",
    "Belkis",
    "Maisha",
    "Doretha",
    "Eliseo",
    "Rhiannon",
    "Annamarie",
    "Latoria",
    "Jerica",
    "Betsey",
    "Delinda",
    "Pamula",
    "Porsha",
    "Fredia",
    "Wilda",
    "Belen"
  };

  vector<string> lastNames = {
    "Best",
    "Shields",
    "Finley",
    "Blankenship",
    "Hobbs",
    "Nichols",
    "Mcneil",
    "Robles",
    "Moyer",
    "Hays",
    "Elliott",
    "Ruiz",
    "Ritter",
    "Gamble",
    "Zamora",
    "Cole",
    "Larson",
    "Ibarra",
    "Choi",
    "Santana",
    "Gray",
    "Crane",
    "Campos",
    "Wright",
    "Morris",
    "Flores",
    "Newman",
    "Santos",
    "Li",
    "Archer",
    "Chavez",
    "Avery",
    "Mora",
    "Liu",
    "Lutz",
    "Miles",
    "Stewart",
    "Austin",
    "Wu",
    "Turner",
    "Brennan",
    "Ferrell",
    "Mcmillan",
    "Whitney",
    "Odonnell",
    "Conley",
    "Maxwell",
    "Stafford",
    "Carlson",
    "Peck"
  };

  for(int i = 0; i < PEOPLE_NUM; i++){
    rand1 = rand()%50;
    rand2 = rand()%50;
    rand3 = rand()%(SCORE_MAX_SIZE+1);
    make << firstNames.at(rand1) + " " + lastNames.at(rand2) << endl;
    make << rand3 << endl;
  }
}

void getData(vector<string> &name, vector<int> &score, string fname, const int& PEOPLE_NUM){
  ifstream get(fname);
  string str;
  int num;
  string numStr;
  if(get.fail()){
    cout << "File could not be opened!" << endl;
  }
  else
   {
    for(int i = 0; i < PEOPLE_NUM; i++)
     {
      getline(get, str);
      getline(get, numStr);
      num = stoi(numStr);
      name.push_back(str);
      score.push_back(num);
     }
  }
}

void swap(int& a, int& b){
  int tmp;
  tmp = a;
  a = b;
  b = tmp;
}

void swapStr(string& a, string& b){
  string tmp;
  tmp = a;
  a = b;
  b = tmp;
}

void sort(vector<string>& name, vector<int>& score, const int& PEOPLE_NUM){
  for(int i = 0; i < PEOPLE_NUM; i++){
    int min = i;
    for(int j=0; j < i; j++){
      if(score[j] < score[min]){
        swap(score[j], score[min]);
        swapStr(name[j], name[min]);
      }
    }
  }
}
