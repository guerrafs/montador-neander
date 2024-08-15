#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEM_SIZE 516 // Tamanho total da memória em bytes 516 - 4 do cabeçalho padrão

// Função que converte a instrução e seu parâmetro em uma representação hexadecimal
void converteParaHexadecimal(const char *instrucao, const char *parametro, char *hexadecimal)
{
    // Compara a entrada com um conjunto de instruções e retorna a saída hexadecimal correspondente
    if (strcmp(instrucao, "NOP") == 0)
    {
        sprintf(hexadecimal, "00 00 00 00");
    }
    else if (strcmp(instrucao, "LDA") == 0)
    {
        sprintf(hexadecimal, "20 00 %s 00", parametro);
    }
    else if (strcmp(instrucao, "STA") == 0)
    {
        sprintf(hexadecimal, "10 00 %s 00", parametro);
    }
    else if (strcmp(instrucao, "ADD") == 0)
    {
        sprintf(hexadecimal, "30 00 %s 00", parametro);
    }
    else if (strcmp(instrucao, "OR") == 0)
    {
        sprintf(hexadecimal, "40 00 %s 00", parametro);
    }
    else if (strcmp(instrucao, "AND") == 0)
    {
        sprintf(hexadecimal, "50 00 %s 00", parametro);
    }
    else if (strcmp(instrucao, "NOT") == 0)
    {
        sprintf(hexadecimal, "60 00 00 00");
    }
    else if (strcmp(instrucao, "JMP") == 0)
    {
        sprintf(hexadecimal, "80 00 %s 00", parametro);
    }
    else if (strcmp(instrucao, "JN") == 0)
    {
        sprintf(hexadecimal, "90 00 %s 00", parametro);
    }
    else if (strcmp(instrucao, "JZ") == 0)
    {
        sprintf(hexadecimal, "A0 00 %s 00", parametro);
    }
    else if (strcmp(instrucao, "HLT") == 0)
    {
        sprintf(hexadecimal, "F0 00 00 00");
    }
}

int main()
{
    FILE *arquivoEntrada, *arquivoSaida; // Ponteiros para arquivos de entrada e saída
    char linha[100];                     // Vetor para ler cada linha do arquivo de entrada
    char instrucao[10];                  // Vetor para armazenar a instrução
    char parametro[10];                  // Vetor para armazenar o parâmetro da instrução
    char hexadecimal[40];                // Vetor para armazenar a  hexadecimal da instrução
    unsigned char memoria[MEM_SIZE];     // Vetor para armazenar a memória (512 bytes)
    int posicao = 0;                     // Posição atual na memória

    memset(memoria, 0, sizeof(memoria)); // Inicializa a memória com zeros

    // Abre o arquivo de entrada para leitura
    arquivoEntrada = fopen("C:\\Users\\guerr\\Desktop\\montador\\montador-neander\\Montador\\instrucoes.txt", "r");

    if (arquivoEntrada == NULL)
    {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    memoria[0] = 0x03;
    memoria[1] = 0x4E;
    memoria[2] = 0x44;
    memoria[3] = 0x52;
    posicao = 4; // Atualiza a posição na memória após o cabeçalho

    // Lê o arquivo linha por linha
    while (fgets(linha, sizeof(linha), arquivoEntrada) && posicao < MEM_SIZE)
    {
        // explicar melhor esse trecho
        linha[strcspn(linha, "\n")] = '\0';           // Remove o caractere de nova linha do 'fgets'
        parametro[0] = '\0';                          // Inicializa  o parâmetro como uma string vazia
        sscanf(linha, "%s %s", instrucao, parametro); // Lê a instrução e o parâmetro da linha

        // Converte a instrução e o parâmetro para hexadecimal
        converteParaHexadecimal(instrucao, parametro, hexadecimal);

        // Converte o hexadecimal para quatro bytes
        unsigned int byte1, byte2, byte3, byte4;
        sscanf(hexadecimal, "%x %x %x %x", &byte1, &byte2, &byte3, &byte4);

        // Armazena os bytes na memória
        if (posicao + 4 <= MEM_SIZE) //verifica se há 4 espaços para bytes
        {
            memoria[posicao++] = (unsigned char)byte1; //unsigned para valores até 255
            memoria[posicao++] = (unsigned char)byte2;
            memoria[posicao++] = (unsigned char)byte3;
            memoria[posicao++] = (unsigned char)byte4;
        }
    }

    fclose(arquivoEntrada); // Fecha o arquivo de entrada

    // Abre o arquivo de saída para escrita binária
    arquivoSaida = fopen("saida.MEM", "wb"); //"wb" garante que o arquivo vai ser tratado como binario

    // Escreve a memória no arquivo de saída
    fwrite(memoria, sizeof(unsigned char), MEM_SIZE, arquivoSaida);

    fclose(arquivoSaida); // Fecha o arquivo de saída

    printf("Conversao concluida com sucesso!\n");
    return 0;
}
