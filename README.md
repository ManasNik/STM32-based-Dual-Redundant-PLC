# Overview 
This is a work-in-progress project that I am developing under the guidance of my college faculty member and a consultancy firm. The objective is to build a cost-effective prototype of a Programmable Logic Controller 
(PLC) with dual redundancy, based on the STM32F103C8T6 microcontroller.

The system consists of individual input/output interface modules - namely Digital Input (DI), Digital Output (DO), Analog Input (AI), and Analog Output (AO) - all connected to a main control module, making the design 
modular. This modular approach simplifies maintenance, allows quick replacement of faulty circuits, and provides flexibility and scalability while keeping costs to a minimum.

The system is being designed with dual redundancy, meaning it will have two PLCs: one serving as the main controller and the other as a standby controller. Both will monitor each other’s operating status, with the 
standby unit taking over if the main controller fails. This ensures that the industrial process continues without interruption, even in the event of a controller fault.

# Design 
The whole system circuitry is currently being tested on breadboards. Each module is set up on separate breadboards each containing a STM32F103C8T6 development board. The modules are currently connected via I2C 
communication protocol, making use of the STM32's I2C peripherals. The main controller's I2C1 peripheral is being used to communicate with the input modules (DI and AI) and the I2C2 is being used to communicate with
the output modules (DO and AO). We chose I2C as it is simpler communication protocol having just two lines, leaving more pins for other uses. 

The circuit diagrams and more details of the modules will be updated shortly.
