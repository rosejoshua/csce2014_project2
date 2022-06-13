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
    void returnBook(string title, string);
    void deleteBook(BookNode *bookNode);    
    void printByAuthor(string author);
    void checkout(string title, string author);
    BookNode* search(string title, string author);
    BookNode* getHead();
    void searchAndUpdateOrDelete(BookNode *bookNode);
    void setHead(BookNode *newHead);
    void printBookList(BookNode *startBook, bool firstCall);
    
    
private:    
    BookNode *head;

};

#endif /* LIBRARY_H */

