#include <iostream>
#include <string.h>
#include "container.h"
#include "lambda.h"
#include "literal.h"
#include "type_inference.h"

using namespace std;

int main(int argc, char const *argv[])
{
  container();
  lambda();
  literal();
  type_inference();

  return 0;
}
