/**
 * @file Executive.cpp
 * @author Siliang Zhang
 * @brief This file will create new Shapes and run the show
 * @date 2021-03-15
 */
#include <iostream>
#include <string>
#include <fstream>
#include "Executive.h"
#include "ShapeContainer.h"
#include "Shape.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
using namespace std;

Executive::Executive(string lineCommand)
{
    m_filename = lineCommand;
    m_sizeOfContainer = 0;
}

void Executive::run()
{
    fstream inFile;
    inFile.open(m_filename);

    if(inFile.is_open())
    {   
        inFile >> m_sizeOfContainer;
        ShapeContainer Container(m_sizeOfContainer);
        string command;
        string shapeName;
        int index = 0;
        double base;
        double height;
        double length;
        double width;
        double radius;
        
        Circle** cirPtr = new Circle*[m_sizeOfContainer];
        Triangle** triPtr = new Triangle*[m_sizeOfContainer];
        Rectangle** recPtr = new Rectangle*[m_sizeOfContainer];
        
        for(int i=0; i<m_sizeOfContainer; i++)
        {
            cirPtr[i] = new Circle();
            triPtr[i] = new Triangle();
            recPtr[i] = new Rectangle();
        }
        
        inFile >> command;
        while(command.compare("EXIT") != 0)
        {
            if(command.compare("ADD") == 0)
            {
                inFile >> index;
                inFile >> shapeName;
                
                if(shapeName.compare("CIR") == 0)
                {
                    inFile >> radius;

                    if(isValid_Cir(radius))
                    {
                        cirPtr[index]->set(radius);
                        Container.add(cirPtr[index],index);
                    }
                    else
                    {
                        cout << "Unable to add Circle to index "<<index<<" due to invalid radius!" << endl;
                    }
                }

                else if(shapeName.compare("TRI") == 0)
                {
                    inFile >> base;
                    inFile >> height;

                    if(isValid_Tri(base, height))
                    {
                        triPtr[index]->set(base,height);
                        Container.add(triPtr[index],index);
                    }
                    else
                    {
                        cout << "Unable to add Triangle to index "<<index<<" due to invalid base or height!" << endl;
                    }
                }

                else if(shapeName.compare("REC") == 0)
                {
                    inFile >> length;
                    inFile >> width;

                    if(isValid_Rec(length, width))
                    {
                        recPtr[index]->set(length,width);
                        Container.add(recPtr[index],index);
                    }
                    else
                    {
                        cout << "Unable to add Rectangle to index "<<index<<" due to invalid length or width!" << endl;
                    }
                }   
            }

            else if(command.compare("PRINT") == 0)
            {
                inFile >> index;
                try
                {
                    cout << "Shape at index "<<index<<": "<<Container.shapeName(index)<<" area = "<<Container.area(index)<<"" << endl;
                }
                catch(runtime_error& rte)
                {
                    cerr << rte.what() << endl;
                }
            }

            else if(command.compare("DELETE") == 0)
            {
                inFile >> index;
                try
                {
                    Container.remove(index);
                }
                catch(runtime_error& rte)
                {
                    cerr << "Shape at index "<<index<<": " << rte.what() << endl;
                } 
            }

            inFile >> command;
        }
        cout << "Exiting..." << endl;
        
        if(cirPtr != nullptr)
        {
            for(int i=0; i<m_sizeOfContainer; i++)
            {
                delete cirPtr[i];
            }
            delete[] cirPtr;
        } 

        if(triPtr != nullptr)
        {
            for(int i=0; i<m_sizeOfContainer; i++)
            {
                delete triPtr[i];
            }
            delete[] triPtr;
        }

        if(recPtr != nullptr)
        {
            for(int i=0; i<m_sizeOfContainer; i++)
            {
                delete recPtr[i];
            }
            delete[] recPtr;
        }
  
        inFile.close();
    }

    else
    {
        cout << "The file cannot be opened!" << endl;
    }
}

bool Executive::isValid_Cir(double radius)
{
    if(radius <= 0)
    {
        return false;
    }

    else 
    {
        return true;
    }
}

bool Executive::isValid_Tri(double base, double height)
{
    if(base <= 0 || height <= 0)
    {
        return false;
    }

    else 
    {
        return true;
    }
}

bool Executive::isValid_Rec(double length, double width)
{
    if(length <= 0 || width <= 0)
    {
        return false;
    }

    else 
    {
        return true;
    }
}