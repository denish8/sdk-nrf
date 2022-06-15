#include <zephyr.h>
#include <sys/printk.h>

#include <dk_buttons_and_leds.h>

static struct k_work_delayable continuous_printing;

static void message_print(struct k_work *work)
{
	printk("Hello World! %s\n", CONFIG_BOARD);
        k_work_reschedule(&continuous_printing, K_MSEC(1000));
}


void main(void)
{
        k_work_init_delayable(&continuous_printing, message_print);
        k_work_submit(&continuous_printing);

        
}
