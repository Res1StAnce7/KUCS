/**
 * @file Executive.cpp
 * @author Siliang Zhang
 * @brief This file will handle the Pokemon file and load it into the tree, then run the show
 * @date 2021-04-29
 */
#include "Executive.h"
#include <fstream>
#include <iostream>
#include "BST.h"
#include "Pokemon.h"

Executive::Executive(string fileName)
{
    m_fileName = fileName;
    Pokedex = nullptr;
    tree = new BST<Pokemon, int>();
    usa = nullptr;
    jap = nullptr;
    id = nullptr;
    m_size = 0;
}

void Executive::run()
{
    if(load())
    {
        int choice;
        do
        {
            BST_Menu();
            cout << "Please input your choice: ";
            cin >> choice; 

            while(cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "Invalid Choice! Please try again: ";
                cin >> choice;
            }
        
            while(choice < 1 || choice > 5)
            {
                cout << "Invalid Choice! Please try again: ";
                cin >> choice;
            }

            if(choice == 1)
            {
                int tempID;
                cout << "\nInput the id of the Pokemon you want to search: ";
                cin >> tempID;
                while(cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Invalid Input! Please try again: ";
                    cin >> tempID;
                }

                try
                {
                    cout << ""<<tree->search(tempID).getUSA()<<" "<<tree->search(tempID).getID()<<" "<<tree->search(tempID).getJAP()<<"" << endl;
                }
                catch(runtime_error &rte)
                {
                    cerr << rte.what() << endl;
                }    
            }

            else if(choice == 2)
            {
                string tempUSA, tempJAP;
                int tempID;
                cout << "\nPlease input the new Pokemon name (US): ";
                cin >> tempUSA;
                cout << "Please input the new Pokemon name (Jap): ";
                cin >> tempJAP;
                do
                {
                    cout << "Please input the new Pokemon id: ";
                    cin >> tempID;

                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        cout << "Invalid Input! Please try again: ";
                        cin >> tempID;
                    }

                    else if(tempID < 0)
                    {
                        cout << "Invalid Input! Please try again: ";
                        cin >> tempID;
                    }
                } while (cin.fail() || tempID < 0);
                
                addPoke(tempUSA, tempID, tempJAP);
            }

            else if(choice == 3)
            {
                int input;
                T_Order();
                cout << "Please input your choice: ";
                cin >> input;

                do
                {
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        cout << "Invalid Choice! Please try again: ";
                        cin >> input;
                    }

                    else if(input < 1 || input > 3)
                    {
                        cout << "Invalid Choice! Please try again: ";
                        cin >> input;
                    }
                } while (cin.fail() || input < 1 || input > 3);

                if(input == 1)
                {
                    try
                    {
                        tree->visitInOrder(visit);
                    }
                    catch(runtime_error& rte)
                    {
                        cerr << rte.what() << endl;
                    }
                }

                else if(input == 2)
                {
                    try
                    {
                        tree->visitPreOrder(visit);
                    }
                    catch(runtime_error& rte)
                    {
                        cerr << rte.what() << endl;
                    }
                }

                else if(input == 3)
                {
                    try
                    {
                        tree->visitPostOrder(visit);
                    }
                    catch(runtime_error& rte)
                    {
                        cerr << rte.what() << endl;
                    }
                } 
            }

            else if(choice == 4)
            {
                int input;
                cout << "Input: ";
                cin >> input;
                try
                {
                   tree->remove(input);
                }
                catch(runtime_error& rte)
                {
                    cerr << rte.what() << endl;
                }  
            }

            else if(choice == 5)
            {
                tree->clear();
                clear();
            }

            if(choice != 5)
            {
                cout << endl;
            }
        } while (cin.fail() || choice < 1 || choice > 5 || choice != 5); 
    }
}

bool Executive::read()
{
    fstream inFile1;
    inFile1.open(m_fileName);

    if(inFile1.is_open())
    {
        string sizeTest;
        while(!inFile1.eof())
        {
            inFile1 >> sizeTest;
            m_size++;
        }
        m_size = m_size / 3;
        
        inFile1.close();

        fstream inFile2;
        inFile2.open(m_fileName);
        usa = new string[m_size];
        jap = new string[m_size];
        id =  new int[m_size];

        int i = 0;
        while(!inFile2.eof())
        {
            inFile2 >> usa[i];
            inFile2 >> id[i];
            inFile2 >> jap[i];
            i++;
        }

        return true;
    }

    cout << "The file cannot be opened!" << endl;
    return false;
}

bool Executive::load()
{
    if(read())
    {
        Pokedex = new Pokemon*[m_size];
        for(int i=0; i<m_size; i++)
        {
            Pokedex[i] = new Pokemon();
        }

        for(int i=0; i<m_size; i++)
        {
            Pokedex[i]->setUSA(usa[i]); 
            Pokedex[i]->setID(id[i]);
            Pokedex[i]->setJAP(jap[i]);
        }

        try
        {
            for(int i=0; i<m_size; i++)
            {
                tree->add(*Pokedex[i]);
            }
        }
        catch(runtime_error& rte)
        {
            cerr << rte.what() << endl;
        } 

        return true;
    }

    return false;
}

void Executive::visit(Pokemon p)
{
    cout << ""<<p.getUSA()<<" "<<p.getID()<<" "<<p.getJAP()<<"" << endl;
}

void Executive::clear()
{
    delete[] usa;
    delete[] id;
    delete[] jap;

    if(Pokedex != nullptr)
    {
        for(int i=0; i<m_size; i++)
        {
            delete Pokedex[i];
        }
        
    }
    delete[] Pokedex;

    delete tree;
}

void Executive::BST_Menu()
{
    cout << "Pokemon BST" << endl;
    cout << "#1 Search" << endl;
    cout << "#2 Add" << endl;
    cout << "#3 Print" << endl;
    cout << "#4 Remove" << endl;
    cout << "#5 Quit" << endl;
    
}

void Executive::T_Order()
{
    cout << "\nTraversal Order" << endl;
    cout << "#1 In Order" << endl;
    cout << "#2 Pre Order" << endl;
    cout << "#3 Post Order" << endl;
}

void Executive::addPoke(string usa, int id, string jap)
{
    Pokemon Poke;
    Poke.setUSA(usa);
    Poke.setJAP(jap);
    Poke.setID(id);
    try
    {
        tree->add(Poke);
    }
    catch(runtime_error &rte)
    {
        cerr << rte.what() << endl;;
    } 
}