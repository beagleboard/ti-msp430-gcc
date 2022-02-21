/* { dg-do link } */
/* To prevent garbage collection, pass -g.  */
/* { dg-options "-g" } */
/* { dg-message "does not recognize interrupt vector section name __interrupt_vector_foo"  "" { target { *-*-* } } 0 } */
/* { dg-message "does not recognize interrupt vector section name __interrupt_vector_wdt"  "" { target { *-*-* } } 0 } */
/* { dg-message "no memory region specified for loadable section" "" { target { ! msp430_large_memory_model } } 0 } */

void __attribute__((naked,interrupt("watchdog"))) watchdog_v (void)
{
}

void __attribute__((naked,interrupt("wdt"))) wdt_v (void)
{
}

void __attribute__((naked,interrupt("foo"))) foo_v (void)
{
}

int main (void)
{
  while (1);
  return 0;
}
