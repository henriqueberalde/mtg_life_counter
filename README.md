# Contador de vida MGT (Magic The Gatherin)

Um dispositivo eletrônico para contar as vidas de dois jogadores de MGT com estilo cyberpunk.

# TODO
- [x] `POC Tinkercad` 2x 7 segments display
- [x] `POC Tinkercad` Add Button
- [x] `POC Tinkercad` Sub Button
- [x] `POC Tinkercad` Reset Button
- [x] `POC Tinkercad` Abandonar a ideia do Tinkercad porque sem arduino é mais facil e barato

- [x] `POC` Contador crescente e decrescente com somente um display
- [x] `POC` da alimentação com o L7905 (regulador de tensão)
- [ ] `POC` Contador crescente e decrescente com display duplo
- [ ] `POC` Botão de reset para 20 pontos de vida
- [ ] `POC` Soldar os componentes com arame
- [ ] `POC` Soldar os componentes numa placa (ilhada ou de fenolite)

- [ ] `Comprar` Trocar os displays de 7seg de AS para BH
- [ ] `Comprar` Comprar a chave gangorra
- [ ] `Comprar` Uma placa de ciruito (ilhada ou de fenolite)

- [ ] `Circuito` Encontrar um simulador de componentes eletronicos que tenha os ICs CD4029BE e SN74LS47N e display dee 7seg 5611BH
- [ ] `Circuito` Documentar o circuito numa ferramenta própria

- [ ] Fazer upload dos videos e fotos que tirei
- [ ] Salvar uma cópia dos datasheets dos componentes aqui no github
- [ ] Calculo de preço (lembrando que até então temos só a metade)
- [ ] Definir o design
- [ ] Construir a primeira versão fora da protoboard


# Lista de Materiais
- `4x` 5611BH (displays de 7seg)
- `4x` CD4029BE
- `4x` SN74LS47N
- `1x` L7905 (regulador de tensão)
- `30x` Resistores de 220 ohms
- `6x` Push Buttons
- `6x` Capacitor de 10uF
- `1x` Suporte para bateria 9v
- `1x` Bateria 9v
- `1x` Chave Alavanca
- `1x` Chave Gangorra
- Placa de ciruito Ilhada ou de Fenolite
- Jumpers
- Arame


# Ideias
###### Eletrônica / Arduino / Tinkercad
- <s>Fazer em dois módulos separados cada um com um display</s>
- <s>Fazer um switch com uma alavanca pequena para os mesmos botões alterarem os dois lados</s>
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


# Tinkercad
> Ideia antiga (foi descontinuada)
- https://www.tinkercad.com/things/4IUuWrgkwlP-counter
