#include <iostream>
#include <windows.h>
#include <pthread.h>
#include "CLPThread.h"

int main() {
    // Inicializa a thread CLP
    CLPThread clpThread;

    std::cout << "Thread principal: Criando thread CLP..." << std::endl;

    if (!clpThread.start()) {
        std::cerr << "Erro ao iniciar thread CLP" << std::endl;
        return 1;
    }

    std::cout << "Thread principal: Pressione Enter para finalizar..." << std::endl;
    std::cin.get();

    std::cout << "Thread principal: Finalizando thread CLP..." << std::endl;
    clpThread.stop();

    std::cout << "Thread principal: Programa encerrado." << std::endl;
    return 0;
}