/* { dg-do link } */
/* { dg-message "does not recognize interrupt vector section name __interrupt_vector_foo"  "" { target { *-*-* } } 0 } */
/* { dg-message "does not recognize interrupt vector section name __interrupt_vector_wdt"  "" { target { *-*-* } } 0 } */

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
