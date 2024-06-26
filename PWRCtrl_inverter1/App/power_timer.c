#include "power_timer.h"

void timer8_int_init()//10K
{
    rcu_periph_clock_enable(RCU_TIMER8);
    
    timer_parameter_struct timere_initpara; 
    
    timer_deinit(TIMER8);														// 复位定时器
	timere_initpara.prescaler = 0;                   		// 时钟预分频值   PSC_CLK= 200MHZ / 200 = 1MHZ       
	timere_initpara.alignedmode = TIMER_COUNTER_EDGE;      	// 边缘对齐                
	timere_initpara.counterdirection = TIMER_COUNTER_UP;    // 向上计数    	                    
	timere_initpara.period = 23999;      									  // 周期    T = 10000 * 1MHZ = 10ms  f = 100HZ   
	timere_initpara.clockdivision = TIMER_CKDIV_DIV1;    	  // 分频因子
	//timere_initpara.repetitioncounter = 0;                  // 重复计数器 0-255  
	timer_init(TIMER8,&timere_initpara);							// 初始化定时器
    
    nvic_irq_enable(TIMER0_BRK_TIMER8_IRQn, 0, 1);
    timer_interrupt_enable(TIMER8,TIMER_INT_UP);
    
    timer_enable(TIMER8);
}
void timer11_int_init()//周期50ms
{
    rcu_periph_clock_enable(RCU_TIMER11);
    
    timer_parameter_struct timere_initpara; 
    
    timer_deinit(TIMER11);														// 复位定时器
	timere_initpara.prescaler = 239;                   		// 时钟预分频值   PSC_CLK= 200MHZ / 200 = 1MHZ       
	timere_initpara.alignedmode = TIMER_COUNTER_EDGE;      	// 边缘对齐                
	timere_initpara.counterdirection = TIMER_COUNTER_UP;    // 向上计数    	                    
	timere_initpara.period = 4999;      									  // 周期    T = 10000 * 1MHZ = 10ms  f = 100HZ   
	timere_initpara.clockdivision = TIMER_CKDIV_DIV1;    	  // 分频因子
	//timere_initpara.repetitioncounter = 0;                  // 重复计数器 0-255  
	timer_init(TIMER11,&timere_initpara);							// 初始化定时器
    
    nvic_irq_enable(TIMER7_BRK_TIMER11_IRQn, 0, 1);
    timer_interrupt_enable(TIMER11,TIMER_INT_UP);
    
    timer_enable(TIMER11);    
}