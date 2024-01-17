#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <cstdlib>
#include <cstring>


using namespace std;



void createList();
void addTask();
void viewList();
void removeTask(const std::string& filename, int taskToDelete);

void menu(){
system("clear");
int a;

cout << "If you want create a list , please press 1 " << endl;
cout << "If you want add taks to an existing list , please press 2 " << endl;
cout << "If you want to see any existent list , press 3 " << endl;
cout << "If you want exit , press 4 " << endl;
cout << "Your answer: "; cin >> a; cout << endl;

switch (a)
{
case 1: createList();
case 2: addTask();
case 3:viewList();
case 4: break;
}

}

int main(){

menu();

    return 0;
}

void createList(){
ofstream newlist;
string name;
cin.ignore();
getline(cin , name);
newlist.open(name+".txt");
newlist.close();
system("clear");
menu();
}

void addTask(){
ifstream fileL;
string list;
cin >> list;
fileL.open(list+".txt"); 

if(!fileL.is_open()){
    cout << "That List isn't exist" << endl;
   // menu();
}
else{
ofstream fileW;
string task;
cin.ignore();
getline(cin , task);
fileW.open(list+".txt" , std::ios::app);
fileW << task << endl;
}

system("clear");
menu();

//file.open(list+"txt", std::ios::app);
//menu();
}

void viewList() {
    std::ifstream list;
    std::string name;
    std::string task;

    std::cin.ignore(); // Ignora el carácter de nueva línea pendiente

    std::cout << "Name of the List: ";
    std::getline(std::cin, name);
    std::cout << std::endl;

    list.open(name + ".txt");

	//list >> task;
	//cout << task << endl;
    if (list.is_open()) {
        int index = 1;

        if (getline(list, task)) {
            do {
                cout << index << ". " << task << endl;
                index++;
            } while (getline(list, task));

            int taskToDelete;
            cout << "Enter the number of the task to delete (0 to cancel): ";
            cin >> taskToDelete;

            if (taskToDelete > 0 && taskToDelete < index) {
                // Eliminar tarea seleccionada
                removeTask(name + ".txt", taskToDelete);
            }
        } else {
            std::cout << "List is empty." << std::endl;
        }

        list.close();
    } else {
        std::cout << "List doesn't exist" << std::endl;
    }

    getchar();
    menu();
}

void removeTask(const std::string& filename, int taskToDelete) {
    std::ifstream originalFile(filename);
    std::ofstream tempFile("temp.txt", std::ios::app);

    std::string task;
    int index = 1;

    while (getline(originalFile, task)) {
        if (index != taskToDelete) {
            tempFile << task << std::endl;
        }
        index++;
    }

    originalFile.close();
    tempFile.close();

    // Reemplazar el archivo original con el temporal
    std::remove(filename.c_str());
    std::rename("temp.txt", filename.c_str());

    std::cout << "Task deleted successfully." << std::endl;
}
