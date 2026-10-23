ITP — Segunda Avaliação: Projeto em C

Nome: Ágata de Oliveira Rodrigues
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

É necessário ter o Dev-C++ instalado, com o compilador GCC configurado.

Abrir o projeto:
- Abra o Dev-C++.
- Acesse File (Arquivo) → Open (Abrir).
- Selecione o arquivo main.c.

Configurar o compilador
- Nas opções do compilador, habilite a opção para adicionar comandos ao chamar o compilador e informe:
- -std=c11
- Essa configuração permite compilar o código usando o padrão C11.

Compilar e executar
- Com o arquivo main.c aberto, selecione Compile & Run (Compilar e Executar) ou utilize a opção equivalente disponível na sua versão do Dev-C++.
- Aguarde a compilação e a abertura do console.
- Informe a quantidade de estudantes, os nomes e as três notas de cada estudante.
- Confira o boletim exibido ao final da execução.

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
