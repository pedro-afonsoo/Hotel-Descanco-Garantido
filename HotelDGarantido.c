#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Definição da estrutura de reserva
typedef struct {
    int diaEntrada;
    int mesEntrada;
    int anoEntrada;
    int diaSaida;
    int mesSaida;
    int anoSaida;
    int codigo_cliente;
    int codigo_funcionario;
} Reserva;

// Máximo de reservas por quarto
#define MAX_RESERVAS 100

// Vetores para armazenar as reservas dos quartos
Reserva reservasSolteiro1[MAX_RESERVAS];
int countSolteiro1 = 0;
Reserva reservasSolteiro2[MAX_RESERVAS];
int countSolteiro2 = 0;
Reserva reservasCasal1[MAX_RESERVAS];
int countCasal1 = 0;
Reserva reservasCasal2[MAX_RESERVAS];
int countCasal2 = 0;

// Estrutura para armazenar informações do cliente
typedef struct {
    int codigo_cliente;
    int codigo_funcionario; // Adicione esta linha
    char nome[100];
    char endereco[100];
    char telefone[20];
    char dataEntrada[20];
    char dataSaida[20];
    int diaEntrada;
    int mesEntrada;
    int anoEntrada;
    int diaSaida;
    int mesSaida;
    int anoSaida;
    char quarto[20];
} Cliente;

#define MAX_CLIENTES 100
Cliente clientes[MAX_CLIENTES];
int countClientes = 0;

// Estrutura para armazenar informações do funcionário
typedef struct {
    int codigo_funcionario;
    char nome[100];
    char telefone[20];
    int cargo;
    int salario;
} Funcionario;

#define MAX_FUNCIONARIOS 100
Funcionario funcionarios[MAX_FUNCIONARIOS];
int countFuncionarios = 0;

// Variáveis para contar funcionários cadastrados
int contRecepcionista = 0;
int contAuxiliarLimpeza = 0;
int contGerente = 0;
int contGarcom = 0;

// Função para calcular a diferença em dias entre duas datas
int calcular_dias(int diaEntrada, int mesEntrada, int anoEntrada, int diaSaida, int mesSaida, int anoSaida) {
    struct tm entrada = {0, 0, 0, diaEntrada, mesEntrada - 1, anoEntrada - 1900};
    struct tm saida = {0, 0, 0, diaSaida, mesSaida - 1, anoSaida - 1900};
    time_t tempoEntrada = mktime(&entrada);
    time_t tempoSaida = mktime(&saida);
    return difftime(tempoSaida, tempoEntrada) / (60 * 60 * 24);
}

// Função para verificar disponibilidade do quarto
int verificar_disponibilidade(Reserva reservas[], int count, int diaEntrada, int mesEntrada, int anoEntrada, int diaSaida, int mesSaida, int anoSaida) {
    for (int i = 0; i < count; i++) {
        if (!(
            (anoSaida < reservas[i].anoEntrada) ||
            (anoEntrada > reservas[i].anoSaida) ||
            (anoEntrada == reservas[i].anoSaida && mesEntrada > reservas[i].mesSaida) ||
            (anoSaida == reservas[i].anoEntrada && mesSaida < reservas[i].mesEntrada) ||
            (anoEntrada == reservas[i].anoSaida && mesEntrada == reservas[i].mesSaida && diaEntrada > reservas[i].diaSaida) ||
            (anoSaida == reservas[i].anoEntrada && mesSaida == reservas[i].mesEntrada && diaSaida < reservas[i].diaEntrada)
        )) {
            return 0; // Não disponível
        }
    }
    return 1; // Disponível
}

int main() {
    //gerar numeros aleatorios entre 1000 e 9997 para o codigo ter no max 5 caracteres
    srand(time(NULL));
    int numero_aleatorio = rand();

    // Declarações de variáveis
    char escolha1, escolha2, nome[100], endereco[100], telefone[20], dataEntrada[20], dataSaida[20], continuar;
    int escolha_valida, cargo, salario, hospedes;
    int diaEntrada, mesEntrada, anoEntrada, diaSaida, mesSaida, anoSaida;
    int valorQuarto, valorTotal;
    char quarto[20];
    int codigo_cliente, codigo_funcionario;

    while (1) {
        escolha_valida = 0;
        printf("\nBem vindo ao Hotel Descanso Garantido (ITACARÉ - BA)\nCADASTRO:\n1. Cliente\n2. Funcionário\n3. Clientes cadastrados\n4. Funcionários cadastrados\n");
        scanf(" %d", &escolha1);

        if (escolha1 == 1) {
            // Cliente
            printf("\nVocê escolheu a opção Cliente\nQual seu nome completo?\n");
            scanf(" %[^\n]", nome);  // Lê o nome completo incluindo espaços
            printf("\nQual o seu endereço? Por favor inclua o cep, número e complemento:\n");
            scanf(" %[^\n]", endereco);  // Lê o endereço completo

            // Loop para garantir que o número de telefone tenha exatamente 9 dígitos
            while (1) {
                printf("\nQual o seu telefone? (9 digitos)\n");
                scanf(" %s", telefone);

                // Verifica se o telefone tem 9 dígitos e se são todos números
                int valido = 1;  // Assume que é válido inicialmente
                for (int i = 0; i < strlen(telefone); i++) {
                    if (!isdigit(telefone[i])) {
                        valido = 0;  // Se encontrar algum não dígito, marca como inválido
                        break;
                    }
                }
                if (strlen(telefone) == 9 && valido) {
                    break;  // Sai do loop se o telefone estiver correto
                } else {
                    printf("Número de telefone incorreto. Digite novamente.\n");
                    while ((getchar()) != '\n');  // Limpa o buffer de entrada
                }
            }

            // Cálculo do código do cliente
            codigo_cliente = 1000 + (numero_aleatorio % 8798) + strlen(nome) + strlen(endereco);
            printf("\nSeu código de cliente é: C%d\n", codigo_cliente);

            // Pergunta se deseja voltar ao início
            printf("\nDeseja voltar ao início? (S/N)\n");
            scanf(" %c", &escolha2);

            // Se não deseja voltar ao início, pede datas de hospedagem
            if (escolha2 == 'N' || escolha2 == 'n') {
                while (1) {
                    printf("\nQual a data em que você deseja se hospedar? (DD/MM/YYYY)\n");
                    scanf(" %s", dataEntrada);

                    // Verifica se a data mínima é 01/01/2024
                    sscanf(dataEntrada, "%d/%d/%d", &diaEntrada, &mesEntrada, &anoEntrada);
                    if (anoEntrada < 2024 || (anoEntrada == 2024 && mesEntrada < 1) || (anoEntrada == 2024 && mesEntrada == 1 && diaEntrada < 1) || mesEntrada > 12 || mesEntrada < 1 || diaEntrada > 30 || diaEntrada < 1) {
                        printf("\nData de entrada inválida. A data mínima permitida é 01/01/2024. Digite novamente.\n");
                        continue;
                    }

                    printf("\nAgora digite o dia anterior à ultima estadia: (DD/MM/YYYY)\n");
                    scanf(" %s", dataSaida);

                    // Verifica se as datas são válidas e se a data de saída é posterior à data de entrada
                    sscanf(dataSaida, "%d/%d/%d", &diaSaida, &mesSaida, &anoSaida);
                    if (anoSaida < anoEntrada || 
                        (anoSaida == anoEntrada && mesSaida < mesEntrada) || 
                        (anoSaida == anoEntrada && mesSaida == mesEntrada && diaSaida < diaEntrada)) {
                        printf("\nErro: Data de saída deve ser posterior à data de entrada. Digite novamente.\n");
                    } else {
                        int diasHospedagem = calcular_dias(diaEntrada, mesEntrada, anoEntrada, diaSaida, mesSaida, anoSaida);
                        printf("\nQuantos hóspedes estarão no quarto? (1 ou 2)\n");
                        scanf("%d", &hospedes);
                        if (hospedes <= 0) {
                            printf("\nQuantidade de hóspedes inválida. Deve ser maior que zero.\n");
                            continue;  // Volta ao início do loop para pedir novamente
                        }

                        int quarto_disponivel = 0;
                        if (hospedes == 1) {
                            if (verificar_disponibilidade(reservasSolteiro1, countSolteiro1, diaEntrada, mesEntrada, anoEntrada, diaSaida, mesSaida, anoSaida)) {
                                strcpy(quarto, "quartoSolteiro1");
                                reservasSolteiro1[countSolteiro1++] = (Reserva){diaEntrada, mesEntrada, anoEntrada, diaSaida, mesSaida, anoSaida, codigo_cliente, codigo_funcionario};
                                quarto_disponivel = 1;
                            } else if (verificar_disponibilidade(reservasSolteiro2, countSolteiro2, diaEntrada, mesEntrada, anoEntrada, diaSaida, mesSaida, anoSaida)) {
                                strcpy(quarto, "quartoSolteiro2");
                                reservasSolteiro2[countSolteiro2++] = (Reserva){diaEntrada, mesEntrada, anoEntrada, diaSaida, mesSaida, anoSaida, codigo_cliente, codigo_funcionario};
                                quarto_disponivel = 1;
                            } else {
                                printf("\nDesculpe, todos os quartos solteiro estão ocupados.\n");
                                continue;  // Volta ao início do loop para pedir novamente
                            }
                        } else if (hospedes == 2) {
                            if (verificar_disponibilidade(reservasCasal1, countCasal1, diaEntrada, mesEntrada, anoEntrada, diaSaida, mesSaida, anoSaida)) {
                                strcpy(quarto, "quartoCasal1");
                                reservasCasal1[countCasal1++] = (Reserva){diaEntrada, mesEntrada, anoEntrada, diaSaida, mesSaida, anoSaida, codigo_cliente, codigo_funcionario};
                                quarto_disponivel = 1;
                            } else if (verificar_disponibilidade(reservasCasal2, countCasal2, diaEntrada, mesEntrada, anoEntrada, diaSaida, mesSaida, anoSaida)) {
                                strcpy(quarto, "quartoCasal2");
                                reservasCasal2[countCasal2++] = (Reserva){diaEntrada, mesEntrada, anoEntrada, diaSaida, mesSaida, anoSaida, codigo_cliente, codigo_funcionario};
                                quarto_disponivel = 1;
                            } else {
                                printf("\nDesculpe, todos os quartos casal estão ocupados.\n");
                                continue;  // Volta ao início do loop para pedir novamente
                            }
                        }

                        // Adiciona o cliente ao vetor clientes
                        Cliente novoCliente;
                        novoCliente.codigo_cliente = codigo_cliente;
                        strcpy(novoCliente.nome, nome);
                        strcpy(novoCliente.endereco, endereco);
                        strcpy(novoCliente.telefone, telefone);
                        strcpy(novoCliente.dataEntrada, dataEntrada);
                        strcpy(novoCliente.dataSaida, dataSaida);
                        novoCliente.diaEntrada = diaEntrada;
                        novoCliente.mesEntrada = mesEntrada;
                        novoCliente.anoEntrada = anoEntrada;
                        novoCliente.diaSaida = diaSaida;
                        novoCliente.mesSaida = mesSaida;
                        novoCliente.anoSaida = anoSaida;
                        strcpy(novoCliente.quarto, quarto);
                        clientes[countClientes++] = novoCliente;

                        valorQuarto = (hospedes == 1) ? 400 : 600;  // Define o valor do quarto com base no número de hóspedes
                        valorTotal = (diasHospedagem + 1) * valorQuarto;
                        printf("\nO valor total da hospedagem será de: R$ %d,00\n", valorTotal);

                        // Pergunta se deseja continuar
                        printf("\nDeseja continuar com a hospedagem? (S/N)\n");
                        scanf(" %c", &continuar);
                        if (continuar == 'N' || continuar == 'n' || continuar != 'S' || continuar != 's') {
                            break;
                        } else {
                            // Cálculo do código de estadia, mensagem de confirmação, etc.
                            // Cálculo do código de estadia
                            int codigo_estadia = codigo_cliente + 1;
                            printf("\nOlá %s,\nSeu código de cliente é: C%d,\nSeu código de estadia é: E%d,\nSeu número de telefone é: %s,\nVocê ficará hospedado no %s por %d diárias, contadas a partir do dia %s às 14 horas e finalizando um dia após %s às 12 horas.\nO valor total da hospedagem será de: R$ %d,00.\nObrigado por se hospedar!\n",
                                   nome, codigo_cliente, codigo_estadia, telefone, quarto, diasHospedagem + 1, dataEntrada, dataSaida, valorTotal);
                            escolha_valida = 1;
                            break;
                        }
                    }
                }
            }
        } else if (escolha1 == 2) {
            // Funcionário
            printf("\nVocê escolheu a opção Funcionário,\nQual seu nome completo?\n");
            scanf(" %[^\n]", nome);  // Lê o nome completo incluindo espaços

            // Loop para garantir que o número de telefone tenha exatamente 9 dígitos
            while (1) {
                printf("\nQual o seu telefone? (9 digitos)\n");
                scanf(" %s", telefone);

                // Verifica se o telefone tem 9 dígitos e se são todos números
                int valido = 1;  // Assume que é válido inicialmente
                for (int i = 0; i < strlen(telefone); i++) {
                    if (!isdigit(telefone[i])) {
                        valido = 0;  // Se encontrar algum não dígito, marca como inválido
                        break;
                    }
                }
                if (strlen(telefone) == 9 && valido) {
                    break;  // Sai do loop se o telefone estiver correto
                } else {
                    printf("Número de telefone incorreto. Digite novamente.\n");
                    while ((getchar()) != '\n');  // Limpa o buffer de entrada
                }
            }

            // Cálculo do código do funcionário
            codigo_funcionario = 1000 + (numero_aleatorio % 8898) + strlen(nome);
            printf("\nSeu código de Funcionário é: F%d\n", codigo_funcionario);

            // Pergunta e define o cargo e o salário
            while (1) {
                printf("\nQual o seu cargo?\n1- Recepcionista (2 vagas)\n2- Auxiliar de limpeza (2 vagas)\n3- Gerente (1 vagas)\n4- Garçom (2 vagas)\n");
                scanf("%d", &cargo);
                switch (cargo) {
                    case 1:
                        if (contRecepcionista < 2) {
                            salario = 4200;
                            printf("Seu salário é de %d\n", salario);
                            contRecepcionista++;
                            escolha_valida = 1;  // Marca como válida a escolha do funcionário
                        } else {
                            printf("Limite de recepcionistas atingido. Não é possível cadastrar mais.\n");
                            continue;  // Retorna ao início do loop para pedir o cargo novamente
                        }
                        break;
                    case 2:
                        if (contAuxiliarLimpeza < 2) {
                            salario = 1400;
                            printf("Seu salário é de %d\n", salario);
                            contAuxiliarLimpeza++;
                            escolha_valida = 1;  // Marca como válida a escolha do funcionário
                        } else {
                            printf("Limite de auxiliares de limpeza atingido. Não é possível cadastrar mais.\n");
                            continue;  // Retorna ao início do loop para pedir o cargo novamente
                        }
                        break;
                    case 3:
                        if (contGerente < 1) {
                            salario = 11200;
                            printf("Seu salário é de %d\n", salario);
                            contGerente++;
                            escolha_valida = 1;  // Marca como válida a escolha do funcionário
                        } else {
                            printf("Limite de gerentes atingido. Não é possível cadastrar mais.\n");
                            continue;  // Retorna ao início do loop para pedir o cargo novamente
                        }
                        break;
                    case 4:
                        if (contGarcom < 2) {
                            salario = 2800;
                            printf("Seu salário é de R$ %d,00\n", salario);
                            contGarcom++;
                            escolha_valida = 1;  // Marca como válida a escolha do funcionário
                        } else {
                            printf("Limite de garçons atingido. Não é possível cadastrar mais.\n");
                            continue;  // Retorna ao início do loop para pedir o cargo novamente
                        }
                        break;
                    default:
                        printf("Cargo inválido. Digite novamente.\n");
                        continue;  // Retorna ao início do loop para pedir o cargo novamente
                }
                printf("\nOlá %s, para verificação seu número de TELEFONE é %s, seu CÓDIGO DE FUNCIONÁRIO é F%d, seu CARGO é o escolhido pelo número %d e seu SALÁRIO será de R$ %d,00.\n", nome, telefone, codigo_funcionario, cargo, salario);
                printf("\nVocê foi cadastrado com sucesso!\n\n");
                
                // Adiciona o funcionário ao vetor funcionarios
                Funcionario novoFuncionario;
                novoFuncionario.codigo_funcionario = codigo_funcionario;
                strcpy(novoFuncionario.nome, nome);
                strcpy(novoFuncionario.telefone, telefone);
                novoFuncionario.cargo = cargo;
                novoFuncionario.salario = salario;
                funcionarios[countFuncionarios++] = novoFuncionario;

                break;  // Sai do loop de solicitação de cargo
            }
        } else if (escolha1 == 3) {
            int codigo_consulta;
            printf("\nDigite o código do cliente SEM o C  na frente para consultar as informações:\n(o cliente tem que ter completado até cadastro de hospedagem)\n");
            scanf("%d", &codigo_consulta);

            // Busca o cliente pelo código
            int clienteEncontrado = 0;
            for (int i = 0; i < countClientes; i++) {
                if (clientes[i].codigo_cliente == codigo_consulta) {
                    printf("\nInformações do Cliente:\n");
                    printf("Código do Cliente: C%d\n", clientes[i].codigo_cliente);
                    printf("Nome: %s\n", clientes[i].nome);
                    printf("Telefone: %s\n", clientes[i].telefone);
                    clienteEncontrado = 1;
                    printf("O codigo de estadia é: E%d\n",clientes[i].codigo_cliente + 1);

                    // Agora que o cliente foi encontrado, busque a reserva
                    int reservaEncontrada = 0;
                    for (int j = 0; j < countSolteiro1; j++) {
                        if (reservasSolteiro1[j].codigo_cliente == codigo_consulta) {
                            printf("Quarto Reservado: quartoSolteiro1\n");
                            printf("Data de Entrada: %02d/%02d/%d\n", reservasSolteiro1[j].diaEntrada, reservasSolteiro1[j].mesEntrada, reservasSolteiro1[j].anoEntrada);
                            printf("Data de Saída: %02d/%02d/%d\n", reservasSolteiro1[j].diaSaida, reservasSolteiro1[j].mesSaida, reservasSolteiro1[j].anoSaida);
                            reservaEncontrada = 1;
                            break;
                        }
                    }
                    if (!reservaEncontrada) {
                        // Verifique os outros tipos de quartos
                        // ...
                    }

                    if (!reservaEncontrada) {
                        printf("Reserva não encontrada para o cliente com código %d.\n", codigo_consulta);
                    }

                    break; // Sai do loop de clientes, pois o cliente foi encontrado
                }
            }

            if (!clienteEncontrado) {
                printf("Cliente com código %d não encontrado.\n", codigo_consulta);
            }
        } else if (escolha1 == 4) {
            int codigo_consulta;
            printf("Digite o código do funcionário SEM o F para consultar as informações:\n(O funcionário tem que ter completado o cadastro todo)\n ");
            scanf("%d", &codigo_consulta);

            // Busca o funcionário pelo código
            int funcionarioEncontrado = 0;
            for (int i = 0; i < countFuncionarios; i++) {
                if (funcionarios[i].codigo_funcionario == codigo_consulta) {
                    printf("\nInformações do Funcionário:\n");
                    printf("Código do Funcionário: F%d\n", funcionarios[i].codigo_funcionario);
                    printf("Nome: %s\n", funcionarios[i].nome);
                    printf("Telefone: %s\n", funcionarios[i].telefone);
                    switch (funcionarios[i].cargo) {
                        case 1:
                            printf("Cargo: Recepcionista\n");
                            break;
                        case 2:
                            printf("Cargo: Auxiliar de Limpeza\n");
                            break;
                        case 3:
                            printf("Cargo: Gerente\n");
                            break;
                        case 4:
                            printf("Cargo: Garçom\n");
                            break;
                    }
                    printf("Salário: R$ %d,00\n", funcionarios[i].salario);
                    funcionarioEncontrado = 1;
                    break;
                }
            }

            if (!funcionarioEncontrado) {
                printf("Funcionário com código %d não encontrado.\n", codigo_consulta);
            }
        } else {
            printf("Opção inválida! Tente novamente.\n");
        }

        // Verifica se deseja continuar ou sair
        if (escolha_valida) {
            printf("\nDeseja realizar outro cadastro? (S/N)\n");
            scanf(" %c", &continuar);
            if (continuar == 'N' || continuar == 'n') {
                printf("\nSessão finalizada.");
                break;  // Sai do loop principal e encerra o programa
            }
        }
    }
    return 0;
}
