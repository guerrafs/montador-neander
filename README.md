# Neander Assembly to Hexadecimal Converter

Este projeto implementa um montador simples para o Neander, uma arquitetura de computador didática, convertendo instruções de assembly em representações hexadecimal. O objetivo é traduzir um conjunto de instruções de assembly armazenadas em um arquivo de texto para um arquivo binário `.MEM`, compatível com emuladores de Neander.

## Funcionalidades

- **Leitura de Instruções**: Leitura de um arquivo de texto contendo instruções de assembly para o Neander.
- **Conversão para Hexadecimal**: Conversão de cada instrução de assembly e seu parâmetro correspondente para uma representação hexadecimal.
- **Armazenamento na Memória**: Armazenamento das instruções convertidas na memória simulada do Neander.
- **Criação de Arquivo Binário**: Geração de um arquivo binário `.MEM` contendo as instruções em formato hexadecimal, pronto para ser utilizado em emuladores de Neander.


## Como usar?
- **1** Certifique-se que as instruções do Neander estão em um arquivo de texto (.txt) nomeado como "instrucoes.txt"
- **2** Modifique o caminho do arquivo de entrada no código, de forma que ele aponte para o diretório onde o arquivo está localizado.
- **3** O arquivo de saída sera gerado com o nome "saida.MEM" no mesmo diretório onde o programa é executado

