  # Hotel-Descanco-Garantido
- PEDRO AFONSO MACHADO VASCONCELOS
- THIAGO COSTA
   # *Planejamento dos Casos de Teste*
  ## *Sprint 1*
- Fazer arquitetura de como ficara o codigo
- Adicionar bibliotecas:#include <stdio.h>,
#include <stdlib.h>,
#include <string.h>,
#include <ctype.h>,
#include <time.h>.
- Adicionar variáveis a serem ultilizadas.
- Separar o codigo em blocos de funções.
- Trabalhar na geração de números aleatórios.
- Trabalhar em na comunicação com o usuário (printf).
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

  ## *Sprint 2*
- Implementar mais variáveis.
- Corrigir bugs e melhorar funcionalidades.
- Trabalhar na parte de datas e hospedagem do quarto.
- Quantificar o número de quartos e funcionários.
- Não permitir particuliaridades, número negativo, datas erradas ou anteriores a 01/01/2024.
- Permitir que assim que outra pessoa saia do quarto outra pessoa alugar.
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
