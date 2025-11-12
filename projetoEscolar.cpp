#include <iostream>
#include <vector>
#include <string>
using namespace std;

// =============================
// Classe base: Pessoa
// =============================
class Pessoa {
protected:
    string nome;
    int idade;

public:
    Pessoa(string nome, int idade) : nome(nome), idade(idade) {}
    virtual void exibirInfo() const {
        cout << "Nome: " << nome << "\nIdade: " << idade << endl;
    }
    string getNome() const { return nome; }
};

// =============================
// Classe Aluno
// =============================
class Aluno : public Pessoa {
private:
    int matricula;

public:
    Aluno(string nome, int idade, int matricula)
        : Pessoa(nome, idade), matricula(matricula) {}

    void exibirInfo() const override {
        cout << "=== Aluno ===" << endl;
        Pessoa::exibirInfo();
        cout << "Matricula: " << matricula << endl;
    }

    int getMatricula() const { return matricula; }
};

// =============================
// Classe Alunos (sistema de alunos)
// =============================
class Alunos {
private:
    vector<Aluno> lista;

public:
    void adicionar(const Aluno &aluno) {
        lista.push_back(aluno);
    }

    void listar() const {
        cout << "\n=== Lista de Alunos ===" << endl;
        for (const auto &a : lista) {
            a.exibirInfo();
            cout << endl;
        }
    }

    void buscar(int matricula) const {
        bool encontrado = false;
        for (const auto &a : lista) {
            if (a.getMatricula() == matricula) {
                cout << "\nAluno encontrado:" << endl;
                a.exibirInfo();
                encontrado = true;
                break;
            }
        }
        if (!encontrado)
            cout << "\nAluno nao encontrado!" << endl;
    }

    vector<Aluno> getLista() const {
        return lista;
    }
};

// =============================
// Classe Professor
// =============================
class Professor : public Pessoa {
private:
    string disciplina;

public:
    Professor(string nome, int idade, string disciplina)
        : Pessoa(nome, idade), disciplina(disciplina) {}

    void exibirInfo() const override {
        cout << "=== Professor ===" << endl;
        Pessoa::exibirInfo();
        cout << "Disciplina: " << disciplina << endl;
    }

    string getDisciplina() const { return disciplina; }
};

// =============================
// Classe Turma
// =============================
class Turma {
private:
    string codigo;
    Professor professor;
    vector<Aluno> alunos;

public:
    Turma(string codigo, Professor professor)
        : codigo(codigo), professor(professor) {}

    void adicionarAluno(const Aluno &aluno) {
        alunos.push_back(aluno);
    }

    void exibirTurma() const {
        cout << "\n===== Turma " << codigo << " =====" << endl;
        cout << "Professor responsavel:" << endl;
        professor.exibirInfo();
        cout << "\n--- Alunos ---" << endl;
        for (const auto &a : alunos) {
            a.exibirInfo();
            cout << endl;
        }
    }

    string getCodigo() const { return codigo; }
};

// =============================
// Classe Setor
// =============================
class Setor {
private:
    string nome;
    Pessoa responsavel;

public:
    Setor(string nome, Pessoa responsavel)
        : nome(nome), responsavel(responsavel) {}

    void exibirSetor() const {
        cout << "\n=== Setor: " << nome << " ===" << endl;
        cout << "Responsavel: " << responsavel.getNome() << endl;
    }

    string getNome() const { return nome; }
};

// =============================
// Classe Secretaria (controladora do sistema)
// =============================
class Secretaria {
private:
    vector<Turma> turmas;
    Alunos alunos;
    vector<Professor> professores;
    vector<Setor> setores;

public:
    // Cadastro
    void cadastrarAluno(const Aluno &aluno) { alunos.adicionar(aluno); }
    void cadastrarProfessor(const Professor &professor) { professores.push_back(professor); }
    void criarTurma(const Turma &turma) { turmas.push_back(turma); }
    void cadastrarSetor(const Setor &setor) { setores.push_back(setor); }

    // Listagens
    void listarAlunos() const { alunos.listar(); }

    void listarTurmas() const {
        cout << "\n=== Turmas Cadastradas ===" << endl;
        for (const auto &t : turmas)
            t.exibirTurma();
    }

    void listarSetores() const {
        cout << "\n=== Setores da Escola ===" << endl;
        for (const auto &s : setores)
            s.exibirSetor();
    }

    // Busca
    void buscarAluno(int matricula) const { alunos.buscar(matricula); }
};

// =============================
// Função principal
// =============================
int main() {
    Secretaria secretaria;

    // Professores
    Professor prof1("Maria Silva", 40, "Matematica");
    Professor prof2("Carlos Souza", 35, "Historia");
    secretaria.cadastrarProfessor(prof1);
    secretaria.cadastrarProfessor(prof2);

    // Alunos
    Aluno a1("Joao", 16, 101);
    Aluno a2("Ana", 17, 102);
    Aluno a3("Pedro", 15, 103);
    secretaria.cadastrarAluno(a1);
    secretaria.cadastrarAluno(a2);
    secretaria.cadastrarAluno(a3);

    // Turmas
    Turma t1("A1", prof1);
    t1.adicionarAluno(a1);
    t1.adicionarAluno(a2);
    Turma t2("B2", prof2);
    t2.adicionarAluno(a3);
    secretaria.criarTurma(t1);
    secretaria.criarTurma(t2);

    // Setores
    Pessoa func1("Fernanda Alves", 32);
    Pessoa func2("Ricardo Lima", 45);
    Setor s1("Secretaria", func1);
    Setor s2("Biblioteca", func2);
    secretaria.cadastrarSetor(s1);
    secretaria.cadastrarSetor(s2);

    // Exibições
    secretaria.listarAlunos();
    secretaria.buscarAluno(102);
    secretaria.listarTurmas();
    secretaria.listarSetores();

    return 0;
}
