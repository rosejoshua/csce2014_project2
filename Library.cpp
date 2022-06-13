/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Library.cpp
 * Author: admin
 * 
 * Created on June 8, 2022, 4:02 PM
 */

//#include <string>
#include "Library.h"

using namespace std;

Library::Library() 
{
    head = NULL;
}

Library::Library(const Library& orig) 
{
    head = orig.head;
}

Library::~Library() 
{
    if (head != NULL)
    {
        BookNode *prev = head;
        BookNode *next = head->getNextBook();
        while(next != NULL)
        {
            delete prev;
            prev = next;
            next = next->getNextBook();
        }
        delete prev;
    }
}

void Library::returnBook(string title, string author)
{
    BookNode *bookNode = search(title, author);
    if (bookNode!=NULL)
    {
        bookNode->setNumAvailable(bookNode->getNumAvailable()+1);
    }
    else 
    {
        bookNode = new BookNode(title, author);   
        BookNode *temp = head;
        BookNode *prev = head;
        //All but first book should succeed here
        if (temp != NULL)
        {
            //short circuits and fails if temp is null
            //if the book coming in has a higher alphanumeric author value than temp, we move to next node
            while(temp != NULL && bookNode->getAuthor() > temp->getAuthor())
            {
                prev = temp;
                temp = temp->getNextBook();
            }        

            if (temp !=NULL)
            {
                //if the temp node isn't null, check for same author...
                //while true, see if new book has higher alphanumeric title and move to next node accordingly
                while(temp != NULL && temp->getAuthor() == bookNode->getAuthor() && bookNode->getTitle() > temp->getTitle())
                {                
                    prev = temp;
                    temp = temp->getNextBook();                
                }
                if (temp!=NULL && bookNode->getAuthor()==temp->getAuthor() && bookNode->getTitle() == temp->getTitle())
                {
                    bookNode->setNumAvailable(bookNode->getNumAvailable()+1);
                }            
            }

            //Case of single book in library that is higher alphanumeric value than new book
            if(temp==prev && prev==head)
            {
                head = bookNode;
                head->setNextBook(temp);
            }
            //at this point temp will have been set to NULL or is a...
            //book higher in alphanumeric value than new book.
            else
            {
                prev->setNextBook(bookNode);            
                bookNode->setNextBook(temp);
            }        
        }
        else head = bookNode;
    }
    
    cout << bookNode->getTitle() << " by " << bookNode->getAuthor() << 
                    " has been returned. There " << 
                    (bookNode->getNumAvailable() > 1 ?
                        "are " + to_string(bookNode->getNumAvailable()) + " copies available." : "is 1 copy available.") 
                    << endl;
}


void Library::deleteBook(BookNode *bookNode)
{
    if(bookNode==NULL)
    {
        cout << "Error, trying to delete null BookNode" << endl;
        return;
    }
    BookNode *prev;
    BookNode *next;    
    
    if(bookNode!=NULL)
        next = bookNode->getNextBook();
    
    if (head!=NULL)
    {   
        
        prev = head;
        if (head==bookNode)
        {
            head = head->getNextBook();
            delete prev;
        }
        else 
        {
             while (prev->getNextBook() != bookNode)
             {
                prev = prev->getNextBook();
             }
             prev->setNextBook(bookNode->getNextBook());
             delete bookNode;
        }

    }
    else 
    {
        cout << "Error, trying to delete book from empty library" << endl;
    }
    
}

void Library::checkout(string title, string author)
{
    BookNode *temp = search(title, author);    
    if (temp == NULL)
    {
        cout << title << " by " << author << " is not currently in our system. Please check back at another time." << endl;
    }    
    else 
    {
        searchAndUpdateOrDelete(temp);
    }    
}

BookNode* Library::search(string title, string author)
{
    BookNode *temp = head;
    while (temp != NULL)
    {
        if (temp->getTitle()== title && temp->getAuthor()==author)
            return temp;
        else temp = temp->getNextBook();
    }
    return NULL;
}

BookNode* Library::getHead()
{
    return head;
}

void Library::setHead(BookNode *newHead)
{
    head = newHead;
}

void Library::searchAndUpdateOrDelete(BookNode *bookNode)
{
    bookNode->setNumAvailable(bookNode->getNumAvailable()-1);
    if (bookNode->getNumAvailable()==0)
    {
        cout << "The last copy of " << bookNode->getTitle() << 
                " by " << bookNode->getAuthor() << " has been checked out." << endl;
        deleteBook(bookNode);
    }
    else 
    {
        cout << bookNode->getTitle() << " by " << bookNode->getAuthor() << 
                " has been successfully checked out. There " << 
                (bookNode->getNumAvailable() > 1 ?
                    "are " + to_string(bookNode->getNumAvailable()) + " copies remaining." : "is 1 copy remaining.") 
                << endl;
    }
    
}

void Library::printByAuthor(string author)
{
    bool didntFindAny = true;
    bool needInitialPrintStatement = true;
    
    BookNode *temp = head;
    while (temp != NULL)
    {
        if (temp->getAuthor()==author)
        {
            didntFindAny = false;
            if (needInitialPrintStatement)
            {
                cout << "The following titles by "<< author <<" are currently in stock:" << endl;
                needInitialPrintStatement = false; 
            }            
            //temp-> title is available, there are numcopies etc
            cout <<"\t" << temp->getTitle() << " is available. There" << (temp->getNumAvailable() > 1 ?
                        " are " + to_string(temp->getNumAvailable()) + " copies available." : " is 1 copy available.") << endl;
        }            
        temp = temp->getNextBook();
    }
    
    if (didntFindAny)
    {
        //finish
        cout << "There are no titles by " << author << " found in the system." << endl;
    }
}

void Library::printBookList(BookNode *startBook, bool firstCall)
{
    if (startBook != NULL)
    {
        if(firstCall)
        {
            cout << "The library currently has the following books in stock: " << endl;
        }
        startBook->print();
        if (startBook->getNextBook() != NULL)
        {            
            printBookList(startBook->getNextBook(), false);
        }
    }
    
}

