#include <iostream>
#include <string>
using namespace std;

class Usuario {
private: 
    string nome;
    int idade;
    float altura;
    string email;
    string senha;
    float peso;
    int freqCardiaca;
    int passos;
    float caloriasQueimadas;

public:
    Usuario() : idade(0), altura(0.0), peso(0.0), freqCardiaca(0), passos(0), caloriasQueimadas(0.0){};

    // faltam criar os métodos aqui (registrar usuario, validar login, registrar os dados de saúde e exibir dados)

    // 1. Criar uma conta
    void registrarUsuario(string nome, int idade, float altura, string email, string senha) {
        cout << "\n=== Registro de Usuario ===" << endl;
        cout << "Digite seu nome: ";
        getline(cin, nome); //usei getline aqui pra poder aceitar quebra de linha
        cout << "Digite sua idade: ";
        cin >> idade;
        cout << "Digite sua altura (em cm): ";
        cin >> altura;
        cin.ignore();

        cout << "Digite seu email: ";
        getline(cin, email);
        cout << "Digite sua senha: ";
        getline(cin, senha);

        // pra fazer o registro, aqui deve chamar o método de registrar usuario
    }

    // 2. Login
    void login(string emailLogin, string senhaLogin) {
        cout << "\n=== Login ===" << endl;
        bool loginValido = false;
        while (!loginValido) {
            cout << "Digite seu email: ";
            getline(cin, emailLogin);
            cout << "Digite sua senha: ";
            getline(cin, senhaLogin);

            // aqui fazer um if/else pra validar o login
        }
    }
};




// Primeiro menu -> para criar conta ou logar
void menu1() {
    cout << "=== Fitflow ===\n";
    cout << "Primeira vez aqui?\n";
    cout << "1. Criar uma conta\n";
    cout << "2. Login\n";
    cout << "3. Sair\n";
}

// Menu depois que é logado
void menu2(string nome) {
    cout << "\nBem-vindo," << nome << "ao Fitflow!\nO que voce gostaria de fazer hoje?\n";
    cout << "1. Registrar dados\n";
    cout << "2. Exibir dados\n";
    cout << "3. Sair\n";
    cout << "Escolha uma opçao: " << endl;
}





int main() {
    Usuario usuario;
    string nome, email, senha, emailLogin, senhaLogin;
    int idade, opcao1, opcao2;
    float altura;

    // menu1
    do {
        menu1();
        cin >> opcao1;

        switch (opcao1) {
        case 1:
            usuario.registrarUsuario(nome, idade, altura, email, senha); 
        case 2: 
            usuario.login(emailLogin, senhaLogin);
        case 3: 
            cout << "Ate a proxima! Obrigado por usar o programa!" << endl;
            break;
        default:
            cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while (opcao1 != 3);

    
    // menu2
    do {
        menu2(nome);
        cin >> opcao2;

        switch (opcao2) {
        case 1: //chamar método que registre os dados de saúde
        case 2: //chamar método que exiba os dados de saúde
            break;
        case 3:
            cout << "Ate a proxima" << nome << "! Obrigado por usar o programa!";
            break;
        default:
            cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while (opcao2 != 3);

    return 0;

}
