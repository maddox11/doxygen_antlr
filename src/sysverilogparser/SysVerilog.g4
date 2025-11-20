
 
grammar SysVerilog;
options { tokenVocab = SysVerilogLexer; }


@parser::postinclude{
#include "entry.h"
}

@lexer:: declarations{int ipc=0; } 
@parser::members{	

  int line=0;
  
  void doLineCount1(antlr4::ParserRuleContext* ctx)
  {
     antlr4::Token *tok = ctx->getStart();
     line= tok->getLine();
     if((line%10)==0){
          std::cout<<"line:"<<line<<" "<<tok->getText()<<"\n";
        }
  }
}

include_path:T_INCLUDEDIR String_literal 
                    ;

library_description: T_LIBRARY ss String_literal (COMMA String_literal)* (T_INCDIR String_literal (COMMA String_literal)*)? SEMI
                     | T_INCLUDEDIR String_literal 
                     | SEMI
                   ; 

source_code:timeunits_declaration? description* EOF 
           
            ;
description:  
             module_declaration
         // | udp_declaration
            | interface_declaration
            | program_declaration
            | package_declaration
            | bind_directive
            | package_item
            | config_declaration
            | library_description
            ;


module_nonansi_header:  module_keyword lifetime? ss package_import_declaration * parameter_port_list?   ( list_of_ports | list_of_port_declarations? ) SEMI
                      ;


//module_ansi_header:  module_keyword lifetime? ss package_import_declaration * parameter_port_list?    list_of_port_declarations?  SEMI
 //                     ;

module_declaration:  module_nonansi_header timeunits_declaration? module_item* T_ENDMODULE ( COLON ss )?
 //                   |module_ansi_header timeunits_declaration?  non_port_module_item* T_ENDMODULE ( COLON ss )?
                    | module_keyword lifetime? ss LP DOTSTAR RP SEMI timeunits_declaration? module_item* T_ENDMODULE ( COLON ss )?
                    |  T_EXTERN module_nonansi_header
//                    | T_EXTERN module_ansi_header
                    ;

module_keyword: T_MODULE
               | T_MACROMODULE
                ;

interface_declaration: interface_class_declaration
                      | interface_nonansi_header timeunits_declaration? interface_item* T_ENDINTERFACE ( COLON ss )?
                      | T_INTERFACE SS LP DOTSTAR RP SEMI (timeunits_declaration )? interface_item* T_ENDINTERFACE ( COLON ss )?
                      | T_EXTERN interface_nonansi_header
                      ;

interface_nonansi_header: T_INTERFACE lifetime? ss package_import_declaration* parameter_port_list? ( list_of_ports | list_of_port_declarations?  ) SEMI
                         ;
//Interface_ansi_header#: ( Attribute_instance )* "interface" [ Lifetime ] SS ( Package_import_declaration )* [ Parameter_port_list ]  ";"

program_declaration:   program_nonansi_header timeunits_declaration? program_item* T_ENDPROGRAM (COLON ss )?
                     | T_PROGRAM ss LP DOTSTAR RP SEMI timeunits_declaration? program_item* T_ENDPROGRAM ( COLON ss )?
                     | T_EXTERN program_nonansi_header
                     ;

program_nonansi_header:  T_PROGRAM lifetime? ss package_import_declaration* parameter_port_list? ( list_of_ports  | (list_of_port_declarations )?) SEMI
                         ;
//Program_ansi_header#: ( Attribute_instance )* "program" [ Lifetime ] SS ( Package_import_declaration )*  [ Parameter_port_list ] [ List_of_port_declarations ] ";"

checker_declaration:T_CHECKER ss ( LP checker_port_list? RP )? SEMI (  checker_or_generate_item )* T_ENDCHECKER ( COLON ss )?
                   ;
class_declaration: T_VIRTUAL? T_CLASS lifetime? ss parameter_port_list? ( T_EXTENDS class_type ( LP list_of_arguments RP )? )? ( T_IMPLEMENTS interface_class_type ( COMMA interface_class_type )* )? SEMI class_item* T_ENDCLASS ( COLON ss )?
                   ;
interface_class_type:psid ( parameter_value_assignment )?
                      ;

interface_class_declaration: T_INTERFACE T_CLASS ss parameter_port_list? ( T_EXTENDS interface_class_type ( COMMA interface_class_type )* )? SEMI ( interface_class_item )* T_ENDCLASS (COLON ss )?
                             ;

interface_class_item: type_declaration
                     | interface_class_method
                     | local_parameter_declaration  SEMI
                     | parameter_declaration SEMI
                     | SEMI
                     ;
interface_class_method:T_PURE T_VIRTUAL method_prototype SEMI
                       ;
package_declaration:  T_PACKAGE lifetime? ss SEMI timeunits_declaration? package_item* T_ENDPACKAGE ( COLON ss )?
                     ;
timeunits_declaration: T_TIMEUNIT time_literal SEMI T_TIMEPRECISION time_literal SEMI
                       | T_TIMEPRECISION time_literal SEMI T_TIMEUNIT time_literal SEMI
                       | T_TIMEPRECISION time_literal SEMI
                       | T_TIMEUNIT time_literal ( SLASH time_literal )? SEMI
    ;


// ----Module parameters and ports

parameter_port_list:  P LP parameter_port_declaration ( COMMA parameter_port_declaration )* RP
                      | P LP list_of_param_assignments ( parameter_port_declaration)* RP
                      | P LP RP 
                     ;

parameter_port_declaration: local_parameter_declaration 
                           | parameter_declaration 
                           | T_TYPE list_of_type_assignments 
                           | data_type list_of_param_assignments 
    ;

parameter_declaration: T_PARAMETER T_TYPE list_of_type_assignments 
                       | T_PARAMETER data_type_or_implicit list_of_param_assignments? 
                       ;

list_of_ports: LP port (COMMA port )* RP
              ;
list_of_port_declarations: LP (ansi_port_declaration (COMMA  ansi_port_declaration )* ) RP 
               ;


param_assignment:     ss? unpacked_dimension*  EQ constant_param_expression
                     | ss? unpacked_dimension+
                     | ss
                    ;

list_of_param_assignments:param_assignment  (COMMA param_assignment )*
                    ;




                 //         || !checkid3(TokenType.T_LOCALPARAM)
port_declaration:  inout_declaration
                 |  input_declaration
                 |   output_declaration
                 |   ref_declaration
                 |  interface_port_declaration
                 ;

port:  DOT ss LP port_expression? RP
       | port_expression?
       ;

port_expression: port_reference
                | LC port_reference ( COMMA port_reference )* RC
                 ;
port_reference: ss constant_select
               ;

port_direction:T_INPUT
               | T_OUTPUT
               | T_INOUT
               | T_REF
                ;

net_port_header: port_direction  net_port_type
                 | net_port_type
                ;
variable_port_header: port_direction? variable_port_type
                     ;

interface_port_header: T_INTERFACE ( DOT ss )?
                      | ss DOT  ss
                      ;

ansi_port_declaration: ( interface_port_header | net_port_header)? (ss)? ( unpacked_dimension )* ( EQ constant_expression )? 
                        |  ( variable_port_header ) ss? (variable_dimension )* ( EQ constant_expression )? 
                        | port_direction? DOT ss LP expression? RP 
                        ;
// Module items


elaboration_system_task: DFATAL ( LP finish_number ( COMMA list_of_arguments)? RP )? SEMI
    | DERROR ( LP ( list_of_arguments ) RP )? SEMI
    | DWARNING ( LP ( list_of_arguments ) RP )? SEMI
    | DINFO ( LP ( list_of_arguments ) RP )? SEMI
    ;

finish_number:number
              | String_literal
              ;

module_common_item:  module_or_generate_item_declaration
                  |  interface_instantiation
                   |  program_instantiation
                   | assertion_item
                   | bind_directive
                   | continuous_assign
                   | net_alias
                   | initial_construct
                   | final_construct
                   | always_construct
                   | loop_generate_construct
                   | conditional_generate_construct
                   | elaboration_system_task
                   | include_path
                   ;

module_item: port_declaration SEMI
            | non_port_module_item
            ;

module_or_generate_item:   parameter_override 
                        |   gate_instantiation 
                      //  |   udp_instantiation 
                        | module_instantiation  
                        |   module_common_item 
                        ;
module_or_generate_item_declaration: package_or_generate_item_declaration
                                     | genvar_declaration
                                     | clocking_declaration
                                     | T_DEFAULT T_CLOCKING ss SEMI
                                     | T_DEFAULT T_DISABLE T_IFF expression_or_dist SEMI
                                     ;

non_port_module_item: generate_region
                     | module_or_generate_item
                     | specify_block
                     | specparam_declaration
                     | program_declaration
                     | module_declaration
                     | interface_declaration
                     | timeunits_declaration
                     ;
parameter_override: T_DEFPARAM list_of_defparam_assignments SEMI
                  ;

bind_directive:   T_BIND ss ( COLON bind_target_instance_list )? bind_instantiation  
             //  | "bind" Bind_target_instance Bind_instantiation  
               ;

bind_target_instance: hierid constant_bit_select
                     ;

bind_target_instance_list:bind_target_instance ( COMMA bind_target_instance )*
                          ;
bind_instantiation:  checker_instantiation //["(" ".*" ")" ]
                    // | Program_instantiation
                     | module_instantiation
                 //  | Interface_instantiation

                   ;
// --Configuration source text

config_declaration: T_CONFIG ss SEMI ( local_parameter_declaration SEMI )* design_statement ( config_rule_statement )* T_ENDCONFIG (COLON ss )?
                   ;
design_statement: T_DESIGN hierid SEMI
                        ;

config_rule_statement:default_clause liblist_clause SEMI
                     |  inst_clause use_clause SEMI
                      |  inst_clause liblist_clause SEMI
                       | cell_clause liblist_clause SEMI
                      | cell_clause use_clause SEMI
                       ;

default_clause: T_DEFAULT
               ;
inst_clause: T_INSTANCE inst_name
             ;
inst_name: ss ( DOT ss )*
          ;
cell_clause: T_CELL (  ss DOT )? ss
            ;
liblist_clause: T_LIBLIST ( ss )*
                ;
use_clause:   T_USE  parameter_value_assignment
            | T_USE named_parameter_assignment (COMMA named_parameter_assignment )* (COLON T_CONFIG)?
            | T_USE ( ss DOT )? ss named_parameter_assignment ( COMMA named_parameter_assignment )* (COLON T_CONFIG)?
            | T_USE ( ss DOT )? ss (COLON T_CONFIG)?
            ;

// Interface items Ordered_parameter_assignment

interface_or_generate_item:
    module_common_item
    |  modport_declaration
    |  extern_tf_declaration
    ;

extern_tf_declaration: T_EXTERN method_prototype SEMI
                       | T_EXTERN T_FORKJOIN task_prototype SEMI
                       ;
interface_item: port_declaration SEMI
               | non_port_interface_item
               ;

non_port_interface_item: generate_region
                        | interface_or_generate_item
                        |  program_declaration
                        | interface_declaration
                        | timeunits_declaration
                        ;


//---Program items

program_item: non_port_program_item
               | port_declaration SEMI
               ;


non_port_program_item:   continuous_assign 
                       |  initial_construct 
                       |   final_construct 
                       |   module_or_generate_item_declaration 
                       |  let_declaration 
                       |  concurrent_assertion_item 
                       | timeunits_declaration 
                       | program_generate_item 
                       ;

program_generate_item: loop_generate_construct
                         | conditional_generate_construct
                         | generate_region
                         | elaboration_system_task
                         ;
//----- Checker

checker_port_list: checker_port_item (COMMA checker_port_item )*
                  ;
checker_port_item:  checker_port_direction? property_formal_type (ss)? variable_dimension* ( EQ property_actual_arg )?
                  ;

checker_port_direction: T_INPUT
                        | T_OUTPUT
                        ;

checker_or_generate_item: initial_construct
                         | always_construct
                         | final_construct
                         | assertion_item
                         | continuous_assign
                         | checker_or_generate_item_declaration
                         | checker_generate_item
                         ;

checker_or_generate_item_declaration: T_RAND? data_declaration
                                     | function_declaration
                                     | checker_declaration
                                     | assertion_item_declaration
                                     | covergroup_declaration
                                     | sequence_declaration
                                     | overload_declaration
                                     | genvar_declaration
                                     |  clocking_declaration
                                     | T_DEFAULT T_CLOCKING ss SEMI
                                     | T_DEFAULT T_DISABLE T_IFF expression_or_dist SEMI
                                     | SEMI
                                     ;

checker_generate_item: loop_generate_construct
                     | conditional_generate_construct
                     | generate_region
                     | elaboration_system_task
                     ;
// -----------Class items

class_item:  class_property
             | class_method
             | class_constraint
             | class_declaration
             | covergroup_declaration
             | local_parameter_declaration SEMI
             |  parameter_declaration SEMI
             | SEMI
              ;

class_property:  T_CONST class_item_qualifier* data_type ss ( EQ constant_expression )? SEMI 
              |  property_qualifier*  data_declaration 
            //    |    Data_declaration { return CURRENT_NODE;}
                ;

class_method:  // "pure" "virtual" ( SCAN 1 Class_item_qualifier)* Method_prototype ";"
              method_qualifier* task_declaration
             |  method_qualifier* function_declaration
             |  (T_EXTERN|T_PURE)  ( method_qualifier )* method_prototype SEMI
             | method_qualifier* class_constructor_declaration
             | T_EXTERN  method_qualifier* class_constructor_prototype
             ;

class_constructor_prototype: T_FUNCTION T_NEW ( LP ( tf_port_list )? RP )? SEMI
                           ;
class_constraint: constraint_prototype
                 | constraint_declaration
                 ;

class_item_qualifier: T_STATIC
                     | T_PROTECTED
                     | T_LOCAL
                     | T_CONST T_LOCAL
                     ;

property_qualifier:  random_qualifier
                   | class_item_qualifier
                   ;

random_qualifier: T_RAND
                 | T_RANDC
                 ;

method_qualifier:  T_PURE? T_VIRTUAL
                 | class_item_qualifier
                 ;
method_prototype: task_prototype
                 | function_prototype
                 ;

class_constructor_declaration: T_FUNCTION class_scope? T_NEW ( LP tf_port_list? RP )? SEMI block_item_declaration* ( T_SUPER DOT T_NEW ( LP RP | LP list_of_arguments RP )? SEMI )? function_statement_or_null* T_ENDFUNCTION ( COLON T_NEW )?
                             ;
// -----Constraints

constraint_declaration: T_STATIC? T_CONSTRAINT ss constraint_block 
                       ;
constraint_block: LC constraint_block_item* RC
                     ;
constraint_block_item: T_SOLVE solve_before_list T_BEFORE solve_before_list SEMI
                        | constraint_expression
                        ;

solve_before_list: constraint_primary ( COMMA constraint_primary )*
                   ;

constraint_primary: (implicit_class_handle DOT | class_scope )? hierid select
                   ;

constraint_expression:  ( T_SOFT )? expression_or_dist SEMI
                        | uniqueness_constraint SEMI
                        | T_IF LP expression RP constraint_set (T_ELSE constraint_set )?
                        | T_FOREACH LP psid LB  loop_variables RB RP constraint_set
                        | T_DISABLE T_SOFT constraint_primary SEMI
                        | expression ARROW constraint_set
                        ;

uniqueness_constraint: T_UNIQUE LC open_range_list RC
                      ;

constraint_set:  LC ( constraint_expression )* RC
                | constraint_expression
               ;

dist_list:dist_item ( COMMA dist_item )*
         ;

dist_item:  value_range ( dist_weight )?
          ;
dist_weight: COLONEQ expression
            | COLONSLASH expression
            ;
constraint_prototype: (constraint_prototype_qualifier )? ( T_STATIC )? T_CONSTRAINT ss  SEMI
                     ;

constraint_prototype_qualifier:T_EXTERN
                               | T_PURE
                                ;
extern_constraint_declaration:( T_STATIC )? T_CONSTRAINT class_scope ss constraint_block
                               ;

identifier_list: ss ( COMMA ss )*
                ;

// --Package items

package_item: package_or_generate_item_declaration
              | anonymous_program
              | package_export_declaration
              | timeunits_declaration
              ;

package_or_generate_item_declaration:  net_declaration 
                                    | data_declaration 
                                    |  task_declaration 
                                    |  function_declaration 
                                    |  checker_declaration 
                                    |  dpi_import_export 
                                    |  extern_constraint_declaration
                                    |  class_declaration 
                                    |  class_constructor_declaration 
                                    |  local_parameter_declaration SEMI
                                    |  parameter_declaration 
                                    |  covergroup_declaration 
                                    |  overload_declaration 
                                    | assertion_item_declaration 
                                    | include_path
                                    | SEMI 
                                    ;

anonymous_program: T_PROGRAM SEMI ( anonymous_program_item )* T_ENDPROGRAM
                   ;
anonymous_program_item: task_declaration
                        |  function_declaration
                        |  class_declaration
                        |  covergroup_declaration
                        | class_constructor_declaration
                        | SEMI
                        ;
//---Module parameter declarations

local_parameter_declaration: T_LOCALPARAM T_TYPE list_of_type_assignments
                             | T_LOCALPARAM data_type_or_implicit list_of_param_assignments
                              ;


specparam_declaration: T_SPECPARAM ( packed_dimension )? list_of_specparam_assignments SEMI
                       ;
// --Port declarations

inout_declaration: T_INOUT net_port_type list_of_port_identifiers
                   ;
input_declaration: T_INPUT net_port_type list_of_port_identifiers
                  | T_INPUT variable_port_type list_of_variable_identifiers
                  ;
output_declaration:  T_OUTPUT variable_port_type list_of_variable_port_identifiers
                    | T_OUTPUT net_port_type list_of_port_identifiers
                    ;
interface_port_declaration: ss list_of_interface_identifiers
                           | ss DOT ss list_of_interface_identifiers
                           ;
ref_declaration:  T_REF variable_port_type list_of_variable_identifiers
               ;


uuu:(data_declaration)+ EOF
   ;

data_declaration: (T_CONST )? (T_VAR )? ( lifetime )? data_type_or_implicit  list_of_variable_decl_assignments SEMI
    | type_declaration 
    | package_import_declaration 
    | package_export_declaration
    | net_type_declaration 
    ;

package_import_declaration: T_IMPORT package_import_item ( COMMA package_import_item )* SEMI
                           ;
package_import_item: ss COLONCOLON STAR
                     | ss COLONCOLON ss
                    ;
package_export_declaration: T_EXPORT SCCS SEMI
                           | T_EXPORT package_import_item ( COMMA package_import_item )* SEMI
                           ;
genvar_declaration: T_GENVAR list_of_genvar_identifiers SEMI
                    ;
net_declaration:  net_type ( drive_strength | charge_strength )? ( T_VECTORED | T_SCALARED )? (data_type_or_implicit)? (delay3 )? list_of_net_decl_assignments SEMI
                   | ss (delay_control )? list_of_net_decl_assignments SEMI
                   | T_INTERCONNECT (implicit_data_type)? ( P delay_value )? ss ( unpacked_dimension )* ( COMMA ss ( unpacked_dimension )* )? SEMI
                  ;

type_declaration:  T_TYPEDEF ss constant_bit_select DOT ss ss SEMI 
                    | T_TYPEDEF (T_CLASS | T_STRUCT | T_UNION | T_ENUM | T_INTERFACE )? ss SEMI
                    | T_TYPEDEF data_type ss ( variable_dimension )* SEMI 
                    ;

net_type_declaration: T_NETTYPE data_type ss (T_WITH (class_scope )? ss )? SEMI
                     | T_NETTYPE (class_scope )? ss ss SEMI
                     ;

lifetime: T_STATIC
          | T_AUTOMATIC
          ;

casting_type:  simple_type
      | number
      | signing
      | T_STRING
      | T_CONST
      | subroutine_call
      | LP expression RP 
      ;

data_type: integer_vector_type ( signing )? (packed_dimension )*
           | integer_atom_type ( signing )?
           | non_integer_type 
           | struct_union (T_PACKED (signing )? )? LC struct_union_member ( struct_union_member )* RC ( packed_dimension )* 
           | T_ENUM (enum_base_type )? LC ( enum_name_declaration ( COMMA enum_name_declaration )* )* RC ( packed_dimension )* 
           | T_STRING 
           | T_CHANDLE 
           | T_VIRTUAL ( T_INTERFACE )? ss (parameter_value_assignment )? ( DOT ss )? 
           | (package_scope)? ss  (packed_dimension)+  
           | class_type 
           | T_EVENT
           | type_reference 
           ;

data_type_or_implicit: data_type  
                      | implicit_data_type 
                      ;

data_type_or_implicit1: data_type  
                      | (packed_dimension )*
                      ;

implicit_data_type:  signing (packed_dimension )*
                  |  (packed_dimension )+
                   ;

enum_base_type: integer_atom_type ( signing )?
               | integer_vector_type (signing )? ( packed_dimension )?
               | ss ( packed_dimension )?
               ;

enum_name_declaration:ss ( LB number (COLON number )? RB )? ( EQ constant_expression )?
                     ;

class_scope: class_type1 COLONCOLON 
            ;

class_type1:  ss (parameter_value_assignment )?  ( COLONCOLON ss ( parameter_value_assignment )? )*
               | DUNIT COLONCOLON ss
               | T_LOCAL
               ;


class_type: psid (parameter_value_assignment )? (COLONCOLON SS (parameter_value_assignment )? )* 
            | DUNIT COLONCOLON ss 
         
           ;



integer_type: integer_vector_type
              | integer_atom_type
              ;

integer_atom_type :T_BYTE
                  | T_SHORTINT
                  | T_INT
                  | T_LONGINT
                  | T_INTEGER
                  | T_TIME
                  ;

integer_vector_type: T_BIT
                    | T_LOGIC
                    | T_REG
                    | T_CONST T_LOGIC
                    ;

non_integer_type: T_SHORTREAL
                 | T_REAL
                 | T_REALTIME
                 ;

net_type: T_SUPPLY0
    | T_SUPPLY1
    | T_TRI
    | T_TRIAND
    | T_TRIOR
    | T_TRIREG
    | T_TRI0
    | T_TRI1
    | T_UWIRE
    | T_WIRE
    | T_WAND
    | T_WOR
    ;

net_port_type: T_INTERCONNECT (implicit_data_type)?
              | net_type?   data_type_or_implicit
               ;

variable_port_type:var_data_type
                  ;

var_data_type: T_VAR data_type_or_implicit
                | data_type
              ;
signing: T_SIGNED
         | T_UNSIGNED
         ;

simple_type:integer_type
    | non_integer_type
    | psid
    ;

struct_union_member: random_qualifier? data_type_or_void list_of_variable_decl_assignments SEMI
                    ;

data_type_or_void: T_VOID
                  | data_type
                  ;

struct_union: T_STRUCT
             | T_UNION T_TAGGED?
              ;

type_reference: T_TYPE LP expression RP
               | T_TYPE LP data_type RP
               ;
// --- strenght

drive_strength:  LP strength0 COMMA strength1 RP
              | LP strength1 COMMA strength0 RP
              | LP strength0 COMMA T_HIGHZ1 RP
              | LP strength1 COMMA T_HIGHZ0 RP
              | LP T_HIGHZ0 COMMA strength1 RP
              | LP T_HIGHZ1 COMMA strength0 RP
              ;

strength0: T_SUPPLY0
    | T_STRONG0
    | T_PULL0
    | T_WEAK0
    ;

strength1:T_SUPPLY1
    | T_STRONG1
    | T_PULL1
    | T_WEAK1
    ;

charge_strength: LP T_SMALL RP
    |  LP T_MEDIUM RP
    | LP T_LARGE RP
    ;
// ---Delays

delay3: pound_delay_value
         | P LP mintypmax_expression ( COMMA mintypmax_expression ( COMMA mintypmax_expression )? )? RP
          ;

delay2:  P LP mintypmax_expression (COMMA mintypmax_expression )? RP
          | pound_delay_value
         ;
delay_value: T_ONESTEP
              | time_literal
              | number
              | psid
              | hierid
              ;
// --- Declaration lists

list_of_defparam_assignments:defparam_assignment ( COMMA defparam_assignment )*
                             ;
list_of_genvar_identifiers:  ss ( COMMA ss )*
                           ;
list_of_interface_identifiers: ss  unpacked_dimension* (COMMA ss ( unpacked_dimension )* )*
                              ;

list_of_net_decl_assignments: net_decl_assignment ( COMMA net_decl_assignment )*
                             ;

list_of_port_identifiers: ss?  unpacked_dimension* ( COMMA ss ( unpacked_dimension )* )*
                          ;
list_of_udp_port_identifiers:  ( COMMA ss )*
                              ;
list_of_specparam_assignments: specparam_assignment ( COMMA specparam_assignment )*
                              ;
list_of_tf_variable_identifiers: ss?  variable_dimension* ( EQ expression )? ( COMMA ss ( variable_dimension )* ( EQ expression )? )*
                               ;
list_of_type_assignments: type_assignment (   COMMA type_assignment )*
                         ;
// SCAN 3 {!checkid3(TokenType.T_PARAMETER)}# =>
list_of_variable_decl_assignments: variable_decl_assignment ( COMMA variable_decl_assignment )*
                                 ;
list_of_variable_identifiers: (ss)?  ( variable_dimension )* ( COMMA ss ( variable_dimension )*)*
                            ;

list_of_variable_port_identifiers: port_id (COMMA port_id )*
                                  ;
port_id: ss  ( variable_dimension)*  EQ constant_expression
          |  ss  ( variable_dimension)+
          | ss
          ;



// ---Declaration assignments

defparam_assignment:hierid EQ constant_mintypmax_expression
                    ;

net_decl_assignment: ss  (unpacked_dimension)* ( EQ expression )?
                    ;

specparam_assignment: ss  EQ constant_mintypmax_expression
                     | pulse_control_specparam
                     ;
type_assignment: ss ( EQ data_type )?
                ;
pulse_control_specparam: T_PATHPULSE EQ LP reject_limit_value ( COMMA error_limit_value )? RP
                         | T_PATHPULSE specify_input_terminal_descriptor DOLLAR specify_output_terminal_descriptor EQ LP reject_limit_value ( COMMA error_limit_value )? RP
                         | T_PATHPULSE EQ expression

                        ;

error_limit_value:limit_value
                  ;
reject_limit_value: limit_value
            ;
limit_value: constant_mintypmax_expression
            ;


variable_decl_assignment
    : ss (     EQ class_new
                   | variable_dimension*  ( EQ (dynamic_array_new|expression) )?
             //    | ( EQ T_NEW (LP list_of_arguments RP )?)
               /*   | (variable_dimension* ( EQ expression )?) */)
         //        | ASSIGN_OP NEW ( OPEN_PARENS list_of_arguments CLOSE_PARENS )?
    ;


class_new:    class_scope? T_NEW ( LP list_of_arguments RP | expression)? 
            //  | T_NEW expression? 
            ;

dynamic_array_new: T_NEW LB expression RB ( LP expression RP )?
                  ;
// ----- Declaration ranges

unpacked_dimension: LB RB
                    | LB constant_expression RB
                    |  LB constant_range RB
                    ;
packed_dimension:   unsized_dimension 
                 | LB constant_range  RB 
                    ;

associative_dimension:  LB STAR RB
                      | LB data_type RB
                      ;
variable_dimension: unsized_dimension 
                   | queue_dimension    
                   | associative_dimension 
                   | unpacked_dimension   
                   ;

queue_dimension: LB DOLLAR (COLON constant_expression )? RB
                ;
unsized_dimension: LB RB
                  ;
// ---Function declarations

function_data_type_or_implicit: implicit_data_type
                                | data_type_or_void
                                 ;
function_declaration: T_FUNCTION ( lifetime )? function_body_declaration
                     ;
function_body_declaration: function_data_type_or_implicit ( ss DOT | class_scope )? ss? function_dec
                             ;

function_dec:  SEMI ( tf_item_declaration)* ( function_statement_or_null )* T_ENDFUNCTION (COLON ss)? 
                | LP ( tf_port_list )? RP SEMI (block_item_declaration )* ( function_statement_or_null)*  T_ENDFUNCTION ( COLON ss)?
                            ;

function_prototype: T_FUNCTION data_type_or_void ss ( LP ( tf_port_list )? RP )?
                   ;
dpi_import_export : T_IMPORT dpi_spec_string ( dpi_function_import_property )? (ss EQ )? ( dpi_function_proto | dpi_task_proto) SEMI  
     | T_EXPORT dpi_spec_string (ss EQ )? (T_FUNCTION | T_TASK) ss SEMI  
    ;

dpi_spec_string: String_literal //"DPI-C"
     ;

dpi_function_import_property: T_CONTEXT
                             | T_PURE
                              ;
dpi_task_import_property: T_CONTEXT
                        ;
dpi_function_proto:function_prototype
               ;
dpi_task_proto: task_prototype
               ;
// ---Task declarations ---

task_declaration: T_TASK (lifetime )? task_body_declaration
                  ;
task_body_declaration:  (ss DOT | class_scope )? ss task_decl
                      ;
task_decl: SEMI ( tf_item_declaration )*  (statement_or_null )* T_ENDTASK (COLON ss )?
            | LP ( tf_port_list )? RP SEMI ( block_item_declaration )* ( statement_or_null )* T_ENDTASK (COLON ss )?
            ;

tf_item_declaration:  block_item_declaration
                     |  tf_port_declaration
                     ;

tf_port_list: tf_port_item ( COMMA tf_port_item )*
             ;
tf_port_item:  ( tf_port_direction )? ( T_VAR )? data_type_or_implicit (ss  (variable_dimension)*)? (EQ expression )?
             //  |   ss (variable_dimension)*  (EQ expression)?
             ;
tf_port_direction:port_direction
                   | T_CONST T_REF
                  ;
tf_port_declaration:  tf_port_direction ( T_VAR )? data_type_or_implicit list_of_tf_variable_identifiers SEMI
                    ;
task_prototype: T_TASK ss ( LP ( tf_port_list )? RP )?
               ;
// ---Block_item declarations

block_item_declaration: local_parameter_declaration SEMI
    |  parameter_declaration SEMI
    |  overload_declaration
    |  let_declaration
    |  data_declaration
    ;

overload_declaration: T_BIND overload_operator T_FUNCTION data_type ss LP overload_proto_formals RP SEMI
                    ;
overload_operator:PLUS
                  | PLUSPLUS
                  | MINUS
                  | MINUSMINS
                  | STAR
                  | SS
                  | SLASH
                  | PER
                  | EQEQ
                  | NE
                  | LT
                  | LTEQ
                  | GT
                  | GE
                  | EQ
                  ;

overload_proto_formals:data_type ( COMMA data_type )*
                      ;
// ---Interface declarations

modport_declaration: T_MODPORT modport_item ( COMMA modport_item )* SEMI
                    ;
modport_item: ss LP modport_ports_declaration ( COMMA modport_ports_declaration )* RP
              ;
modport_ports_declaration:  modport_simple_ports_declaration
                          |  modport_tf_ports_declaration
                          |  modport_clocking_declaration
                          ;

modport_clocking_declaration :T_CLOCKING ss
                             ;

modport_simple_ports_declaration:port_direction modport_simple_port (COMMA modport_simple_port )*
                                 ;
modport_simple_port: ss
                    | DOT ss LP ( expression )? RP
                    ;

modport_tf_ports_declaration:import_export modport_tf_port ( COMMA modport_tf_port )*
                             ;

modport_tf_port: method_prototype
                 | ss
                 ;

import_export:T_IMPORT
               | T_EXPORT
                ;
// ---Assertion declarations---------------

concurrent_assertion_item:  concurrent_assertion_statement 
                           | checker_instantiation 
                           ;

concurrent_assertion_statement:  assert_property_statement
    | assume_property_statement
    | cover_property_statement
    | cover_sequence_statement
    | restrict_property_statement
    ;

assert_property_statement:(ss COLON )?  T_ASSERT T_PROPERTY LP property_spec RP action_block
                          ;
assume_property_statement:( ss COLON )? T_ASSUME T_PROPERTY LP property_spec RP action_block
                          ;
cover_property_statement:( ss COLON )? T_COVER T_PROPERTY LP property_spec RP statement_or_null
                          ;
expect_property_statement: T_EXPECT LP property_spec RP action_block
                           ;
cover_sequence_statement: T_COVER T_SEQUENCE LP ( clocking_event )? ( T_DISABLE T_IFF LP expression_or_dist RP )? sequence_expr RP statement_or_null
                          ;
restrict_property_statement: T_RESTRICT T_PROPERTY LP property_spec RP SEMI
                            ;
property_instance:psid ( LP ( property_list_of_arguments )? RP )?
                            ;
property_list_of_arguments: property_actual_arg  ( COMMA ( property_actual_arg )? )* ( COMMA DOT ss LP ( property_actual_arg )? RP )*
                           | DOT ss LP ( property_actual_arg )? RP ( COMMA DOT ss LP ( property_actual_arg )? RP )*
                           ;

property_actual_arg: property_expr
                    | sequence_actual_arg
                    ;

assertion_item_declaration: property_declaration
                           | sequence_declaration
                           | let_declaration
                           ;

property_declaration: T_PROPERTY ss ( LP ( property_port_list )? RP )? SEMI (assertion_variable_declaration )* property_spec (SEMI )? T_ENDPROPERTY ( COLON ss )? 
                     ;
property_port_list: property_port_item (COMMA property_port_item )*
                   ;
property_port_item: (T_LOCAL ( property_lvar_port_direction )? )? property_formal_type (ss)? (variable_dimension )* (EQ property_actual_arg )?
                    ;
property_lvar_port_direction:T_INPUT
                             ;
property_formal_type:sequence_formal_type
                     | T_PROPERTY
                      ;
property_spec:(clocking_event )? ( T_DISABLE T_IFF LP expression_or_dist RP )?   property_expr
              ;

  property_expr:
       sequence_expr 
      | T_STRONG LP sequence_expr RP 
      | T_WEAK LP sequence_expr RP
      | T_NOT property_expr
      | property_expr T_OR property_expr
      | LP property_expr RP 
      | property_expr T_AND property_expr
      | sequence_expr BARARROW property_expr
      | sequence_expr BAREQGT property_expr
      | T_IF LP expression_or_dist RP property_expr (T_ELSE property_expr )?
      | T_CASE LP expression_or_dist RP ( property_case_item )+ T_ENDCASE
      | sequence_expr PMP property_expr
      | sequence_expr PEP property_expr
      | T_NEXTTIME ( LB  constant_range RB )? property_expr
      | T_S_NEXTTIME  ( LB  constant_range RB )? property_expr
      | T_ALWAYS ( LB cycle_delay_const_range_expression RB )? property_expr
      | T_S_ALWAYS (LB  constant_range RB )? property_expr
      | T_S_EVENTUALLY ( LB cycle_delay_const_range_expression RB )? property_expr
      | T_EVENTUALLY LB constant_range RB property_expr
      | property_expr T_UNTIL property_expr
      | property_expr T_S_UNTIL property_expr
      | property_expr T_UNTIL_WITH property_expr
      | property_expr T_S_UNTIL_WITH property_expr
      | property_expr T_IMPLIES property_expr
      | property_expr T_IFF property_expr
      | T_ACCEPT_ON LP expression_or_dist RP property_expr
      | T_REJECT_ON LP expression_or_dist RP property_expr
      | T_SYNC_ACCEPT_ON LP expression_or_dist RP property_expr
      | T_SYNC_REJECT_ON LP expression_or_dist RP property_expr
      | property_instance 
      | clocking_event property_expr
      ;



property_case_item:  expression_or_dist (COMMA expression_or_dist )* COLON property_expr ( SEMI )?
                   | T_DEFAULT ( COLON )? property_expr ( SEMI )?
                    ;

sequence_declaration: T_SEQUENCE ss ( LP (sequence_port_list )? RP )? SEMI ( assertion_variable_declaration )* sequence_expr ( SEMI )? T_ENDSEQUENCE ( COLON ss) ?
                     ;


sequence_port_list:sequence_port_item ( COMMA sequence_port_item )*
                   ;
sequence_port_item:  ( T_LOCAL ( sequence_lvar_port_direction )? )? sequence_formal_type (ss)? (variable_dimension )* ( EQ sequence_actual_arg )?
                   ;
sequence_lvar_port_direction:T_INPUT
                            | T_INOUT
                            | T_OUTPUT
                           ;

sequence_formal_type: data_type_or_implicit
                       | T_SEQUENCE
                       | T_UNTYPED
                       ;


/*
sequence_expr:
     cycle_delay_range sequence_expr ( cycle_delay_range sequence_expr )*
    | expression_or_dist T_THROUGHOUT sequence_expr
    | d_callsequence_metho
    | sequence_instance ( sequence_abbrev )?
    | expression_or_dist (boolean_abbrev) ? property_expr2
    |  LP sequence_expr (COMMA sequence_match_item )* RP (sequence_abbrev )? sequence_expr2
    |  T_AND sequence_expr2
    |  T_INTERSECT sequence_expr
    | T_OR sequence_expr2
    | T_FIRST_MATCH LP sequence_expr (COMMA sequence_match_item )* RP
    | T_WITHIN sequence_expr
    | clocking_event sequence_expr
    ;
 */   
    
 sequence_expr: cycle_delay_range sequence_expr (cycle_delay_range sequence_expr )*
    | sequence_expr cycle_delay_range sequence_expr ( cycle_delay_range sequence_expr )*
    | expression_or_dist ( boolean_abbrev )?
    | sequence_instance (sequence_abbrev )?
    | LP sequence_expr ( COMMA sequence_match_item )* RP ( sequence_abbrev )?
    | sequence_expr T_AND sequence_expr
    | sequence_expr T_INTERSECT sequence_expr
    | sequence_expr T_OR sequence_expr
    | T_FIRST_MATCH LP sequence_expr ( COMMA sequence_match_item )* RP
    | expression_or_dist T_THROUGHOUT sequence_expr
    | sequence_expr T_WITHIN sequence_expr
    | clocking_event sequence_expr
    ;

cycle_delay_range: PP LB STAR RB
                  | PP LB PLUS RB
                  | PP LB cycle_delay_const_range_expression RB
                  | PP primary
                   ;

sequence_method_call: sequence_instance  DOT ss
                   ;

sequence_match_item: operator_assignment
    | subroutine_call
    | inc_or_dec_expression
    ;

sequence_instance: psid  (LP ( sequence_list_of_arguments )? RP)?
                  ;
sequence_list_of_arguments:  sequence_actual_arg  ( COMMA ( sequence_actual_arg )? )* ( COMMA DOT ss LP ( sequence_actual_arg )? RP )*
                           | DOT ss LP ( sequence_actual_arg )? RP (COMMA DOT ss LP ( sequence_actual_arg )? RP )*
                           ;
sequence_actual_arg:event_expression
                    | sequence_expr
                    ;
boolean_abbrev:
    goto_repetition
    | consecutive_repetition
    |  non_consecutive_repetition
  ;

sequence_abbrev:consecutive_repetition
                ;
consecutive_repetition:  LB STAR const_or_range_expression RB
                       |  LB STAR RB
                       | LB PLUS RB
                        ;

non_consecutive_repetition:LB EQ const_or_range_expression RB
                           ;

goto_repetition: LB ARROW const_or_range_expression RB
                  ;
const_or_range_expression:  cycle_delay_const_range_expression
                           | constant_expression
                          ;
cycle_delay_const_range_expression:  constant_expression COLON DOLLAR
                                     | constant_expression COLON constant_expression
                                      ;
expression_or_dist: expression (T_DIST LC dist_list RC )?
                    ;
assertion_variable_declaration: var_data_type list_of_variable_decl_assignments SEMI
                              ;
let_declaration: T_LET ss ( LP ( let_port_list )? RP )? EQ expression SEMI
                 ;
let_identifier: ss
              ;
let_port_list:let_port_item ( COMMA let_port_item )*
               ;
let_port_item:  let_formal_type ss  ( variable_dimension )* ( EQ expression )?
              ;
let_formal_type:data_type_or_implicit
                | T_UNTYPED
                 ;
let_expression: ( package_scope )? ss ( LP (  let_list_of_arguments )? RP )?
               ;
let_list_of_arguments:  let_actual_arg  ( COMMA ( let_actual_arg )? )* ( COMMA DOT ss LP ( let_actual_arg )? RP )*
                        | DOT ss LP ( let_actual_arg )? RP (COMMA DOT ss LP ( let_actual_arg )? RP )*
                         ;
let_actual_arg:event_expression
              ;
// ---Covergroup declarations---

covergroup_declaration: T_COVERGROUP ss ( LP ( tf_port_list )? RP )? (coverage_event )? SEMI (coverage_spec_or_option )* T_ENDGROUP ( COLON ss )?
                       ;
coverage_spec_or_option:  coverage_spec
                        |  coverage_option SEMI
                        ;
coverage_option :T_OPTION DOT ss EQ expression
                | T_TYPE_OPTION DOT ss EQ constant_expression
                ;
coverage_spec:cover_point
    | cover_cross
    ;
coverage_event:clocking_event
              | T_WITH T_FUNCTION ss LP ( tf_port_list )? RP
              | ATAT LP block_event_expression RP
              ;

block_event_expression:  block_event_expression T_OR block_event_expression
                       | T_BEGIN hierarchical_btf_identifier
                       | T_END hierarchical_btf_identifier
                       ;

hierarchical_btf_identifier: hierid
                            | class_scope  ss
                            ;

cover_point: data_type_or_implicit  (ss COLON )? T_COVERPOINT  expression ( T_IFF LP expression RP )? bins_or_empty 
             |  ( ss COLON )? T_COVERPOINT  expression ( T_IFF LP expression RP )?   bins_or_empty 
             ;
bins_or_empty:  LC (bins_or_options SEMI )* RC 
             | SEMI 
             ;
//[SCAN 1 {checkid()}# =>SS]
bins_or_options:coverage_option
                |  ( T_WILDCARD )? bins_keyword ss ( LB ( covergroup_expression )?  RB )? EQ LC covergroup_range_list RC ( T_WITH LP with_covergroup_expression RP )? ( T_IFF LP expression RP )?

                |  ( T_WILDCARD )? bins_keyword ss ( LB ( covergroup_expression )? RB )? EQ set_covergroup_expression ( T_WITH LP with_covergroup_expression RP )? ( T_IFF RP expression LP )?

             //   | SCAN [ "wildcard" ] Bins_keyword SS [ "[" [ Covergroup_expression ] "]" ] "=" Set_covergroup_expression [ "iff" "(" Expression ")" ]

                |  ( T_WILDCARD )? bins_keyword ss ( LB RB )? EQ trans_list ( T_IFF LP expression RP )?

                 | bins_keyword ss EQ T_DEFAULT T_SEQUENCE ( T_IFF LP expression RP )?

                | bins_keyword ss ( LB ( covergroup_expression )? RB )? EQ T_DEFAULT (T_IFF LP expression RP )?

                ;

bins_keyword:
    T_BINS
    | T_ILLEGAL_BINS
    | T_IGNORE_BINS
    ;

trans_list: LP trans_set RP ( COMMA LP trans_set RP )*
           ;
trans_set: trans_range_list ( EQGT trans_range_list )*
                    ;
trans_range_list: trans_item (LB STAR repeat_range RB |  LB ARROW repeat_range RB  | LB EQ repeat_range RB)?
               //  | SCAN Trans_item "[""*" Repeat_range "]"
               //  | SCAN Trans_item "[""->" Repeat_range "]"
               //  | Trans_item "[""=" Repeat_range "]"
                 ;
trans_item: covergroup_range_list
           ;
repeat_range: covergroup_expression  (COLON covergroup_expression)?
             ;
cover_cross:( ss COLON )? T_CROSS list_of_cross_items ( T_IFF LP expression RP )? cross_body 
            ;
list_of_cross_items: cross_item COMMA cross_item ( COMMA cross_item )*
                    ;
cross_item: ss
           ;
cross_body:LC ( cross_body_item  )* RC
           | SEMI
           ;
cross_body_item:  function_declaration
                | bins_selection_or_option SEMI
                ;
bins_selection_or_option:  coverage_option
                         |  bins_selection
                          ;
bins_selection: bins_keyword ss EQ (select_expression)+ ( T_IFF LP expression RP )?
               ;



select_expression2 : (select_expression select_expression2)?
                   ;
select_expression: select_condition
                    | NOT select_condition
                    | ANDAND select_expression2
                    | BARBAR select_expression2
                    | LP select_expression RP
                    | T_WITH LP expression RP ( T_MATCHES integer_covergroup_expression )?
                    | ss
                 // | Cross_set_expression [ "matches" Integer_covergroup_expression ]
   ;

select_condition: T_BINSOF LP bins_expression RP ( T_INTERSECT LC covergroup_range_list RC )?
                  ;
bins_expression: ss ( DOT ss )?
                 ;
covergroup_range_list:covergroup_value_range ( COMMA covergroup_value_range )*
                     ;
covergroup_value_range: LB covergroup_expression COLON covergroup_expression RB
                          | covergroup_expression
                       ;
with_covergroup_expression:covergroup_expression
                   ;
set_covergroup_expression:covergroup_expression
                   ;
integer_covergroup_expression:covergroup_expression
                    ;
cross_set_expression:covergroup_expression
                     ;
covergroup_expression:expression
                      ;
// --Primitive instantiation and instances----------
gate_instantiation:cmos_switchtype (delay3 )? cmos_switch_instance ( COMMA cmos_switch_instance )* SEMI
    | enable_gatetype (drive_strength )? ( delay3 )? enable_gate_instance (COMMA enable_gate_instance )* SEMI
    
    | mos_switchtype ( delay3  )? mos_switch_instance ( COMMA mos_switch_instance )* SEMI
    
    | n_input_gatetype ( drive_strength )? ( delay2 )? n_input_gate_instance ( COMMA n_input_gate_instance )* SEMI
    
    | n_output_gatetype ( drive_strength )? (delay2 )? n_output_gate_instance (COMMA n_output_gate_instance )* SEMI
    
    | pass_en_switchtype (delay2 )? pass_enable_switch_instance ( COMMA pass_enable_switch_instance )* SEMI
   
    | pass_switchtype pass_switch_instance ( COMMA pass_switch_instance )* SEMI
    
    | T_PULLDOWN ( pulldown_strength )? pull_gate_instance (COMMA pull_gate_instance )* SEMI
    
    | T_PULLUP ( pullup_strength )? pull_gate_instance (COMMA pull_gate_instance )* SEMI
     ;


cmos_switch_instance: ( name_of_instance )? LP output_terminal COMMA input_terminal COMMA ncontrol_terminal COMMA pcontrol_terminal RP
                     ;
enable_gate_instance: ( name_of_instance )? LP output_terminal COMMA input_terminal COMMA enable_terminal RP
                      ;
mos_switch_instance:(name_of_instance )? LP output_terminal COMMA input_terminal COMMA enable_terminal RP
                     ;
n_input_gate_instance: (name_of_instance )? LP output_terminal COMMA input_terminal ( COMMA input_terminal )* RP
                       ;
n_output_gate_instance:(name_of_instance )? LP output_terminal ( COMMA output_terminal )*  RP
                       ;

pass_switch_instance: ( name_of_instance )? LP inout_terminal COMMA inout_terminal RP
                         ;
pass_enable_switch_instance: ( name_of_instance )? LP inout_terminal COMMA inout_terminal COMMA enable_terminal RP
                            ;

pull_gate_instance: (name_of_instance )? LP output_terminal RP
                    ;

//-- Primitive strengths

pulldown_strength:LP strength0 COMMA strength1 RP
    | LP strength1 COMMA strength0 RP
    | LP strength0 RP
     ;
pullup_strength:  LP strength0 COMMA strength1 RP
    | LP strength1 COMMA strength0 RP
    | LP strength1 RP
     ;
// ---Primitive terminals--

enable_terminal:expression
                ;
inout_terminal: net_lvalue
                ;
input_terminal: expression
               ;
ncontrol_terminal: expression
               ;
output_terminal: net_lvalue
               ;
pcontrol_terminal: expression
               ;
// ---Primitive gate and switch types

cmos_switchtype: T_CMOS
                | T_RCMOS
                ;

enable_gatetype: T_BUFIF0
                | T_BUFIF1
                | T_NOTIF0
                | T_NOTIF1
                ;

mos_switchtype: T_NMOS
               | T_PMOS
               | T_RNMOS
               | T_RPMOS
                ;

n_input_gatetype: T_AND
                | T_NAND
                | T_OR
                | T_NOR
                | T_XOR
                | T_XNOR
                ;

n_output_gatetype: T_BUF
                  | T_NOT
                  ;

pass_en_switchtype:  T_TRANIF0
                    | T_TRANIF1
                    | T_RTRANIF1
                    | T_RTRANIF0
                    ;

pass_switchtype: T_TRAN
                | T_RTRAN
                ;

// --------Module instantation ----------

module_instantiation: ss ( parameter_value_assignment )? hierarchical_instance (COMMA hierarchical_instance )* SEMI
                      ;
parameter_value_assignment: P LP ( list_of_parameter_assignments )? RP
                          // | P Integer
                           | T_POUND
                          ;
list_of_parameter_assignments:ordered_parameter_assignment (COMMA ordered_parameter_assignment )*
                              | named_parameter_assignment ( COMMA named_parameter_assignment )*
                              ;
ordered_parameter_assignment: param_expression
                               ;


named_parameter_assignment: DOT ss LP ( param_expression )? RP 
                          //  | SCAN "." SS"(" [ Mintypmax_expression] ")"
                          //  | "$"
                           ;


hierarchical_instance: name_of_instance LP  list_of_port_connections RP
                               ;
name_of_instance: ss (unpacked_dimension )*
                  ;
list_of_port_connections:  named_port_connection (COMMA named_port_connection )*
                           | ordered_port_connection ( COMMA ordered_port_connection )*
                         ;

ordered_port_connection: ( expression )?
                       ;
named_port_connection:  DOT ss ( LP ( expression )? RP )?
                       |  DOTSTAR
                       ;

// --------Interface instantiation -----------

interface_instantiation: ss (parameter_value_assignment)? hierarchical_instance ( COMMA hierarchical_instance )* SEMI
                        ;
// ----Checker instantiation ------------

checker_instantiation: psid name_of_instance LP ( list_of_checker_port_connections )? RP SEMI
                      ;
list_of_checker_port_connections: ordered_checker_port_connection (COMMA ordered_checker_port_connection )*
                                 | named_checker_port_connection (COMMA named_checker_port_connection )*
                                 ;
ordered_checker_port_connection:   property_actual_arg
                              ;
named_checker_port_connection:  DOT ss ( LP ( property_actual_arg )? RP )?
                              |  DOTSTAR
                              ;
// ---Program instantiation---

program_instantiation: ss (parameter_value_assignment )? hierid ( COMMA hierid )*  (LP DOTSTAR RP )? SEMI
                      ;
// --- Generated instantiation ---------------

generate_region: T_GENERATE (T_BEGIN COLON ss)?( generate_item )* T_ENDGENERATE
                       ;
loop_generate_construct: T_FOR LP genvar_initialization SEMI genvar_expression SEMI genvar_iteration RP generate_block
                        ;
genvar_initialization: ( T_GENVAR )? ss EQ constant_expression
                      ;

genvar_iteration: ss assignment_operator genvar_expression
                 | inc_or_dec_operator ss
                 | ss inc_or_dec_operator
                 ;

conditional_generate_construct: if_generate_construct
                               | case_generate_construct
                               ;
if_generate_construct: T_IF LP constant_expression RP generate_block ( T_ELSE generate_block )?
                        ;

//if_generate_construct: T_IF LP constant_expression RP generate_block 
//                       ( T_ELSE generate_block  | {_input->LA(1) != T_ELSE}? )
//                        ;
                       


case_generate_construct:T_CASE LP constant_expression RP (case_generate_item)+ T_ENDCASE
                         ;
case_generate_item: constant_expression ( COMMA constant_expression )* COLON generate_block
                    | T_DEFAULT ( COLON )? generate_block
                     ;
generate_block:  (ss COLON )? T_BEGIN ( COLON ss)? ( generate_item )* T_END ( COLON ss )?
                |  generate_item
                ;
generate_item: module_or_generate_item
              | modport_declaration
              | extern_tf_declaration
             // | checker_generate_item
              | generate_region
              | elaboration_system_task
              | loop_generate_construct
              ;
// ----Continuous assignment and net alias statements ---

continuous_assign: T_ASSIGN ( drive_strength )? ( delay3 )? list_of_net_assignments SEMI //(simple_immediate_assertion_statement)?
                  | T_ASSIGN ( delay_control )? list_of_variable_assignments SEMI
   ;

list_of_net_assignments: net_assignment (COMMA net_assignment )*
                         ;
list_of_variable_assignments: variable_assignment ( COMMA variable_assignment )*
                           ;
net_alias: T_ALIAS net_lvalue EQ net_lvalue ( EQ net_lvalue )* SEMI
           ;
net_assignment: net_lvalue EQ expression
               ;
// ----Procedural blocks and assignments---------

initial_construct:  T_INITIAL statement_or_null 
                  ;
always_construct: always_keyword statement
                 ;
always_keyword:T_ALWAYS
    | T_ALWAYS_COMB
    | T_ALWAYS_LATCH
    | T_ALWAYS_FF
    ;

final_construct: T_FINAL function_statement
                 ;

blocking_assignment:   nonrange_variable_lvalue EQ dynamic_array_new 
                  |  (implicit_class_handle DOT | class_scope )? hierid select EQ class_new 
                  |   variable_lvalue  EQ delay_or_event_control expression 
                  |  |operator_assignment  
                

    ;

operator_assignment: variable_lvalue assignment_operator expression 
                    ;

assignment_operator: EQ
    | PLUSEQ 
    | MINUSEQ 
    | SEQ
    | SLASHEQ
    | PE
    | AE
    | BAREQ
    | CARETEQ
    | LTLTEQ
    | GTGTEQ 
    | LTLTLTEQ
    | GTGTGTEQ
    ;

nonblocking_assignment: variable_lvalue LTEQ (delay_or_event_control )? expression
                     ;

procedural_continuous_assignment: T_ASSERT variable_assignment
                                 | T_ASSIGN variable_assignment
                                 | T_DEASSIGN variable_lvalue
                                 | T_FORCE variable_assignment
                                 | T_FORCE net_assignment
                                 | T_RELEASE variable_lvalue
                                 | T_RELEASE net_lvalue
                                  ;
variable_assignment:variable_lvalue EQ expression
                     ;
//-----Parallel and sequential blocks--------

//action_block: statement (T_ELSE statement_or_null)?
//              | T_ELSE statement_or_null
//              | SEMI
//              ;

action_block: statement? T_ELSE statement_or_null  
              | statement_or_null 
              | SEMI 
              ;

seq_block: T_BEGIN (COLON ss )?(block_item_declaration)* (statement_or_null)* T_END (COLON ss )?
          ;
par_block: T_FORK (COLON ss )? (block_item_declaration )* (statement_or_null )* join_keyword (COLON ss )?
          ;
join_keyword: T_JOIN
               | T_JOIN_ANY
               | T_JOIN_NONE
             ;
// -------------------- Statements ---------------------

statement_or_null: statement
                    |  SEMI
                     ;
statement: ( ss COLON )?  statement_item
            ;
statement_item:  procedural_continuous_assignment SEMI
                   | blocking_assignment SEMI
                   | nonblocking_assignment SEMI  
               | case_statement  
               | conditional_statement  
               | inc_or_dec_expression SEMI 
               | subroutine_call_statement  
               | disable_statement 
               | event_trigger  
               | loop_statement 
               | jump_statement 
               | par_block  
               | procedural_timing_control_statement  
               | seq_block  
               | wait_statement  
               | procedural_assertion_statement  
               | clocking_drive SEMI  
               | randsequence_statement  
               | randcase_statement  
               | expect_property_statement  
               | elaboration_system_task 
               ;

function_statement:statement
                    ;
function_statement_or_null: function_statement
                           |  SEMI
                           ;
variable_identifier_list: ss ( COMMA ss )*
                         ;
// ---------Timing control statements ---

procedural_timing_control_statement:procedural_timing_control statement_or_null
                                    ;
delay_or_event_control: delay_control
                        | event_control
                        | T_REPEAT LP expression RP event_control
                          ;
delay_control: pound_delay_value
               | P LP mintypmax_expression RP
               ;

pound_delay_value
  :  T_POUND time_unit?
  | P delay_value
  ;

event_control:  AT LP STAR RP       
               | AT LP event_expression RP
               | AT STAR
             //  | AT LP SRP
             //  | AT LPS RP
                | ATSTAR
               | AT hierid
               | AT package_scope ss

               ;
   // | "@" ps_or_hierarchical_sequence_identifier


//event_expression2: (event_expression event_expression2)?
                  
event_expression:  ( edge_identifier )? expression ( T_IFF expression )? // event_expression2
                 | sequence_instance ( T_IFF expression )?
                 |  event_expression T_OR event_expression
                 |  event_expression COMMA event_expression
                 | LP event_expression RP
                 ;

procedural_timing_control:  delay_control
                           | event_control
                           | cycle_delay
                             ;

jump_statement: T_RETURN ( expression )? SEMI
                 | T_BREAK SEMI
                 | T_CONTINUE SEMI
                  ;

wait_statement:  T_WAIT LP expression RP statement_or_null
                | T_WAIT T_FORK SEMI
                | T_WAIT_ORDER LP hierid ( COMMA hierid )* RP action_block
                 ;
event_trigger:  MINUSGTGT ( delay_or_event_control )? hierid SEMI
                 | ARROW hierid SEMI

                  ;
disable_statement: T_DISABLE ss SEMI
                  | T_DISABLE T_FORK SEMI
                   ;
// --- Conditional statements ----

//conditional_statement:( unique_priority )? T_IF LP cond_predicate RP statement_or_null ( T_ELSE T_IF LP cond_predicate RP statement_or_null )* ( T_ELSE statement_or_null )?
//                      ;

conditional_statement
  : unique_priority? T_IF LP cond_predicate RP statement_or_null (
    T_ELSE statement_or_null
    | {_input->LA(1) != T_ELSE}?
  )
  ;

unique_priority: T_UNIQUE
                | T_UNIQUE0
                | T_PRIORITY
                 ;

cond_predicate: expression_or_cond_pattern ( ANDANDAND expression_or_cond_pattern )*
                          ;
expression_or_cond_pattern :expression
                           | cond_pattern
                            ;

cond_pattern :expression T_MATCHES pattern
             ;
// ---Case statements -------------

case_statement: ( unique_priority )? case_keyword LP  case_expression RP ccase 
                ;

 ccase: T_MATCHES (case_pattern_item)+ T_ENDCASE
        | T_INSIDE (case_inside_item)+ T_ENDCASE
        | (case_item)+ T_ENDCASE
        ;

case_keyword: T_CASE
             | T_CASEZ
             | T_CASEX
             ;
case_expression:expression
            ;
case_item: case_item_expression ( COMMA case_item_expression )* COLON statement_or_null
            | T_DEFAULT (COLON )? statement_or_null
                   ;
case_pattern_item: pattern  (ANDANDAND expression )? COLON statement_or_null
                   | T_DEFAULT ( COLON )? statement_or_null
                   ;
case_inside_item:open_range_list COLON statement_or_null
    | T_DEFAULT ( COLON )? statement_or_null
              ;
case_item_expression: expression
                     ;
randcase_statement: T_RANDCASE (randcase_item)+ T_ENDCASE
                       ;
randcase_item: expression COLON statement_or_null
                ;
open_range_list:open_value_range ( COMMA open_value_range )*
                  ;
open_value_range:value_range
                 ;

// -----------_ Patterns ---------------se

pattern:  DOT ss
          | T_TAGGED ss ( pattern )?
         | QUOTE LC pattern ( COMMA pattern )* RC
         | QUOTE LC ss COLON pattern ( COMMA ss COLON pattern )* RC
         | constant_expression
         | DOTSTAR
         ;

assignment_pattern:  QUOTE LC RC // ???
                   |  QUOTE LC expression ( COMMA expression )* RC
                   |  QUOTE LC structure_pattern_key COLON expression ( COMMA structure_pattern_key COLON expression )* RC
                   |  QUOTE LC  array_pattern_key COLON expression (COMMA array_pattern_key COLON expression )* RC
                   |  QUOTE LC constant_expression LC expression ( COMMA expression )* RC RC
                   ;

structure_pattern_key: assignment_pattern_key
                      ;
array_pattern_key: assignment_pattern_key
                  | constant_expression
                  ;
                  
assignment_pattern_key:T_DEFAULT
                      | simple_type
                      ;
assignment_pattern_expression: (assignment_pattern_expression_type )? assignment_pattern 
                              ;
assignment_pattern_expression_type: type_reference
                                    | psid
                                    | integer_atom_type
                                                                  ;

constant_assignment_pattern_expression: assignment_pattern_expression
                                   ;
assignment_pattern_net_lvalue: QUOTE LC net_lvalue ( COMMA net_lvalue )*  RC
                                  ;

assignment_pattern_variable_lvalue: QUOTE LC variable_lvalue ( COMMA variable_lvalue )* RC
                               ;
//-------------------- Loop statement --------------

loop_statement: T_FOREVER statement_or_null
                | T_REPEAT LP expression RP statement_or_null
                | T_WHILE LP expression RP statement_or_null
                | T_FOR LP ( for_initialization )? SEMI ( expression )? SEMI (for_step )? RP statement_or_null
                | T_DO statement_or_null T_WHILE ( expression ) SEMI
                | T_FOREACH LP hierarchical_btf_identifier (LB  loop_variables RB)* RP statement
                ;

for_initialization: list_of_variable_assignments
                    | for_variable_declaration ( COMMA for_variable_declaration )*
                      ;
for_variable_declaration: ( T_VAR )? data_type ss EQ expression ( COMMA ss EQ expression )*
                        ;
for_step: for_step_assignment ( COMMA for_step_assignment )*
                ;

for_step_assignment: inc_or_dec_expression
                   | operator_assignment
                   | subroutine_call
                      ;
loop_variables:  ss?  (  COMMA  (ss)? )*
               ;

// ------- Subroutine call statements -----------------

subroutine_call_statement : subroutine_call SEMI
                          | T_VOID QUOTE LP subroutine_call RP SEMI
                           ;
// ----------  Assertion statements ---------------

assertion_item: concurrent_assertion_item
              | deferred_immediate_assertion_item
                ;
deferred_immediate_assertion_item: ( ss COLON )? deferred_immediate_assertion_statement
                              ;
procedural_assertion_statement: concurrent_assertion_statement
                               | immediate_assertion_statement
                               | checker_instantiation
                               ;

immediate_assertion_statement:deferred_immediate_assertion_statement
                               |  simple_immediate_assertion_statement
                               ;
simple_immediate_assertion_statement:simple_immediate_assert_statement
                                     | simple_immediate_assume_statement
                                     | simple_immediate_cover_statement
                                     ;

simple_immediate_assert_statement: T_ASSERT LP expression RP action_block 
                                ;
simple_immediate_assume_statement: T_ASSUME LP expression RP action_block
                                ;
simple_immediate_cover_statement: T_COVER LP expression RP statement_or_null
                          ;
deferred_immediate_assertion_statement: deferred_immediate_assert_statement
                                       | deferred_immediate_assume_statement
                                       | deferred_immediate_cover_statement
                                        ;
deferred_immediate_assert_statement:T_ASSERT T_POUND LP expression RP action_block
                                   | T_ASSERT T_FINAL LP expression RP action_block
                                    ;
deferred_immediate_assume_statement:  T_ASSUME T_POUND LP expression RP action_block
                                      | T_ASSUME T_FINAL LP expression RP action_block
                                    ;

deferred_immediate_cover_statement: T_COVER T_POUND LP expression RP statement_or_null
                                    | T_COVER T_FINAL LP expression RP statement_or_null
                                    ;
// --- Clocking block ---------------

clocking_declaration:   T_GLOBAL T_CLOCKING ( ss )? clocking_event SEMI T_ENDCLOCKING (COLON ss)?
                        | (T_DEFAULT )? T_CLOCKING ( ss ) ? clocking_event SEMI (clocking_item)* T_ENDCLOCKING ( COLON ss)?
                       ;
clocking_event: AT ss
               | AT LP event_expression RP
                ;

clocking_item : T_DEFAULT default_skew SEMI
               | clocking_direction list_of_clocking_decl_assign SEMI
               |  assertion_item_declaration
               ;

default_skew:
    T_INPUT clocking_skew ( T_OUTPUT clocking_skew )?
    | T_OUTPUT clocking_skew
    ;
clocking_direction:  T_OUTPUT (clocking_skew )?
                   | T_INPUT (clocking_skew )? T_OUTPUT ( clocking_skew )?
                   | T_INPUT ( clocking_skew )?
                   | T_INOUT
                    ;
list_of_clocking_decl_assign:clocking_decl_assign (COMMA clocking_decl_assign )*
                              ;
clocking_decl_assign: ss ( EQ expression )?
                   ;
clocking_skew:edge_identifier ( delay_control )?
              | delay_control
               ;
clocking_drive: clockvar_expression LTEQ ( cycle_delay )? expression
           ;
cycle_delay: PP number
            | PP ss
            | PP LP expression RP
            ;
clockvar:hierid
         ;
clockvar_expression: clockvar select
          ;
// -----------Randsequence------------------------------

randsequence_statement:T_RANDSEQUENCE LP ss? RP (production)+ T_ENDSEQUENCE
                        ;
production: data_type_or_void? ss ( LP tf_port_list RP )? COLON rs_rule ( BAR rs_rule )* SEMI
          ;
rs_rule: rs_production_list ( COLONEQ weight_specification ( rs_code_block )? )?
                           ;

rs_production_list: rs_prod rs_prod *
                    | T_RAND T_JOIN ( LP expression RP )? ( production_item )+
                    ;
weight_specification: number
                      | psid  LP expression RP
                     ;
rs_code_block: LC data_declaration* statement_or_null* RC
              ;

rs_prod: production_item
    | rs_code_block
    | rs_if_else
    | rs_repeat
    | rs_case
    ;
production_item: ss ( LP list_of_arguments RP )?
                 ;
rs_if_else: T_IF LP expression RP production_item ( T_ELSE production_item )?
               ;
rs_repeat: T_REPEAT LP expression RP production_item
              ;

rs_case: T_CASE LP case_expression RP rs_case_item rs_case_item* T_ENDCASE
                ;
rs_case_item: case_item_expression ( COMMA case_item_expression )* COLON production_item SEMI
             | T_DEFAULT COLON? production_item SEMI
            ;
//---------------------Specify block declaration ------------------

specify_block: T_SPECIFY  specify_item* T_ENDSPECIFY
              ;
specify_item: specparam_declaration
             | pulsestyle_declaration
             | showcancelled_declaration
             | path_declaration
             | system_timing_check
   ;

pulsestyle_declaration:T_PULSESTYLE_ONEVENT list_of_path_outputs SEMI
                       | T_PULSESTYLE_ONDETECT list_of_path_outputs SEMI
                     ;
showcancelled_declaration: T_SHOWCANCELLED list_of_path_outputs SEMI
                          | T_NOSHOWCANCELLED list_of_path_outputs SEMI
                          ;
// -------Specify path declarations ---------

path_declaration: simple_path_declaration SEMI
                 | edge_sensitive_path_declaration SEMI
                 | state_dependent_path_declaration SEMI
                 ;

simple_path_declaration: parallel_path_description EQ path_delay_value 
                        | full_path_description EQ path_delay_value 
                        ;

edge_sensitive_path_declaration: parallel_edge_sensitive_path_description EQ path_delay_value 
                                  | full_edge_sensitive_path_description EQ path_delay_value 
                                  ;

parallel_path_description: LP specify_input_terminal_descriptor (polarity_operator )? EQGT specify_output_terminal_descriptor RP
                          ;


parallel_edge_sensitive_path_description:LP edge_identifier? specify_input_terminal_descriptor (polarity_operator )? EQGT LP specify_output_terminal_descriptor  ( PLUSCOLON | MCOLON | COLON)? data_source_expression RP RP
                  ;


full_path_description: LP list_of_path_inputs polarity_operator? SGT list_of_path_outputs RP
                       ;

full_edge_sensitive_path_description: LP edge_identifier? list_of_path_inputs ( polarity_operator )? SGT LP list_of_path_outputs ( PLUSCOLON | MCOLON | COLON)? data_source_expression RP RP
                       ;

list_of_path_inputs: specify_input_terminal_descriptor ( COMMA specify_input_terminal_descriptor )*
                       ;
list_of_path_outputs: specify_output_terminal_descriptor ( COMMA specify_output_terminal_descriptor )*
                   ;
// --------------- Specify block terminals -----------------------

specify_input_terminal_descriptor:  input_identifier ( LB constant_range_expression RB )?
               ;
specify_output_terminal_descriptor: output_identifier (  LB constant_range_expression RB )?
             ;

input_identifier: ss (DOT ss)?
       ;
output_identifier: ss (DOT ss)?
         ;
 // ----Specify path delays ----------------------------------------

path_delay_value:  LP list_of_path_delay_expressions RP
                     | list_of_path_delay_expressions
                     ;

list_of_path_delay_expressions:   path_delay_expression (COMMA path_delay_expression )*
             ;
  /*
    t_path_delay_expression
    | trise_path_delay_expression , tfall_path_delay_expression
    | trise_path_delay_expression , tfall_path_delay_expression , tz_path_delay_expression
    | t01_path_delay_expression , t10_path_delay_expression , t0z_path_delay_expression , tz1_path_delay_expression , t1z_path_delay_expression , tz0_path_delay_expression
    | t01_path_delay_expression , t10_path_delay_expression , t0z_path_delay_expression , tz1_path_delay_expression , t1z_path_delay_expression , tz0_path_delay_expression , t0x_path_delay_expression , tx1_path_delay_expression , t1x_path_delay_expression , tx0_path_delay_expression , txz_path_delay_expression , tzx_path_delay_expression
   */
/*
t_path_delay_expression
    path_delay_expression

trise_path_delay_expression
    path_delay_expression

tfall_path_delay_expression
    path_delay_expression

tz_path_delay_expression
    path_delay_expression

t01_path_delay_expression
    path_delay_expression

t10_path_delay_expression
    path_delay_expression

t0z_path_delay_expression
    path_delay_expression

tz1_path_delay_expression
    path_delay_expression

t1z_path_delay_expression
    path_delay_expression

tz0_path_delay_expression
    path_delay_expression

t0x_path_delay_expression
    path_delay_expression

tx1_path_delay_expression
    path_delay_expression

t1x_path_delay_expression
    path_delay_expression

tx0_path_delay_expression
    path_delay_expression

txz_path_delay_expression
    path_delay_expression

tzx_path_delay_expression
    path_delay_expression
 */

path_delay_expression:   constant_mintypmax_expression
                      ;


data_source_expression: expression
                   ;
edge_identifier: T_POSEDGE
                | T_NEGEDGE
                | T_EDGE
                ;
state_dependent_path_declaration:  T_IF LP expression RP edge_sensitive_path_declaration
                                  | T_IF LP expression RP simple_path_declaration
                                  | T_IFNONE simple_path_declaration
                                 ;
polarity_operator: PLUS | MINUS
       ;
//  -------------- system_timing_check   ------------------------

 system_timing_check:  setup_timing_check
                        | hold_timing_check
                        | setuphold_timing_check
                        | recovery_timing_check
                        | removal_timing_check
                        | recrem_timing_check
                        | skew_timing_check
                        | timeskew_timing_check
                        | fullskew_timing_check
                        | period_timing_check
                        | width_timing_check
                        | nochange_timing_check
                        ;
setup_timing_check: T_SETUP LP data_event COMMA reference_event COMMA timing_check_limit (  COMMA (notifier )? )? RP SEMI
              ;
hold_timing_check: T_HOLD LP reference_event COMMA data_event COMMA timing_check_limit ( COMMA (notifier )? )? RP SEMI
             ;
setuphold_timing_check: T_SETUPHOLD LP reference_event COMMA data_event COMMA timing_check_limit COMMA timing_check_limit (COMMA (notifier )? (COMMA (timestamp_condition )? (COMMA (timecheck_condition )? ( COMMA (delayed_reference )? ( COMMA (delayed_data )? )? )? )? )? )? RP SEMI
             ;
recovery_timing_check: T_RECOVERY LP reference_event COMMA data_event COMMA timing_check_limit ( COMMA ( notifier )? )? RP SEMI
             ;
removal_timing_check: T_REMOVAL LP reference_event COMMA data_event COMMA timing_check_limit ( COMMA ( notifier )? )? RP SEMI
             ;
recrem_timing_check: T_RECREM LP reference_event COMMA data_event COMMA timing_check_limit COMMA timing_check_limit ( COMMA ( notifier )? ( COMMA ( timestamp_condition )? ( COMMA ( timecheck_condition )? ( COMMA (delayed_reference )? ( COMMA ( delayed_data )? )? )? )? )? )? RP SEMI
            ;
skew_timing_check:  T_SKEW  LP reference_event  COMMA data_event COMMA timing_check_limit ( COMMA ( notifier )? )? RP SEMI
            ;
timeskew_timing_check: T_TIMESKEW LP reference_event COMMA data_event COMMA timing_check_limit ( COMMA ( notifier )? ( COMMA ( event_based_flag )? ( COMMA ( remain_active_flag )? )? )? )? RP SEMI
            ;
fullskew_timing_check: T_FULLSKEW  LP reference_event COMMA data_event COMMA timing_check_limit COMMA timing_check_limit /*(  ( notifier )? ( COMMA ( event_based_flag )? ( COMMA (remain_active_flag )? )? )? )? */ RP SEMI
            ;
period_timing_check: T_PERIOD  LP controlled_reference_event COMMA timing_check_limit ( COMMA ( notifier )? )? RP SEMI 
            ;
width_timing_check: T_WIDTH  LP controlled_reference_event COMMA timing_check_limit COMMA threshold ( COMMA ( notifier )? )? RP SEMI
             ;
nochange_timing_check: T_NOCHANGE  LP reference_event COMMA data_event COMMA start_edge_offset COMMA end_edge_offset ( COMMA ( notifier )? )? RP SEMI
             ;
// ---------system timing check command arguments -----------

timecheck_condition: mintypmax_expression
         ;
controlled_reference_event: controlled_timing_check_event
        ;

data_event: timing_check_event
          ;

delayed_data:  ss LB constant_mintypmax_expression RB
            |  ss
          ;

delayed_reference:  ss LB constant_mintypmax_expression RB
                 | ss
                 ;
end_edge_offset: mintypmax_expression
        ;
event_based_flag:constant_expression
        ;
notifier:  ss
       ;
reference_event:timing_check_event
        ;
remain_active_flag: constant_mintypmax_expression
        ;
timestamp_condition:mintypmax_expression
       ;
start_edge_offset:mintypmax_expression
        ;
threshold: constant_expression
       ;
timing_check_limit: mintypmax_expression
      ;
// ------- System timing check event definitions -------------

timing_check_event: timing_check_event_control? specify_terminal_descriptor (ANDANDAND timing_check_condition )?
                     ;

controlled_timing_check_event: timing_check_event_control specify_terminal_descriptor (  ANDANDAND timing_check_condition )?
                          ;

timing_check_event_control: T_POSEDGE
                             | T_NEGEDGE
                             | edge_control_specifier
                             | T_EDGE
          ;

specify_terminal_descriptor: specify_input_terminal_descriptor
                           // | Specify_output_terminal_descriptor
        ;

edge_control_specifier: T_EDGE ( edge_descriptor (COMMA edge_descriptor )* )?
           ;
edge_descriptor:  number ss
                   | ss number
                   | number
                   ;

timing_check_condition: LP scalar_timing_check_condition RP
                       |  scalar_timing_check_condition
    ;

scalar_timing_check_condition:  SQUIG expression
                              | expression ( EQEQ | EQEQEQ | NE | NEE)  scalar_constant
                              | expression
                               ;

scalar_constant: number
   ;

// ---------------- Concatenations  ------------------------

concatenation: LC expression ( COMMA expression )* RC
             ;
constant_concatenation: LC constant_expression ( COMMA constant_expression )* RC
              ;

constant_multiple_concatenation: LC constant_expression constant_concatenation RC
                   ;
module_path_concatenation: LC module_path_expression ( COMMA module_path_expression )* RC
                   ;
module_path_multiple_concatenation: LC constant_expression module_path_concatenation RC
                ;
multiple_concatenation:  LC expression concatenation RC
               ;
streaming_concatenation:  LC stream_operator  slice_size  stream_concatenation RC
                         | LC stream_operator  stream_concatenation RC
                         ;
stream_operator: GTGT
                 | LTLT
                ;

slice_size: simple_type
             | constant_expression
             ;

stream_concatenation: LC stream_expression ( COMMA stream_expression )* RC
      ;
stream_expression: expression (T_WITH LB array_range_expression RB )?
              ;
array_range_expression:  expression (( COLON | PLUSCOLON | MCOLON ) expression)?
              ;
empty_queue: LC RC
          ;
// ------------- Subroutine calls --------------------------------



tf_call:    (method_name | class_scope) ( LP list_of_arguments RP )? (array_manipulation_call | method_call)?
         //   | class_scope method_name  ( LP (list_of_arguments)? RP )? (array_manipulation_call | method_call)?
          | ( (method_name | implicit_class_handle ) (DOT | COLONCOLON)?)?   randomize_call
            ;



method_call: DOT ss (LP list_of_arguments RP)?
            ;
system_tf_call: System_identifier  LP list_of_arguments RP  
                | System_identifier LP data_type (COMMA expression )? RP 
                | System_identifier LP expression ( (COMMA)+  expression )* (COMMA  clocking_event)? RP
                |  System_identifier LP expression (COMMA)+   clocking_event RP
                | System_identifier 
             ;

subroutine_call: tf_call 
                  | ss COLONCOLON  randomize_call 
                  | system_tf_call 
                  ;




argument: expression?;

list_of_arguments
  : expression? (COMMA argument)* (
    COMMA DOT ss LP expression? RP
  )*
  | DOT ss LP expression? RP (
    COMMA DOT ss LP expression? RP
  )*
  ;

//#Array_manipulation_call#: Array_method_name  [ "(" [ List_of_arguments ] ")" ] [ "with" "(" Expression ")" ] {return CURRENT_NODE;}
array_manipulation_call:   T_WITH LP expression RP
                         //  | randomize_call
                        ;

randomize_call: T_RANDOMIZE  LP (variable_identifier_list | T_NULL )? RP  ( T_WITH ( LP ( identifier_list )? RP )? constraint_block )?
              ;

method_name:    (class_scope ) ? hierid select               
                | ss DOT array_method_name
                ;

array_method_name:  T_UNIQUE
                    | T_AND
                    | T_OR
                    | T_XOR
                 //   | T_SAMPLE
                    | T_RANDOMIZE
                    ;
//---------Expressions ---------------------------------------------------------


inc_or_dec_expression: inc_or_dec_operator  variable_lvalue
                       | variable_lvalue  inc_or_dec_operator
    ;

//constant_expression2: (constant_expression constant_expression2)?
         

constant_expression: unary_operator? constant_primary 
                     |  constant_expression binary_operator  constant_expression
                     |  constant_expression QUES   constant_expression COLON constant_expression
                     | constant_expression T_INSIDE LC open_range_list RC 
                     ;

constant_mintypmax_expression: constant_expression ( COLON constant_expression COLON constant_expression)? 
         ;
constant_param_expression: constant_mintypmax_expression
                            | data_type
                            | DOLLAR
                            ;

param_expression:   mintypmax_expression
                   | data_type
                   | DOLLAR
     ;

constant_range_expression: constant_expression
                            | constant_part_select_range
  ;
constant_part_select_range:  constant_range
                           | constant_indexed_range
   ;

constant_range: constant_expression COLON constant_expression 
      ;
constant_indexed_range: constant_expression (PLUSCOLON|MCOLON) constant_expression
     ;
   
expression: unary_operator? primary  
            | LP operator_assignment RP  
            | inc_or_dec_expression 
            | expression (PLUS|MINUS| STAR| SLASH| PER| NE| EQEQEQ| EQEQ| NEE| EQEQQUEST| NEQ| ANDAND| BARBAR| SS| LT| LTEQ| GT| GE| AND| BAR| CARET| SQUIGCARET| CARETSQUIG| GTGT| LTLT| GTGTGT| LTLTLT| ARROW| LTMINUSGT| PLUSPLUS| MINUSMINS | SQUIGBAR | SQUIGAND)  expression 
            |  expression QUES  expression COLON expression
            |  expression T_INSIDE LC open_range_list RC
            | tagged_union_expression 
           ;

  // muss noch weiter bearbeitet werden
conditional_expression:
   <assoc = right> expression QUES  expression COLON expression
   ;

tagged_union_expression: T_TAGGED ss (expression)?
     ;
//Inside_expression#: Expression "inside" ( Open_range_list )
 //    ;
value_range :  LB expression COLON expression RB
              | expression

  ;
mintypmax_expression: expression ( COLON expression COLON expression) ?
   ;
module_path_conditional_expression:  QUES  module_path_expression COLON module_path_expression
     ;
module_path_expression: module_path_primary
                        | unary_module_path_operator  module_path_primary
                        | binary_module_path_operator  module_path_expression
                       // | Module_path_conditional_expression
                        ;

module_path_mintypmax_expression: module_path_expression ( COLON module_path_expression COLON module_path_expression )?
        ;

part_select_range:  constant_range
                    | indexed_range
                   ;

indexed_range: expression (PLUSCOLON | MCOLON ) constant_expression
         ;
genvar_expression: constant_expression
 ;

//--------Primaries----------------------------------------------------------


 

constant_primary: primary_literal
     | subroutine_call
     | LB constant_range_expression RB
     | constant_concatenation ( LB constant_range_expression RB )?
     | constant_multiple_concatenation ( LB constant_range_expression RB )? 
   // | (class_scope )? ss
     |  constant_cast
     | constant_let_expression
     | LP constant_mintypmax_expression RP
     | constant_assignment_pattern_expression
     | type_reference
     | DOLLAR
    ;

module_path_primary: number
    | ss
    | module_path_concatenation
    | module_path_multiple_concatenation
    | subroutine_call
    | LP module_path_mintypmax_expression RP
  ;


primary:   
           primary_literal
       //   | class_qualifier (package_scope)? hierid select
          | tf_call
          | (concatenation | multiple_concatenation )( LB range_expression RB )?
          | streaming_concatenation
          | assignment_pattern_expression
          | system_tf_call 
          | empty_queue
          | sequence_method_call
          | cast
          | T_THIS
          | DOLLAR
          | T_NULL     
          | LP expression (COLON expression COLON expression)? RP
        
    ;

class_qualifier:   ( T_LOCAL COLONCOLON )? ( implicit_class_handle DOT )?
      ;

range_expression:  expression
                    | part_select_range
          ;

primary_literal:   time_literal
                   | number 
                   | UNLIT
                   | String_literal
             
  ;

time_literal: Time_literal
 ;

time_unit: ss
  ;

implicit_class_handle: T_SUPER
                        | T_THIS DOT T_SUPER
                        | T_THIS
   ;

bit_select: ( LB expression RB )*
 ;

//bit_select1: ( LB expression RB )+
// ;

//select:   ( DOT ss  bit_select)+ ( LB part_select_range RB)? 
//            | bit_select  (DOT ss)? ( LB part_select_range RB)? 
//            ;

select : ((DOT ss bit_select)* DOT ss)? bit_select (LB part_select_range RB )?
  ;

nonrange_select: (( DOT ss bit_select )* DOT ss)? bit_select
   ;

constant_bit_select: ( LB constant_expression RB )*
 ;

//constant_bit_select11: LB constant_expression RB
// ;

//constant_select: ((DOT  ss constant_bit_select)* DOT ss)? (  constant_bit_select11 )* (LB constant_part_select_range RB )?
  
  constant_select : ((DOT ss constant_bit_select)* DOT ss)? constant_bit_select ( LB constant_part_select_range RB )?
  ;

  

constant_cast: casting_type QUOTE LP constant_expression RP
 ;

constant_let_expression: let_expression
 ;

cast: casting_type QUOTE LP expression RP
   ;
//------- Expression left-side values -----------------------------------------------------------

net_lvalue: psid constant_select
             | LC net_lvalue ( COMMA  net_lvalue )* RC
             | (assignment_pattern_expression_type )? assignment_pattern_net_lvalue
             ;

variable_lvalue:  ( implicit_class_handle DOT | package_scope )? hierid select 
                   | streaming_concatenation 
                   | LC variable_lvalue ( COMMA variable_lvalue )*  RC
                   | ( assignment_pattern_expression_type )? assignment_pattern_variable_lvalue 
                   ;

nonrange_variable_lvalue: ( implicit_class_handle DOT | package_scope )? hierid
 ;
//-------- Operators ----------------------------------------------------------

unary_operator:
	PLUS
	| MINUS
	| NOT
	| SQUIG
	| AND
	| SQUIGAND
	| BAR
	| SQUIGBAR
	| CARET
	| SQUIGCARET
	| CARETSQUIG
;

binary_operator:
	PLUS
	|MINUS
	| STAR
	| SLASH
	| PER
	| NE
	| EQEQEQ
	| EQEQ
	| NEE
	| EQEQQUEST
	| NEQ
	| ANDAND
	| BARBAR
	| SS
	| LT
	| LTEQ
	| GT
	| GE
	| AND
	| BAR
	| CARET
	| SQUIGCARET
	| CARETSQUIG
	| GTGT
	| LTLT
	| GTGTGT
	| LTLTLT
	| ARROW
	| LTMINUSGT
	| PLUSPLUS
	| MINUSMINS
;

inc_or_dec_operator:
	PLUSPLUS
	|MINUSMINS
;

unary_module_path_operator:
	NOT
	| SQUIG
	| AND
	| SQUIGAND
	| BAR
	| SQUIGBAR
	| CARET
	| SQUIGCARET
	| CARETSQUIG
;

binary_module_path_operator:
	EQEQ
	| NE
	| ANDAND
	| BARBAR
	| AND
	| BAR
	| CARET
	| CARETSQUIG
	| SQUIG
;

number: Realnumber
	| Integer
	| Octal_number
	| Binary_number
	| Hex_number
	| Decimal_number
;

/**
#Attribute_instance#: "(*" Attr_spec ("," Attr_spec)* "*)" {return CURRENT_NODE;}
;

Attr_spec#: SS ( "=" Constant_expression )?
;
*/

package_scope: ss COLONCOLON
                 | DUNIT COLONCOLON
;

psid: (package_scope)? ss
;
/*( (DROOT | implicit_class_handle)  DOT )? */
//hierid1: ( (DROOT | implicit_class_handle)  DOT )? ( ss constant_bit_select  DOT )*  ss 
 //       ;


hierid : ((DROOT | implicit_class_handle) DOT ) ? ss ( (LB constant_expression RB)* DOT ss)*
  ;

ss : Escape_identifier // {doLineCount1($ctx);}
    | Simple_identifier // {doLineCount1($ctx);}
   // | MacroId
    ;

