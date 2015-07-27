![JAGA logo](https://github.com/JorgeGzm/JAGA/blob/master/docs/logo.jpg)

# English:

The JAGA project was conceived by Jorge Guzman and Rafael Lopes and aims to create universal libraries using the C language The construction of each lib shall ensure good performance, modularity, code portability for microcontrollers with architectures 8, 16 and 32-bit and easy integration with an RTOS.

The initial development of the libs will be focused on the most used in teaching embedded systems and Arduino shields that can be easily purchased peripherals.

The software architecture is based on the communication of 3 layers: Application, Middleware and HAL (Hardware Application Layer). Communication between the layers takes place through data abstraction, orientation events and the following rules:

Application Layer:

- Avoid horizontal calls at the application layer
- Only call functionality functions of middleware layer.

Layer Middleware:

- There can be, in any way, horizontal calls;
- Can only include libraries Header Files(".h") from HAL layer.

HAL layer (Driver):

- There is only to allow platform portability and organize access to peripherals.
- Provide abstracted functions to configure and access the registers the specific microcontroller.
- It is the only layer whose libraries can make horizontal calls.

Independent Libraries (Util):

- Libraries that do not depend on any other may be independent, so they can be called from any layer. eg vars.h, crc.h, printf.h;

Layer "Init hardware" is different for each project, it's responsible for configuring peripherals and microcontroller interrupts, also initialize and configure the middleware layer libraries.

The major purpose of this project is to create, teach and share knowledge for the development of a good firmware.

-------------------------------------------------------------------------------------------------------------------

# Português:

O projeto JAGA foi idealizado por Jorge Guzman e Rafael Lopes e tem como objetivos criar bibliotecas universais usando a linguagem C. A construção de cada lib deverá garantir uma boa performance, modularidade, portabilidade do código para microcontroladores com arquiteturas de 8, 16 e 32 bits e de fácil integração com um RTOS.

O desenvolvimento inicial das libs será focado nos periféricos mais usados no ensino de sistemas embarcados e em shields arduinos que podem ser facilmente adquiridos.

A arquitetura do software é baseada na comunicação de 3 camadas: Application, Middleware e HAL (Hardware Application Layer). A comunicação entre as camadas se dá por meio da abstração de dados, orientação a eventos e as seguintes regras abaixo:

Camada de Aplicação:
- Evitar chamadas horizontais na camada de aplicação
- Somente chamar funções de funcionalidade da camada de Middleware.

Camada de Middleware:

- Não pode haver, de maneira alguma, chamadas horizontais;
- Só pode incluir Header Files(".h") das bibliotecas da camada HAL

Camada HAL (Driver):
- Só existe para permitir portabilidade de plataforma e organizar o acesso aos periféricos.
- Fornecerá funções abstraídas para configurar e acessar os registradores do microcontrolador específico.
- É a única camada cujas bibliotecas podem fazer chamadas horizontais.

Bibliotecas Independentes(Util):

- Bibliotecas que não dependem de nenhuma outra podem ser independentes, então podem ser chamadas de qualquer camada. ex: vars.h, crc.h, printf.h;

A Camada “Init hardware” é diferente para cada projeto, ela é responsável por configurar os periféricos e interrupções do microcontrolador, também inicializar e configura as bibliotecas da camada middleware.

O maior intuito deste projeto é criar, ensinar e compartilhar conhecimento para o desenvolvimento de um bom firmware.

Referências:

http://www.embarcados.com.br/arquitetura-de-software-em-sistemas-embarcados/
https://selivre.wordpress.com/2011/10/15/praticas-para-a-qualidade-design-da-firmware/
