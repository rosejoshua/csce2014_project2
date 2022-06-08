/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Library.h
 * Author: admin
 *
 * Created on June 8, 2022, 4:02 PM
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include "BookNode.h"

class Library {
public:
    Library();
    Library(const Library& orig);
    virtual ~Library();
    
    void insertBook(BookNode *bookNode);
    void deleteBook();
    void search();
    void print();
    
    
private:

};

#endif /* LIBRARY_H */

