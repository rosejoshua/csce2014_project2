/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on June 8, 2022, 3:55 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Library.h"
#include <string>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Library library;
    //project2-books.txt    
    std::string filename = "";
    ifstream infile;
    std::string inputString = "";
    int delim = 0;
    
    cout << "Please input a filename to open >> ";
    
    cin >> filename;
    
    infile.open(filename);
    if(infile.fail())
    {
        cout << "Open file failed... exiting now.\n";
    }
    while(infile.peek() != EOF)
    {
        inputString = "";
        getline(infile, inputString);
        switch(inputString[0]){
            case '1':
                for(int i=2; i<inputString.length(); i++)
                {
                    if(inputString.at(i) == ' ')
                    {
                        delim = i;
                    }
                }
                
                library.returnBook(inputString.substr(2,delim-2), inputString.substr(delim+1, inputString.length()-delim-1));
                break;
            
            case '2':
                for(int i=2; i<inputString.length(); i++)
                {
                    if(inputString.at(i) == ' ')
                    {
                        delim = i;
                    }
                }
                library.checkout(inputString.substr(2,delim-2), inputString.substr(delim+1, inputString.length()-delim-1));
                break;
                
            case '3':
                library.printByAuthor(inputString.substr(2));
                break;
            
            case '4':
                library.printBookList(library.getHead(), true);
                break;
                
            case '5':
                cout << "Thank you for using the new library system!  Goodbye." << endl;
                return 0;
            break;
            
            default:
                cout << "Error in switch statement" << endl;
        }
                
    }
    infile.close();
    
    return 0;
}

