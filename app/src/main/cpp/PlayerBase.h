//
// Created by lijing14 on 2022/4/11.
//

#ifndef MY_APPLICATION_PLAYERBASE_H
#define MY_APPLICATION_PLAYERBASE_H

#include <string>


using std::string;

class PlayerBase {
protected:
    string name;

public:
    PlayerBase(string name) {
        this->name = name;
    }

    virtual string getName() = 0;

    virtual void start() = 0;

    virtual void pause() = 0;
};


#endif //MY_APPLICATION_PLAYERBASE_H
