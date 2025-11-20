lexer grammar MacroLexer;

fragment
Digit : '0'..'9' ;

fragment
Lower_case_letter : 'a'..'z' ;

fragment
Upper_case_letter : 'A'..'Z' ;

fragment
Letter: (Lower_case_letter |Upper_case_letter ) ;

fragment
Letter_or_digit: ( Letter | Digit ) ;

fragment
Z_digit: ('z'|'Z'|'?') ;

fragment
X_digit:('x'|'X') ;

fragment
Hex_digit: X_digit | Z_digit | ('0'..'9' | 'a'..'f' | 'A'..'F') ;//(X_digit | Z_digit | Digit | ([a-zA-Z0-9]) );

fragment
Binary_digit: (X_digit | Z_digit | Digit | ('0' | '1') );

fragment
Octal_digit: (X_digit | Z_digit | Digit | ([0-7]) );

fragment
Non_zero_unsigned_number : '1'..'9' ( '_' | '0'..'9' )* ;

fragment
Fixe_point_number : (Integer '.' Integer) ;

fragment
Non_zero_decimal_digit:('1'..'9' ) ;

fragment
Hex_base : (('\'')('s'|'S')? ('h'|'H') );
    
fragment    
Binary_base : (('\'')('s'|'S')? ('b'|'B') );
    
fragment
Octal_base : (('\'')('s'|'S')? ('o'|'O') );
    
fragment
Decimal_base :  (('\'')('s'|'S')? ('d'|'D') );   
  
fragment
Hex_value: (Hex_digit ('_' | Hex_digit)*) ;
    
fragment  
Octal_value : (Octal_digit ('_' | Octal_digit)*) ;  
    
fragment 
Binary_value: (Binary_digit ('_' | Binary_digit)*) ;   

fragment
Time_unit:(('m'|'n'|'p'|'f')? ('s')) ;
   
fragment 
Text : .*? ;
 

LP: '(' ;
RP: ')' ;
LC: '{' ;
RC: '}' ;
LB: '[' ;
RB: ']' ;
SEMI: ';' ;
COMMA: ',' ;
DOT: '.' ;
COLON: ':' ;
MINUS: '-';
STAR: '*';
NOT: '!';
P: '#';
DOLLAR: '$';
DERROR: '$error';
DFATAL: '$fatal';
DINFO: '$info';
DROOT: '$root';
DUNIT: '$unit';
DWARNING: '$warning';
PER: '%';
AND: '&';
SLASH: '/';
QUES: '?';
AT: '@';
QUOTE: '\'';
CARET: '^';
BAR: '|';
SQUIG: '~';
PLUS: '+';
PLUSCOLON: '+:';
LT: '<';
EQ: '=';
GT: '>';
T_INCLUDE: '`include' ;
T_DEFINE: '`define' ;
SSLASH: '\\';

        Decimal_number: ( Non_zero_unsigned_number' '* )? Decimal_base ' '* (Integer | X_digit | Z_digit | '_')*;
        Octal_number : ( Non_zero_unsigned_number' '* )? Octal_base ' '* Octal_value;
        Binary_number : ( Non_zero_unsigned_number' '* )? Binary_base ' '*  Binary_value;
        Hex_number : ( Non_zero_unsigned_number' '* )? Hex_base ' '* Hex_value ;
        Real_number: Fixe_point_number ;
        UNLIT : '\'' ('0'|'1'|'x'|'X'|'z'|'Z');
        //String_literal : ('"'   ~('\\' | '"'| '\r' | '\n')* '"');
        String_literal
        : '"'                          // a opening quote
        (                            // start group
         '\\' ~('\r')        // an escaped char other than a line break char
        |                          // OR
         ~('\\' | '"'| '\r' | '\n') // any char other than '"', '\' and line breaks
        )*                           // end group and repeat zero or more times
        '"'                          // the closing quote
        ;
 
 // Number :     (Decimal_number | Octal_number | Binary_number | Real_number| Hex_number | UNLIT);
        
        Integer :   Digit+ ;         // match integers
        Time_literal :( Integer Time_unit | (Fixe_point_number Time_unit) ) ;
        NEWLINE:'\n' ;    // return newlines to parser (is end-statement signal)
   	 WS  :   [ \t]+  ; // toss out whitespace
        Block_comment : ('/*' Text '*/' ) ;
        Out_line_comment: ('@@' ~('\n' | '\r')* ('\n' | '\r' | '\r\n')? );
        One_line_comment: ('//' ~('\n' | '\r')* ('\n' | '\r' | '\r\n')? );
        Simple_identifier : (Letter| '_') (Letter_or_digit |'`' | '_'| '$')*;
        MacroId:('`') (Letter_or_digit |'`' | '_'| '$')*;
        System_identifier : ('$' (Letter_or_digit|'_'|'$')+ );
        Escape_identifier : ('\\')([\u0021-\u005b]|[\u005d-\u007e])+; 
      
	 
