#include "kernel/Kernel.hpp" 

//Function definitions
void Kernel::createTask(void (*taskFunction)(), uint8_t priority){
    if(m_processCount >= MAX_PROCESSES) { return; }

    //Create and add a process to list 
    Process* newProcess = new Process(taskFunction, priority);

    m_PCB[m_processCount] = newProcess;

    ++m_processCount;
}

Kernel& Kernel::getInstance(){
    static Kernel instance{};
    return instance;
}

//Constructor definitions
Kernel::Kernel(){
    m_currentProcess = nullptr;
    m_processCount = 0;
    
    for (uint8_t index {}; index < MAX_PROCESSES; ++index){
        m_PCB[index] = nullptr;
    }
}
