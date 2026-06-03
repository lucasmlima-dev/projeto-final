# 📝 Sistema de Notas v4.1 - Projeto final

Um sistema prático e eficiente desenvolvido em C++ para gerenciamento de notas escolares, cálculo de médias, classificação de alunos e persistência de dados em arquivos.

---

## 🚀 Funcionalidades

- Cadastro de alunos e notas por disciplina
- Cálculo de médias por aluno
- Classificação: Aprovado, Recuperação ou Reprovado
- Relatório salvo em arquivo .txt com data e hora
- Leitura de relatório salvo
- Menu "Sobre o sistema"

---

## 📊 Regras de Negócio (Critérios de Avaliação)

A situação acadêmica do estudante é calculada de forma automatizada com base nos seguintes parâmetros:

| Média Final | Situação Acadêmica | Indicador Visual |
| :--- | :--- | :---: |
| **Maior ou igual a 7.0** | Aprovado | 🟢 |
| **Entre 5.0 e 6.9** | Recuperação | 🟡 |
| **Menor que 5.0** | Reprovado | 🔴 |

---

## 🛠️ Conceitos de Programação Aplicados

Para quem deseja estudar o código-fonte, este projeto serve como um excelente modelo prático de:
**Estruturas de Dados:** Uso de vetores para armazenar strings (nomes) e floats (médias), combinado com uma matriz bidimensional para cruzar os dados de notas por aluno e disciplina.
**Controle de Fluxo Robustos:** Uso de laços for imbricados para varredura de tabelas e laços do-while para consistência e validação de dados de entrada.
**Gerenciamento de Fluxo de Entrada:** Uso do método cin.ignore() para limpeza do buffer do teclado, evitando conflitos na leitura de strings após a captura de dados numéricos.