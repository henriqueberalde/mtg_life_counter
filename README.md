# Contador de vida MGT (Magic The Gatherin)

Um dispositivo eletrônico para contar as vidas de dois jogadores de MGT com estilo cyberpunk.

# Decisões
## Arquitetura do Contador
### Opção 1 - Somente CIs
PROS
 - Varios componentes para o visual
 - Não usa Arduino


CONS
 - Complexo para construir
 - Só da pra usar display de 7seg
 - Muitos componentes (dificil de testar, fazer funcionar e descobrir erros)
 - Precisa de 2 CIs para cada display (total 8 CIs)
 - Complexidade de trilhas (talvez nem de pra fazer manualmente numa placa universal)

### Opção 2 - Arduino e qualquer display
[Thinkercad](https://www.tinkercad.com/things/4IUuWrgkwlP-mtg-counter/editel)

PROS
 - Circuito mais simples
 - Display mais bonito (dependendo da escolha)
 - Mais possibilidades de exibição / design (outros leds ou outras figuras mostradas no display além do número em si)
 - Possibilidade de prototipar em ferramentas online
 - Simplicidade para fazer funcionar sem precisar entender binário ou conversões do tipo
 - Muitos tutoriais prontos


CONS
 - Depende de conseguir executar o Arduino stand alone (chip atmega328p)
 - Menos componentes na placa (visual)


### Opção 3 - Modularizado
PROS
 - Simplicidade de circuito
 - Possibilidade de mudar o produto depois de pronto (trocando os modulos) 


CONS
 - Muitas conexões e pinagens só para modularizar
 - Demora mais no geral pra terminar

## Entradas / Configurações
...

## Fonte de Energeia
...

# EasyEDA
## Fonte
![image](https://user-images.githubusercontent.com/13604070/235566773-9c3d9bad-1e4c-46e1-880f-7b4684251aec.png)
![image](https://user-images.githubusercontent.com/13604070/235567106-514e6fbb-51b4-4f7c-bca0-2ea6ad5c9f2a.png)

## Botões
![image](https://user-images.githubusercontent.com/13604070/235566697-5bb0d549-5de7-4f24-898c-0f1eed5315e5.png)
![image](https://user-images.githubusercontent.com/13604070/235567019-b0f162d7-c365-42a0-9df8-8db6f34aadb2.png)

## Display
![image](https://user-images.githubusercontent.com/13604070/235566811-c893d4d3-ff48-4350-a79c-d3f09c949fcb.png)
![image](https://user-images.githubusercontent.com/13604070/235567166-070ee30e-d852-464d-acf2-1ccaee0834cd.png)


# Lista de Materiais
...


# Ideias
###### Eletrônica / Arduino / Tinkercad
- Fazer em módulos separados cada um com um display
- Fazer um switch com uma alavanca pequena para os mesmos botões alterarem os dois lados
- Usar o PCF8574 para economizar portas
- Fazer sem arduino (usando IC4029 e IC7447 / 7448)
- Outros leds de enfeite (pensar nas portas que eles vão usar)
- Uma forma gráfica (com leds) de mostrar a porcentagem da vida (proporcional a 20 pontos)
- Usar uma bateria pequena como aquela redondinha de 3v

###### Material / Construção / Estilo
- A própria estrutura de fios e soldas formar um dispositivo exposto bem cyberpunk
- Usar outro objeto bem legal e característico improvisado
- Muitos leds
- Usar uma placa de circuito mesmo mas pintar ela com spray com cores neon
- <s>Colocar um buser para soar alguma coisa quando a vida estiver baixa</s>


# Tinkercad
> Ideia antiga (foi descontinuada)
- https://www.tinkercad.com/things/4IUuWrgkwlP-counter

EasyEDA Componentes

Button
Reset - K4-6x6_TH
Clock - K4-12x12_SMD

Resistor
R_AXIAL-0.4_US

Capacitor
C_Ele_TH_D4.0xF1.5_EU

7Seg
SEG-TH_0.56x1_Anode

Regulador de tensão
7905(TO-220)

Lever Switch (Não encontrei um igual)
SK-12D02-VG5


# Referências

Contador crescente e decrescente sem arduino
- https://www.youtube.com/watch?v=QCqeS5KknzE
- https://www.youtube.com/watch?v=OqT0pV7JWu8&t=168s
- https://www.youtube.com/watch?v=fAuexgN2OsA

Contador sem botões
- https://www.youtube.com/watch?v=fZEkisltjMQ
- https://www.youtube.com/watch?v=rH2aJZNqYcQ

Contador sem Arduino (simples de fazer mas não serve porque não da pra subtrair do contador)
- https://www.youtube.com/watch?v=5cRS2lRKSAg

Contador sem Arduino de dois dígitos (simples de fazer mas não serve porque não da pra subtrair do contador)
- https://www.youtube.com/watch?v=V1SdCgZvbzA

Truque para usar no push button (debounce)
- https://www.youtube.com/watch?v=ZoaUlquC6x8

Como usar o Arduino fora da placa
- https://www.youtube.com/watch?v=4KMgb_S4bF4

Como usar o extensor de portas PCF8574 para Arduino
- https://www.youtube.com/watch?v=dRb5mAvJfCo
- https://www.youtube.com/watch?v=usPiM_vv-rc
- https://www.youtube.com/watch?v=r-3p-weAtOY

Contadores de vida MTG
- https://github.com/mprosk/mtg_life_counter
- https://www.hackster.io/news/hexentronics-releases-electronic-dice-timer-and-life-counter-for-card-and-board-games-f8d0f96f8e9e
- https://www.google.com/imgres?imgurl=https%3A%2F%2Fclay.ch%2Fwp-content%2Fuploads%2F2021%2F11%2FMTG-Lifecounter-4-Player-Commander-01-scaled.jpg&imgrefurl=https%3A%2F%2Fclay.ch%2Fprodukt%2Fmtg-lifecounter-4-player%2F&tbnid=QurRptWFmbnecM&vet=10CAIQxiAoAGoXChMIsKLv6PrU_QIVAAAAAB0AAAAAEAg..i&docid=GLDRg-MtMykYNM&w=2560&h=2560&itg=1&q=cyberpunk%20MGT%20life%20counter&client=ubuntu&ved=0CAIQxiAoAGoXChMIsKLv6PrU_QIVAAAAAB0AAAAAEAg
- https://www.youtube.com/watch?v=t6Y_GCoSUt4

Todos os tipos de dado D&D em um dispositivo
- https://www.digikey.com/en/maker/projects/all-dungeons-and-dragons-dice-in-one-device/7f0a5df5e8144a67a1707f0b45166c76


# Referências Visuais
![image](https://github.com/henriqueberalde/mtg_life_counter/assets/13604070/edd71168-a7b4-479a-8633-40eac22f4d62)
