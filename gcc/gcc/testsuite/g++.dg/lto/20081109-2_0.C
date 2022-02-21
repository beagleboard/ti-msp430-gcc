/* { dg-lto-do assemble }  */
// { dg-skip-if "" { msp430-*-* } { "*" } { "-fexceptions" } }
extern void func(int);

struct Foo
{
 void bar() {
   static int local;
   func(local);
 }
 void baz();
};

void Foo::baz() {
 bar();
}
