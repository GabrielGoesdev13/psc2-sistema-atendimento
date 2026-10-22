# Sistema de Atendimento

Desafio Squad da disciplina PSC II, curso de Engenharia de Software, Centro Universitário Campo Real. Professor: Giovane Galvão.

O programa simula o atendimento de uma clínica usando três estruturas de dados implementadas do zero, sem a STL: uma fila, uma pilha e uma lista encadeada.

## Estruturas utilizadas

| Requisito | Estrutura | Função no sistema |
|-----------|-----------|-------------------|
| R1 | Fila (FIFO) com ponteiros `frente` e `tras` | Pacientes entram no final e são atendidos pelo início |
| R2 | Pilha (LIFO) | Guarda o histórico de atendimentos concluídos |
| R3 | Lista encadeada | Médicos de plantão. Quem é chamado sai do início e volta para o final depois de atender |
| R4 | Relatório | Imprime o histórico completo, do último atendimento ao primeiro, sem destruir os dados |

## Como funciona

1. Os médicos são cadastrados na lista.
2. Os pacientes chegam e entram na fila.
3. Enquanto houver paciente e médico disponível, o primeiro da fila é atendido pelo primeiro médico da lista.
4. Cada atendimento é empilhado no histórico e o médico volta para o final da lista.
5. No fim, o programa mostra o último atendimento (`peek`) e o relatório completo.

O relatório usa uma pilha auxiliar: os itens são desempilhados e impressos e depois devolvidos para o histórico na ordem original.

## Como compilar

Requisitos: `g++` com suporte a C++17.

```bash
g++ -std=c++17 -Wall -o atendimento atendimento.cpp
```

## Como usar

```bash
./atendimento
```

No Windows, use `atendimento.exe`.

## Exemplo de saída

```
Médicos disponíveis: Dra. Ana Lima -> Dr. Bruno Costa -> Dra. Carla Ramos

Pacientes chegando:
Próximo a ser atendido: Eduardo (urgencia=3)
Total na fila: 4

Simulação de atendimentos:
  [1] Dra. Ana Lima atende Eduardo (urgencia=3)
  [2] Dr. Bruno Costa atende Fernanda (urgencia=1)
  [3] Dra. Carla Ramos atende Gabriel (urgencia=2)
  [4] Dra. Ana Lima atende Helena (urgencia=1)

Último atendimento registrado (peek): Dra. Ana Lima → Helena (urgencia=1)

=== Relatório de Atendimentos ===
  1. Dra. Ana Lima → Helena (urgencia=1)
  2. Dra. Carla Ramos → Gabriel (urgencia=2)
  3. Dr. Bruno Costa → Fernanda (urgencia=1)
  4. Dra. Ana Lima → Eduardo (urgencia=3)
```

## Regras seguidas

- Nenhum contêiner da STL (`vector`, `queue`, `stack`, `list`).
- Todo `new` tem o `delete` correspondente, feito em `dequeue`, `pop`, `chamarMedico` e nos destrutores.
- O programa compila sem warnings com `-Wall`.

## Integrante
- Gabriel Goes