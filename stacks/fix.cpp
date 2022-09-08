// infix, postfix and prefix
// infix : x + y
// postfix xy+
// prefix + xy
// advatngaes
// do not need brackets, precedence and associativity rules
// can be eva;uated by a prohgram that traverses the given exp only once
// if two or more operators have same precendence, we gotta refer associativity
// 10 + 20 * 2 = 10 + 40 = 50 (precedence)
// 10 + 2 - 3 = 12 - 3 = 9 (associativity L to R) 
// 2 ^ 1 ^ 2 = 2 ^ 1 = 2 (associativity R to L for power opeartor)

// infix can have brackets to define priority
// but prefix and postfix do not brackets, associativity and precedence rules

// infix to postfix
// first operand, the second operand, then operator (rule)
// x + y * z
// => (x + (y * z))
// => (x + (yz*))
// => xyz*+

// (x + y) * z
// => ((xy+) * z)
// => (xy+z*)

// infix to prefix (operator, then first operand, then second operand)

// infix to postfoix program
// naive - do brackets around them and calculate it


// evaluate postfix
// traverse through expression, if operator comes, take prev two operands and evaluate them