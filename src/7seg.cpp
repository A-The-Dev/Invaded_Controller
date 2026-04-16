
#include "7seg.h"


void init_Timer5(void)
{
    pinMode(13, OUTPUT); // Set pin 13 as an output
    cli(); // Stop interrupts while setting up the timer

    // Set up Timer5 (16-bit timer)
    TCCR5A = 0; // Set entire TCCR5A register to 0
    TCCR5B = 0; // Set entire TCCR5B register to 0
    TCNT5 = 0;  // Initialize counter value to 0

    // Set compare match register for 1Hz frequency:
    // Formula: OCRnA = [ (CPU_freq) / (prescaler * desired_frequency) ] - 1
    // For 1kHz with 1024 prescaler: OCR5A = [16,000,000 / (1024 * 1000)] - 1 = 16
    OCR5A = 16;

    // Turn on CTC mode (Clear Timer on Compare Match)
    TCCR5B |= (1 << WGM42);

    // Set CS42 and CS40 bits for 1024 prescaler
    TCCR5B |= (1 << CS42) | (1 << CS40);

    // Enable timer compare interrupt for Timer5's Compare Match A
    TIMSK5 |= (1 << OCIE5A);

    sei(); // Allow interrupts to run
}

void init_7seg(void)
{
    // PIN select digit
    pinMode(Pin_D1, OUTPUT);
    pinMode(Pin_D2, OUTPUT);
    pinMode(Pin_D3, OUTPUT);
    pinMode(Pin_D4, OUTPUT);

    pinMode(Pin_A, OUTPUT);
    pinMode(Pin_B, OUTPUT);
    pinMode(Pin_C, OUTPUT);
    pinMode(Pin_D, OUTPUT);
    pinMode(Pin_E, OUTPUT);
    pinMode(Pin_F, OUTPUT);
    pinMode(Pin_G, OUTPUT);

}

void AfficherUnDigit(int digitSel, int nombre)
{
    switch(digitSel)
    {
        case 1:
            digitalWrite(Pin_D1, 0);
            digitalWrite(Pin_D2, 1);
            digitalWrite(Pin_D3, 1);
            digitalWrite(Pin_D4, 1);
        break;

        case 2:
            digitalWrite(Pin_D1, 1);
            digitalWrite(Pin_D2, 0);
            digitalWrite(Pin_D3, 1);
            digitalWrite(Pin_D4, 1);
        break;

        case 3:
            digitalWrite(Pin_D1, 1);
            digitalWrite(Pin_D2, 1);
            digitalWrite(Pin_D3, 0);
            digitalWrite(Pin_D4, 1);
        break;

        case 4:
            digitalWrite(Pin_D1, 1);
            digitalWrite(Pin_D2, 1);
            digitalWrite(Pin_D3, 1);
            digitalWrite(Pin_D4, 0);
        break;
    }
    

    switch(nombre)
    {

        case 0:
            digitalWrite(Pin_A, 1);
            digitalWrite(Pin_B, 1);
            digitalWrite(Pin_C, 1);
            digitalWrite(Pin_D, 1);
            digitalWrite(Pin_E, 1);
            digitalWrite(Pin_F, 1);
            digitalWrite(Pin_G, 0);
        break;

        case 1:
            digitalWrite(Pin_A, 0);
            digitalWrite(Pin_B, 1);
            digitalWrite(Pin_C, 1);
            digitalWrite(Pin_D, 0);
            digitalWrite(Pin_E, 0);
            digitalWrite(Pin_F, 0);
            digitalWrite(Pin_G, 0);
        break;

        case 2:
            digitalWrite(Pin_A, 1);
            digitalWrite(Pin_B, 1);
            digitalWrite(Pin_C, 0);
            digitalWrite(Pin_D, 1);
            digitalWrite(Pin_E, 1);
            digitalWrite(Pin_F, 0);
            digitalWrite(Pin_G, 1);
        break;

        case 3:
            digitalWrite(Pin_A, 1);
            digitalWrite(Pin_B, 1);
            digitalWrite(Pin_C, 1);
            digitalWrite(Pin_D, 1);
            digitalWrite(Pin_E, 0);
            digitalWrite(Pin_F, 0);
            digitalWrite(Pin_G, 1);
        break;

        case 4:
            digitalWrite(Pin_A, 0);
            digitalWrite(Pin_B, 1);
            digitalWrite(Pin_C, 1);
            digitalWrite(Pin_D, 0);
            digitalWrite(Pin_E, 0);
            digitalWrite(Pin_F, 1);
            digitalWrite(Pin_G, 1);
        break;

        case 5:
            digitalWrite(Pin_A, 1);
            digitalWrite(Pin_B, 0);
            digitalWrite(Pin_C, 1);
            digitalWrite(Pin_D, 1);
            digitalWrite(Pin_E, 0);
            digitalWrite(Pin_F, 1);
            digitalWrite(Pin_G, 1);
        break;

        case 6:
            digitalWrite(Pin_A, 1);
            digitalWrite(Pin_B, 0);
            digitalWrite(Pin_C, 1);
            digitalWrite(Pin_D, 1);
            digitalWrite(Pin_E, 1);
            digitalWrite(Pin_F, 1);
            digitalWrite(Pin_G, 1);
        break;

        case 7:
            digitalWrite(Pin_A, 1);
            digitalWrite(Pin_B, 1);
            digitalWrite(Pin_C, 1);
            digitalWrite(Pin_D, 0);
            digitalWrite(Pin_E, 0);
            digitalWrite(Pin_F, 0);
            digitalWrite(Pin_G, 0);
        break;

        case 8:
            digitalWrite(Pin_A, 1);
            digitalWrite(Pin_B, 1);
            digitalWrite(Pin_C, 1);
            digitalWrite(Pin_D, 1);
            digitalWrite(Pin_E, 1);
            digitalWrite(Pin_F, 1);
            digitalWrite(Pin_G, 1);
        break;

        case 9:
            digitalWrite(Pin_A, 1);
            digitalWrite(Pin_B, 1);
            digitalWrite(Pin_C, 1);
            digitalWrite(Pin_D, 1);
            digitalWrite(Pin_E, 0);
            digitalWrite(Pin_F, 1);
            digitalWrite(Pin_G, 1);
        break;

        case -1:
            digitalWrite(Pin_A, 0);
            digitalWrite(Pin_B, 0);
            digitalWrite(Pin_C, 0);
            digitalWrite(Pin_D, 0);
            digitalWrite(Pin_E, 0);
            digitalWrite(Pin_F, 0);
            digitalWrite(Pin_G, 0);
        break;
    }
}

void Affichage7Seg(int digitSel, int valeur)
{
    int digit1 = 0, digit2 = 0, digit3 = 0, digit4 = 0;

    digit1 = valeur/1000;    
    digit2 = (valeur%1000)/100;
    digit3 = (valeur%100)/10;
    digit4 = valeur%10;

    if(digit1 == 0)
    {
        digit1 = -1;

        if(digit2 == 0)
        {
            digit2 = -1;

            if(digit3 == 0)
            {
                digit3 = -1;
            }
        }
    }

    if(digitSel == 1)
    {
        AfficherUnDigit(1, digit1);
    }
    else if(digitSel == 2)
    {
        AfficherUnDigit(2, digit2);
    }
    else if(digitSel == 3)
    {
        AfficherUnDigit(3, digit3);
    }
    else if(digitSel == 4)
    {
        AfficherUnDigit(4, digit4);
    }

}





