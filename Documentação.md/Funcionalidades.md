  # Hotel-Descanco-Garantido
- PEDRO AFONSO MACHADO VASCONCELOS
- THIAGO COSTA
## *Documentação das Funcionalidades do Software*

## Introdução
- O software desenvolvido é um sistema de reservas para um hotel, que permite o cadastro de clientes e funcionários, a reserva de quartos e a verificação de disponibilidade de quartos. O sistema é interativo, utilizando o terminal para entrada e saída de dados.

## Funcionalides:
  ## *Cadastro de Clientes:*

- Recebe o nome completo, endereço e telefone do cliente.

- Gera um código ***único*** para o cliente.

- Solicita as datas de entrada e saída da hospedagem, verificando a disponibilidade dos quartos.

### Oferta de Quartos:

- Oferece aos clientes **2 quartos de casal e 2 quartos de solteiro**.

### Verificação de Disponibilidade de Quartos:

- **Não** permite **números negativos**, datas incorretas ou **anteriores a 01/01/2024**.

- A data de saída deve ser **posterior** à data de entrada na hospedagem.

### Reservas de Quartos

- Permite alugar um quarto **no mesmo dia em que a hospedagem de outra pessoa termina**.
  
- Calcula o valor total da hospedagem e confirma a reserva.

- A hospedagem sempre **começa às 14h** e **termina às 12h**, é solicitando o dia anterior à última estadia para evitar a inutilização por outra pessoa do quarto no último dia de hospedagem.

### Bloqueio de Quartos:

- **Bloqueia** o quarto alugado durante o período de entrada e saída.

   ## *Cadastro de Funcionários:*

- Recebe o nome completo e telefone do funcionário.

- Gera um código **único** para o funcionário de 4 digitos.

- Solicita o cargo e define o salário correspondente.

### Limite de Funcionários:

- Permite no **máximo 2 auxiliares de limpeza, 2 garçons, 2 secretárias e 1 gerente para cadastro**.

- Verifica se há vagas disponíveis para o cargo escolhido.


  ## *Consulta de Clientes Cadastrados:*

- Permite a consulta de informações de um cliente cadastrado através do código do cliente.

- Exibe as **informações pessoais e detalhes da reserva, incluindo o código de estadia**.


  ## *Consulta de Funcionários Cadastrados:*

- Permite a consulta de informações de um funcionário cadastrado através do código do funcionário.

- Exibe as **informações pessoais, incluindo cargo e salário**.

  ## *Validação de Entrada de Dados:*

- Aceita **apenas números ou letras válidas**, dependendo da pergunta feita durante o cadastro.
