//
// Created by João Pedro Vidal on 25/11/2024.
//

#include "Aluno.h"
#include<iostream>
using namespace std;

Aluno::Aluno() {
    this->ra = -1;
    this-> nome = "";
};

Aluno::Aluno(int ra, std::string nome) {
    this-> ra = ra;
    this-> nome = nome;
}

string Aluno::getNome() const {
    return nome;
}

int Aluno::getRa() const {
    return ra;
}



