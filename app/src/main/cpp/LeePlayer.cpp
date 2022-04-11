//
// Created by lijing14 on 2022/4/11.
//

#include "PlayerBase.h"
#include <string>
#include <iostream>

using namespace std;

class LeePlayer : PlayerBase {
public:
    LeePlayer(string name1) : PlayerBase(name1) {
        cout << "构造函数" << endl;
    }

    string getName() override {
        return name;
    }

    void start() override {
        cout << "string" << endl;
    }

    void pause() override {
        cout << "string" << endl;
    }

    ~LeePlayer() {
        cout << "析造函数" << endl;
    }
};