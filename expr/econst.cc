#include "econst.h" 

EConstExpression::EConstExpression()
  : ConstExpression(2.7182818) {}
  
std::string EConstExpression::toString()
{
  return "e";
}
