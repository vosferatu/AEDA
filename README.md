# AEDA 2016/2017 - "Boleias Partilhadas" [projeto C++]

### Descrição do tema

Uma empresa deseja explorar o conceito de car-pooling e ride-sharing, e pretende criar um sistema para a
gestão de uma rede social de partilha de boleias. Poderá haver dois tipos de utilizadores: os registados no
sistema e aqueles que utilizam o sistema ocasionalmente. Entre os utilizadores, também haverá aqueles que
desejam disponibilizar as suas viaturas, e aqueles que não têm viaturas para partilhar, mas apenas partilham as
viagens.

Quando um utilizador disponibiliza o seu veículo no sistema, deverá indicar o número de lugares disponíveis, e o
itinerário que realiza como uma lista de pontos de passagem, sendo o primeiro ponto o endereço de origem da
viagem e o último ponto o endereço de destino. Utilizadores que possam ter interesse em partilhar a viagem toda
ou trechos das viagens, podem candidatar-se aos lugares disponíveis. É possível que fiquem vagos lugares no
decorrer da viagem, podendo estar disponíveis a quem desejar realizar o trecho ou parte do trecho
remanescente.

Sendo construído em torno do conceito de redes socais, o sistema também privilegia a formação de grupos de
partilha de viagem entre pessoas próximas entre si; os utilizadores, ao se registarem no sistema, podem
associar-se como “buddy” de outros utilizadores – desta forma é possível criar uma rede de relações diretas e
indiretas entre utilizadores. O serviço de partilha é mantido pelos próprios utilizadores. Os utilizadores que têm
viatura própria e a partilham no sistema, pagam apenas uma taxa de manutenção; os utilizadores registados sem
viatura, pagam uma mensalidade fixa de manutenção mais o que realizarem em número de viagens, durante o
mês; os utilizadores que utilizam o serviço esporadicamente devem efetuar pagamento em cada viagem.

O sistema, para além de guardar as relações de amizade (“buddies”) dos utilizadores registados, também
mantém o histórico das viagens realizadas, incluindo o nome do utilizador proprietário da viatura, os pontos de
origem e destino da viagem, a hora de início e de fim, assim como o dia em que foi realizada. Adicionalmente
poderá considerar veículos diferentes, nomeadamente veículos ligeiros (5 lugares), vans (de 7 lugares), entre
outras opções.

### Linhas gerais do trabalho

Trabalho prático - Parte 1

O trabalho agora enunciado apenas se refere à primeira parte do mesmo. 

A segunda parte do trabalho será enunciada posteriormente (após a entrega desta primeira parte).


### Notas relativas à implementação (itens sujeitos a avaliação)
+ Deve utilizar **classes adequadas** para representação das entidades envolvidas. Os atributos devem ser escolhidos de forma a caracterizar os conceitos mais importantes das entidades a representar).
+ Deve utilizar o conceito de **herança e polimorfismo** onde considerar conveniente.
+ Os dados usados pela aplicação devem ser **guardados em ficheiro**, para utilização em futuras execuções.
+ Deve tratar convenientemente possíveis excepções.
+ Deve usar algoritmos de **pesquisa e ordenação** (por exemplo, nas múltiplas listagens solicitadas) 
+ As classes implementadas devem ser **devidamente documentadas (usando Doxygen)**.

### Notas relativas à demonstração (itens sujeitos a avaliação)
+ Preparação adequada para demonstrar as funcionalidades do trabalho
+ Deve usar um número significativo de itens (dados).
+ Todos os elementos do grupo devem estar presentes

### Relatório (itens sujeitos a avaliação)
+ O relatório, a ser entregue em formato pdf, deve incluir:
 + Página de rosto com título do trabalho, identificação dos elementos do grupo (nome, código, email) e data
 + Descrição sucinta do tema do trabalho
 + Descrição da solução implementada
 + Diagramas UML do modelo de dados concebido (diagrama de classes, indicando para cada classe as suas relações, atributos e métodos)
 + Lista de Casos de Utilização identificados para a aplicação (não é necessário desenhar os diagramas de casos de utilização)
 + Relato das principais dificuldades encontradas no desenvolvimento do trabalho
 + Indicação do esforço dedicado por cada elemento do grupo

### Entrega
+ Disponibilizar em um ficheiro <NOME>.zip: 
 + pasta **codigo** (contém código fonte do programa)
 + pasta **documentacao** (contém documentação html, criada pelo Doxygen)
 + ficheiro **relatorio** (documento em formato pdf)

+ O <NOME> do ficheiro deverá obedecer ao formato AEDA1617_<TURMA>_<GRUPO>, onde turma é o código da turma teórico/prática e <GRUPO> é uma letra que identifica o grupo, conforme indicado na atribuição de trabalhos. Por exemplo: AEDA1617_2MIEIC5_C.zip corresponde ao trabalho realizado pelo grupo C da turma 2MIEIC5
 + No nosso caso, **AEDA1617_2MIEIC04_G**

### Datas
+ Data de entrega: 
 + dia **18/novembro, até às 23h59m**. 
 + Submeter pelo Moodle: **Relatório em pdf + Código do programa + documentação**
+ Apresentação do trabalho:  
 + de **21 a 24 de novembro**, em horário a combinar com o docente das aulas práticas

