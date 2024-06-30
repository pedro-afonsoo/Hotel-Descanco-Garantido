# Hotel-Descanco-Garantido
## *1. Documentação das Funcionalidades do Software*

## Introdução
- O software desenvolvido é um sistema de reservas para um hotel, que permite o cadastro de clientes e funcionários, a reserva de quartos e a verificação de disponibilidade de quartos. O sistema é interativo, utilizando o terminal para entrada e saída de dados.

## Funcionalidades
    ## *Cadastro de Clientes:*

- Recebe o nome completo, endereço e telefone do cliente.

- Gera um código único para o cliente.

- Solicita as datas de entrada e saída da hospedagem, verificando a disponibilidade dos quartos.

### Oferta de Quartos:

- Oferece aos clientes 2 quartos de casal e 2 quartos de solteiro.

### Verificação de Disponibilidade de Quartos:

- Não permite números negativos, datas incorretas ou anteriores a 01/01/2024.

- A data de saída deve ser posterior à data de entrada na hospedagem.

### Reservas de Quartos

- Permite alugar um quarto no mesmo dia em que a hospedagem de outra pessoa termina.
  
- Calcula o valor total da hospedagem e confirma a reserva.

- A hospedagem sempre começa às 14h e termina às 12h do dia seguinte, solicitando o dia anterior à última estadia para evitar a inutilização do quarto no último dia de hospedagem.

### Bloqueio de Quartos:

- Bloqueia o quarto alugado durante o período de entrada e saída.

## *Cadastro de Funcionários:*

- Recebe o nome completo e telefone do funcionário.

- Gera um código único para o funcionário de 4 digitos.

- Solicita o cargo e define o salário correspondente.

### Limite de Funcionários:

- Permite no máximo 2 auxiliares de limpeza, 2 garçons, 2 secretárias e 1 gerente para cadastro.

- Verifica se há vagas disponíveis para o cargo escolhido.


## *Consulta de Clientes Cadastrados:*

- Permite a consulta de informações de um cliente cadastrado através do código do cliente.

- Exibe as informações pessoais e detalhes da reserva, incluindo o código de estadia.


## *Consulta de Funcionários Cadastrados:*

- Permite a consulta de informações de um funcionário cadastrado através do código do funcionário.

- Exibe as informações pessoais, cargo e salário.

## *Validação de Entrada de Dados:*

- Aceita apenas números ou letras válidas, dependendo da pergunta feita durante o cadastro.

# 2. Planejamento dos Casos de Teste

## Sprint 1

### Funcionalidade: Cadastro de Clientes

#### Caso de Teste 1: Cadastro de Cliente

**Entrada:**
Nome: "João Silva"
Endereço: "Rua A, 123, Centro, 12345-678"
Telefone: "123456789"

**Procedimento de Teste:**
1. Iniciar o programa.
2. Selecionar a opção "1. Cliente".
3. Inserir o nome, endereço e telefone conforme indicado.
4. Confirmar o código de cliente gerado.
5. Inserir a data de entrada "05/01/2024" e data de saída "10/01/2024".
6. Inserir a quantidade de hóspedes "1".
7. Confirmar a reserva.

**Saída Esperada:**
- Código de cliente gerado e exibido.
- Informações do cliente e detalhes da reserva exibidos corretamente.
- Mensagem de confirmação com valor total da hospedagem.

#### Caso de Teste 2: Validação do Número de Telefone

**Entrada:**
Telefone: "12345abc9"

**Procedimento de Teste:**
1. Iniciar o programa.
2. Selecionar a opção "1. Cliente".
3. Inserir nome e endereço válidos.
4. Inserir o telefone com caracteres inválidos.

**Saída Esperada:**
- Mensagem de erro "Número de telefone incorreto. Digite novamente."

#### Caso de Teste 3: Verificação de Disponibilidade do Quarto

**Entrada:**
Data de Entrada: "05/01/2024"
Data de Saída: "10/01/2024"
Hóspedes: "1"

**Procedimento de Teste:**
1. Realizar o cadastro de um cliente.
2. Inserir as datas de hospedagem e a quantidade de hóspedes.

**Saída Esperada:**
- Mensagem confirmando a disponibilidade do quarto.
- Detalhes da reserva exibidos corretamente.

## Sprint 2

### Funcionalidade: Cadastro de Funcionários

#### Caso de Teste 4: Cadastro de Funcionário

**Entrada:**
Nome: "Maria Souza"
Telefone: "987654321"
Cargo: "1" (Recepcionista)

**Procedimento de Teste:**
1. Iniciar o programa.
2. Selecionar a opção "2. Funcionário".
3. Inserir o nome, telefone e cargo conforme indicado.
4. Confirmar o código de funcionário gerado e as informações exibidas.

**Saída Esperada:**
- Código de funcionário gerado e exibido.
- Informações do funcionário e detalhes do cargo exibidos corretamente.

#### Caso de Teste 5: Validação do Número de Telefone do Funcionário

**Entrada:**
Telefone: "abc987654"

**Procedimento de Teste:**
1. Iniciar o programa.
2. Selecionar a opção "2. Funcionário".
3. Inserir nome válido.
4. Inserir o telefone com caracteres inválidos.

**Saída Esperada:**
- Mensagem de erro "Número de telefone incorreto. Digite novamente."

#### Caso de Teste 6: Consulta de Cliente Cadastrado

**Entrada:**
Código do Cliente: "1001"

**Procedimento de Teste:**
1. Iniciar o programa.
2. Selecionar a opção "3. Clientes cadastrados".
3. Inserir o código do cliente.

**Saída Esperada:**
- Informações do cliente exibidas corretamente.
- Detalhes da reserva exibidos corretamente.

#### Caso de Teste 7: Consulta de Cliente Não Cadastrado

**Entrada:**
Código do Cliente: "9999"

**Procedimento de Teste:**
1. Iniciar o programa.
2. Selecionar a opção "3. Clientes cadastrados".
3. Inserir o código de cliente inexistente.

**Saída Esperada:**
- Mensagem de erro "Cliente com código 9999 não encontrado."

#### Caso de Teste 8: Consulta de Funcionário Cadastrado

**Entrada:**
Código do Funcionário: "1001"

**Procedimento de Teste:**
1. Iniciar o programa.
2. Selecionar a opção "4. Funcionários cadastrados".
3. Inserir o código do funcionário.

**Saída Esperada:**
- Informações do funcionário exibidas corretamente.

#### Caso de Teste 9: Consulta de Funcionário Não Cadastrado

**Entrada:**
Código do Funcionário: "9999"

**Procedimento de Teste:**
1. Iniciar o programa.
2. Selecionar a opção "4. Funcionários cadastrados".
3. Inserir o código de funcionário inexistente.

**Saída Esperada:**
- Mensagem de erro "Funcionário com código 9999 não encontrado."
