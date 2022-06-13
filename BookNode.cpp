/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   BookNode.cpp
 * Author: admin
 * 
 * Created on June 8, 2022, 4:07 PM
 */

#include "BookNode.h"

BookNode::BookNode() 
{
    title = "";
    author = "";
    numCopiesAvailable = 0;
    nextBook = NULL;
}

BookNode::BookNode(string titleParam, 
        string authorParam)
{
    title = titleParam;
    author = authorParam;
    numCopiesAvailable = 1;
    nextBook = NULL;
}

BookNode::BookNode(string titleParam, 
        string authorParam, int numCopiesParam)
{
    title = titleParam;
    author = authorParam;
    numCopiesAvailable = numCopiesParam;
    nextBook = NULL;
}

BookNode::BookNode(string titleParam, 
        string authorParam, int numCopiesParam, 
        BookNode *nextParam)
{
    title = titleParam;
    author = authorParam;
    numCopiesAvailable = numCopiesParam;
    nextBook = nextParam;
}

BookNode::BookNode(const BookNode& orig) 
{
    //set fields
}

BookNode::~BookNode() {
}

BookNode* BookNode::getNextBook()
{
    return nextBook;
}

void BookNode::setNextBook(BookNode *next)
{
    nextBook = next;
}

void BookNode::setNumAvailable(const int newNumAvailable)
{
    numCopiesAvailable = newNumAvailable;
}

string BookNode::getTitle() const
{
    return title;
}

string BookNode::getAuthor() const
{
    return author;
}

int BookNode::getNumAvailable() const
{
    return numCopiesAvailable;
}

void BookNode::print() const
{
    cout << "\t" << title << " by ";
    cout << author << " has ";
    cout << numCopiesAvailable << " cop";
    cout << (numCopiesAvailable > 1 ? "ies" : "y");
    cout << " available." << endl;
}