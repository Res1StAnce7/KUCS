/**
 * @file BrowserHistory.cpp
 * @author Siliang Zhang
 * @brief This file will implement the linked browser history
 * @date 2021-03-22 
 */
#include <iostream>
#include "BrowserHistory.h"
#include "LinkedList.h"
using namespace std;

BrowserHistory::BrowserHistory()
{
    m_current = 0;
    URLContainer = new LinkedList<string>();
}

BrowserHistory::~BrowserHistory()
{
    if(URLContainer != nullptr)
    {
        delete URLContainer;
    }  
}

void BrowserHistory::navigateTo(string url)
{
    try
    {
        m_current++;
        URLContainer->insert(m_current, url);

        if (m_current < URLContainer->length())
        {
            int tempLength = URLContainer->length();
            for (int i = 0; i < (tempLength - m_current); i++)
            {
                URLContainer->remove(m_current + 1);
            }
        }
    }

    catch (runtime_error &rte)
    {
        cerr << rte.what() << endl;
    }
}

void BrowserHistory::forward()
{
    if (m_current < URLContainer->length())
    {
        m_current++;
    }
}

void BrowserHistory::back()
{
    if (m_current > 1)
    {
        m_current--;
    }
}

string BrowserHistory::current() const
{
    return (URLContainer->getEntry(m_current));
}

void BrowserHistory::history() const
{

    cout << "Oldest" << endl;
    cout << "===========" << endl;
    for (int i = 1; i <= URLContainer->length(); i++)
    {
        try
        {
            if (URLContainer->getEntry(i).compare(URLContainer->getEntry(m_current)) == 0)
            {
                cout << "<" << URLContainer->getEntry(i) << ">  <==current" << endl;
            }

            else
            {
                cout << "<" << URLContainer->getEntry(i) << ">" << endl;
            }
        }

        catch (runtime_error &rte)
        {
            cerr << rte.what() << endl;
        }
    }
    cout << "===========" << endl;
    cout << "Newest" << endl;
}

void BrowserHistory::copyCurrentHistory(ListInterface<string> &destination)
{
    for (int i = 1; i <= URLContainer->length(); i++)
    {
        destination.insert(destination.length() + 1, URLContainer->getEntry(i));
    }
}
