# Alimentador automático para aquário

## Descrição
Este projeto consiste em um alimentador automático para aquário, capaz de liberar comida para o peixe de forma automática em intervalos de tempo programados.

O sistema utiliza um ESP32, um módulo RTC DS3231, um motor de passo 28BYJ-48 e um driver ULN2003.

## Funcionamento
O RTC controla o horário e o motor de passo gira o compartimento de ração, liberando comida automaticamente.

No código atual, a alimentação acontece a cada 5 segundos (valor usado para teste).

## Componentes utilizados
- ESP32
- Motor de passo 28BYJ-48
- Driver ULN2003
- RTC DS3231
- Fonte 5V

## Autoras
Maria Lívia Fernandes Domingues e Sofia Sarah Moreira de Oliveira
