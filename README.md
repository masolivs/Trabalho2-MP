# Solução do Problema das 8 Rainhas

Este é um programa em C++ para resolver o problema das 8 rainhas em um tabuleiro de xadrez.

## Funcionalidades

Verificar Tabuleiro (isValidInput): Verifica se o tabuleiro fornecido representa um tabuleiro válido de 8 rainhas.

Detectar Ataques (isAttacking): Detecta se duas rainhas estão atacando uma à outra no tabuleiro.

Salvar Ataques (saveAttacks): Salva os movimentos de ataque das rainhas em um arquivo.

Resolver Problema (solve8Queens): Resolve o problema das 8 rainhas a partir de um tabuleiro ou de um arquivo.

## Desenvolvimento

Este programa foi desenvolvido utilizando a metodologia de Desenvolvimento Orientado a Testes (TDD). Foram implementados testes automatizados para garantir a corretude das funções em diferentes cenários.

## Execução

Você pode executar o programa utilizando o Makefile fornecido. Abaixo estão algumas regras úteis:

make cpplint: Executa o linter para verificar a conformidade do código com as diretrizes de estilo.

make all: Executa todos os testes para garantir a integridade do código.

make clean: Remove todos os arquivos gerados durante a compilação.
