ITP — Segunda Avaliação: Projeto em C

Nome: Ágata Rodrigues
Projeto escolhido: Opção 1 — Boletim de uma pequena turma

1. Descrição do projeto

O programa permite cadastrar de 1 a 10 estudantes, registrar três notas por estudante e calcular suas médias.

O boletim apresenta o nome de cada estudante, as três notas, a média individual e a situação em relação à meta de 6,0. O programa também calcula a média geral da turma e identifica o estudante ou os estudantes com a maior média, incluindo casos de empate.

2. Funcionalidades implementadas

- Cadastro e validação dos nomes dos estudantes.
- Leitura de três notas por estudante, aceitando valores de 0 a 10.
- Armazenamento das notas em uma matriz.
- Cálculo das médias individuais em um vetor alocado dinamicamente.
- Exibição do boletim com notas, médias e situações.
- Cálculo da média geral da turma.
- Identificação da maior média e de todos os estudantes empatados.

3. Como compilar e executar

É necessário ter o compilador GCC instalado.

Compilação:

gcc -std=c11 -Wall -Wextra main.c -o boletim

Execução no Linux ou macOS:

./boletim

Execução no Windows, após a compilação:

.\boletim.exe

4. Testes realizados

Teste 1 — Funcionamento normal

Entradas:

- Quantidade de estudantes: 1
- Nome: Ana
- Nota 1: 5
- Nota 2: 6
- Nota 3: 7

Resultados esperados:

- Média individual: 6,00.
- Situação: Atingiu a meta.
- Média geral da turma: 6,00.
- Maior média: 6,00.
- Estudante com a maior média: Ana.

Teste 2 — Nota inválida

Entradas:

- Quantidade de estudantes: 1
- Nome: Ana
- Primeira nota digitada: 11
- Primeira nota válida após a nova solicitação: 5
- Nota 2: 6
- Nota 3: 7

Resultados esperados:

- O programa informa que a nota deve estar entre 0 e 10.
- O programa solicita novamente a nota inválida.
- Após a entrada das notas válidas, a média individual é 6,00.

5. Vídeo de apresentação

Link do vídeo no YouTube: 

6. Referências

- Materiais de estudo da unidade disponibilizados pelo professor no Notion:
  - Aula 6 — Matrizes.
  - Aula 7 — Tipos de dados.
  - Aula 8 — Strings em C.
  - Aula 9 — Estrutura de Memória.
  - Aula 10 — Memória Estática e Heap.
  - Aula 11 — Ponteiros e Alocação Dinâmica.

- Instruções da Segunda Avaliação — Projeto em C, disponibilizadas pelo professor.