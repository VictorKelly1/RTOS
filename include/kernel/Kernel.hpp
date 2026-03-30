#ifndef KERNEL_HPP
#define KERNEL_HPP

#include <stdint.h>
#include "Process.hpp"

class Kernel final 
{
public:                                                                     //public interface and singleton aplied
    static Kernel& getInstance();

    Kernel(const Kernel&) = delete;
    Kernel& operator=(const Kernel&) = delete;

    //Func definitions 
    void createTask(void (*taskFunction)(), uint8_t priority);
    void scheduler();
    void switchContext(Process* nextProcess);
    void start(); 

    Process* getCurrentProcess() const { return m_currentProcess; } 

private: 
    
    Kernel();

    ~Kernel() = default;

private:
    //list of processes 
    static constexpr uint8_t MAX_PROCESSES { 10 }; 
    Process* m_PCB[MAX_PROCESSES];

    //Ptr to current process en CPU
    Process* m_currentProcess {nullptr};
};

#endif 
