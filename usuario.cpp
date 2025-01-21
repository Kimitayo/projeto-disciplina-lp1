#include "Usuario.h"
#include <iostream>
using namespace std;

Usuario::Usuario(const string& nome, int idade, double peso, double altura)
    : nome(nome), idade(idade), peso(peso), altura(altura), passos(0), frequenciaCardiaca(0) {}

void Usuario::registrarPeso(double novoPeso) {
    if (novoPeso > 0) {
        peso = novoPeso;
        cout << "Peso atualizado para " << peso << " kg." << endl;
    } else {
        cout << "Peso inválido." << endl;
    }
}

void Usuario::registrarAltura(double novaAltura) {
    if (novaAltura > 0) {
        altura = novaAltura;
        cout << "Altura atualizada para " << altura << " metros." << endl;
    } else {
        cout << "Altura inválida." << endl;
    }
}

void Usuario::registrarPassos(int novosPassos) {
    if (novosPassos >= 0) {
        passos += novosPassos;
        cout << "Passos registrados. Total: " << passos << " passos." << endl;
    } else {
        cout << "Número de passos inválido." << endl;
    }
}

void Usuario::atualizarFrequenciaCardiaca(int novaFrequencia) {
    if (novaFrequencia > 0) {
        frequenciaCardiaca = novaFrequencia;
        cout << "Frequência cardíaca atualizada para " << frequenciaCardiaca << " bpm." << endl;
    } else {
        cout << "Frequência cardíaca inválida." << endl;
    }
}

void Usuario::exibirPerfil() const {
    cout << "--- Perfil do Usuário ---\n";
    cout << "Nome: " << nome << "\n";
    cout << "Idade: " << idade << " anos\n";
    cout << "Peso: " << peso << " kg\n";
    cout << "Altura: " << altura << " metros\n";
}

void Usuario::exibirDadosDeSaude() const {
    cout << "--- Dados de Saúde ---\n";
    cout << "Passos: " << passos << "\n";
    cout << "Frequência Cardíaca: " << frequenciaCardiaca << " bpm\n";
    cout << "Calorias Queimadas: " << calcularCalorias() << " kcal\n";
}

double Usuario::calcularCalorias() const {
    const double caloriasPorPasso = 0.05;
    return passos * caloriasPorPasso;
}
