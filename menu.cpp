#include <iostream>
#include <string>
#include <unordered_map>
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

    bool setIdade(int novaIdade) {
        if (novaIdade <= 0) {
            cout << "Idade invalida. Tente novamente." << endl;
            return false;
        }
        this->idade = novaIdade;
        return true;
    }

    int getIdade() const { return this->idade; }

    void setAltura(float novaAltura) {
        if (novaAltura < 1.00 || novaAltura > 2.50) {
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

    bool setEmail(const string& novoEmail) {
        if (novoEmail.find("@") == string::npos ||
            novoEmail.find(".") == string::npos ||
            novoEmail.find(" ") != string::npos ||
            novoEmail.length() < 5) {
            cout << "Email invalido. Tente novamente." << endl;
            return false;
        }
        this->email = novoEmail;
        return true;
    }

    string getEmail() const { return this->email; }

    bool setSenha(const string& senha1, const string& senha2) { 
        if (senha1 != senha2) {
            cout << "Senhas nao conferem. Tente novamente." << endl;
            return false;
        }
        if (senha1.length() < 8) {
            cout << "Senha muito curta. A senha deve conter no minimo 8 caracteres." << endl;
            return false;
        }

        this->senha = senha1;
        return true;
    }

    string getSenha() const { return this->senha; }

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
};

class Sistema {
private:
    unordered_map<string, Usuario> usuarios;

public:
    void registrarUsuario(Usuario* usuario) {
        string nome, email, senha1, senha2;
        int idade = 22;
        bool ret;   

        cout << "\n--- Registro de Usuario ---" << endl;
        cout << "Digite seu nome: ";
        getline(cin, nome); //usei getline aqui pra poder aceitar quebra de linha
        usuario->setNome(nome);

        cout << "Digite sua idade: ";
        cin >> idade;
        cin.ignore();
        ret = usuario->setIdade(idade);
        if (!ret) {
            return;
        }

        cout << "Digite seu email: ";
        getline(cin, email);
        ret = usuario->setEmail(email);
        if (!ret) {
            return;
        }   

        cout << "Digite sua senha: ";
        getline(cin, senha1);

        cout << "Digite sua senha novamente: ";
        getline(cin, senha2);
        ret = usuario->setSenha(senha1, senha2);
        if (!ret) {
            return;
        }

        if (usuarios.count(email) > 0) {
            cout << "Email ja cadastrado. Tente novamente." << endl;
            return;
        }
        usuarios.emplace(email, *usuario);
        cout << "Usuario registrado com sucesso!" << endl;
    }

    // 2. Login
    bool logarUsuario(string email, string senha) {
        cout << "\n--- Login ---" << endl;
        cout << "Digite 0 para voltar ao menu anterior." << endl;
        bool emailValido = false;
        bool senhaValida = false;

        do {
            cout << "Digite seu email: ";
            getline(cin, email);

            if (email == "0") {
                return false;
            }

            if (usuarios.count(email) == 0) {
                cout << "Email nao cadastrado. Tente novamente." << endl;
            } else {
                emailValido = true;
            }
        } while (!emailValido && email != "0");
        
        do {
            cout << "Digite sua senha: ";
            getline(cin, senha);

            if (senha == "0") {
                return false;
            }   

            if (usuarios[email].getSenha() != senha) {
                cout << "Senha incorreta. Tente novamente." << endl;
            } else {
                senhaValida = true;
            }
        } while (!senhaValida && senha != "0");

        cout << "Login efetuado com sucesso!" << endl;
        return true;
    }
};

// Menu depois que é logado
void menuLogado(Usuario* usuario) {
    int opcao = 0;
    while (opcao != 4) {
        int freqCardiaca, passos;
        float altura, peso;

        cout << "\n--- Bem-vindo ao Fitflow, " << usuario->getNome() << "! ---\n";
        cout << "O que voce gostaria de fazer hoje?\n\n";
        cout << "1. Registrar dados\n";
        cout << "2. Exibir dados do usuario\n";
        cout << "3. Exibir dados de saude\n";
        cout << "4. Sair\n";
        cout << "=> ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
        case 1: //chamar método que registre os dados de saúde
            cout << "Digite seu peso (em kg): ";
            cin >> peso;
            usuario->setPeso(peso);
            cout << "Peso atualizado para " << usuario->getPeso() << " kg." << endl;

            cout << "Digite sua altura (em m): ";
            cin >> altura;
            usuario->setAltura(altura);
            cout << "Altura atualizada para " << usuario->getAltura() << " metros." << endl;

            cout << "Digite o numero de passos dados: ";
            cin >> passos;
            usuario->setPassos(passos);
            cout << "Passos registrados. Total: " << usuario->getPassos() << " passos." << endl;

            cout << "Digite sua frequencia cardiaca (em bpm): ";
            cin >> freqCardiaca;
            usuario->setFreqCardiaca(freqCardiaca);
            cout << "Frequencia cardiaca atualizada para " << usuario->getFreqCardiaca() << " bpm." << endl;

            usuario->setCaloriasQueimadas();

            cout << "Dados atualizados com sucesso!" << endl;
            break;
        case 2: //chamar método que exiba os dados do usuario
            usuario->exibirDadosDoUsuario();
            break;
        case 3: //chamar método que exiba os dados de saude
            usuario->exibirDadosDeSaude();
            break;
        case 4:
            cout << "Ate a proxima " << usuario->getNome() << "! Obrigado por usar o programa!\n\n";
            break;
        default:
            cout << "Opcao invalida. Tente novamente." << endl;
        }
    }
}

int main() {
    Usuario usuario;
    Sistema sistema;
    string nome, email, senha;
    int opcao1;
    bool menuAberto = true;

    // Menu Principal
    do {
        cout << "=== Fitflow ===\n";
        cout << "1. Criar uma conta\n";
        cout << "2. Login\n";
        cout << "3. Sair\n";
        cout << "=> ";
        cin >> opcao1;
        cin.ignore(); 

        switch (opcao1) {
        case 1:
            sistema.registrarUsuario(&usuario);
            break;
        case 2: 
            if (!sistema.logarUsuario(email, senha)) {
                break;
            }
            menuLogado(&usuario);
            break;
        case 3: 
            cout << "Encerrando Fitflow... Obrigado por usar o programa!" << endl;
            menuAberto = false;
            break;

        default:
            cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while (menuAberto);

    return 0;
}
