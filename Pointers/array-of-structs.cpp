#include <bits/stdc++.h>
using namespace std;

struct Person {

  string name;
  int height;
  int weight;
  double doglo;

  // Person(){
  //     name = "Umang";
  //     height = weight = 1;
  //     cout<<"Constructor Invoked !"<<endl;
  // }

  //the constructer will be called 6 times, 3 for creating objects and 3 objects of arrays

  void setter(string name1, int height1, int weight1) {
    name = name1;
    height = height1;
    weight = weight1;
  };
  void name_printer() {
    cout << name << "\t" << height << "\t" << weight << endl;
  }
};

int main() {
  Person umang, harsh, jay;
  Person arr_of_structs[3];
  Person *arr_of_pointers[3];

  umang.setter("umang", 182, 60);
  arr_of_structs[0] = umang;
  arr_of_pointers[0] = &umang;

  harsh.setter("harsh", 181, 75);
  arr_of_structs[1] = harsh;
  arr_of_pointers[1] = &harsh;

  jay.setter("jay", 183, 63);
  arr_of_structs[2] = jay;
  arr_of_pointers[2] = &jay;

  cout << "Printing through array of structs" << endl;
  for (auto person : arr_of_structs) {
    person.name_printer();
  }

  cout << endl;

  cout << "Printing through array of pointers" << endl;
  for (auto person : arr_of_pointers) {
    person->name_printer();
  }
}
