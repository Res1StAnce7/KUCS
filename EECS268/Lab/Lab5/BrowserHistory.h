#ifndef BROWSERHISTORY_H
#define BROWSERHISTORY_H
#include "BrowserHistoryInterface.h"
#include "LinkedList.h"
using namespace std;

class BrowserHistory : public BrowserHistoryInterface
{
    public:
    BrowserHistory();
    ~BrowserHistory();

    /**
    * @pre none
    * @post the browser navigate to the given url
    * @param url, a string representing a URL
    */
    void navigateTo(string url);

    /**
    * @pre none
    * @post if possible, the browser navigates forward in the history otherwise it keeps focus on the current URL
    */
    void forward();

    /**
    * @pre none
    * @post if possible, the browser navigates backwards in the history otherwise it keeps focus on the current URL 
    */
    void back();
    
    /**
    * @return the current URL 
    */
    string current() const;

    /**
    * @pre None
    * @post The list is cleared out, then the current browser history is copied into the given list  
    * @param destination, an empty list of strings
    */
    void copyCurrentHistory(ListInterface<string> &destination);

    /** 
    * @pre 
    * @post print the browser history
    * @throw   
    **/
    void history() const;

    protected:
    int m_current;
    LinkedList<string> *URLContainer;
};

#endif
