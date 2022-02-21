// { dg-lto-do run }
const char *func(long val) {
 switch (val) {
   case 2147483647: return "foo";
   default: return "";
 }
}

int main() {
 return 0;
}
