This is a simulation of two Atmega32 microcontrollers communicating serially over USART
U1: it displays a message on LCD Through PORT C 
    it sends input of PORT B to U2
    it Receives 8-bit Data from U2 and displays it on PORT A

U2: it Receives a 8-bit Data from U1 and displays it on PORT A
    it Sends input of PORT B to U1