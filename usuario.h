#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
private:
    std::string nome;
    int idade;
    double peso; 
    double altura;
    int passos;
    int frequenciaCardiaca;
    double calcularCalorias() const;
public:
    Usuario(const std::string& nome, int idade, double peso, double altura);

    void registrarPeso(double novoPeso);
    void registrarAltura(double novaAltura);
    void registrarPassos(int novosPassos);
    void atualizarFrequenciaCardiaca(int novaFrequencia);
    void exibirPerfil() const;
    void exibirDadosDeSaude() const;
};

#endif