//
// Created by Caio- on 15/11/2022.
//

#ifndef PROJETO_BANCO_H
#define PROJETO_BANCO_H

#include "Banco.h"
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#include "sys/types.h"
#include "signal.h"
#include "sched.h"
#include <iostream>


struct Banco {
     int saldo;
     int tentativas;
};
typedef Banco conta;


#endif //PROJETO_BANCO_H
