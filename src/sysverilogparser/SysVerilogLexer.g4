lexer grammar SysVerilogLexer;

@lexer:: declarations{int ipc=0; } 
@lexer::members
{
  void doLineCount()
  { 
   /* 
    if((ipc%200)==0){
    std::cout<<"parsing line::"<<ipc<<"\n";
     }
    */
    ipc++;
  }
 
}

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
Fixe_point_number : Integer DOT Integer ;

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
 
//fragment
//NameChar
//   : '\u0033'..'\u0039'
//   | '\u0042'..'\u007E'
//   ;

  // ATTRIBUTE: ( LPS Text SRP) -> channel(HIDDEN);
     

 Macro_directive :     (T_CELLDEF|T_ENDCELL|T_LINE|T_PRAGMA
                      |T_LINE| T_BEGINKEY| T_ENDKEY|T_NOUNCON|T_PRAGMA|T_ACCEL
                      |T_NOACC|T_USELIB|T_DEFNET|T_DEFDEC|T_DEFTRI|T_DELMOD
                      |T_DELMODDIS|T_DELMODUNIT|T_DELMODZERO|T_DISPORT|T_ENPORT
                      |T_NOSUPP|T_ENDPROT|T_ENDPROTED|T_EXP
                      |T_NOEXP|T_PROTECTE|T_AUTO|T_REMGATE|T_NONET|T_RENET
                      |T_SIG|T_UNSIG|T_BEGINKEY|T_ENDKEY) ('//' ~('\n' | '\r')* ('\n' | '\r' | '\r\n')? )->channel(HIDDEN);
                    //  | <T_IFDEF>| <T_IFNDEF> | <T_ENDIF> | <T_UNDEF>| <TT_ELSE> | <T_ELSIF>| <T_INCLUDEDIR>)(~["\n", "\r"])*("\n" | "\r" | "\r\n")?  >;


LP: '(' ;
RP: ')' ;
LC: '{' ;
RC: '}' ;
LB: '[' ;
RB: ']' ;
SEMI: ';' ;
COMMA: ',' ;
DOT: '.' ;
COLONCOLON: '::' ;
ATSTAR: '@' ' '? '(' ' '? '*' ' '? ')';
//LPS: '(*' ;
//SRP: '*)' ;
COLON: ':' ;
MINUS: '-';
STAR: '*';
MINUSMINS: '--';
NOT: '!';
NE: '!=';
NEQ: '!=?';
NEE: '!==';
DPI: 'DPI';
DPIC: 'DPI-C';
P: '#';
PP: '##';
PMP: '#-#';
PEP: '#=#';
//PZ: '#0';
DOLLAR: '$';
DERROR: '$error';
DFATAL: '$fatal';
DINFO: '$info';
DROOT: '$root';
DUNIT: '$unit';
DWARNING: '$warning';
PER: '%';
PE: '%=';
AND: '&';
ANDAND: '&&';
ANDANDAND: '&&&';
AE: '&=';
SS: '**';
SCCS: '*::*';
SEQ: '*=';
SGT: '*>';
DOTSTAR: '.*';
SLASH: '/';
SLASHEQ: '/=';
MCOLON: '-:';
COLONSLASH: ':/';
COLONEQ: ':=';
QUES: '?';
AT: '@';
ATAT: '@@';
QUOTE: '\'';
CARET: '^';
CARETSQUIG: '^~';
CARETEQ: '^=';
BAR: '|';
BARBAR: '||';
BAREQ: '|=';
BAREQGT: '|=>';
BARARROW: '|->';
SQUIG: '~';
SQUIGAND: '~&';
SQUIGCARET: '~^';
SQUIGBAR: '~|';
PLUS: '+';
PLUSCOLON: '+:';
PLUSPLUS: '++';
PLUSEQ: '+=';
LT: '<';
LTLT: '<<';
LTLTLT: '<<<';
LTLTLTEQ: '<<<=';
LTLTEQ: '<<=';
LTEQ: '<=';
LTMINUSGT: '<->';
EQ: '=';
MINUSEQ: '-=';
EQEQ: '==';
EQEQQUEST: '==?';
EQEQEQ: '===';
EQGT: '=>';
GT: '>';
ARROW: '->';
GE: '>=';
GTGT: '>>';
MINUSGTGT: '->>';
GTGTEQ: '>>=';
GTGTGT: '>>>' ;
GTGTGTEQ: '>>>=';
// TOKEN #KeyWord:
T_ONESTEP: '1step';
T_ACCEPT_ON: 'accept_on';
T_ALIAS: 'alias';
T_ALWAYS: 'always';
T_ALWAYS_COMB: 'always_comb';
T_ALWAYS_FF: 'always_ff';
T_ALWAYS_LATCH: 'always_latch';
T_AND: 'and';
T_ASSERT: 'assert';
T_ASSIGN: 'assign';
T_ASSUME: 'assume';
T_AUTOMATIC: 'automatic';
T_BEFORE: 'before';
T_BEGIN: 'begin';
T_BIND: 'bind';
T_BINS: 'bins';
T_BINSOF: 'binsof';
T_BIT: 'bit';
T_BREAK: 'break';
T_BUF: 'buf';
T_BUFIF0: 'bufif0';
T_BUFIF1: 'bufif1';
T_BYTE: 'byte';
T_CASE: 'case';
T_CASEX: 'casex';
T_CASEZ: 'casez';
T_CELL: 'cell';
T_CHANDLE: 'chandle';
T_CHECKER: 'checker';
T_CLASS: 'class';
T_CLOCKING: 'clocking';
T_CMOS: 'cmos';
T_CONFIG: 'config';
T_CONST: 'const';
T_CONSTRAINT: 'constraint';
T_CONTEXT: 'context';
T_CONTINUE: 'continue';
T_COVER: 'cover';
T_COVERGROUP: 'covergroup';
T_COVERPOINT: 'coverpoint';
T_CROSS: 'cross';
T_DEASSIGN: 'deassign';
T_DEFAULT: 'default';
T_DEFPARAM: 'defparam';
T_DESIGN: 'design';
T_DISABLE: 'disable';
T_DIST: 'dist';
T_DO: 'do';
T_EDGE: 'edge';
T_ELSE: 'else';
T_END: 'end';
T_ENDCASE: 'endcase';
T_ENDCHECKER: 'endchecker';
T_ENDCLASS: 'endclass';
T_ENDCLOCKING: 'endclocking';
T_ENDCONFIG: 'endconfig';
T_ENDFUNCTION: 'endfunction';
T_ENDGENERATE: 'endgenerate';
T_ENDGROUP: 'endgroup';
T_ENDPROGRAM: 'endprogram';
T_ENDINTERFACE: 'endinterface';
T_ENDMODULE: 'endmodule';
T_ENDPACKAGE: 'endpackage';
T_ENDSEQUENCE: 'endsequence';
T_ENDSPECIFY: 'endspecify';
T_ENDTASK: 'endtask';
T_ENDPROPERTY: 'endproperty';
T_ENUM: 'enum';
T_EVENT: 'event';
T_EVENTUALLY: 'eventually';
T_EXPECT: 'expect';
T_EXPORT: 'export';
T_EXTENDS: 'extends';
T_EXTERN: 'extern';
T_FINAL: 'final';
T_FIRST_MATCH: 'first_match';
T_FOR: 'for';
T_FORCE: 'force';
T_FOREACH: 'foreach';
T_FOREVER: 'forever';
T_FORK: 'fork';
T_FORKJOIN: 'forkjoin';
T_FUNCTION: 'function';
T_GENERATE: 'generate';
T_GENVAR: 'genvar';
T_GLOBAL: 'global';
T_HIGHZ0: 'highz0';
T_HIGHZ1: 'highz1';
T_IF: 'if';
T_IFF: 'iff';
T_IFNONE: 'ifnone';
T_IGNORE_BINS: 'ignore_bins';
T_ILLEGAL_BINS: 'illegal_bins';
T_IMPLEMENTS: 'implements';
T_IMPLIES: 'implies';
T_IMPORT: 'import';
T_INCDIR: '-incdir';
T_INCLUDE: 'include';
T_INITIAL: 'initial';
T_INOUT: 'inout';
T_INPUT: 'input';
T_INSIDE: 'inside';
T_INSTANCE: 'instance';
T_INTEGER: 'integer';
T_INT: 'int';
T_INTERCONNECT: 'interconnect';
T_INTERFACE: 'interface';
T_INTERSECT: 'intersect';
T_JOIN: 'join';
T_JOIN_ANY: 'join_any';
T_JOIN_NONE: 'join_none';
T_LARGE: 'large';
T_LET: 'let';
T_LIBLIST: 'liblist';
T_LIBRARY: 'library';
T_LOCAL: 'local';
T_LOCALPARAM: 'localparam';
T_LOGIC: 'logic';
T_LONGINT: 'longint';
T_MACROMODULE: 'macromodule';
T_MATCHES: 'matches';
T_MEDIUM: 'medium';
T_MODPORT: 'modport';
T_MODULE: 'module';
T_NAND: 'nand';
T_NEGEDGE: 'negedge';
T_NETTYPE: 'nettype';
T_NEW: 'new';
T_NEXTTIME: 'nexttime';
T_NMOS: 'nmos';
T_NOR: 'nor';
T_NOSHOWCANCELLED: 'noshowcancelled';
T_NOT: 'not';
T_NOTIF0: 'notif0';
T_NOTIF1: 'notif1';
T_NULL: 'null';
T_OPTION: 'option';
T_OR: 'or';
T_OUTPUT: 'output';
T_PACKAGE: 'package';
T_PACKED: 'packed';
T_PARAMETER: 'parameter';
T_PATHPULSE: 'PATHPULSE$';
T_PMOS: 'pmos';
T_POSEDGE: 'posedge';
T_PRIORITY: 'priority';
T_PROGRAM: 'program';
T_PROPERTY: 'property';
T_PROTECTED: 'protected';
T_PULL0: 'pull0';
T_PULL1: 'pull1';
T_PULLDOWN: 'pulldown';
T_PULLUP: 'pullup';
T_PULSESTYLE_ONDETECT: 'pulsestyle_ondetect';
T_PULSESTYLE_ONEVENT: 'pulsestyle_onevent';
T_PURE: 'pure';
T_RAND: 'rand';
T_RANDC: 'randc';
T_RANDCASE: 'randcase';
T_RANDOMIZE: 'randomize';
T_RANDSEQUENCE: 'randsequence';
T_RCMOS: 'rcmos';
T_REAL: 'real';
T_REALTIME: 'realtime';
T_REF: 'ref';
T_REG: 'reg';
T_REJECT_ON: 'reject_on';
T_RELEASE: 'release';
T_REPEAT: 'repeat';
T_RESTRICT: 'restrict';
T_RETURN: 'return';
T_RNMOS: 'rnmos';
T_RPMOS: 'rpmos';
T_RTRAN: 'rtran';
T_RTRANIF0: 'rtranif0';
T_RTRANIF1: 'rtranif1';
T_S_ALWAYS: 's_always';
T_S_EVENTUALLY: 's_eventually';
T_S_NEXTTIME: 's_nexttime';
T_S_UNTIL: 's_until';
T_S_UNTIL_WITH: 's_until_with';
//T_SAMPLE: 'sample';
T_SCALARED: 'scalared';
T_SEQUENCE: 'sequence';
T_SHORTINT: 'shortint';
T_SHORTREAL: 'shortreal';
T_SHOWCANCELLED: 'showcancelled';
T_SIGNED: 'signed';
T_SMALL: 'small';
T_SOFT: 'soft';
T_SOLVE: 'solve';
T_SPECIFY: 'specify';
T_SPECPARAM: 'specparam';
T_STATIC: 'static';
T_STRING: 'string';
T_STRONG: 'strong';
T_STRONG0: 'strong0';
T_STRONG1: 'strong1';
T_STRUCT: 'struct';
T_SUPER: 'super';
T_SUPPLY0: 'supply0';
T_SUPPLY1: 'supply1';
T_SYNC_ACCEPT_ON: 'sync_accept_on';
T_SYNC_REJECT_ON: 'sync_reject_on';
T_TAGGED: 'tagged';
T_TASK: 'task';
T_THIS: 'this';
T_THROUGHOUT: 'throughout';
T_TIME: 'time';
T_TIMEPRECISION: 'timeprecision';
T_TIMEUNIT: 'timeunit';
T_TRAN: 'tran';
T_TRANIF0: 'tranif0';
T_TRANIF1: 'tranif1';
T_TRI: 'tri';
T_TRI0: 'tri0';
T_TRI1: 'tri1';
T_TRIAND: 'triand';
T_TRIOR: 'trior';
T_TRIREG: 'trireg';
T_TYPE: 'type';
T_TYPE_OPTION: 'type_option';
T_TYPEDEF: 'typedef';
T_UNION: 'union';
T_UNIQUE: 'unique';
T_UNIQUE0: 'unique0';
T_UNSIGNED: 'unsigned';
T_UNTIL: 'until';
T_UNTIL_WITH: 'until_with';
T_UNTYPED: 'untyped';
T_USE: 'use';
T_UWIRE: 'uwire';
T_VAR: 'var';
T_VECTORED: 'vectored';
T_VIRTUAL: 'virtual';
T_VOID: 'void';
T_WAIT: 'wait';
T_WAIT_ORDER: 'wait_order';
T_WAND: 'wand';
T_WEAK: 'weak';
T_WEAK0: 'weak0';
T_WEAK1: 'weak1';
T_WHILE: 'while';
T_WILDCARD: 'wildcard';
T_WIRE: 'wire';
T_WITH: 'with';
T_WITHIN: 'within';
T_WOR: 'wor';
T_XNOR: 'xnor' ;
T_XOR: 'xor'  ;
T_SETUP: '$setup'  ;
T_HOLD: '$hold' ;
T_SETUPHOLD: '$setuphold' ;
T_RECOVERY: '$recovery' ;
T_RECREM: '$recrem' ;
T_SKEW: '$skew' ;
T_TIMESKEW: '$timeskew' ;
T_FULLSKEW :'$fullskew' ;
T_PERIOD: '$period' ;
T_WIDTH: '$width' ;
T_NOCHANGE: '$nochange' ;
T_REMOVAL: '$removal' ;
//macros---------------------------------
T_TIMESCALE: '`timescale' ;
T_CELLDEF: '`celldefine' ;
T_ENDCELL: '`endcelldefine' ;
T_LINE: '`line' ;
T_BEGINKEY: '`begin_keywords' ;
T_ENDKEY: '`end_keywords' ;
T_UNCONN: '`unconnected_drive' ;
T_NOUNCON: '`nounconnected_drive' ;
T_PRAGMA: '`pragma' ;
T_ACCEL: '`accelerate' ;
T_NOACC: '`noaccelerate' ;
T_USELIB: '`uselib' ;
T_DEFNET: '`default_nettype' ;
T_DEFDEC: '`default_decay_time' ;
T_DEFTRI: '`default_trireg_strength' ;
T_DELMOD: '`delay_mode_path' ;
T_DELMODDIS: '`delay_mode_distributed' ;
T_DELMODUNIT: '`delay_mode_unit' ;
T_DELMODZERO: '`delay_mode_zero' ;
T_PROT: '`protect' ;
T_DISPORT: '`disable_portfaults' ;
T_ENPORT: '`enable_portfaults' ;
T_NOSUPP: '`nosuppress_faults' ;
T_ENDPROT: '`endprotect' ;
T_ENDPROTED: '`endprotected' ;
T_EXP: '`expand_vectornets' ;
T_NOEXP: '`noexpand_vectornets' ;
T_PROTECTE: '`protected' ;
T_AUTO: '`autoexpand_vectornets' ;
T_REMGATE: '`remove_gatename' ;
T_NONET: '`noremove_netnames' ;
T_RENET: '`remove_netname' ;
T_SIG: '`signed' ;
T_UNSIG: '`unsigned' ;
T_IFDEF: '`ifdef' ;
T_IFNDEF: '`ifndef' ;
T_ENDIF: '`endif' ;
T_UNDEF: '`undef' ;
TT_ELSE: '`else' ;
T_ELSIF: '`elsif' ;
T_INCLUDEDIR: '`include' ;
T_POUND: '#' ' '* [0-9] [0-9_.]*;

        Decimal_number: ( Non_zero_unsigned_number ' '* )? Decimal_base ' '* (Integer | X_digit | Z_digit | '_')*;
        Octal_number : ( Non_zero_unsigned_number ' '* )? Octal_base ' '* Octal_value;
        Binary_number : ( Non_zero_unsigned_number ' '* )? Binary_base ' '*  Binary_value;
        Hex_number : ( Non_zero_unsigned_number ' '* )? Hex_base ' '* Hex_value ;
        Realnumber :  Integer ('.' Integer)? ('e'|'E')('+'|'-')? Integer
                  | Fixe_point_number
                  ;

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
        
/**
#Attribute_instance#: "(*" Attr_spec ("," Attr_spec)* "*)" {return CURRENT_NODE;}
;

Attr_spec#: SS ( "=" Constant_expression )?
;
*/

        Integer :   Digit ('_' | Digit)* ;         // match integers
        Time_literal :( Integer Time_unit | (Fixe_point_number Time_unit) ) ;
        NEWLINE:'\n'{doLineCount();} -> channel(2);   // return newlines to parser (is end-statement signal)
   	    WS  :   [ \t]+ -> channel(2) ; // toss out whitespace
        Attribute_instance: (LP STAR Text?  STAR RP) ->channel(2); 
        Block_comment : ('/*' Text '*/' ) -> channel(2);
        Out_line_comment: ('<<!' ~('\n' | '\r')* ('\n' | '\r' | '\r\n')? )->channel(2);
        One_line_comment: ('//' ~('\n' | '\r')* ('\n' | '\r' | '\r\n')? )->channel(2);
        Simple_identifier : (Letter| '_'|'`') (Letter_or_digit | '_'| '$')*;      
        System_identifier :  (Letter_or_digit|'_'|'$')+ ;
        Escape_identifier : ('\\')([\u0021-\u005b]|[\u005d-\u007e])+; 
        Define: (('`define') ((~'\n')* '\n' ))->channel(2);
        Macro:   (('`define') ((~'\n'| '\r'))+ ('\\')('\n') (~('\n'|'\r')* ('\\')('\n'))* (~('\n'|'\r'))* )->channel(2);
       
	       // MacroId:('||>' Text '<||')->channel(2);
        MacroId:('||>' Text '<||')->channel(2);