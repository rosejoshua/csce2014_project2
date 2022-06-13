/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   BookNode.h
 * Author: admin
 *
 * Created on June 8, 2022, 4:07 PM
 */

#ifndef BOOKNODE_H
#define BOOKNODE_H

#include <iostream>
using namespace std;


class BookNode {
public:
    BookNode();
    BookNode(string titleParam, string authorParam);
    BookNode(string titleParam, string authorParam, int numCopiesParam);
    BookNode(string titleParam, string authorParam, int numCopiesParam, BookNode *nextParam);
    BookNode(const BookNode& orig);
    virtual ~BookNode();
    string getTitle() const;
    string getAuthor() const;
    int getNumAvailable() const;
    void setNumAvailable(int newNumAvailable);
    void setNextBook(BookNode *next);
    BookNode* getNextBook();
    void print() const;
private:
    string title;
    string author;
    int numCopiesAvailable;
    BookNode *nextBook;

};

#endif /* BOOKNODE_H */

