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
    Usuario() : idade(0), altura(0.0), peso(0.0), freqCardiaca(0), passos(0), caloriasQueimadas(0.0) {};

    // Setters e Getters (Encapsulamento)
    void setNome(const string& novoNome) { this->nome = novoNome; }

    string getNome() const { return this->nome; }

    void setIdade(int novaIdade) {
        if (novaIdade < 0) {
            cout << "Idade invalida. Tente novamente." << endl;
            return;
        }
        this->idade = novaIdade;
    }

    int getIdade() const { return this->idade; }

    void setAltura(float novaAltura) {
        if (novaAltura < 100 || novaAltura > 250) {
            cout << "Altura invalida. Tente novamente." << endl;
            return;
        }
        this->altura = novaAltura;
    }

    float getAltura() const { return this->altura; }

    void setPeso(float novoPeso) {
        if (novoPeso < 0) {
            cout << "Peso invalido. Tente novamente." << endl;
            return;
        }
        this->peso = novoPeso;
    }

    float getPeso() const { return this->peso; }

    void setFreqCardiaca(int novaFreqCardiaca) {
        if (novaFreqCardiaca <= 0) {
            cout << "Frequencia cardiaca invalida. Tente novamente." << endl;
            return;
        }
        this->freqCardiaca = novaFreqCardiaca;
    }

    int getFreqCardiaca() const { return this->freqCardiaca; }

    void setPassos(int novosPassos) {
        if (novosPassos <= 0) {
            cout << "Numero de passos invalido. Tente novamente." << endl;
            return;
        }
        this->passos = novosPassos;
    }

    int getPassos() const { return this->passos; }

    void setCaloriasQueimadas() {
        const double caloriasPorPasso = 0.05;
        this->caloriasQueimadas = passos * caloriasPorPasso;
    }

    float getCaloriasQueimadas() const { return this->caloriasQueimadas; }

    void setEmail(const string& novoEmail) {
        if (novoEmail.find("@") == string::npos ||
            novoEmail.find(".") == string::npos ||
            novoEmail.find(" ") != string::npos ||
            novoEmail.length() < 5) {
            cout << "Email invalido. Tente novamente." << endl;
            return;
        }
        this->email = novoEmail;
    }

    string getEmail() const { return this->email; }

    void setSenha(const string& novaSenha) {
        if (novaSenha.length() < 8) {
            cout << "Senha invalida. Tente novamente." << endl;
            return;
        }
        this->senha = novaSenha;
    }

    string getSenha() const { return this->senha; }

    // Método de validar login
    bool validarLogin(string email, string senha) {
        return email == this->email && senha == this->senha;
    }


    // Métodos pra exbibir dados
    void exibirDadosDoUsuario() {
        cout << "--- Perfil do Usuario ---\n";
        cout << "Nome: " << this->getNome() << "\n";
        cout << "Idade: " << this->getIdade() << " anos\n";
        cout << "Peso: " << this->getPeso() << " kg\n";
        cout << "Altura: " << this->getAltura() << " metros\n";
    }

    void exibirDadosDeSaude() const {
        cout << "--- Dados de Saude ---\n";
        cout << "Passos: " << this->getPassos() << "\n";
        cout << "Frequencia Cardiaca: " << this->getFreqCardiaca() << " bpm\n";
        cout << "Calorias Queimadas: " << this->getCaloriasQueimadas() << " kcal\n";
    }


    // 1. Criar uma conta
    void registrarUsuario(Usuario usuario) {
        string nomeTmp, emailTmp, senhaTmp;
        int idadeTmp;

        cout << "\n--- Registro de Usuario ---" << endl;
        cout << "Digite seu nome: ";
        getline(cin, nome); //usei getline aqui pra poder aceitar quebra de linha
        usuario.setNome(nomeTmp);

        cout << "Digite sua idade: ";
        cin >> idadeTmp;
        cin.ignore();
        usuario.setIdade(idadeTmp);

        cout << "Digite seu email: ";
        getline(cin, emailTmp);
        usuario.setEmail(emailTmp);

        cout << "Digite sua senha: ";
        getline(cin, senhaTmp);
        usuario.setSenha(senhaTmp);

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
            usuario.registrarUsuario(usuario);
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
            cout << "Digite seu peso (em kg): ";
            cin >> peso;
            usuario.setPeso(peso);
            cout << "Peso atualizado para " << peso << " kg." << endl;

            cout << "Digite sua altura (em m): ";
            cin >> altura;
            usuario.setAltura(altura);
            cout << "Altura atualizada para " << altura << " metros." << endl;

            cout << "Digite o numero de passos dados: ";
            cin >> passos;
            usuario.setPassos(passos);
            cout << "Passos registrados. Total: " << usuario.getPassos() << " passos." << endl;

            cout << "Digite sua frequencia cardiaca (em bpm): ";
            cin >> freqCardiaca;
            usuario.setFreqCardiaca(freqCardiaca);
            cout << "Frequencia cardiaca atualizada para " << usuario.getFreqCardiaca() << " bpm." << endl;

            usuario.setCaloriasQueimadas();

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
