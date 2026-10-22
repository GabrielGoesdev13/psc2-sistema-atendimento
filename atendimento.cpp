#include <iostream>
#include <string>
using namespace std;

struct No {
    string nome;
    int    urgencia;
    No*    prox;
    No(const string& n, int u = 0) : nome(n), urgencia(u), prox(nullptr) {}
};

struct FilaPacientes {
    No* frente = nullptr;
    No* tras   = nullptr;

    void enqueue(const string& nome, int urgencia) {
        No* novo = new No(nome, urgencia);
        if (isEmpty()) {
            frente = novo;
            tras   = novo;
        } else {
            tras->prox = novo;
            tras       = novo;
        }
    }

    string dequeue() {
        if (isEmpty()) return "";
        No* removido = frente;
        string nome  = removido->nome;
        frente = frente->prox;
        if (frente == nullptr) tras = nullptr;
        delete removido;
        return nome;
    }

    string frente_peek() const {
        if (isEmpty()) return "";
        return frente->nome;
    }

    bool isEmpty() const { return frente == nullptr; }

    int tamanho() const {
        int total = 0;
        for (No* p = frente; p != nullptr; p = p->prox) total++;
        return total;
    }

    ~FilaPacientes() {
        while (!isEmpty()) dequeue();
    }
};

struct PilhaHistorico {
    No* topo = nullptr;

    void push(const string& nome) {
        No* novo  = new No(nome);
        novo->prox = topo;
        topo       = novo;
    }

    string pop() {
        if (isEmpty()) return "";
        No* removido = topo;
        string nome  = removido->nome;
        topo = topo->prox;
        delete removido;
        return nome;
    }

    string peek() const {
        if (isEmpty()) return "";
        return topo->nome;
    }

    bool isEmpty() const { return topo == nullptr; }

    ~PilhaHistorico() {
        while (!isEmpty()) pop();
    }
};

int main() {
    FilaPacientes  fila;
    PilhaHistorico historico;

    fila.enqueue("Eduardo (urgencia=3)", 3);
    fila.enqueue("Fernanda (urgencia=1)", 1);
    fila.enqueue("Gabriel (urgencia=2)", 2);
    fila.enqueue("Helena (urgencia=1)", 1);

    cout << "Próximo a ser atendido: " << fila.frente_peek() << "\n";
    cout << "Total na fila: " << fila.tamanho() << "\n";

    cout << "\nAtendendo pacientes:\n";
    while (!fila.isEmpty()) {
        string paciente = fila.dequeue();
        cout << "  " << paciente << "\n";
        historico.push(paciente);
    }

    cout << "\nÚltimo atendimento registrado (peek): " << historico.peek() << "\n";

    return 0;
}