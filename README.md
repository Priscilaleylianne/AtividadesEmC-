# Sistema Escolar Orientado a Objetos em C++

![C++](https://img.shields.io/badge/Linguagem-C%2B%2B-blue)
![License](https://img.shields.io/badge/Licença-MIT-green)
![POO](https://img.shields.io/badge/Paradigma-POO-orange)
![Status](https://img.shields.io/badge/Status-Em%20Desenvolvimento-yellow)

## Sobre o Projeto

O **Sistema Escolar em C++** é uma aplicação desenvolvida com **Programação Orientada a Objetos (POO)** que visa gerenciar **alunos, professores, turmas e setores** de uma escola.  
O projeto aplica os principais conceitos de POO: **herança, encapsulamento, polimorfismo e composição**.

---

## Estrutura do Sistema

### Classes Principais:
- **Pessoa** → Classe base para atributos comuns (nome, idade).  
- **Aluno** → Herda de `Pessoa`, inclui matrícula.  
- **Alunos** → Gerencia vários objetos `Aluno` (sistema de alunos).  
- **Professor** → Herda de `Pessoa`, inclui disciplina.  
- **Turma** → Contém um professor e vários alunos.  
- **Setor** → Representa setores administrativos (Secretaria, Biblioteca, etc.).  
- **Secretaria** → Gerencia todos os módulos do sistema.

---

## Conceitos de POO Aplicados

| Conceito | Descrição |
|-----------|------------|
| **Herança** | `Aluno` e `Professor` derivam de `Pessoa`. |
| **Encapsulamento** | Atributos protegidos e privados. |
| **Polimorfismo** | Método `exibirInfo()` sobrescrito nas subclasses. |
| **Composição** | `Turma` contém `Aluno` e `Professor`. |
| **Agregação** | `Secretaria` gerencia coleções de objetos. |

---

## Tecnologias Utilizadas

- **Linguagem:** C++  
- **Paradigma:** Programação Orientada a Objetos  
- **Modelagem:** UML  
- **Ambiente:** VS Code / Code::Blocks / Dev-C++  
- **Bibliotecas padrão:** `iostream`, `vector`, `string`

---
## Como Executar o Projeto

1. **Clone o repositório:**
   ```bash
   git clone https://github.com/SEU_USUARIO/Sistema-Escolar-Cpp.git
     cd Sistema-Escolar-Cpp
---

## Estrutura de Pastas

```bash
🗂️ Sistema-Escolar
│
├── 🗂️ src/
│ ├── Pessoa.h / Pessoa.cpp
│ ├── Aluno.h / Aluno.cpp
│ ├── Professor.h / Professor.cpp
│ ├── Alunos.h / Alunos.cpp
│ ├── Turma.h / Turma.cpp
│ ├── Setor.h / Setor.cpp
│ ├── Secretaria.h / Secretaria.cpp
│ └── main.cpp
│
├── 🗂️ docs/
│ ├── diagrama_UML.png
│ └── Sistema_Escolar_C++.pdf
│
└── README.md
