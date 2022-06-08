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
    //set defaults
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

string BookNode::getTitle() const
{
    return title;
}

string BookNode::getAuthor() const
{
    return author;
}