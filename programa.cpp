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

    // Método de validar login
    bool validarLogin(string email, string senha) {
        return this->email == email && this->senha == senha;
    }

    // Juntei aqui os métodos criados por Bernardo
    void registrarPeso (float novoPeso) {
        cout << "Digite seu peso (em kg): ";
        cin >> novoPeso;
        if (novoPeso>0) {
            peso = novoPeso;
            this->peso = peso;
            cout << "Peso atualizado para " << peso << " kg." << endl;
        } else {
            cout << "Peso invalido." << endl;
        }
    }

    void registrarAltura(float novaAltura) {
        cout << "Digite sua altura (em m): ";
        cin >> novaAltura;
        if (novaAltura > 0) {
            altura = novaAltura;
            this->altura = altura;
            cout << "Altura atualizada para " << altura << " metros." << endl;
        } else {
            cout << "Altura invalida." << endl;
        }
    }

    void registrarPassos(int novosPassos) {
        cout << "Digite o numero de passos dados: ";
        cin >> novosPassos;
        if (novosPassos >= 0) {
            passos += novosPassos;
            this->passos = passos;
            cout << "Passos registrados. Total: " << passos << " passos." << endl;
        } else {
            cout << "Numero de passos invalido." << endl;
        }
    }

    void atualizarFrequenciaCardiaca(int novaFrequencia) {
        cout << "Digite sua frequencia cardiaca (em bpm): ";
        cin >> novaFrequencia;
        if (novaFrequencia > 0) {
            freqCardiaca = novaFrequencia;
            this->freqCardiaca = freqCardiaca;
            cout << "Frequencia cardiaca atualizada para " << freqCardiaca << " bpm." << endl;
        } else {
            cout << "Frequencia cardiaca invalida." << endl;
        }
    }

    double calcularCalorias() const {
        const double caloriasPorPasso = 0.05;
        return passos * caloriasPorPasso;
    }


    // Métodos pra exbibir dados
    void exibirDadosDoUsuario() {
        cout << "--- Perfil do Usuario ---\n";
        cout << "Nome: " << nome << "\n";
        cout << "Idade: " << idade << " anos\n";
        cout << "Peso: " << peso << " kg\n";
        cout << "Altura: " << altura << " metros\n";
    }

    void exibirDadosDeSaude() const {
        cout << "--- Dados de Saude ---\n";
        cout << "Passos: " << passos << "\n";
        cout << "Frequencia Cardiaca: " << freqCardiaca << " bpm\n";
        cout << "Calorias Queimadas: " << calcularCalorias() << " kcal\n";
    }


    // 1. Criar uma conta
    void registrarUsuario(string nome, int idade, string email, string senha) {
        cout << "\n--- Registro de Usuario ---" << endl;
        cout << "Digite seu nome: ";
        getline(cin, nome); //usei getline aqui pra poder aceitar quebra de linha
        cout << "Digite sua idade: ";
        cin >> idade;
        cin.ignore();

        cout << "Digite seu email: ";
        getline(cin, email);
        cout << "Digite sua senha: ";
        getline(cin, senha);

        this->nome = nome;
        this->idade = idade;
        this->email = email;
        this->senha = senha;
        cout << "Usuario registrado com sucesso!" << endl;

    }

    // 2. Login
    void login(string emailLogin, string senhaLogin) {
        cout << "\n--- Login ---" << endl;
        bool loginValido = false;
        while (!loginValido) {
            cout << "Digite seu email: ";
            getline(cin, emailLogin);
            cout << "Digite sua senha: ";
            getline(cin, senhaLogin);

            if (validarLogin(emailLogin, senhaLogin)) {
                cout << "Login realizado com sucesso!" << endl;
                loginValido = true;
            } else {
                cout << "Email ou senha incorretos. Tente novamente." << endl;
            }
        }
    }

};




// Primeiro menu -> para criar conta ou logar
void menu1() {
    cout << "=== Fitflow ===\n";
    cout << "1. Criar uma conta\n";
    cout << "2. Login\n";
    cout << "3. Sair\n";

    cout << "=> ";
}

// Menu depois que é logado
void menu2(string nome) {
    cout << "\n--- Bem-vindo," << nome << "ao Fitflow! ---\nO que voce gostaria de fazer hoje? \n";
    cout << "1. Registrar dados\n";
    cout << "2. Exibir dados do usuario\n";
    cout << "3. Exibir dados de saude\n";
    cout << "4. Sair\n";
    cout << "=> ";
}





int main() {
    Usuario usuario;
    string nome, email, senha, emailLogin, senhaLogin;
    int idade, opcao1, opcao2;
    float altura, peso, caloriasQueimadas;
    int freqCardiaca, passos;

    bool menu11 = true;
    bool menu22 = false;

    // menu1
    do {
        menu1();
        cin >> opcao1;
        cin.ignore(); 

        switch (opcao1) {
        case 1:
            usuario.registrarUsuario(nome, idade, email, senha); 
            break;
        case 2: 
            usuario.login(emailLogin, senhaLogin);
            nome = emailLogin;
            menu22 = true;
            menu11 = false;
            break;
        case 3: 
            cout << "Ate a proxima! Obrigado por usar o programa!" << endl;
            break;

        default:
            cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while (opcao1 != 3 && menu11==true);

    
    // menu2
    do {
        menu2(nome);
        cin >> opcao2;
        cin.ignore(); 

        switch (opcao2) {
        case 1: //chamar método que registre os dados de saúde
            usuario.registrarPeso(peso);
            usuario.registrarAltura(altura);
            usuario.registrarPassos(passos);
            usuario.atualizarFrequenciaCardiaca(freqCardiaca);
            usuario.calcularCalorias();

            cout << "Dados atualizados com sucesso!" << endl;
            break;
        case 2: //chamar método que exiba os dados do usuario
            usuario.exibirDadosDoUsuario();
            break;
        case 3: //chamar método que exiba os dados de saude
            usuario.exibirDadosDeSaude();
            break;
        case 4:
            cout << "Ate a proxima" << nome << "! Obrigado por usar o programa!";
            break;
        default:
            cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while (opcao2 != 4);

    return 0;

}
