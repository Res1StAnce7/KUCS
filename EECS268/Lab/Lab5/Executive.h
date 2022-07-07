#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
using namespace std;

class Executive
{
    public:
    Executive(string lineCommand);

    /** 
    * @pre 
    * @post run the show
    * @throw 
    **/
    void run();

    private:
    string m_filename;
};

#endif 
