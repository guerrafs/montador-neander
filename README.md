#Neander Assembly to Hexadecimal Converter
Este projeto implementa um montador simples para o Neander, uma arquitetura de computador didática, convertendo instruções de assembly em representações hexadecimal. O objetivo é traduzir um conjunto de instruções de assembly armazenadas em um arquivo de texto para um arquivo binário .MEM, compatível com emuladores de Neander.

#Funcionalidades
Leitura de Instruções: Leitura de um arquivo de texto contendo instruções de assembly para o Neander.
Conversão para Hexadecimal: Conversão de cada instrução de assembly e seu parâmetro correspondente para uma representação hexadecimal.
Armazenamento na Memória: Armazenamento das instruções convertidas na memória simulada do Neander.
Criação de Arquivo Binário: Geração de um arquivo binário .MEM contendo as instruções em formato hexadecimal, pronto para ser utilizado em emuladores de Neander.
#Estrutura do Código
main(): Função principal que gerencia a leitura do arquivo de entrada, a conversão das instruções e a escrita no arquivo de saída.
converteParaHexadecimal(): Função que converte uma instrução de assembly e seu parâmetro em uma representação hexadecimal.
Uso de fgets e sscanf: Para leitura de linhas do arquivo e extração de instruções e parâmetros.
Manipulação de Memória: Armazenamento das instruções convertidas em um
