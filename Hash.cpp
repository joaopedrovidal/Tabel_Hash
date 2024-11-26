//
// Created by João Pedro Vidal on 25/11/2024.
//
#include "Aluno.h"
#include "Hash.h"
#include <iostream>
using namespace std;

void Hash::print(){
    for(int i = 0; i < max_items; i++){
        cout << i << ":" <<
            structure[i].getRa() << ", " <<
            structure[i].getNome() << endl;
    }
}

int Hash::getHash(Aluno aluno){
    return aluno.getRa() % max_items;
}

void Hash::retrieveItem(Aluno& aluno, bool& found){
    int starloc = getHash(aluno);
    bool moreToSearch = true;
    int location = starloc;
    do {
        if (structure[location].getRa() == aluno.getRa() ||
            structure[location].getRa() == -1) {
            moreToSearch = false;
        }else {
            location = (location + 1) % max_items;
        }
    }while (location != starloc && moreToSearch);

    found = (structure[location].getRa() == aluno.getRa());
    if (found) {
        aluno = structure[location];
    }
}

void Hash::insertItem(Aluno aluno) {
    if (isFull()) {
        cout << "Erro: a tabela hash está cheia." << endl;
        return;
    }

    int location = getHash(aluno); // Calcula o hash
    while (structure[location].getRa() > 0) { // Procura a próxima posição vazia
        location = (location + 1) % max_items;
    }
    structure[location] = aluno; // Insere o aluno na posição encontrada
    length++; // Atualiza o tamanho
}

void Hash::deleteItem(Aluno aluno){
    int starLoc = getHash(aluno);
    bool moreToSearch = true;
    int location = starLoc;
    do {
        if (structure[location].getRa() == aluno.getRa() ||
            structure[location].getRa() == -1) {
            moreToSearch = false;
        }else {
            location = (location + 1) % max_items;
        }
    }while (location != starLoc && moreToSearch);

    if (structure[location].getRa() == aluno.getRa()) {
        structure[location] = Aluno (-2, "");
        length--;
    }
}

Hash::Hash(int max) {
    length = 0;
    max_items = max;
    structure = new Aluno [max_items];
}

Hash::~Hash() {
    delete[]structure;
}

bool Hash::isFull() const {
    return (length == max_items);
}

int Hash::getLength() const {
    return length;
}



