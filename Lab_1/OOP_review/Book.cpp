#include <bits/stdc++.h>
using namespace std;
class Book
{
private:
    char* title;
    char* authors;
    int publishingYear;

public:
    Book()
    {
        this->title = nullptr;
        this->authors = nullptr;
        this->publishingYear = 0;
        /*
         * STUDENT ANSWER
         * TODO: set zero publishingYear and null pointer
         */
    }

    Book(const char* title, const char* authors, int publishingYear)
    {
        this->title = new char;
        this->title = const_cast<char*>(title);
        this->authors = new char;
        this->authors = const_cast<char*>(authors);
        this->publishingYear = publishingYear;
    }

    Book(const Book &book)
    {
        this->title = new char;
        this->title = book.title;
        this->authors = new char;
        this->authors = book.authors;
        this->publishingYear = book.publishingYear;
    }
    
    void setTitle(const char* title)
    {
        this->title = new char;
        this->title = const_cast<char*>(title);
    }

    void setAuthors(const char* authors)
    {
        this->authors = new char;
        this->authors = const_cast<char*>(authors);
    }

    void setPublishingYear(int publishingYear)
    {
        this->publishingYear = publishingYear;
    }

    char* getTitle() const
    {
        return title;
    }

    char* getAuthors() const
    {
        return authors;
    }

    int getPublishingYear() const
    {
        return publishingYear;
    }

    ~Book()
    {
        this->title = nullptr;
        this->authors = nullptr;
        publishingYear = 0;
    }

    void printBook(){
        printf("%s\n%s\n%d", this->title, this->authors, this->publishingYear);
    }
};
