## *Bibliotecas Utilizadas:*

1. **stdio.h**: Biblioteca padrão de entrada e saída em C, utilizada para funções como `printf` e `scanf`.

2. **stdlib.h**: Fornece funções para alocação de memória (`malloc`, `free`) e geração de números aleatórios (`rand`, `srand`).

3. **string.h**: Contém funções para manipulação de strings, como `strcpy` (cópia de strings) e `strlen` (comprimento de strings).

4. **ctype.h**: Fornece funções para manipulação de caracteres, como `isdigit` (verifica se um caractere é um dígito).

5. **time.h**: Permite manipulação de data e hora, com funções como `time` (obtém o tempo atual) e `mktime` (converte uma estrutura `tm` em um `time_t`).

## *Variáveis Globais:*

### Reservas por Tipo de Quarto

- `reservasSolteiro1`, `reservasSolteiro2`, `reservasCasal1`, `reservasCasal2`: Arrays que armazenam reservas de quartos do tipo solteiro e casal.
- `countSolteiro1`, `countSolteiro2`, `countCasal1`, `countCasal2`: Contadores para acompanhar o número de reservas por tipo de quarto.

### Clientes

- `clientes`: Array que armazena informações dos clientes cadastrados.
- `countClientes`: Contador que registra o número de clientes cadastrados.

### Funcionários

- `funcionarios`: Array que armazena informações dos funcionários cadastrados.
- `countFuncionarios`: Contador que registra o número de funcionários cadastrados.

### Contadores de Funcionários por Cargo

- `contRecepcionista`, `contAuxiliarLimpeza`, `contGerente`, `contGarcom`: Variáveis inteiras que contam o número de funcionários por cargo.

## Variáveis Locais (dentro da função `main` e outras funções)

### Variáveis de Entrada e Controle

- `escolha1`, `escolha2`: Controles do menu de escolha de cadastro.
- `nome`, `endereco`, `telefone`, `dataEntrada`, `dataSaida`: Arrays para armazenar informações inseridas pelo usuário.
- `escolha_valida`: Controle da validade da escolha do usuário.
- `continuar`: Controle para continuar ou não após cada operação.

### Datas de Entrada e Saída

- `diaEntrada`, `mesEntrada`, `anoEntrada`, `diaSaida`, `mesSaida`, `anoSaida`: Variáveis para partes das datas de entrada e saída.

### Códigos de Cliente e Funcionário

- `codigo_cliente`, `codigo_funcionario`: Variáveis para armazenar códigos atribuídos a cada cliente e funcionário.

### Outras Variáveis de Controle

- `hospedes`: Número de hóspedes no quarto.
- `valorQuarto`, `valorTotal`: Valores calculados para o quarto e o total da hospedagem.
- `quarto`: Tipo de quarto escolhido pelo cliente.

### Variáveis de Aleatoriedade

- `numero_aleatorio`: Número aleatório usado para atribuir códigos de cliente e funcionário.
