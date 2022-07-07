#ifndef BROWSERHISTORYINTERFACE_H
#define BROWSERHISTORYINTERFACE_H
#include "ListInterface.h"
#include <string>
using namespace std;

class BrowserHistoryInterface
{
  public:
  /**
  * @post All memory allocated by the implementing class should be freed. 
  *       This, as with all virtual destructors, is an empty definition since we
  *       have no knowledge of specific implementation details.
  */
  virtual ~BrowserHistoryInterface(){} 

  /**
  * @pre none
  * @post the browser navigate to the given url
  * @param url, a string representing a URL
  */
  virtual void navigateTo(string url) = 0;

  /**
  * @pre none
  * @post if possible, the browser navigates forward in the history otherwise it keeps focus
  *         on the current URL
  */
  virtual void forward() = 0;

  /**
  * @pre none
  * @post if possible, the browser navigates backwards in the history otherwise it keeps focus
  *         on the current URL 
  */
  virtual void back() = 0;

  /**
  * @return the current URL 
  */
  virtual string current() const = 0;

  /**
  * @pre None
  * @post The list is cleared out, then the current browser history is copied into the given list  
  * @param destination, an empty list of strings
  */
  virtual void copyCurrentHistory(ListInterface<string>& destination) = 0;

};

#endif
