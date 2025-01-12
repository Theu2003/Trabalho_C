# Mateus Martins Peres
# Gerenciamento de Máquinas de Aluguel

Este programa em C permite gerenciar informações sobre máquinas de aluguel. Ele permite cadastrar máquinas, buscar por registro, listar máquinas por tipo e calcular o valor total do aluguel com base nos dias alugados e no valor diário.

## Funcionalidades

- **Cadastrar Máquinas:** Insira as informações das máquinas, incluindo registro, tipo, modelo, fabricante, valor diário e número de dias alugados.
- **Listar Máquinas por Tipo:** Filtre e exiba máquinas de um tipo específico ou de todos os tipos.
- **Buscar Máquina pelo Registro:** Encontre rapidamente uma máquina pelo número de registro.
- **Alterar Quantidade de Máquinas:** Adapte o sistema para gerenciar mais ou menos máquinas, realocando memória conforme necessário.
- **Calcular Valor Total:** O programa calcula automaticamente o valor total do aluguel com base nos dias alugados e no valor diário.

## Estrutura de Dados

O programa utiliza a seguinte estrutura para representar as máquinas:

```c
typedef struct {
    int registro;
    char tipo[50];
    char modelo[50];
    char fabricante[50];
    float valorDiario;
    int diasAlugados;
    float valorTotal;
} Maquina;
```

## Como Executar

1. Compile o programa com o compilador GCC:
   ```bash
   gcc -o gerenciamento_maquinas gerenciamento_maquinas.c
   ```
2. Execute o programa:
   ```bash
   ./gerenciamento_maquinas
   ```

## Uso

1. Informe a quantidade de máquinas no início do programa.
2. Escolha entre as opções do menu principal:
   - Alterar a quantidade de máquinas.
   - Inserir dados das máquinas.
   - Realizar operações com máquinas (listar por tipo ou buscar pelo registro).
   - Sair do programa.
3. Ao listar máquinas ou buscar por registro, as informações detalhadas da máquina serão exibidas.

## Menu Principal

- **[1] Alterar a quantidade de máquinas**: Altera o número de máquinas gerenciadas pelo programa.
- **[2] Entrar com os dados de cada máquina**: Cadastra as informações detalhadas das máquinas.
- **[3] Realizar operações com máquinas**: Exibe um submenu para listar máquinas por tipo ou buscar pelo registro.
- **[4] Sair**: Encerra o programa.

## Exemplo de Entrada

Ao preencher os dados de uma máquina:
```
Digite o registro da máquina 1: 101
Digite o tipo da máquina 1: Escavadeira
Digite o modelo da máquina 1: CAT320
Digite o fabricante da máquina 1: Caterpillar
Digite o valor cobrado por dia de aluguel da máquina 1: 150.00
Digite o número de dias de aluguel da máquina 1: 5
Valor total do aluguel: 750.00
```

## Exemplo de Saída

Listando máquinas por tipo "Escavadeira":
```
Registro: 101
Tipo: Escavadeira
Modelo: CAT320
Fabricante: Caterpillar
Valor diário: 150.00
Dias alugados: 5
Valor total do aluguel: 750.00
Número de máquinas encontradas: 1
```

## Requisitos

- GCC (compilador C).
- Sistema operacional compatível com a execução de programas em C.

## Autor

- **Nome:** [Mateus Martins Peres]
