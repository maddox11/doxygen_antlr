
// Generated from SysVerilog.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "SysVerilogListener.h"


/**
 * This class provides an empty implementation of SysVerilogListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  SysVerilogBaseListener : public SysVerilogListener {
public:

  virtual void enterInclude_path(SysVerilogParser::Include_pathContext * /*ctx*/) override { }
  virtual void exitInclude_path(SysVerilogParser::Include_pathContext * /*ctx*/) override { }

  virtual void enterLibrary_description(SysVerilogParser::Library_descriptionContext * /*ctx*/) override { }
  virtual void exitLibrary_description(SysVerilogParser::Library_descriptionContext * /*ctx*/) override { }

  virtual void enterSource_code(SysVerilogParser::Source_codeContext * /*ctx*/) override { }
  virtual void exitSource_code(SysVerilogParser::Source_codeContext * /*ctx*/) override { }

  virtual void enterDescription(SysVerilogParser::DescriptionContext * /*ctx*/) override { }
  virtual void exitDescription(SysVerilogParser::DescriptionContext * /*ctx*/) override { }

  virtual void enterModule_nonansi_header(SysVerilogParser::Module_nonansi_headerContext * /*ctx*/) override { }
  virtual void exitModule_nonansi_header(SysVerilogParser::Module_nonansi_headerContext * /*ctx*/) override { }

  virtual void enterModule_declaration(SysVerilogParser::Module_declarationContext * /*ctx*/) override { }
  virtual void exitModule_declaration(SysVerilogParser::Module_declarationContext * /*ctx*/) override { }

  virtual void enterModule_keyword(SysVerilogParser::Module_keywordContext * /*ctx*/) override { }
  virtual void exitModule_keyword(SysVerilogParser::Module_keywordContext * /*ctx*/) override { }

  virtual void enterInterface_declaration(SysVerilogParser::Interface_declarationContext * /*ctx*/) override { }
  virtual void exitInterface_declaration(SysVerilogParser::Interface_declarationContext * /*ctx*/) override { }

  virtual void enterInterface_nonansi_header(SysVerilogParser::Interface_nonansi_headerContext * /*ctx*/) override { }
  virtual void exitInterface_nonansi_header(SysVerilogParser::Interface_nonansi_headerContext * /*ctx*/) override { }

  virtual void enterProgram_declaration(SysVerilogParser::Program_declarationContext * /*ctx*/) override { }
  virtual void exitProgram_declaration(SysVerilogParser::Program_declarationContext * /*ctx*/) override { }

  virtual void enterProgram_nonansi_header(SysVerilogParser::Program_nonansi_headerContext * /*ctx*/) override { }
  virtual void exitProgram_nonansi_header(SysVerilogParser::Program_nonansi_headerContext * /*ctx*/) override { }

  virtual void enterChecker_declaration(SysVerilogParser::Checker_declarationContext * /*ctx*/) override { }
  virtual void exitChecker_declaration(SysVerilogParser::Checker_declarationContext * /*ctx*/) override { }

  virtual void enterClass_declaration(SysVerilogParser::Class_declarationContext * /*ctx*/) override { }
  virtual void exitClass_declaration(SysVerilogParser::Class_declarationContext * /*ctx*/) override { }

  virtual void enterInterface_class_type(SysVerilogParser::Interface_class_typeContext * /*ctx*/) override { }
  virtual void exitInterface_class_type(SysVerilogParser::Interface_class_typeContext * /*ctx*/) override { }

  virtual void enterInterface_class_declaration(SysVerilogParser::Interface_class_declarationContext * /*ctx*/) override { }
  virtual void exitInterface_class_declaration(SysVerilogParser::Interface_class_declarationContext * /*ctx*/) override { }

  virtual void enterInterface_class_item(SysVerilogParser::Interface_class_itemContext * /*ctx*/) override { }
  virtual void exitInterface_class_item(SysVerilogParser::Interface_class_itemContext * /*ctx*/) override { }

  virtual void enterInterface_class_method(SysVerilogParser::Interface_class_methodContext * /*ctx*/) override { }
  virtual void exitInterface_class_method(SysVerilogParser::Interface_class_methodContext * /*ctx*/) override { }

  virtual void enterPackage_declaration(SysVerilogParser::Package_declarationContext * /*ctx*/) override { }
  virtual void exitPackage_declaration(SysVerilogParser::Package_declarationContext * /*ctx*/) override { }

  virtual void enterTimeunits_declaration(SysVerilogParser::Timeunits_declarationContext * /*ctx*/) override { }
  virtual void exitTimeunits_declaration(SysVerilogParser::Timeunits_declarationContext * /*ctx*/) override { }

  virtual void enterParameter_port_list(SysVerilogParser::Parameter_port_listContext * /*ctx*/) override { }
  virtual void exitParameter_port_list(SysVerilogParser::Parameter_port_listContext * /*ctx*/) override { }

  virtual void enterParameter_port_declaration(SysVerilogParser::Parameter_port_declarationContext * /*ctx*/) override { }
  virtual void exitParameter_port_declaration(SysVerilogParser::Parameter_port_declarationContext * /*ctx*/) override { }

  virtual void enterParameter_declaration(SysVerilogParser::Parameter_declarationContext * /*ctx*/) override { }
  virtual void exitParameter_declaration(SysVerilogParser::Parameter_declarationContext * /*ctx*/) override { }

  virtual void enterList_of_ports(SysVerilogParser::List_of_portsContext * /*ctx*/) override { }
  virtual void exitList_of_ports(SysVerilogParser::List_of_portsContext * /*ctx*/) override { }

  virtual void enterList_of_port_declarations(SysVerilogParser::List_of_port_declarationsContext * /*ctx*/) override { }
  virtual void exitList_of_port_declarations(SysVerilogParser::List_of_port_declarationsContext * /*ctx*/) override { }

  virtual void enterParam_assignment(SysVerilogParser::Param_assignmentContext * /*ctx*/) override { }
  virtual void exitParam_assignment(SysVerilogParser::Param_assignmentContext * /*ctx*/) override { }

  virtual void enterList_of_param_assignments(SysVerilogParser::List_of_param_assignmentsContext * /*ctx*/) override { }
  virtual void exitList_of_param_assignments(SysVerilogParser::List_of_param_assignmentsContext * /*ctx*/) override { }

  virtual void enterPort_declaration(SysVerilogParser::Port_declarationContext * /*ctx*/) override { }
  virtual void exitPort_declaration(SysVerilogParser::Port_declarationContext * /*ctx*/) override { }

  virtual void enterPort(SysVerilogParser::PortContext * /*ctx*/) override { }
  virtual void exitPort(SysVerilogParser::PortContext * /*ctx*/) override { }

  virtual void enterPort_expression(SysVerilogParser::Port_expressionContext * /*ctx*/) override { }
  virtual void exitPort_expression(SysVerilogParser::Port_expressionContext * /*ctx*/) override { }

  virtual void enterPort_reference(SysVerilogParser::Port_referenceContext * /*ctx*/) override { }
  virtual void exitPort_reference(SysVerilogParser::Port_referenceContext * /*ctx*/) override { }

  virtual void enterPort_direction(SysVerilogParser::Port_directionContext * /*ctx*/) override { }
  virtual void exitPort_direction(SysVerilogParser::Port_directionContext * /*ctx*/) override { }

  virtual void enterNet_port_header(SysVerilogParser::Net_port_headerContext * /*ctx*/) override { }
  virtual void exitNet_port_header(SysVerilogParser::Net_port_headerContext * /*ctx*/) override { }

  virtual void enterVariable_port_header(SysVerilogParser::Variable_port_headerContext * /*ctx*/) override { }
  virtual void exitVariable_port_header(SysVerilogParser::Variable_port_headerContext * /*ctx*/) override { }

  virtual void enterInterface_port_header(SysVerilogParser::Interface_port_headerContext * /*ctx*/) override { }
  virtual void exitInterface_port_header(SysVerilogParser::Interface_port_headerContext * /*ctx*/) override { }

  virtual void enterAnsi_port_declaration(SysVerilogParser::Ansi_port_declarationContext * /*ctx*/) override { }
  virtual void exitAnsi_port_declaration(SysVerilogParser::Ansi_port_declarationContext * /*ctx*/) override { }

  virtual void enterElaboration_system_task(SysVerilogParser::Elaboration_system_taskContext * /*ctx*/) override { }
  virtual void exitElaboration_system_task(SysVerilogParser::Elaboration_system_taskContext * /*ctx*/) override { }

  virtual void enterFinish_number(SysVerilogParser::Finish_numberContext * /*ctx*/) override { }
  virtual void exitFinish_number(SysVerilogParser::Finish_numberContext * /*ctx*/) override { }

  virtual void enterModule_common_item(SysVerilogParser::Module_common_itemContext * /*ctx*/) override { }
  virtual void exitModule_common_item(SysVerilogParser::Module_common_itemContext * /*ctx*/) override { }

  virtual void enterModule_item(SysVerilogParser::Module_itemContext * /*ctx*/) override { }
  virtual void exitModule_item(SysVerilogParser::Module_itemContext * /*ctx*/) override { }

  virtual void enterModule_or_generate_item(SysVerilogParser::Module_or_generate_itemContext * /*ctx*/) override { }
  virtual void exitModule_or_generate_item(SysVerilogParser::Module_or_generate_itemContext * /*ctx*/) override { }

  virtual void enterModule_or_generate_item_declaration(SysVerilogParser::Module_or_generate_item_declarationContext * /*ctx*/) override { }
  virtual void exitModule_or_generate_item_declaration(SysVerilogParser::Module_or_generate_item_declarationContext * /*ctx*/) override { }

  virtual void enterNon_port_module_item(SysVerilogParser::Non_port_module_itemContext * /*ctx*/) override { }
  virtual void exitNon_port_module_item(SysVerilogParser::Non_port_module_itemContext * /*ctx*/) override { }

  virtual void enterParameter_override(SysVerilogParser::Parameter_overrideContext * /*ctx*/) override { }
  virtual void exitParameter_override(SysVerilogParser::Parameter_overrideContext * /*ctx*/) override { }

  virtual void enterBind_directive(SysVerilogParser::Bind_directiveContext * /*ctx*/) override { }
  virtual void exitBind_directive(SysVerilogParser::Bind_directiveContext * /*ctx*/) override { }

  virtual void enterBind_target_instance(SysVerilogParser::Bind_target_instanceContext * /*ctx*/) override { }
  virtual void exitBind_target_instance(SysVerilogParser::Bind_target_instanceContext * /*ctx*/) override { }

  virtual void enterBind_target_instance_list(SysVerilogParser::Bind_target_instance_listContext * /*ctx*/) override { }
  virtual void exitBind_target_instance_list(SysVerilogParser::Bind_target_instance_listContext * /*ctx*/) override { }

  virtual void enterBind_instantiation(SysVerilogParser::Bind_instantiationContext * /*ctx*/) override { }
  virtual void exitBind_instantiation(SysVerilogParser::Bind_instantiationContext * /*ctx*/) override { }

  virtual void enterConfig_declaration(SysVerilogParser::Config_declarationContext * /*ctx*/) override { }
  virtual void exitConfig_declaration(SysVerilogParser::Config_declarationContext * /*ctx*/) override { }

  virtual void enterDesign_statement(SysVerilogParser::Design_statementContext * /*ctx*/) override { }
  virtual void exitDesign_statement(SysVerilogParser::Design_statementContext * /*ctx*/) override { }

  virtual void enterConfig_rule_statement(SysVerilogParser::Config_rule_statementContext * /*ctx*/) override { }
  virtual void exitConfig_rule_statement(SysVerilogParser::Config_rule_statementContext * /*ctx*/) override { }

  virtual void enterDefault_clause(SysVerilogParser::Default_clauseContext * /*ctx*/) override { }
  virtual void exitDefault_clause(SysVerilogParser::Default_clauseContext * /*ctx*/) override { }

  virtual void enterInst_clause(SysVerilogParser::Inst_clauseContext * /*ctx*/) override { }
  virtual void exitInst_clause(SysVerilogParser::Inst_clauseContext * /*ctx*/) override { }

  virtual void enterInst_name(SysVerilogParser::Inst_nameContext * /*ctx*/) override { }
  virtual void exitInst_name(SysVerilogParser::Inst_nameContext * /*ctx*/) override { }

  virtual void enterCell_clause(SysVerilogParser::Cell_clauseContext * /*ctx*/) override { }
  virtual void exitCell_clause(SysVerilogParser::Cell_clauseContext * /*ctx*/) override { }

  virtual void enterLiblist_clause(SysVerilogParser::Liblist_clauseContext * /*ctx*/) override { }
  virtual void exitLiblist_clause(SysVerilogParser::Liblist_clauseContext * /*ctx*/) override { }

  virtual void enterUse_clause(SysVerilogParser::Use_clauseContext * /*ctx*/) override { }
  virtual void exitUse_clause(SysVerilogParser::Use_clauseContext * /*ctx*/) override { }

  virtual void enterInterface_or_generate_item(SysVerilogParser::Interface_or_generate_itemContext * /*ctx*/) override { }
  virtual void exitInterface_or_generate_item(SysVerilogParser::Interface_or_generate_itemContext * /*ctx*/) override { }

  virtual void enterExtern_tf_declaration(SysVerilogParser::Extern_tf_declarationContext * /*ctx*/) override { }
  virtual void exitExtern_tf_declaration(SysVerilogParser::Extern_tf_declarationContext * /*ctx*/) override { }

  virtual void enterInterface_item(SysVerilogParser::Interface_itemContext * /*ctx*/) override { }
  virtual void exitInterface_item(SysVerilogParser::Interface_itemContext * /*ctx*/) override { }

  virtual void enterNon_port_interface_item(SysVerilogParser::Non_port_interface_itemContext * /*ctx*/) override { }
  virtual void exitNon_port_interface_item(SysVerilogParser::Non_port_interface_itemContext * /*ctx*/) override { }

  virtual void enterProgram_item(SysVerilogParser::Program_itemContext * /*ctx*/) override { }
  virtual void exitProgram_item(SysVerilogParser::Program_itemContext * /*ctx*/) override { }

  virtual void enterNon_port_program_item(SysVerilogParser::Non_port_program_itemContext * /*ctx*/) override { }
  virtual void exitNon_port_program_item(SysVerilogParser::Non_port_program_itemContext * /*ctx*/) override { }

  virtual void enterProgram_generate_item(SysVerilogParser::Program_generate_itemContext * /*ctx*/) override { }
  virtual void exitProgram_generate_item(SysVerilogParser::Program_generate_itemContext * /*ctx*/) override { }

  virtual void enterChecker_port_list(SysVerilogParser::Checker_port_listContext * /*ctx*/) override { }
  virtual void exitChecker_port_list(SysVerilogParser::Checker_port_listContext * /*ctx*/) override { }

  virtual void enterChecker_port_item(SysVerilogParser::Checker_port_itemContext * /*ctx*/) override { }
  virtual void exitChecker_port_item(SysVerilogParser::Checker_port_itemContext * /*ctx*/) override { }

  virtual void enterChecker_port_direction(SysVerilogParser::Checker_port_directionContext * /*ctx*/) override { }
  virtual void exitChecker_port_direction(SysVerilogParser::Checker_port_directionContext * /*ctx*/) override { }

  virtual void enterChecker_or_generate_item(SysVerilogParser::Checker_or_generate_itemContext * /*ctx*/) override { }
  virtual void exitChecker_or_generate_item(SysVerilogParser::Checker_or_generate_itemContext * /*ctx*/) override { }

  virtual void enterChecker_or_generate_item_declaration(SysVerilogParser::Checker_or_generate_item_declarationContext * /*ctx*/) override { }
  virtual void exitChecker_or_generate_item_declaration(SysVerilogParser::Checker_or_generate_item_declarationContext * /*ctx*/) override { }

  virtual void enterChecker_generate_item(SysVerilogParser::Checker_generate_itemContext * /*ctx*/) override { }
  virtual void exitChecker_generate_item(SysVerilogParser::Checker_generate_itemContext * /*ctx*/) override { }

  virtual void enterClass_item(SysVerilogParser::Class_itemContext * /*ctx*/) override { }
  virtual void exitClass_item(SysVerilogParser::Class_itemContext * /*ctx*/) override { }

  virtual void enterClass_property(SysVerilogParser::Class_propertyContext * /*ctx*/) override { }
  virtual void exitClass_property(SysVerilogParser::Class_propertyContext * /*ctx*/) override { }

  virtual void enterClass_method(SysVerilogParser::Class_methodContext * /*ctx*/) override { }
  virtual void exitClass_method(SysVerilogParser::Class_methodContext * /*ctx*/) override { }

  virtual void enterClass_constructor_prototype(SysVerilogParser::Class_constructor_prototypeContext * /*ctx*/) override { }
  virtual void exitClass_constructor_prototype(SysVerilogParser::Class_constructor_prototypeContext * /*ctx*/) override { }

  virtual void enterClass_constraint(SysVerilogParser::Class_constraintContext * /*ctx*/) override { }
  virtual void exitClass_constraint(SysVerilogParser::Class_constraintContext * /*ctx*/) override { }

  virtual void enterClass_item_qualifier(SysVerilogParser::Class_item_qualifierContext * /*ctx*/) override { }
  virtual void exitClass_item_qualifier(SysVerilogParser::Class_item_qualifierContext * /*ctx*/) override { }

  virtual void enterProperty_qualifier(SysVerilogParser::Property_qualifierContext * /*ctx*/) override { }
  virtual void exitProperty_qualifier(SysVerilogParser::Property_qualifierContext * /*ctx*/) override { }

  virtual void enterRandom_qualifier(SysVerilogParser::Random_qualifierContext * /*ctx*/) override { }
  virtual void exitRandom_qualifier(SysVerilogParser::Random_qualifierContext * /*ctx*/) override { }

  virtual void enterMethod_qualifier(SysVerilogParser::Method_qualifierContext * /*ctx*/) override { }
  virtual void exitMethod_qualifier(SysVerilogParser::Method_qualifierContext * /*ctx*/) override { }

  virtual void enterMethod_prototype(SysVerilogParser::Method_prototypeContext * /*ctx*/) override { }
  virtual void exitMethod_prototype(SysVerilogParser::Method_prototypeContext * /*ctx*/) override { }

  virtual void enterClass_constructor_declaration(SysVerilogParser::Class_constructor_declarationContext * /*ctx*/) override { }
  virtual void exitClass_constructor_declaration(SysVerilogParser::Class_constructor_declarationContext * /*ctx*/) override { }

  virtual void enterConstraint_declaration(SysVerilogParser::Constraint_declarationContext * /*ctx*/) override { }
  virtual void exitConstraint_declaration(SysVerilogParser::Constraint_declarationContext * /*ctx*/) override { }

  virtual void enterConstraint_block(SysVerilogParser::Constraint_blockContext * /*ctx*/) override { }
  virtual void exitConstraint_block(SysVerilogParser::Constraint_blockContext * /*ctx*/) override { }

  virtual void enterConstraint_block_item(SysVerilogParser::Constraint_block_itemContext * /*ctx*/) override { }
  virtual void exitConstraint_block_item(SysVerilogParser::Constraint_block_itemContext * /*ctx*/) override { }

  virtual void enterSolve_before_list(SysVerilogParser::Solve_before_listContext * /*ctx*/) override { }
  virtual void exitSolve_before_list(SysVerilogParser::Solve_before_listContext * /*ctx*/) override { }

  virtual void enterConstraint_primary(SysVerilogParser::Constraint_primaryContext * /*ctx*/) override { }
  virtual void exitConstraint_primary(SysVerilogParser::Constraint_primaryContext * /*ctx*/) override { }

  virtual void enterConstraint_expression(SysVerilogParser::Constraint_expressionContext * /*ctx*/) override { }
  virtual void exitConstraint_expression(SysVerilogParser::Constraint_expressionContext * /*ctx*/) override { }

  virtual void enterUniqueness_constraint(SysVerilogParser::Uniqueness_constraintContext * /*ctx*/) override { }
  virtual void exitUniqueness_constraint(SysVerilogParser::Uniqueness_constraintContext * /*ctx*/) override { }

  virtual void enterConstraint_set(SysVerilogParser::Constraint_setContext * /*ctx*/) override { }
  virtual void exitConstraint_set(SysVerilogParser::Constraint_setContext * /*ctx*/) override { }

  virtual void enterDist_list(SysVerilogParser::Dist_listContext * /*ctx*/) override { }
  virtual void exitDist_list(SysVerilogParser::Dist_listContext * /*ctx*/) override { }

  virtual void enterDist_item(SysVerilogParser::Dist_itemContext * /*ctx*/) override { }
  virtual void exitDist_item(SysVerilogParser::Dist_itemContext * /*ctx*/) override { }

  virtual void enterDist_weight(SysVerilogParser::Dist_weightContext * /*ctx*/) override { }
  virtual void exitDist_weight(SysVerilogParser::Dist_weightContext * /*ctx*/) override { }

  virtual void enterConstraint_prototype(SysVerilogParser::Constraint_prototypeContext * /*ctx*/) override { }
  virtual void exitConstraint_prototype(SysVerilogParser::Constraint_prototypeContext * /*ctx*/) override { }

  virtual void enterConstraint_prototype_qualifier(SysVerilogParser::Constraint_prototype_qualifierContext * /*ctx*/) override { }
  virtual void exitConstraint_prototype_qualifier(SysVerilogParser::Constraint_prototype_qualifierContext * /*ctx*/) override { }

  virtual void enterExtern_constraint_declaration(SysVerilogParser::Extern_constraint_declarationContext * /*ctx*/) override { }
  virtual void exitExtern_constraint_declaration(SysVerilogParser::Extern_constraint_declarationContext * /*ctx*/) override { }

  virtual void enterIdentifier_list(SysVerilogParser::Identifier_listContext * /*ctx*/) override { }
  virtual void exitIdentifier_list(SysVerilogParser::Identifier_listContext * /*ctx*/) override { }

  virtual void enterPackage_item(SysVerilogParser::Package_itemContext * /*ctx*/) override { }
  virtual void exitPackage_item(SysVerilogParser::Package_itemContext * /*ctx*/) override { }

  virtual void enterPackage_or_generate_item_declaration(SysVerilogParser::Package_or_generate_item_declarationContext * /*ctx*/) override { }
  virtual void exitPackage_or_generate_item_declaration(SysVerilogParser::Package_or_generate_item_declarationContext * /*ctx*/) override { }

  virtual void enterAnonymous_program(SysVerilogParser::Anonymous_programContext * /*ctx*/) override { }
  virtual void exitAnonymous_program(SysVerilogParser::Anonymous_programContext * /*ctx*/) override { }

  virtual void enterAnonymous_program_item(SysVerilogParser::Anonymous_program_itemContext * /*ctx*/) override { }
  virtual void exitAnonymous_program_item(SysVerilogParser::Anonymous_program_itemContext * /*ctx*/) override { }

  virtual void enterLocal_parameter_declaration(SysVerilogParser::Local_parameter_declarationContext * /*ctx*/) override { }
  virtual void exitLocal_parameter_declaration(SysVerilogParser::Local_parameter_declarationContext * /*ctx*/) override { }

  virtual void enterSpecparam_declaration(SysVerilogParser::Specparam_declarationContext * /*ctx*/) override { }
  virtual void exitSpecparam_declaration(SysVerilogParser::Specparam_declarationContext * /*ctx*/) override { }

  virtual void enterInout_declaration(SysVerilogParser::Inout_declarationContext * /*ctx*/) override { }
  virtual void exitInout_declaration(SysVerilogParser::Inout_declarationContext * /*ctx*/) override { }

  virtual void enterInput_declaration(SysVerilogParser::Input_declarationContext * /*ctx*/) override { }
  virtual void exitInput_declaration(SysVerilogParser::Input_declarationContext * /*ctx*/) override { }

  virtual void enterOutput_declaration(SysVerilogParser::Output_declarationContext * /*ctx*/) override { }
  virtual void exitOutput_declaration(SysVerilogParser::Output_declarationContext * /*ctx*/) override { }

  virtual void enterInterface_port_declaration(SysVerilogParser::Interface_port_declarationContext * /*ctx*/) override { }
  virtual void exitInterface_port_declaration(SysVerilogParser::Interface_port_declarationContext * /*ctx*/) override { }

  virtual void enterRef_declaration(SysVerilogParser::Ref_declarationContext * /*ctx*/) override { }
  virtual void exitRef_declaration(SysVerilogParser::Ref_declarationContext * /*ctx*/) override { }

  virtual void enterUuu(SysVerilogParser::UuuContext * /*ctx*/) override { }
  virtual void exitUuu(SysVerilogParser::UuuContext * /*ctx*/) override { }

  virtual void enterData_declaration(SysVerilogParser::Data_declarationContext * /*ctx*/) override { }
  virtual void exitData_declaration(SysVerilogParser::Data_declarationContext * /*ctx*/) override { }

  virtual void enterPackage_import_declaration(SysVerilogParser::Package_import_declarationContext * /*ctx*/) override { }
  virtual void exitPackage_import_declaration(SysVerilogParser::Package_import_declarationContext * /*ctx*/) override { }

  virtual void enterPackage_import_item(SysVerilogParser::Package_import_itemContext * /*ctx*/) override { }
  virtual void exitPackage_import_item(SysVerilogParser::Package_import_itemContext * /*ctx*/) override { }

  virtual void enterPackage_export_declaration(SysVerilogParser::Package_export_declarationContext * /*ctx*/) override { }
  virtual void exitPackage_export_declaration(SysVerilogParser::Package_export_declarationContext * /*ctx*/) override { }

  virtual void enterGenvar_declaration(SysVerilogParser::Genvar_declarationContext * /*ctx*/) override { }
  virtual void exitGenvar_declaration(SysVerilogParser::Genvar_declarationContext * /*ctx*/) override { }

  virtual void enterNet_declaration(SysVerilogParser::Net_declarationContext * /*ctx*/) override { }
  virtual void exitNet_declaration(SysVerilogParser::Net_declarationContext * /*ctx*/) override { }

  virtual void enterType_declaration(SysVerilogParser::Type_declarationContext * /*ctx*/) override { }
  virtual void exitType_declaration(SysVerilogParser::Type_declarationContext * /*ctx*/) override { }

  virtual void enterNet_type_declaration(SysVerilogParser::Net_type_declarationContext * /*ctx*/) override { }
  virtual void exitNet_type_declaration(SysVerilogParser::Net_type_declarationContext * /*ctx*/) override { }

  virtual void enterLifetime(SysVerilogParser::LifetimeContext * /*ctx*/) override { }
  virtual void exitLifetime(SysVerilogParser::LifetimeContext * /*ctx*/) override { }

  virtual void enterCasting_type(SysVerilogParser::Casting_typeContext * /*ctx*/) override { }
  virtual void exitCasting_type(SysVerilogParser::Casting_typeContext * /*ctx*/) override { }

  virtual void enterData_type(SysVerilogParser::Data_typeContext * /*ctx*/) override { }
  virtual void exitData_type(SysVerilogParser::Data_typeContext * /*ctx*/) override { }

  virtual void enterData_type_or_implicit(SysVerilogParser::Data_type_or_implicitContext * /*ctx*/) override { }
  virtual void exitData_type_or_implicit(SysVerilogParser::Data_type_or_implicitContext * /*ctx*/) override { }

  virtual void enterData_type_or_implicit1(SysVerilogParser::Data_type_or_implicit1Context * /*ctx*/) override { }
  virtual void exitData_type_or_implicit1(SysVerilogParser::Data_type_or_implicit1Context * /*ctx*/) override { }

  virtual void enterImplicit_data_type(SysVerilogParser::Implicit_data_typeContext * /*ctx*/) override { }
  virtual void exitImplicit_data_type(SysVerilogParser::Implicit_data_typeContext * /*ctx*/) override { }

  virtual void enterEnum_base_type(SysVerilogParser::Enum_base_typeContext * /*ctx*/) override { }
  virtual void exitEnum_base_type(SysVerilogParser::Enum_base_typeContext * /*ctx*/) override { }

  virtual void enterEnum_name_declaration(SysVerilogParser::Enum_name_declarationContext * /*ctx*/) override { }
  virtual void exitEnum_name_declaration(SysVerilogParser::Enum_name_declarationContext * /*ctx*/) override { }

  virtual void enterClass_scope(SysVerilogParser::Class_scopeContext * /*ctx*/) override { }
  virtual void exitClass_scope(SysVerilogParser::Class_scopeContext * /*ctx*/) override { }

  virtual void enterClass_type1(SysVerilogParser::Class_type1Context * /*ctx*/) override { }
  virtual void exitClass_type1(SysVerilogParser::Class_type1Context * /*ctx*/) override { }

  virtual void enterClass_type(SysVerilogParser::Class_typeContext * /*ctx*/) override { }
  virtual void exitClass_type(SysVerilogParser::Class_typeContext * /*ctx*/) override { }

  virtual void enterInteger_type(SysVerilogParser::Integer_typeContext * /*ctx*/) override { }
  virtual void exitInteger_type(SysVerilogParser::Integer_typeContext * /*ctx*/) override { }

  virtual void enterInteger_atom_type(SysVerilogParser::Integer_atom_typeContext * /*ctx*/) override { }
  virtual void exitInteger_atom_type(SysVerilogParser::Integer_atom_typeContext * /*ctx*/) override { }

  virtual void enterInteger_vector_type(SysVerilogParser::Integer_vector_typeContext * /*ctx*/) override { }
  virtual void exitInteger_vector_type(SysVerilogParser::Integer_vector_typeContext * /*ctx*/) override { }

  virtual void enterNon_integer_type(SysVerilogParser::Non_integer_typeContext * /*ctx*/) override { }
  virtual void exitNon_integer_type(SysVerilogParser::Non_integer_typeContext * /*ctx*/) override { }

  virtual void enterNet_type(SysVerilogParser::Net_typeContext * /*ctx*/) override { }
  virtual void exitNet_type(SysVerilogParser::Net_typeContext * /*ctx*/) override { }

  virtual void enterNet_port_type(SysVerilogParser::Net_port_typeContext * /*ctx*/) override { }
  virtual void exitNet_port_type(SysVerilogParser::Net_port_typeContext * /*ctx*/) override { }

  virtual void enterVariable_port_type(SysVerilogParser::Variable_port_typeContext * /*ctx*/) override { }
  virtual void exitVariable_port_type(SysVerilogParser::Variable_port_typeContext * /*ctx*/) override { }

  virtual void enterVar_data_type(SysVerilogParser::Var_data_typeContext * /*ctx*/) override { }
  virtual void exitVar_data_type(SysVerilogParser::Var_data_typeContext * /*ctx*/) override { }

  virtual void enterSigning(SysVerilogParser::SigningContext * /*ctx*/) override { }
  virtual void exitSigning(SysVerilogParser::SigningContext * /*ctx*/) override { }

  virtual void enterSimple_type(SysVerilogParser::Simple_typeContext * /*ctx*/) override { }
  virtual void exitSimple_type(SysVerilogParser::Simple_typeContext * /*ctx*/) override { }

  virtual void enterStruct_union_member(SysVerilogParser::Struct_union_memberContext * /*ctx*/) override { }
  virtual void exitStruct_union_member(SysVerilogParser::Struct_union_memberContext * /*ctx*/) override { }

  virtual void enterData_type_or_void(SysVerilogParser::Data_type_or_voidContext * /*ctx*/) override { }
  virtual void exitData_type_or_void(SysVerilogParser::Data_type_or_voidContext * /*ctx*/) override { }

  virtual void enterStruct_union(SysVerilogParser::Struct_unionContext * /*ctx*/) override { }
  virtual void exitStruct_union(SysVerilogParser::Struct_unionContext * /*ctx*/) override { }

  virtual void enterType_reference(SysVerilogParser::Type_referenceContext * /*ctx*/) override { }
  virtual void exitType_reference(SysVerilogParser::Type_referenceContext * /*ctx*/) override { }

  virtual void enterDrive_strength(SysVerilogParser::Drive_strengthContext * /*ctx*/) override { }
  virtual void exitDrive_strength(SysVerilogParser::Drive_strengthContext * /*ctx*/) override { }

  virtual void enterStrength0(SysVerilogParser::Strength0Context * /*ctx*/) override { }
  virtual void exitStrength0(SysVerilogParser::Strength0Context * /*ctx*/) override { }

  virtual void enterStrength1(SysVerilogParser::Strength1Context * /*ctx*/) override { }
  virtual void exitStrength1(SysVerilogParser::Strength1Context * /*ctx*/) override { }

  virtual void enterCharge_strength(SysVerilogParser::Charge_strengthContext * /*ctx*/) override { }
  virtual void exitCharge_strength(SysVerilogParser::Charge_strengthContext * /*ctx*/) override { }

  virtual void enterDelay3(SysVerilogParser::Delay3Context * /*ctx*/) override { }
  virtual void exitDelay3(SysVerilogParser::Delay3Context * /*ctx*/) override { }

  virtual void enterDelay2(SysVerilogParser::Delay2Context * /*ctx*/) override { }
  virtual void exitDelay2(SysVerilogParser::Delay2Context * /*ctx*/) override { }

  virtual void enterDelay_value(SysVerilogParser::Delay_valueContext * /*ctx*/) override { }
  virtual void exitDelay_value(SysVerilogParser::Delay_valueContext * /*ctx*/) override { }

  virtual void enterList_of_defparam_assignments(SysVerilogParser::List_of_defparam_assignmentsContext * /*ctx*/) override { }
  virtual void exitList_of_defparam_assignments(SysVerilogParser::List_of_defparam_assignmentsContext * /*ctx*/) override { }

  virtual void enterList_of_genvar_identifiers(SysVerilogParser::List_of_genvar_identifiersContext * /*ctx*/) override { }
  virtual void exitList_of_genvar_identifiers(SysVerilogParser::List_of_genvar_identifiersContext * /*ctx*/) override { }

  virtual void enterList_of_interface_identifiers(SysVerilogParser::List_of_interface_identifiersContext * /*ctx*/) override { }
  virtual void exitList_of_interface_identifiers(SysVerilogParser::List_of_interface_identifiersContext * /*ctx*/) override { }

  virtual void enterList_of_net_decl_assignments(SysVerilogParser::List_of_net_decl_assignmentsContext * /*ctx*/) override { }
  virtual void exitList_of_net_decl_assignments(SysVerilogParser::List_of_net_decl_assignmentsContext * /*ctx*/) override { }

  virtual void enterList_of_port_identifiers(SysVerilogParser::List_of_port_identifiersContext * /*ctx*/) override { }
  virtual void exitList_of_port_identifiers(SysVerilogParser::List_of_port_identifiersContext * /*ctx*/) override { }

  virtual void enterList_of_udp_port_identifiers(SysVerilogParser::List_of_udp_port_identifiersContext * /*ctx*/) override { }
  virtual void exitList_of_udp_port_identifiers(SysVerilogParser::List_of_udp_port_identifiersContext * /*ctx*/) override { }

  virtual void enterList_of_specparam_assignments(SysVerilogParser::List_of_specparam_assignmentsContext * /*ctx*/) override { }
  virtual void exitList_of_specparam_assignments(SysVerilogParser::List_of_specparam_assignmentsContext * /*ctx*/) override { }

  virtual void enterList_of_tf_variable_identifiers(SysVerilogParser::List_of_tf_variable_identifiersContext * /*ctx*/) override { }
  virtual void exitList_of_tf_variable_identifiers(SysVerilogParser::List_of_tf_variable_identifiersContext * /*ctx*/) override { }

  virtual void enterList_of_type_assignments(SysVerilogParser::List_of_type_assignmentsContext * /*ctx*/) override { }
  virtual void exitList_of_type_assignments(SysVerilogParser::List_of_type_assignmentsContext * /*ctx*/) override { }

  virtual void enterList_of_variable_decl_assignments(SysVerilogParser::List_of_variable_decl_assignmentsContext * /*ctx*/) override { }
  virtual void exitList_of_variable_decl_assignments(SysVerilogParser::List_of_variable_decl_assignmentsContext * /*ctx*/) override { }

  virtual void enterList_of_variable_identifiers(SysVerilogParser::List_of_variable_identifiersContext * /*ctx*/) override { }
  virtual void exitList_of_variable_identifiers(SysVerilogParser::List_of_variable_identifiersContext * /*ctx*/) override { }

  virtual void enterList_of_variable_port_identifiers(SysVerilogParser::List_of_variable_port_identifiersContext * /*ctx*/) override { }
  virtual void exitList_of_variable_port_identifiers(SysVerilogParser::List_of_variable_port_identifiersContext * /*ctx*/) override { }

  virtual void enterPort_id(SysVerilogParser::Port_idContext * /*ctx*/) override { }
  virtual void exitPort_id(SysVerilogParser::Port_idContext * /*ctx*/) override { }

  virtual void enterDefparam_assignment(SysVerilogParser::Defparam_assignmentContext * /*ctx*/) override { }
  virtual void exitDefparam_assignment(SysVerilogParser::Defparam_assignmentContext * /*ctx*/) override { }

  virtual void enterNet_decl_assignment(SysVerilogParser::Net_decl_assignmentContext * /*ctx*/) override { }
  virtual void exitNet_decl_assignment(SysVerilogParser::Net_decl_assignmentContext * /*ctx*/) override { }

  virtual void enterSpecparam_assignment(SysVerilogParser::Specparam_assignmentContext * /*ctx*/) override { }
  virtual void exitSpecparam_assignment(SysVerilogParser::Specparam_assignmentContext * /*ctx*/) override { }

  virtual void enterType_assignment(SysVerilogParser::Type_assignmentContext * /*ctx*/) override { }
  virtual void exitType_assignment(SysVerilogParser::Type_assignmentContext * /*ctx*/) override { }

  virtual void enterPulse_control_specparam(SysVerilogParser::Pulse_control_specparamContext * /*ctx*/) override { }
  virtual void exitPulse_control_specparam(SysVerilogParser::Pulse_control_specparamContext * /*ctx*/) override { }

  virtual void enterError_limit_value(SysVerilogParser::Error_limit_valueContext * /*ctx*/) override { }
  virtual void exitError_limit_value(SysVerilogParser::Error_limit_valueContext * /*ctx*/) override { }

  virtual void enterReject_limit_value(SysVerilogParser::Reject_limit_valueContext * /*ctx*/) override { }
  virtual void exitReject_limit_value(SysVerilogParser::Reject_limit_valueContext * /*ctx*/) override { }

  virtual void enterLimit_value(SysVerilogParser::Limit_valueContext * /*ctx*/) override { }
  virtual void exitLimit_value(SysVerilogParser::Limit_valueContext * /*ctx*/) override { }

  virtual void enterVariable_decl_assignment(SysVerilogParser::Variable_decl_assignmentContext * /*ctx*/) override { }
  virtual void exitVariable_decl_assignment(SysVerilogParser::Variable_decl_assignmentContext * /*ctx*/) override { }

  virtual void enterClass_new(SysVerilogParser::Class_newContext * /*ctx*/) override { }
  virtual void exitClass_new(SysVerilogParser::Class_newContext * /*ctx*/) override { }

  virtual void enterDynamic_array_new(SysVerilogParser::Dynamic_array_newContext * /*ctx*/) override { }
  virtual void exitDynamic_array_new(SysVerilogParser::Dynamic_array_newContext * /*ctx*/) override { }

  virtual void enterUnpacked_dimension(SysVerilogParser::Unpacked_dimensionContext * /*ctx*/) override { }
  virtual void exitUnpacked_dimension(SysVerilogParser::Unpacked_dimensionContext * /*ctx*/) override { }

  virtual void enterPacked_dimension(SysVerilogParser::Packed_dimensionContext * /*ctx*/) override { }
  virtual void exitPacked_dimension(SysVerilogParser::Packed_dimensionContext * /*ctx*/) override { }

  virtual void enterAssociative_dimension(SysVerilogParser::Associative_dimensionContext * /*ctx*/) override { }
  virtual void exitAssociative_dimension(SysVerilogParser::Associative_dimensionContext * /*ctx*/) override { }

  virtual void enterVariable_dimension(SysVerilogParser::Variable_dimensionContext * /*ctx*/) override { }
  virtual void exitVariable_dimension(SysVerilogParser::Variable_dimensionContext * /*ctx*/) override { }

  virtual void enterQueue_dimension(SysVerilogParser::Queue_dimensionContext * /*ctx*/) override { }
  virtual void exitQueue_dimension(SysVerilogParser::Queue_dimensionContext * /*ctx*/) override { }

  virtual void enterUnsized_dimension(SysVerilogParser::Unsized_dimensionContext * /*ctx*/) override { }
  virtual void exitUnsized_dimension(SysVerilogParser::Unsized_dimensionContext * /*ctx*/) override { }

  virtual void enterFunction_data_type_or_implicit(SysVerilogParser::Function_data_type_or_implicitContext * /*ctx*/) override { }
  virtual void exitFunction_data_type_or_implicit(SysVerilogParser::Function_data_type_or_implicitContext * /*ctx*/) override { }

  virtual void enterFunction_declaration(SysVerilogParser::Function_declarationContext * /*ctx*/) override { }
  virtual void exitFunction_declaration(SysVerilogParser::Function_declarationContext * /*ctx*/) override { }

  virtual void enterFunction_body_declaration(SysVerilogParser::Function_body_declarationContext * /*ctx*/) override { }
  virtual void exitFunction_body_declaration(SysVerilogParser::Function_body_declarationContext * /*ctx*/) override { }

  virtual void enterFunction_dec(SysVerilogParser::Function_decContext * /*ctx*/) override { }
  virtual void exitFunction_dec(SysVerilogParser::Function_decContext * /*ctx*/) override { }

  virtual void enterFunction_prototype(SysVerilogParser::Function_prototypeContext * /*ctx*/) override { }
  virtual void exitFunction_prototype(SysVerilogParser::Function_prototypeContext * /*ctx*/) override { }

  virtual void enterDpi_import_export(SysVerilogParser::Dpi_import_exportContext * /*ctx*/) override { }
  virtual void exitDpi_import_export(SysVerilogParser::Dpi_import_exportContext * /*ctx*/) override { }

  virtual void enterDpi_spec_string(SysVerilogParser::Dpi_spec_stringContext * /*ctx*/) override { }
  virtual void exitDpi_spec_string(SysVerilogParser::Dpi_spec_stringContext * /*ctx*/) override { }

  virtual void enterDpi_function_import_property(SysVerilogParser::Dpi_function_import_propertyContext * /*ctx*/) override { }
  virtual void exitDpi_function_import_property(SysVerilogParser::Dpi_function_import_propertyContext * /*ctx*/) override { }

  virtual void enterDpi_task_import_property(SysVerilogParser::Dpi_task_import_propertyContext * /*ctx*/) override { }
  virtual void exitDpi_task_import_property(SysVerilogParser::Dpi_task_import_propertyContext * /*ctx*/) override { }

  virtual void enterDpi_function_proto(SysVerilogParser::Dpi_function_protoContext * /*ctx*/) override { }
  virtual void exitDpi_function_proto(SysVerilogParser::Dpi_function_protoContext * /*ctx*/) override { }

  virtual void enterDpi_task_proto(SysVerilogParser::Dpi_task_protoContext * /*ctx*/) override { }
  virtual void exitDpi_task_proto(SysVerilogParser::Dpi_task_protoContext * /*ctx*/) override { }

  virtual void enterTask_declaration(SysVerilogParser::Task_declarationContext * /*ctx*/) override { }
  virtual void exitTask_declaration(SysVerilogParser::Task_declarationContext * /*ctx*/) override { }

  virtual void enterTask_body_declaration(SysVerilogParser::Task_body_declarationContext * /*ctx*/) override { }
  virtual void exitTask_body_declaration(SysVerilogParser::Task_body_declarationContext * /*ctx*/) override { }

  virtual void enterTask_decl(SysVerilogParser::Task_declContext * /*ctx*/) override { }
  virtual void exitTask_decl(SysVerilogParser::Task_declContext * /*ctx*/) override { }

  virtual void enterTf_item_declaration(SysVerilogParser::Tf_item_declarationContext * /*ctx*/) override { }
  virtual void exitTf_item_declaration(SysVerilogParser::Tf_item_declarationContext * /*ctx*/) override { }

  virtual void enterTf_port_list(SysVerilogParser::Tf_port_listContext * /*ctx*/) override { }
  virtual void exitTf_port_list(SysVerilogParser::Tf_port_listContext * /*ctx*/) override { }

  virtual void enterTf_port_item(SysVerilogParser::Tf_port_itemContext * /*ctx*/) override { }
  virtual void exitTf_port_item(SysVerilogParser::Tf_port_itemContext * /*ctx*/) override { }

  virtual void enterTf_port_direction(SysVerilogParser::Tf_port_directionContext * /*ctx*/) override { }
  virtual void exitTf_port_direction(SysVerilogParser::Tf_port_directionContext * /*ctx*/) override { }

  virtual void enterTf_port_declaration(SysVerilogParser::Tf_port_declarationContext * /*ctx*/) override { }
  virtual void exitTf_port_declaration(SysVerilogParser::Tf_port_declarationContext * /*ctx*/) override { }

  virtual void enterTask_prototype(SysVerilogParser::Task_prototypeContext * /*ctx*/) override { }
  virtual void exitTask_prototype(SysVerilogParser::Task_prototypeContext * /*ctx*/) override { }

  virtual void enterBlock_item_declaration(SysVerilogParser::Block_item_declarationContext * /*ctx*/) override { }
  virtual void exitBlock_item_declaration(SysVerilogParser::Block_item_declarationContext * /*ctx*/) override { }

  virtual void enterOverload_declaration(SysVerilogParser::Overload_declarationContext * /*ctx*/) override { }
  virtual void exitOverload_declaration(SysVerilogParser::Overload_declarationContext * /*ctx*/) override { }

  virtual void enterOverload_operator(SysVerilogParser::Overload_operatorContext * /*ctx*/) override { }
  virtual void exitOverload_operator(SysVerilogParser::Overload_operatorContext * /*ctx*/) override { }

  virtual void enterOverload_proto_formals(SysVerilogParser::Overload_proto_formalsContext * /*ctx*/) override { }
  virtual void exitOverload_proto_formals(SysVerilogParser::Overload_proto_formalsContext * /*ctx*/) override { }

  virtual void enterModport_declaration(SysVerilogParser::Modport_declarationContext * /*ctx*/) override { }
  virtual void exitModport_declaration(SysVerilogParser::Modport_declarationContext * /*ctx*/) override { }

  virtual void enterModport_item(SysVerilogParser::Modport_itemContext * /*ctx*/) override { }
  virtual void exitModport_item(SysVerilogParser::Modport_itemContext * /*ctx*/) override { }

  virtual void enterModport_ports_declaration(SysVerilogParser::Modport_ports_declarationContext * /*ctx*/) override { }
  virtual void exitModport_ports_declaration(SysVerilogParser::Modport_ports_declarationContext * /*ctx*/) override { }

  virtual void enterModport_clocking_declaration(SysVerilogParser::Modport_clocking_declarationContext * /*ctx*/) override { }
  virtual void exitModport_clocking_declaration(SysVerilogParser::Modport_clocking_declarationContext * /*ctx*/) override { }

  virtual void enterModport_simple_ports_declaration(SysVerilogParser::Modport_simple_ports_declarationContext * /*ctx*/) override { }
  virtual void exitModport_simple_ports_declaration(SysVerilogParser::Modport_simple_ports_declarationContext * /*ctx*/) override { }

  virtual void enterModport_simple_port(SysVerilogParser::Modport_simple_portContext * /*ctx*/) override { }
  virtual void exitModport_simple_port(SysVerilogParser::Modport_simple_portContext * /*ctx*/) override { }

  virtual void enterModport_tf_ports_declaration(SysVerilogParser::Modport_tf_ports_declarationContext * /*ctx*/) override { }
  virtual void exitModport_tf_ports_declaration(SysVerilogParser::Modport_tf_ports_declarationContext * /*ctx*/) override { }

  virtual void enterModport_tf_port(SysVerilogParser::Modport_tf_portContext * /*ctx*/) override { }
  virtual void exitModport_tf_port(SysVerilogParser::Modport_tf_portContext * /*ctx*/) override { }

  virtual void enterImport_export(SysVerilogParser::Import_exportContext * /*ctx*/) override { }
  virtual void exitImport_export(SysVerilogParser::Import_exportContext * /*ctx*/) override { }

  virtual void enterConcurrent_assertion_item(SysVerilogParser::Concurrent_assertion_itemContext * /*ctx*/) override { }
  virtual void exitConcurrent_assertion_item(SysVerilogParser::Concurrent_assertion_itemContext * /*ctx*/) override { }

  virtual void enterConcurrent_assertion_statement(SysVerilogParser::Concurrent_assertion_statementContext * /*ctx*/) override { }
  virtual void exitConcurrent_assertion_statement(SysVerilogParser::Concurrent_assertion_statementContext * /*ctx*/) override { }

  virtual void enterAssert_property_statement(SysVerilogParser::Assert_property_statementContext * /*ctx*/) override { }
  virtual void exitAssert_property_statement(SysVerilogParser::Assert_property_statementContext * /*ctx*/) override { }

  virtual void enterAssume_property_statement(SysVerilogParser::Assume_property_statementContext * /*ctx*/) override { }
  virtual void exitAssume_property_statement(SysVerilogParser::Assume_property_statementContext * /*ctx*/) override { }

  virtual void enterCover_property_statement(SysVerilogParser::Cover_property_statementContext * /*ctx*/) override { }
  virtual void exitCover_property_statement(SysVerilogParser::Cover_property_statementContext * /*ctx*/) override { }

  virtual void enterExpect_property_statement(SysVerilogParser::Expect_property_statementContext * /*ctx*/) override { }
  virtual void exitExpect_property_statement(SysVerilogParser::Expect_property_statementContext * /*ctx*/) override { }

  virtual void enterCover_sequence_statement(SysVerilogParser::Cover_sequence_statementContext * /*ctx*/) override { }
  virtual void exitCover_sequence_statement(SysVerilogParser::Cover_sequence_statementContext * /*ctx*/) override { }

  virtual void enterRestrict_property_statement(SysVerilogParser::Restrict_property_statementContext * /*ctx*/) override { }
  virtual void exitRestrict_property_statement(SysVerilogParser::Restrict_property_statementContext * /*ctx*/) override { }

  virtual void enterProperty_instance(SysVerilogParser::Property_instanceContext * /*ctx*/) override { }
  virtual void exitProperty_instance(SysVerilogParser::Property_instanceContext * /*ctx*/) override { }

  virtual void enterProperty_list_of_arguments(SysVerilogParser::Property_list_of_argumentsContext * /*ctx*/) override { }
  virtual void exitProperty_list_of_arguments(SysVerilogParser::Property_list_of_argumentsContext * /*ctx*/) override { }

  virtual void enterProperty_actual_arg(SysVerilogParser::Property_actual_argContext * /*ctx*/) override { }
  virtual void exitProperty_actual_arg(SysVerilogParser::Property_actual_argContext * /*ctx*/) override { }

  virtual void enterAssertion_item_declaration(SysVerilogParser::Assertion_item_declarationContext * /*ctx*/) override { }
  virtual void exitAssertion_item_declaration(SysVerilogParser::Assertion_item_declarationContext * /*ctx*/) override { }

  virtual void enterProperty_declaration(SysVerilogParser::Property_declarationContext * /*ctx*/) override { }
  virtual void exitProperty_declaration(SysVerilogParser::Property_declarationContext * /*ctx*/) override { }

  virtual void enterProperty_port_list(SysVerilogParser::Property_port_listContext * /*ctx*/) override { }
  virtual void exitProperty_port_list(SysVerilogParser::Property_port_listContext * /*ctx*/) override { }

  virtual void enterProperty_port_item(SysVerilogParser::Property_port_itemContext * /*ctx*/) override { }
  virtual void exitProperty_port_item(SysVerilogParser::Property_port_itemContext * /*ctx*/) override { }

  virtual void enterProperty_lvar_port_direction(SysVerilogParser::Property_lvar_port_directionContext * /*ctx*/) override { }
  virtual void exitProperty_lvar_port_direction(SysVerilogParser::Property_lvar_port_directionContext * /*ctx*/) override { }

  virtual void enterProperty_formal_type(SysVerilogParser::Property_formal_typeContext * /*ctx*/) override { }
  virtual void exitProperty_formal_type(SysVerilogParser::Property_formal_typeContext * /*ctx*/) override { }

  virtual void enterProperty_spec(SysVerilogParser::Property_specContext * /*ctx*/) override { }
  virtual void exitProperty_spec(SysVerilogParser::Property_specContext * /*ctx*/) override { }

  virtual void enterProperty_expr(SysVerilogParser::Property_exprContext * /*ctx*/) override { }
  virtual void exitProperty_expr(SysVerilogParser::Property_exprContext * /*ctx*/) override { }

  virtual void enterProperty_case_item(SysVerilogParser::Property_case_itemContext * /*ctx*/) override { }
  virtual void exitProperty_case_item(SysVerilogParser::Property_case_itemContext * /*ctx*/) override { }

  virtual void enterSequence_declaration(SysVerilogParser::Sequence_declarationContext * /*ctx*/) override { }
  virtual void exitSequence_declaration(SysVerilogParser::Sequence_declarationContext * /*ctx*/) override { }

  virtual void enterSequence_port_list(SysVerilogParser::Sequence_port_listContext * /*ctx*/) override { }
  virtual void exitSequence_port_list(SysVerilogParser::Sequence_port_listContext * /*ctx*/) override { }

  virtual void enterSequence_port_item(SysVerilogParser::Sequence_port_itemContext * /*ctx*/) override { }
  virtual void exitSequence_port_item(SysVerilogParser::Sequence_port_itemContext * /*ctx*/) override { }

  virtual void enterSequence_lvar_port_direction(SysVerilogParser::Sequence_lvar_port_directionContext * /*ctx*/) override { }
  virtual void exitSequence_lvar_port_direction(SysVerilogParser::Sequence_lvar_port_directionContext * /*ctx*/) override { }

  virtual void enterSequence_formal_type(SysVerilogParser::Sequence_formal_typeContext * /*ctx*/) override { }
  virtual void exitSequence_formal_type(SysVerilogParser::Sequence_formal_typeContext * /*ctx*/) override { }

  virtual void enterSequence_expr(SysVerilogParser::Sequence_exprContext * /*ctx*/) override { }
  virtual void exitSequence_expr(SysVerilogParser::Sequence_exprContext * /*ctx*/) override { }

  virtual void enterCycle_delay_range(SysVerilogParser::Cycle_delay_rangeContext * /*ctx*/) override { }
  virtual void exitCycle_delay_range(SysVerilogParser::Cycle_delay_rangeContext * /*ctx*/) override { }

  virtual void enterSequence_method_call(SysVerilogParser::Sequence_method_callContext * /*ctx*/) override { }
  virtual void exitSequence_method_call(SysVerilogParser::Sequence_method_callContext * /*ctx*/) override { }

  virtual void enterSequence_match_item(SysVerilogParser::Sequence_match_itemContext * /*ctx*/) override { }
  virtual void exitSequence_match_item(SysVerilogParser::Sequence_match_itemContext * /*ctx*/) override { }

  virtual void enterSequence_instance(SysVerilogParser::Sequence_instanceContext * /*ctx*/) override { }
  virtual void exitSequence_instance(SysVerilogParser::Sequence_instanceContext * /*ctx*/) override { }

  virtual void enterSequence_list_of_arguments(SysVerilogParser::Sequence_list_of_argumentsContext * /*ctx*/) override { }
  virtual void exitSequence_list_of_arguments(SysVerilogParser::Sequence_list_of_argumentsContext * /*ctx*/) override { }

  virtual void enterSequence_actual_arg(SysVerilogParser::Sequence_actual_argContext * /*ctx*/) override { }
  virtual void exitSequence_actual_arg(SysVerilogParser::Sequence_actual_argContext * /*ctx*/) override { }

  virtual void enterBoolean_abbrev(SysVerilogParser::Boolean_abbrevContext * /*ctx*/) override { }
  virtual void exitBoolean_abbrev(SysVerilogParser::Boolean_abbrevContext * /*ctx*/) override { }

  virtual void enterSequence_abbrev(SysVerilogParser::Sequence_abbrevContext * /*ctx*/) override { }
  virtual void exitSequence_abbrev(SysVerilogParser::Sequence_abbrevContext * /*ctx*/) override { }

  virtual void enterConsecutive_repetition(SysVerilogParser::Consecutive_repetitionContext * /*ctx*/) override { }
  virtual void exitConsecutive_repetition(SysVerilogParser::Consecutive_repetitionContext * /*ctx*/) override { }

  virtual void enterNon_consecutive_repetition(SysVerilogParser::Non_consecutive_repetitionContext * /*ctx*/) override { }
  virtual void exitNon_consecutive_repetition(SysVerilogParser::Non_consecutive_repetitionContext * /*ctx*/) override { }

  virtual void enterGoto_repetition(SysVerilogParser::Goto_repetitionContext * /*ctx*/) override { }
  virtual void exitGoto_repetition(SysVerilogParser::Goto_repetitionContext * /*ctx*/) override { }

  virtual void enterConst_or_range_expression(SysVerilogParser::Const_or_range_expressionContext * /*ctx*/) override { }
  virtual void exitConst_or_range_expression(SysVerilogParser::Const_or_range_expressionContext * /*ctx*/) override { }

  virtual void enterCycle_delay_const_range_expression(SysVerilogParser::Cycle_delay_const_range_expressionContext * /*ctx*/) override { }
  virtual void exitCycle_delay_const_range_expression(SysVerilogParser::Cycle_delay_const_range_expressionContext * /*ctx*/) override { }

  virtual void enterExpression_or_dist(SysVerilogParser::Expression_or_distContext * /*ctx*/) override { }
  virtual void exitExpression_or_dist(SysVerilogParser::Expression_or_distContext * /*ctx*/) override { }

  virtual void enterAssertion_variable_declaration(SysVerilogParser::Assertion_variable_declarationContext * /*ctx*/) override { }
  virtual void exitAssertion_variable_declaration(SysVerilogParser::Assertion_variable_declarationContext * /*ctx*/) override { }

  virtual void enterLet_declaration(SysVerilogParser::Let_declarationContext * /*ctx*/) override { }
  virtual void exitLet_declaration(SysVerilogParser::Let_declarationContext * /*ctx*/) override { }

  virtual void enterLet_identifier(SysVerilogParser::Let_identifierContext * /*ctx*/) override { }
  virtual void exitLet_identifier(SysVerilogParser::Let_identifierContext * /*ctx*/) override { }

  virtual void enterLet_port_list(SysVerilogParser::Let_port_listContext * /*ctx*/) override { }
  virtual void exitLet_port_list(SysVerilogParser::Let_port_listContext * /*ctx*/) override { }

  virtual void enterLet_port_item(SysVerilogParser::Let_port_itemContext * /*ctx*/) override { }
  virtual void exitLet_port_item(SysVerilogParser::Let_port_itemContext * /*ctx*/) override { }

  virtual void enterLet_formal_type(SysVerilogParser::Let_formal_typeContext * /*ctx*/) override { }
  virtual void exitLet_formal_type(SysVerilogParser::Let_formal_typeContext * /*ctx*/) override { }

  virtual void enterLet_expression(SysVerilogParser::Let_expressionContext * /*ctx*/) override { }
  virtual void exitLet_expression(SysVerilogParser::Let_expressionContext * /*ctx*/) override { }

  virtual void enterLet_list_of_arguments(SysVerilogParser::Let_list_of_argumentsContext * /*ctx*/) override { }
  virtual void exitLet_list_of_arguments(SysVerilogParser::Let_list_of_argumentsContext * /*ctx*/) override { }

  virtual void enterLet_actual_arg(SysVerilogParser::Let_actual_argContext * /*ctx*/) override { }
  virtual void exitLet_actual_arg(SysVerilogParser::Let_actual_argContext * /*ctx*/) override { }

  virtual void enterCovergroup_declaration(SysVerilogParser::Covergroup_declarationContext * /*ctx*/) override { }
  virtual void exitCovergroup_declaration(SysVerilogParser::Covergroup_declarationContext * /*ctx*/) override { }

  virtual void enterCoverage_spec_or_option(SysVerilogParser::Coverage_spec_or_optionContext * /*ctx*/) override { }
  virtual void exitCoverage_spec_or_option(SysVerilogParser::Coverage_spec_or_optionContext * /*ctx*/) override { }

  virtual void enterCoverage_option(SysVerilogParser::Coverage_optionContext * /*ctx*/) override { }
  virtual void exitCoverage_option(SysVerilogParser::Coverage_optionContext * /*ctx*/) override { }

  virtual void enterCoverage_spec(SysVerilogParser::Coverage_specContext * /*ctx*/) override { }
  virtual void exitCoverage_spec(SysVerilogParser::Coverage_specContext * /*ctx*/) override { }

  virtual void enterCoverage_event(SysVerilogParser::Coverage_eventContext * /*ctx*/) override { }
  virtual void exitCoverage_event(SysVerilogParser::Coverage_eventContext * /*ctx*/) override { }

  virtual void enterBlock_event_expression(SysVerilogParser::Block_event_expressionContext * /*ctx*/) override { }
  virtual void exitBlock_event_expression(SysVerilogParser::Block_event_expressionContext * /*ctx*/) override { }

  virtual void enterHierarchical_btf_identifier(SysVerilogParser::Hierarchical_btf_identifierContext * /*ctx*/) override { }
  virtual void exitHierarchical_btf_identifier(SysVerilogParser::Hierarchical_btf_identifierContext * /*ctx*/) override { }

  virtual void enterCover_point(SysVerilogParser::Cover_pointContext * /*ctx*/) override { }
  virtual void exitCover_point(SysVerilogParser::Cover_pointContext * /*ctx*/) override { }

  virtual void enterBins_or_empty(SysVerilogParser::Bins_or_emptyContext * /*ctx*/) override { }
  virtual void exitBins_or_empty(SysVerilogParser::Bins_or_emptyContext * /*ctx*/) override { }

  virtual void enterBins_or_options(SysVerilogParser::Bins_or_optionsContext * /*ctx*/) override { }
  virtual void exitBins_or_options(SysVerilogParser::Bins_or_optionsContext * /*ctx*/) override { }

  virtual void enterBins_keyword(SysVerilogParser::Bins_keywordContext * /*ctx*/) override { }
  virtual void exitBins_keyword(SysVerilogParser::Bins_keywordContext * /*ctx*/) override { }

  virtual void enterTrans_list(SysVerilogParser::Trans_listContext * /*ctx*/) override { }
  virtual void exitTrans_list(SysVerilogParser::Trans_listContext * /*ctx*/) override { }

  virtual void enterTrans_set(SysVerilogParser::Trans_setContext * /*ctx*/) override { }
  virtual void exitTrans_set(SysVerilogParser::Trans_setContext * /*ctx*/) override { }

  virtual void enterTrans_range_list(SysVerilogParser::Trans_range_listContext * /*ctx*/) override { }
  virtual void exitTrans_range_list(SysVerilogParser::Trans_range_listContext * /*ctx*/) override { }

  virtual void enterTrans_item(SysVerilogParser::Trans_itemContext * /*ctx*/) override { }
  virtual void exitTrans_item(SysVerilogParser::Trans_itemContext * /*ctx*/) override { }

  virtual void enterRepeat_range(SysVerilogParser::Repeat_rangeContext * /*ctx*/) override { }
  virtual void exitRepeat_range(SysVerilogParser::Repeat_rangeContext * /*ctx*/) override { }

  virtual void enterCover_cross(SysVerilogParser::Cover_crossContext * /*ctx*/) override { }
  virtual void exitCover_cross(SysVerilogParser::Cover_crossContext * /*ctx*/) override { }

  virtual void enterList_of_cross_items(SysVerilogParser::List_of_cross_itemsContext * /*ctx*/) override { }
  virtual void exitList_of_cross_items(SysVerilogParser::List_of_cross_itemsContext * /*ctx*/) override { }

  virtual void enterCross_item(SysVerilogParser::Cross_itemContext * /*ctx*/) override { }
  virtual void exitCross_item(SysVerilogParser::Cross_itemContext * /*ctx*/) override { }

  virtual void enterCross_body(SysVerilogParser::Cross_bodyContext * /*ctx*/) override { }
  virtual void exitCross_body(SysVerilogParser::Cross_bodyContext * /*ctx*/) override { }

  virtual void enterCross_body_item(SysVerilogParser::Cross_body_itemContext * /*ctx*/) override { }
  virtual void exitCross_body_item(SysVerilogParser::Cross_body_itemContext * /*ctx*/) override { }

  virtual void enterBins_selection_or_option(SysVerilogParser::Bins_selection_or_optionContext * /*ctx*/) override { }
  virtual void exitBins_selection_or_option(SysVerilogParser::Bins_selection_or_optionContext * /*ctx*/) override { }

  virtual void enterBins_selection(SysVerilogParser::Bins_selectionContext * /*ctx*/) override { }
  virtual void exitBins_selection(SysVerilogParser::Bins_selectionContext * /*ctx*/) override { }

  virtual void enterSelect_expression2(SysVerilogParser::Select_expression2Context * /*ctx*/) override { }
  virtual void exitSelect_expression2(SysVerilogParser::Select_expression2Context * /*ctx*/) override { }

  virtual void enterSelect_expression(SysVerilogParser::Select_expressionContext * /*ctx*/) override { }
  virtual void exitSelect_expression(SysVerilogParser::Select_expressionContext * /*ctx*/) override { }

  virtual void enterSelect_condition(SysVerilogParser::Select_conditionContext * /*ctx*/) override { }
  virtual void exitSelect_condition(SysVerilogParser::Select_conditionContext * /*ctx*/) override { }

  virtual void enterBins_expression(SysVerilogParser::Bins_expressionContext * /*ctx*/) override { }
  virtual void exitBins_expression(SysVerilogParser::Bins_expressionContext * /*ctx*/) override { }

  virtual void enterCovergroup_range_list(SysVerilogParser::Covergroup_range_listContext * /*ctx*/) override { }
  virtual void exitCovergroup_range_list(SysVerilogParser::Covergroup_range_listContext * /*ctx*/) override { }

  virtual void enterCovergroup_value_range(SysVerilogParser::Covergroup_value_rangeContext * /*ctx*/) override { }
  virtual void exitCovergroup_value_range(SysVerilogParser::Covergroup_value_rangeContext * /*ctx*/) override { }

  virtual void enterWith_covergroup_expression(SysVerilogParser::With_covergroup_expressionContext * /*ctx*/) override { }
  virtual void exitWith_covergroup_expression(SysVerilogParser::With_covergroup_expressionContext * /*ctx*/) override { }

  virtual void enterSet_covergroup_expression(SysVerilogParser::Set_covergroup_expressionContext * /*ctx*/) override { }
  virtual void exitSet_covergroup_expression(SysVerilogParser::Set_covergroup_expressionContext * /*ctx*/) override { }

  virtual void enterInteger_covergroup_expression(SysVerilogParser::Integer_covergroup_expressionContext * /*ctx*/) override { }
  virtual void exitInteger_covergroup_expression(SysVerilogParser::Integer_covergroup_expressionContext * /*ctx*/) override { }

  virtual void enterCross_set_expression(SysVerilogParser::Cross_set_expressionContext * /*ctx*/) override { }
  virtual void exitCross_set_expression(SysVerilogParser::Cross_set_expressionContext * /*ctx*/) override { }

  virtual void enterCovergroup_expression(SysVerilogParser::Covergroup_expressionContext * /*ctx*/) override { }
  virtual void exitCovergroup_expression(SysVerilogParser::Covergroup_expressionContext * /*ctx*/) override { }

  virtual void enterGate_instantiation(SysVerilogParser::Gate_instantiationContext * /*ctx*/) override { }
  virtual void exitGate_instantiation(SysVerilogParser::Gate_instantiationContext * /*ctx*/) override { }

  virtual void enterCmos_switch_instance(SysVerilogParser::Cmos_switch_instanceContext * /*ctx*/) override { }
  virtual void exitCmos_switch_instance(SysVerilogParser::Cmos_switch_instanceContext * /*ctx*/) override { }

  virtual void enterEnable_gate_instance(SysVerilogParser::Enable_gate_instanceContext * /*ctx*/) override { }
  virtual void exitEnable_gate_instance(SysVerilogParser::Enable_gate_instanceContext * /*ctx*/) override { }

  virtual void enterMos_switch_instance(SysVerilogParser::Mos_switch_instanceContext * /*ctx*/) override { }
  virtual void exitMos_switch_instance(SysVerilogParser::Mos_switch_instanceContext * /*ctx*/) override { }

  virtual void enterN_input_gate_instance(SysVerilogParser::N_input_gate_instanceContext * /*ctx*/) override { }
  virtual void exitN_input_gate_instance(SysVerilogParser::N_input_gate_instanceContext * /*ctx*/) override { }

  virtual void enterN_output_gate_instance(SysVerilogParser::N_output_gate_instanceContext * /*ctx*/) override { }
  virtual void exitN_output_gate_instance(SysVerilogParser::N_output_gate_instanceContext * /*ctx*/) override { }

  virtual void enterPass_switch_instance(SysVerilogParser::Pass_switch_instanceContext * /*ctx*/) override { }
  virtual void exitPass_switch_instance(SysVerilogParser::Pass_switch_instanceContext * /*ctx*/) override { }

  virtual void enterPass_enable_switch_instance(SysVerilogParser::Pass_enable_switch_instanceContext * /*ctx*/) override { }
  virtual void exitPass_enable_switch_instance(SysVerilogParser::Pass_enable_switch_instanceContext * /*ctx*/) override { }

  virtual void enterPull_gate_instance(SysVerilogParser::Pull_gate_instanceContext * /*ctx*/) override { }
  virtual void exitPull_gate_instance(SysVerilogParser::Pull_gate_instanceContext * /*ctx*/) override { }

  virtual void enterPulldown_strength(SysVerilogParser::Pulldown_strengthContext * /*ctx*/) override { }
  virtual void exitPulldown_strength(SysVerilogParser::Pulldown_strengthContext * /*ctx*/) override { }

  virtual void enterPullup_strength(SysVerilogParser::Pullup_strengthContext * /*ctx*/) override { }
  virtual void exitPullup_strength(SysVerilogParser::Pullup_strengthContext * /*ctx*/) override { }

  virtual void enterEnable_terminal(SysVerilogParser::Enable_terminalContext * /*ctx*/) override { }
  virtual void exitEnable_terminal(SysVerilogParser::Enable_terminalContext * /*ctx*/) override { }

  virtual void enterInout_terminal(SysVerilogParser::Inout_terminalContext * /*ctx*/) override { }
  virtual void exitInout_terminal(SysVerilogParser::Inout_terminalContext * /*ctx*/) override { }

  virtual void enterInput_terminal(SysVerilogParser::Input_terminalContext * /*ctx*/) override { }
  virtual void exitInput_terminal(SysVerilogParser::Input_terminalContext * /*ctx*/) override { }

  virtual void enterNcontrol_terminal(SysVerilogParser::Ncontrol_terminalContext * /*ctx*/) override { }
  virtual void exitNcontrol_terminal(SysVerilogParser::Ncontrol_terminalContext * /*ctx*/) override { }

  virtual void enterOutput_terminal(SysVerilogParser::Output_terminalContext * /*ctx*/) override { }
  virtual void exitOutput_terminal(SysVerilogParser::Output_terminalContext * /*ctx*/) override { }

  virtual void enterPcontrol_terminal(SysVerilogParser::Pcontrol_terminalContext * /*ctx*/) override { }
  virtual void exitPcontrol_terminal(SysVerilogParser::Pcontrol_terminalContext * /*ctx*/) override { }

  virtual void enterCmos_switchtype(SysVerilogParser::Cmos_switchtypeContext * /*ctx*/) override { }
  virtual void exitCmos_switchtype(SysVerilogParser::Cmos_switchtypeContext * /*ctx*/) override { }

  virtual void enterEnable_gatetype(SysVerilogParser::Enable_gatetypeContext * /*ctx*/) override { }
  virtual void exitEnable_gatetype(SysVerilogParser::Enable_gatetypeContext * /*ctx*/) override { }

  virtual void enterMos_switchtype(SysVerilogParser::Mos_switchtypeContext * /*ctx*/) override { }
  virtual void exitMos_switchtype(SysVerilogParser::Mos_switchtypeContext * /*ctx*/) override { }

  virtual void enterN_input_gatetype(SysVerilogParser::N_input_gatetypeContext * /*ctx*/) override { }
  virtual void exitN_input_gatetype(SysVerilogParser::N_input_gatetypeContext * /*ctx*/) override { }

  virtual void enterN_output_gatetype(SysVerilogParser::N_output_gatetypeContext * /*ctx*/) override { }
  virtual void exitN_output_gatetype(SysVerilogParser::N_output_gatetypeContext * /*ctx*/) override { }

  virtual void enterPass_en_switchtype(SysVerilogParser::Pass_en_switchtypeContext * /*ctx*/) override { }
  virtual void exitPass_en_switchtype(SysVerilogParser::Pass_en_switchtypeContext * /*ctx*/) override { }

  virtual void enterPass_switchtype(SysVerilogParser::Pass_switchtypeContext * /*ctx*/) override { }
  virtual void exitPass_switchtype(SysVerilogParser::Pass_switchtypeContext * /*ctx*/) override { }

  virtual void enterModule_instantiation(SysVerilogParser::Module_instantiationContext * /*ctx*/) override { }
  virtual void exitModule_instantiation(SysVerilogParser::Module_instantiationContext * /*ctx*/) override { }

  virtual void enterParameter_value_assignment(SysVerilogParser::Parameter_value_assignmentContext * /*ctx*/) override { }
  virtual void exitParameter_value_assignment(SysVerilogParser::Parameter_value_assignmentContext * /*ctx*/) override { }

  virtual void enterList_of_parameter_assignments(SysVerilogParser::List_of_parameter_assignmentsContext * /*ctx*/) override { }
  virtual void exitList_of_parameter_assignments(SysVerilogParser::List_of_parameter_assignmentsContext * /*ctx*/) override { }

  virtual void enterOrdered_parameter_assignment(SysVerilogParser::Ordered_parameter_assignmentContext * /*ctx*/) override { }
  virtual void exitOrdered_parameter_assignment(SysVerilogParser::Ordered_parameter_assignmentContext * /*ctx*/) override { }

  virtual void enterNamed_parameter_assignment(SysVerilogParser::Named_parameter_assignmentContext * /*ctx*/) override { }
  virtual void exitNamed_parameter_assignment(SysVerilogParser::Named_parameter_assignmentContext * /*ctx*/) override { }

  virtual void enterHierarchical_instance(SysVerilogParser::Hierarchical_instanceContext * /*ctx*/) override { }
  virtual void exitHierarchical_instance(SysVerilogParser::Hierarchical_instanceContext * /*ctx*/) override { }

  virtual void enterName_of_instance(SysVerilogParser::Name_of_instanceContext * /*ctx*/) override { }
  virtual void exitName_of_instance(SysVerilogParser::Name_of_instanceContext * /*ctx*/) override { }

  virtual void enterList_of_port_connections(SysVerilogParser::List_of_port_connectionsContext * /*ctx*/) override { }
  virtual void exitList_of_port_connections(SysVerilogParser::List_of_port_connectionsContext * /*ctx*/) override { }

  virtual void enterOrdered_port_connection(SysVerilogParser::Ordered_port_connectionContext * /*ctx*/) override { }
  virtual void exitOrdered_port_connection(SysVerilogParser::Ordered_port_connectionContext * /*ctx*/) override { }

  virtual void enterNamed_port_connection(SysVerilogParser::Named_port_connectionContext * /*ctx*/) override { }
  virtual void exitNamed_port_connection(SysVerilogParser::Named_port_connectionContext * /*ctx*/) override { }

  virtual void enterInterface_instantiation(SysVerilogParser::Interface_instantiationContext * /*ctx*/) override { }
  virtual void exitInterface_instantiation(SysVerilogParser::Interface_instantiationContext * /*ctx*/) override { }

  virtual void enterChecker_instantiation(SysVerilogParser::Checker_instantiationContext * /*ctx*/) override { }
  virtual void exitChecker_instantiation(SysVerilogParser::Checker_instantiationContext * /*ctx*/) override { }

  virtual void enterList_of_checker_port_connections(SysVerilogParser::List_of_checker_port_connectionsContext * /*ctx*/) override { }
  virtual void exitList_of_checker_port_connections(SysVerilogParser::List_of_checker_port_connectionsContext * /*ctx*/) override { }

  virtual void enterOrdered_checker_port_connection(SysVerilogParser::Ordered_checker_port_connectionContext * /*ctx*/) override { }
  virtual void exitOrdered_checker_port_connection(SysVerilogParser::Ordered_checker_port_connectionContext * /*ctx*/) override { }

  virtual void enterNamed_checker_port_connection(SysVerilogParser::Named_checker_port_connectionContext * /*ctx*/) override { }
  virtual void exitNamed_checker_port_connection(SysVerilogParser::Named_checker_port_connectionContext * /*ctx*/) override { }

  virtual void enterProgram_instantiation(SysVerilogParser::Program_instantiationContext * /*ctx*/) override { }
  virtual void exitProgram_instantiation(SysVerilogParser::Program_instantiationContext * /*ctx*/) override { }

  virtual void enterGenerate_region(SysVerilogParser::Generate_regionContext * /*ctx*/) override { }
  virtual void exitGenerate_region(SysVerilogParser::Generate_regionContext * /*ctx*/) override { }

  virtual void enterLoop_generate_construct(SysVerilogParser::Loop_generate_constructContext * /*ctx*/) override { }
  virtual void exitLoop_generate_construct(SysVerilogParser::Loop_generate_constructContext * /*ctx*/) override { }

  virtual void enterGenvar_initialization(SysVerilogParser::Genvar_initializationContext * /*ctx*/) override { }
  virtual void exitGenvar_initialization(SysVerilogParser::Genvar_initializationContext * /*ctx*/) override { }

  virtual void enterGenvar_iteration(SysVerilogParser::Genvar_iterationContext * /*ctx*/) override { }
  virtual void exitGenvar_iteration(SysVerilogParser::Genvar_iterationContext * /*ctx*/) override { }

  virtual void enterConditional_generate_construct(SysVerilogParser::Conditional_generate_constructContext * /*ctx*/) override { }
  virtual void exitConditional_generate_construct(SysVerilogParser::Conditional_generate_constructContext * /*ctx*/) override { }

  virtual void enterIf_generate_construct(SysVerilogParser::If_generate_constructContext * /*ctx*/) override { }
  virtual void exitIf_generate_construct(SysVerilogParser::If_generate_constructContext * /*ctx*/) override { }

  virtual void enterCase_generate_construct(SysVerilogParser::Case_generate_constructContext * /*ctx*/) override { }
  virtual void exitCase_generate_construct(SysVerilogParser::Case_generate_constructContext * /*ctx*/) override { }

  virtual void enterCase_generate_item(SysVerilogParser::Case_generate_itemContext * /*ctx*/) override { }
  virtual void exitCase_generate_item(SysVerilogParser::Case_generate_itemContext * /*ctx*/) override { }

  virtual void enterGenerate_block(SysVerilogParser::Generate_blockContext * /*ctx*/) override { }
  virtual void exitGenerate_block(SysVerilogParser::Generate_blockContext * /*ctx*/) override { }

  virtual void enterGenerate_item(SysVerilogParser::Generate_itemContext * /*ctx*/) override { }
  virtual void exitGenerate_item(SysVerilogParser::Generate_itemContext * /*ctx*/) override { }

  virtual void enterContinuous_assign(SysVerilogParser::Continuous_assignContext * /*ctx*/) override { }
  virtual void exitContinuous_assign(SysVerilogParser::Continuous_assignContext * /*ctx*/) override { }

  virtual void enterList_of_net_assignments(SysVerilogParser::List_of_net_assignmentsContext * /*ctx*/) override { }
  virtual void exitList_of_net_assignments(SysVerilogParser::List_of_net_assignmentsContext * /*ctx*/) override { }

  virtual void enterList_of_variable_assignments(SysVerilogParser::List_of_variable_assignmentsContext * /*ctx*/) override { }
  virtual void exitList_of_variable_assignments(SysVerilogParser::List_of_variable_assignmentsContext * /*ctx*/) override { }

  virtual void enterNet_alias(SysVerilogParser::Net_aliasContext * /*ctx*/) override { }
  virtual void exitNet_alias(SysVerilogParser::Net_aliasContext * /*ctx*/) override { }

  virtual void enterNet_assignment(SysVerilogParser::Net_assignmentContext * /*ctx*/) override { }
  virtual void exitNet_assignment(SysVerilogParser::Net_assignmentContext * /*ctx*/) override { }

  virtual void enterInitial_construct(SysVerilogParser::Initial_constructContext * /*ctx*/) override { }
  virtual void exitInitial_construct(SysVerilogParser::Initial_constructContext * /*ctx*/) override { }

  virtual void enterAlways_construct(SysVerilogParser::Always_constructContext * /*ctx*/) override { }
  virtual void exitAlways_construct(SysVerilogParser::Always_constructContext * /*ctx*/) override { }

  virtual void enterAlways_keyword(SysVerilogParser::Always_keywordContext * /*ctx*/) override { }
  virtual void exitAlways_keyword(SysVerilogParser::Always_keywordContext * /*ctx*/) override { }

  virtual void enterFinal_construct(SysVerilogParser::Final_constructContext * /*ctx*/) override { }
  virtual void exitFinal_construct(SysVerilogParser::Final_constructContext * /*ctx*/) override { }

  virtual void enterBlocking_assignment(SysVerilogParser::Blocking_assignmentContext * /*ctx*/) override { }
  virtual void exitBlocking_assignment(SysVerilogParser::Blocking_assignmentContext * /*ctx*/) override { }

  virtual void enterOperator_assignment(SysVerilogParser::Operator_assignmentContext * /*ctx*/) override { }
  virtual void exitOperator_assignment(SysVerilogParser::Operator_assignmentContext * /*ctx*/) override { }

  virtual void enterAssignment_operator(SysVerilogParser::Assignment_operatorContext * /*ctx*/) override { }
  virtual void exitAssignment_operator(SysVerilogParser::Assignment_operatorContext * /*ctx*/) override { }

  virtual void enterNonblocking_assignment(SysVerilogParser::Nonblocking_assignmentContext * /*ctx*/) override { }
  virtual void exitNonblocking_assignment(SysVerilogParser::Nonblocking_assignmentContext * /*ctx*/) override { }

  virtual void enterProcedural_continuous_assignment(SysVerilogParser::Procedural_continuous_assignmentContext * /*ctx*/) override { }
  virtual void exitProcedural_continuous_assignment(SysVerilogParser::Procedural_continuous_assignmentContext * /*ctx*/) override { }

  virtual void enterVariable_assignment(SysVerilogParser::Variable_assignmentContext * /*ctx*/) override { }
  virtual void exitVariable_assignment(SysVerilogParser::Variable_assignmentContext * /*ctx*/) override { }

  virtual void enterAction_block(SysVerilogParser::Action_blockContext * /*ctx*/) override { }
  virtual void exitAction_block(SysVerilogParser::Action_blockContext * /*ctx*/) override { }

  virtual void enterSeq_block(SysVerilogParser::Seq_blockContext * /*ctx*/) override { }
  virtual void exitSeq_block(SysVerilogParser::Seq_blockContext * /*ctx*/) override { }

  virtual void enterPar_block(SysVerilogParser::Par_blockContext * /*ctx*/) override { }
  virtual void exitPar_block(SysVerilogParser::Par_blockContext * /*ctx*/) override { }

  virtual void enterJoin_keyword(SysVerilogParser::Join_keywordContext * /*ctx*/) override { }
  virtual void exitJoin_keyword(SysVerilogParser::Join_keywordContext * /*ctx*/) override { }

  virtual void enterStatement_or_null(SysVerilogParser::Statement_or_nullContext * /*ctx*/) override { }
  virtual void exitStatement_or_null(SysVerilogParser::Statement_or_nullContext * /*ctx*/) override { }

  virtual void enterStatement(SysVerilogParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(SysVerilogParser::StatementContext * /*ctx*/) override { }

  virtual void enterStatement_item(SysVerilogParser::Statement_itemContext * /*ctx*/) override { }
  virtual void exitStatement_item(SysVerilogParser::Statement_itemContext * /*ctx*/) override { }

  virtual void enterFunction_statement(SysVerilogParser::Function_statementContext * /*ctx*/) override { }
  virtual void exitFunction_statement(SysVerilogParser::Function_statementContext * /*ctx*/) override { }

  virtual void enterFunction_statement_or_null(SysVerilogParser::Function_statement_or_nullContext * /*ctx*/) override { }
  virtual void exitFunction_statement_or_null(SysVerilogParser::Function_statement_or_nullContext * /*ctx*/) override { }

  virtual void enterVariable_identifier_list(SysVerilogParser::Variable_identifier_listContext * /*ctx*/) override { }
  virtual void exitVariable_identifier_list(SysVerilogParser::Variable_identifier_listContext * /*ctx*/) override { }

  virtual void enterProcedural_timing_control_statement(SysVerilogParser::Procedural_timing_control_statementContext * /*ctx*/) override { }
  virtual void exitProcedural_timing_control_statement(SysVerilogParser::Procedural_timing_control_statementContext * /*ctx*/) override { }

  virtual void enterDelay_or_event_control(SysVerilogParser::Delay_or_event_controlContext * /*ctx*/) override { }
  virtual void exitDelay_or_event_control(SysVerilogParser::Delay_or_event_controlContext * /*ctx*/) override { }

  virtual void enterDelay_control(SysVerilogParser::Delay_controlContext * /*ctx*/) override { }
  virtual void exitDelay_control(SysVerilogParser::Delay_controlContext * /*ctx*/) override { }

  virtual void enterPound_delay_value(SysVerilogParser::Pound_delay_valueContext * /*ctx*/) override { }
  virtual void exitPound_delay_value(SysVerilogParser::Pound_delay_valueContext * /*ctx*/) override { }

  virtual void enterEvent_control(SysVerilogParser::Event_controlContext * /*ctx*/) override { }
  virtual void exitEvent_control(SysVerilogParser::Event_controlContext * /*ctx*/) override { }

  virtual void enterEvent_expression(SysVerilogParser::Event_expressionContext * /*ctx*/) override { }
  virtual void exitEvent_expression(SysVerilogParser::Event_expressionContext * /*ctx*/) override { }

  virtual void enterProcedural_timing_control(SysVerilogParser::Procedural_timing_controlContext * /*ctx*/) override { }
  virtual void exitProcedural_timing_control(SysVerilogParser::Procedural_timing_controlContext * /*ctx*/) override { }

  virtual void enterJump_statement(SysVerilogParser::Jump_statementContext * /*ctx*/) override { }
  virtual void exitJump_statement(SysVerilogParser::Jump_statementContext * /*ctx*/) override { }

  virtual void enterWait_statement(SysVerilogParser::Wait_statementContext * /*ctx*/) override { }
  virtual void exitWait_statement(SysVerilogParser::Wait_statementContext * /*ctx*/) override { }

  virtual void enterEvent_trigger(SysVerilogParser::Event_triggerContext * /*ctx*/) override { }
  virtual void exitEvent_trigger(SysVerilogParser::Event_triggerContext * /*ctx*/) override { }

  virtual void enterDisable_statement(SysVerilogParser::Disable_statementContext * /*ctx*/) override { }
  virtual void exitDisable_statement(SysVerilogParser::Disable_statementContext * /*ctx*/) override { }

  virtual void enterConditional_statement(SysVerilogParser::Conditional_statementContext * /*ctx*/) override { }
  virtual void exitConditional_statement(SysVerilogParser::Conditional_statementContext * /*ctx*/) override { }

  virtual void enterUnique_priority(SysVerilogParser::Unique_priorityContext * /*ctx*/) override { }
  virtual void exitUnique_priority(SysVerilogParser::Unique_priorityContext * /*ctx*/) override { }

  virtual void enterCond_predicate(SysVerilogParser::Cond_predicateContext * /*ctx*/) override { }
  virtual void exitCond_predicate(SysVerilogParser::Cond_predicateContext * /*ctx*/) override { }

  virtual void enterExpression_or_cond_pattern(SysVerilogParser::Expression_or_cond_patternContext * /*ctx*/) override { }
  virtual void exitExpression_or_cond_pattern(SysVerilogParser::Expression_or_cond_patternContext * /*ctx*/) override { }

  virtual void enterCond_pattern(SysVerilogParser::Cond_patternContext * /*ctx*/) override { }
  virtual void exitCond_pattern(SysVerilogParser::Cond_patternContext * /*ctx*/) override { }

  virtual void enterCase_statement(SysVerilogParser::Case_statementContext * /*ctx*/) override { }
  virtual void exitCase_statement(SysVerilogParser::Case_statementContext * /*ctx*/) override { }

  virtual void enterCcase(SysVerilogParser::CcaseContext * /*ctx*/) override { }
  virtual void exitCcase(SysVerilogParser::CcaseContext * /*ctx*/) override { }

  virtual void enterCase_keyword(SysVerilogParser::Case_keywordContext * /*ctx*/) override { }
  virtual void exitCase_keyword(SysVerilogParser::Case_keywordContext * /*ctx*/) override { }

  virtual void enterCase_expression(SysVerilogParser::Case_expressionContext * /*ctx*/) override { }
  virtual void exitCase_expression(SysVerilogParser::Case_expressionContext * /*ctx*/) override { }

  virtual void enterCase_item(SysVerilogParser::Case_itemContext * /*ctx*/) override { }
  virtual void exitCase_item(SysVerilogParser::Case_itemContext * /*ctx*/) override { }

  virtual void enterCase_pattern_item(SysVerilogParser::Case_pattern_itemContext * /*ctx*/) override { }
  virtual void exitCase_pattern_item(SysVerilogParser::Case_pattern_itemContext * /*ctx*/) override { }

  virtual void enterCase_inside_item(SysVerilogParser::Case_inside_itemContext * /*ctx*/) override { }
  virtual void exitCase_inside_item(SysVerilogParser::Case_inside_itemContext * /*ctx*/) override { }

  virtual void enterCase_item_expression(SysVerilogParser::Case_item_expressionContext * /*ctx*/) override { }
  virtual void exitCase_item_expression(SysVerilogParser::Case_item_expressionContext * /*ctx*/) override { }

  virtual void enterRandcase_statement(SysVerilogParser::Randcase_statementContext * /*ctx*/) override { }
  virtual void exitRandcase_statement(SysVerilogParser::Randcase_statementContext * /*ctx*/) override { }

  virtual void enterRandcase_item(SysVerilogParser::Randcase_itemContext * /*ctx*/) override { }
  virtual void exitRandcase_item(SysVerilogParser::Randcase_itemContext * /*ctx*/) override { }

  virtual void enterOpen_range_list(SysVerilogParser::Open_range_listContext * /*ctx*/) override { }
  virtual void exitOpen_range_list(SysVerilogParser::Open_range_listContext * /*ctx*/) override { }

  virtual void enterOpen_value_range(SysVerilogParser::Open_value_rangeContext * /*ctx*/) override { }
  virtual void exitOpen_value_range(SysVerilogParser::Open_value_rangeContext * /*ctx*/) override { }

  virtual void enterPattern(SysVerilogParser::PatternContext * /*ctx*/) override { }
  virtual void exitPattern(SysVerilogParser::PatternContext * /*ctx*/) override { }

  virtual void enterAssignment_pattern(SysVerilogParser::Assignment_patternContext * /*ctx*/) override { }
  virtual void exitAssignment_pattern(SysVerilogParser::Assignment_patternContext * /*ctx*/) override { }

  virtual void enterStructure_pattern_key(SysVerilogParser::Structure_pattern_keyContext * /*ctx*/) override { }
  virtual void exitStructure_pattern_key(SysVerilogParser::Structure_pattern_keyContext * /*ctx*/) override { }

  virtual void enterArray_pattern_key(SysVerilogParser::Array_pattern_keyContext * /*ctx*/) override { }
  virtual void exitArray_pattern_key(SysVerilogParser::Array_pattern_keyContext * /*ctx*/) override { }

  virtual void enterAssignment_pattern_key(SysVerilogParser::Assignment_pattern_keyContext * /*ctx*/) override { }
  virtual void exitAssignment_pattern_key(SysVerilogParser::Assignment_pattern_keyContext * /*ctx*/) override { }

  virtual void enterAssignment_pattern_expression(SysVerilogParser::Assignment_pattern_expressionContext * /*ctx*/) override { }
  virtual void exitAssignment_pattern_expression(SysVerilogParser::Assignment_pattern_expressionContext * /*ctx*/) override { }

  virtual void enterAssignment_pattern_expression_type(SysVerilogParser::Assignment_pattern_expression_typeContext * /*ctx*/) override { }
  virtual void exitAssignment_pattern_expression_type(SysVerilogParser::Assignment_pattern_expression_typeContext * /*ctx*/) override { }

  virtual void enterConstant_assignment_pattern_expression(SysVerilogParser::Constant_assignment_pattern_expressionContext * /*ctx*/) override { }
  virtual void exitConstant_assignment_pattern_expression(SysVerilogParser::Constant_assignment_pattern_expressionContext * /*ctx*/) override { }

  virtual void enterAssignment_pattern_net_lvalue(SysVerilogParser::Assignment_pattern_net_lvalueContext * /*ctx*/) override { }
  virtual void exitAssignment_pattern_net_lvalue(SysVerilogParser::Assignment_pattern_net_lvalueContext * /*ctx*/) override { }

  virtual void enterAssignment_pattern_variable_lvalue(SysVerilogParser::Assignment_pattern_variable_lvalueContext * /*ctx*/) override { }
  virtual void exitAssignment_pattern_variable_lvalue(SysVerilogParser::Assignment_pattern_variable_lvalueContext * /*ctx*/) override { }

  virtual void enterLoop_statement(SysVerilogParser::Loop_statementContext * /*ctx*/) override { }
  virtual void exitLoop_statement(SysVerilogParser::Loop_statementContext * /*ctx*/) override { }

  virtual void enterFor_initialization(SysVerilogParser::For_initializationContext * /*ctx*/) override { }
  virtual void exitFor_initialization(SysVerilogParser::For_initializationContext * /*ctx*/) override { }

  virtual void enterFor_variable_declaration(SysVerilogParser::For_variable_declarationContext * /*ctx*/) override { }
  virtual void exitFor_variable_declaration(SysVerilogParser::For_variable_declarationContext * /*ctx*/) override { }

  virtual void enterFor_step(SysVerilogParser::For_stepContext * /*ctx*/) override { }
  virtual void exitFor_step(SysVerilogParser::For_stepContext * /*ctx*/) override { }

  virtual void enterFor_step_assignment(SysVerilogParser::For_step_assignmentContext * /*ctx*/) override { }
  virtual void exitFor_step_assignment(SysVerilogParser::For_step_assignmentContext * /*ctx*/) override { }

  virtual void enterLoop_variables(SysVerilogParser::Loop_variablesContext * /*ctx*/) override { }
  virtual void exitLoop_variables(SysVerilogParser::Loop_variablesContext * /*ctx*/) override { }

  virtual void enterSubroutine_call_statement(SysVerilogParser::Subroutine_call_statementContext * /*ctx*/) override { }
  virtual void exitSubroutine_call_statement(SysVerilogParser::Subroutine_call_statementContext * /*ctx*/) override { }

  virtual void enterAssertion_item(SysVerilogParser::Assertion_itemContext * /*ctx*/) override { }
  virtual void exitAssertion_item(SysVerilogParser::Assertion_itemContext * /*ctx*/) override { }

  virtual void enterDeferred_immediate_assertion_item(SysVerilogParser::Deferred_immediate_assertion_itemContext * /*ctx*/) override { }
  virtual void exitDeferred_immediate_assertion_item(SysVerilogParser::Deferred_immediate_assertion_itemContext * /*ctx*/) override { }

  virtual void enterProcedural_assertion_statement(SysVerilogParser::Procedural_assertion_statementContext * /*ctx*/) override { }
  virtual void exitProcedural_assertion_statement(SysVerilogParser::Procedural_assertion_statementContext * /*ctx*/) override { }

  virtual void enterImmediate_assertion_statement(SysVerilogParser::Immediate_assertion_statementContext * /*ctx*/) override { }
  virtual void exitImmediate_assertion_statement(SysVerilogParser::Immediate_assertion_statementContext * /*ctx*/) override { }

  virtual void enterSimple_immediate_assertion_statement(SysVerilogParser::Simple_immediate_assertion_statementContext * /*ctx*/) override { }
  virtual void exitSimple_immediate_assertion_statement(SysVerilogParser::Simple_immediate_assertion_statementContext * /*ctx*/) override { }

  virtual void enterSimple_immediate_assert_statement(SysVerilogParser::Simple_immediate_assert_statementContext * /*ctx*/) override { }
  virtual void exitSimple_immediate_assert_statement(SysVerilogParser::Simple_immediate_assert_statementContext * /*ctx*/) override { }

  virtual void enterSimple_immediate_assume_statement(SysVerilogParser::Simple_immediate_assume_statementContext * /*ctx*/) override { }
  virtual void exitSimple_immediate_assume_statement(SysVerilogParser::Simple_immediate_assume_statementContext * /*ctx*/) override { }

  virtual void enterSimple_immediate_cover_statement(SysVerilogParser::Simple_immediate_cover_statementContext * /*ctx*/) override { }
  virtual void exitSimple_immediate_cover_statement(SysVerilogParser::Simple_immediate_cover_statementContext * /*ctx*/) override { }

  virtual void enterDeferred_immediate_assertion_statement(SysVerilogParser::Deferred_immediate_assertion_statementContext * /*ctx*/) override { }
  virtual void exitDeferred_immediate_assertion_statement(SysVerilogParser::Deferred_immediate_assertion_statementContext * /*ctx*/) override { }

  virtual void enterDeferred_immediate_assert_statement(SysVerilogParser::Deferred_immediate_assert_statementContext * /*ctx*/) override { }
  virtual void exitDeferred_immediate_assert_statement(SysVerilogParser::Deferred_immediate_assert_statementContext * /*ctx*/) override { }

  virtual void enterDeferred_immediate_assume_statement(SysVerilogParser::Deferred_immediate_assume_statementContext * /*ctx*/) override { }
  virtual void exitDeferred_immediate_assume_statement(SysVerilogParser::Deferred_immediate_assume_statementContext * /*ctx*/) override { }

  virtual void enterDeferred_immediate_cover_statement(SysVerilogParser::Deferred_immediate_cover_statementContext * /*ctx*/) override { }
  virtual void exitDeferred_immediate_cover_statement(SysVerilogParser::Deferred_immediate_cover_statementContext * /*ctx*/) override { }

  virtual void enterClocking_declaration(SysVerilogParser::Clocking_declarationContext * /*ctx*/) override { }
  virtual void exitClocking_declaration(SysVerilogParser::Clocking_declarationContext * /*ctx*/) override { }

  virtual void enterClocking_event(SysVerilogParser::Clocking_eventContext * /*ctx*/) override { }
  virtual void exitClocking_event(SysVerilogParser::Clocking_eventContext * /*ctx*/) override { }

  virtual void enterClocking_item(SysVerilogParser::Clocking_itemContext * /*ctx*/) override { }
  virtual void exitClocking_item(SysVerilogParser::Clocking_itemContext * /*ctx*/) override { }

  virtual void enterDefault_skew(SysVerilogParser::Default_skewContext * /*ctx*/) override { }
  virtual void exitDefault_skew(SysVerilogParser::Default_skewContext * /*ctx*/) override { }

  virtual void enterClocking_direction(SysVerilogParser::Clocking_directionContext * /*ctx*/) override { }
  virtual void exitClocking_direction(SysVerilogParser::Clocking_directionContext * /*ctx*/) override { }

  virtual void enterList_of_clocking_decl_assign(SysVerilogParser::List_of_clocking_decl_assignContext * /*ctx*/) override { }
  virtual void exitList_of_clocking_decl_assign(SysVerilogParser::List_of_clocking_decl_assignContext * /*ctx*/) override { }

  virtual void enterClocking_decl_assign(SysVerilogParser::Clocking_decl_assignContext * /*ctx*/) override { }
  virtual void exitClocking_decl_assign(SysVerilogParser::Clocking_decl_assignContext * /*ctx*/) override { }

  virtual void enterClocking_skew(SysVerilogParser::Clocking_skewContext * /*ctx*/) override { }
  virtual void exitClocking_skew(SysVerilogParser::Clocking_skewContext * /*ctx*/) override { }

  virtual void enterClocking_drive(SysVerilogParser::Clocking_driveContext * /*ctx*/) override { }
  virtual void exitClocking_drive(SysVerilogParser::Clocking_driveContext * /*ctx*/) override { }

  virtual void enterCycle_delay(SysVerilogParser::Cycle_delayContext * /*ctx*/) override { }
  virtual void exitCycle_delay(SysVerilogParser::Cycle_delayContext * /*ctx*/) override { }

  virtual void enterClockvar(SysVerilogParser::ClockvarContext * /*ctx*/) override { }
  virtual void exitClockvar(SysVerilogParser::ClockvarContext * /*ctx*/) override { }

  virtual void enterClockvar_expression(SysVerilogParser::Clockvar_expressionContext * /*ctx*/) override { }
  virtual void exitClockvar_expression(SysVerilogParser::Clockvar_expressionContext * /*ctx*/) override { }

  virtual void enterRandsequence_statement(SysVerilogParser::Randsequence_statementContext * /*ctx*/) override { }
  virtual void exitRandsequence_statement(SysVerilogParser::Randsequence_statementContext * /*ctx*/) override { }

  virtual void enterProduction(SysVerilogParser::ProductionContext * /*ctx*/) override { }
  virtual void exitProduction(SysVerilogParser::ProductionContext * /*ctx*/) override { }

  virtual void enterRs_rule(SysVerilogParser::Rs_ruleContext * /*ctx*/) override { }
  virtual void exitRs_rule(SysVerilogParser::Rs_ruleContext * /*ctx*/) override { }

  virtual void enterRs_production_list(SysVerilogParser::Rs_production_listContext * /*ctx*/) override { }
  virtual void exitRs_production_list(SysVerilogParser::Rs_production_listContext * /*ctx*/) override { }

  virtual void enterWeight_specification(SysVerilogParser::Weight_specificationContext * /*ctx*/) override { }
  virtual void exitWeight_specification(SysVerilogParser::Weight_specificationContext * /*ctx*/) override { }

  virtual void enterRs_code_block(SysVerilogParser::Rs_code_blockContext * /*ctx*/) override { }
  virtual void exitRs_code_block(SysVerilogParser::Rs_code_blockContext * /*ctx*/) override { }

  virtual void enterRs_prod(SysVerilogParser::Rs_prodContext * /*ctx*/) override { }
  virtual void exitRs_prod(SysVerilogParser::Rs_prodContext * /*ctx*/) override { }

  virtual void enterProduction_item(SysVerilogParser::Production_itemContext * /*ctx*/) override { }
  virtual void exitProduction_item(SysVerilogParser::Production_itemContext * /*ctx*/) override { }

  virtual void enterRs_if_else(SysVerilogParser::Rs_if_elseContext * /*ctx*/) override { }
  virtual void exitRs_if_else(SysVerilogParser::Rs_if_elseContext * /*ctx*/) override { }

  virtual void enterRs_repeat(SysVerilogParser::Rs_repeatContext * /*ctx*/) override { }
  virtual void exitRs_repeat(SysVerilogParser::Rs_repeatContext * /*ctx*/) override { }

  virtual void enterRs_case(SysVerilogParser::Rs_caseContext * /*ctx*/) override { }
  virtual void exitRs_case(SysVerilogParser::Rs_caseContext * /*ctx*/) override { }

  virtual void enterRs_case_item(SysVerilogParser::Rs_case_itemContext * /*ctx*/) override { }
  virtual void exitRs_case_item(SysVerilogParser::Rs_case_itemContext * /*ctx*/) override { }

  virtual void enterSpecify_block(SysVerilogParser::Specify_blockContext * /*ctx*/) override { }
  virtual void exitSpecify_block(SysVerilogParser::Specify_blockContext * /*ctx*/) override { }

  virtual void enterSpecify_item(SysVerilogParser::Specify_itemContext * /*ctx*/) override { }
  virtual void exitSpecify_item(SysVerilogParser::Specify_itemContext * /*ctx*/) override { }

  virtual void enterPulsestyle_declaration(SysVerilogParser::Pulsestyle_declarationContext * /*ctx*/) override { }
  virtual void exitPulsestyle_declaration(SysVerilogParser::Pulsestyle_declarationContext * /*ctx*/) override { }

  virtual void enterShowcancelled_declaration(SysVerilogParser::Showcancelled_declarationContext * /*ctx*/) override { }
  virtual void exitShowcancelled_declaration(SysVerilogParser::Showcancelled_declarationContext * /*ctx*/) override { }

  virtual void enterPath_declaration(SysVerilogParser::Path_declarationContext * /*ctx*/) override { }
  virtual void exitPath_declaration(SysVerilogParser::Path_declarationContext * /*ctx*/) override { }

  virtual void enterSimple_path_declaration(SysVerilogParser::Simple_path_declarationContext * /*ctx*/) override { }
  virtual void exitSimple_path_declaration(SysVerilogParser::Simple_path_declarationContext * /*ctx*/) override { }

  virtual void enterEdge_sensitive_path_declaration(SysVerilogParser::Edge_sensitive_path_declarationContext * /*ctx*/) override { }
  virtual void exitEdge_sensitive_path_declaration(SysVerilogParser::Edge_sensitive_path_declarationContext * /*ctx*/) override { }

  virtual void enterParallel_path_description(SysVerilogParser::Parallel_path_descriptionContext * /*ctx*/) override { }
  virtual void exitParallel_path_description(SysVerilogParser::Parallel_path_descriptionContext * /*ctx*/) override { }

  virtual void enterParallel_edge_sensitive_path_description(SysVerilogParser::Parallel_edge_sensitive_path_descriptionContext * /*ctx*/) override { }
  virtual void exitParallel_edge_sensitive_path_description(SysVerilogParser::Parallel_edge_sensitive_path_descriptionContext * /*ctx*/) override { }

  virtual void enterFull_path_description(SysVerilogParser::Full_path_descriptionContext * /*ctx*/) override { }
  virtual void exitFull_path_description(SysVerilogParser::Full_path_descriptionContext * /*ctx*/) override { }

  virtual void enterFull_edge_sensitive_path_description(SysVerilogParser::Full_edge_sensitive_path_descriptionContext * /*ctx*/) override { }
  virtual void exitFull_edge_sensitive_path_description(SysVerilogParser::Full_edge_sensitive_path_descriptionContext * /*ctx*/) override { }

  virtual void enterList_of_path_inputs(SysVerilogParser::List_of_path_inputsContext * /*ctx*/) override { }
  virtual void exitList_of_path_inputs(SysVerilogParser::List_of_path_inputsContext * /*ctx*/) override { }

  virtual void enterList_of_path_outputs(SysVerilogParser::List_of_path_outputsContext * /*ctx*/) override { }
  virtual void exitList_of_path_outputs(SysVerilogParser::List_of_path_outputsContext * /*ctx*/) override { }

  virtual void enterSpecify_input_terminal_descriptor(SysVerilogParser::Specify_input_terminal_descriptorContext * /*ctx*/) override { }
  virtual void exitSpecify_input_terminal_descriptor(SysVerilogParser::Specify_input_terminal_descriptorContext * /*ctx*/) override { }

  virtual void enterSpecify_output_terminal_descriptor(SysVerilogParser::Specify_output_terminal_descriptorContext * /*ctx*/) override { }
  virtual void exitSpecify_output_terminal_descriptor(SysVerilogParser::Specify_output_terminal_descriptorContext * /*ctx*/) override { }

  virtual void enterInput_identifier(SysVerilogParser::Input_identifierContext * /*ctx*/) override { }
  virtual void exitInput_identifier(SysVerilogParser::Input_identifierContext * /*ctx*/) override { }

  virtual void enterOutput_identifier(SysVerilogParser::Output_identifierContext * /*ctx*/) override { }
  virtual void exitOutput_identifier(SysVerilogParser::Output_identifierContext * /*ctx*/) override { }

  virtual void enterPath_delay_value(SysVerilogParser::Path_delay_valueContext * /*ctx*/) override { }
  virtual void exitPath_delay_value(SysVerilogParser::Path_delay_valueContext * /*ctx*/) override { }

  virtual void enterList_of_path_delay_expressions(SysVerilogParser::List_of_path_delay_expressionsContext * /*ctx*/) override { }
  virtual void exitList_of_path_delay_expressions(SysVerilogParser::List_of_path_delay_expressionsContext * /*ctx*/) override { }

  virtual void enterPath_delay_expression(SysVerilogParser::Path_delay_expressionContext * /*ctx*/) override { }
  virtual void exitPath_delay_expression(SysVerilogParser::Path_delay_expressionContext * /*ctx*/) override { }

  virtual void enterData_source_expression(SysVerilogParser::Data_source_expressionContext * /*ctx*/) override { }
  virtual void exitData_source_expression(SysVerilogParser::Data_source_expressionContext * /*ctx*/) override { }

  virtual void enterEdge_identifier(SysVerilogParser::Edge_identifierContext * /*ctx*/) override { }
  virtual void exitEdge_identifier(SysVerilogParser::Edge_identifierContext * /*ctx*/) override { }

  virtual void enterState_dependent_path_declaration(SysVerilogParser::State_dependent_path_declarationContext * /*ctx*/) override { }
  virtual void exitState_dependent_path_declaration(SysVerilogParser::State_dependent_path_declarationContext * /*ctx*/) override { }

  virtual void enterPolarity_operator(SysVerilogParser::Polarity_operatorContext * /*ctx*/) override { }
  virtual void exitPolarity_operator(SysVerilogParser::Polarity_operatorContext * /*ctx*/) override { }

  virtual void enterSystem_timing_check(SysVerilogParser::System_timing_checkContext * /*ctx*/) override { }
  virtual void exitSystem_timing_check(SysVerilogParser::System_timing_checkContext * /*ctx*/) override { }

  virtual void enterSetup_timing_check(SysVerilogParser::Setup_timing_checkContext * /*ctx*/) override { }
  virtual void exitSetup_timing_check(SysVerilogParser::Setup_timing_checkContext * /*ctx*/) override { }

  virtual void enterHold_timing_check(SysVerilogParser::Hold_timing_checkContext * /*ctx*/) override { }
  virtual void exitHold_timing_check(SysVerilogParser::Hold_timing_checkContext * /*ctx*/) override { }

  virtual void enterSetuphold_timing_check(SysVerilogParser::Setuphold_timing_checkContext * /*ctx*/) override { }
  virtual void exitSetuphold_timing_check(SysVerilogParser::Setuphold_timing_checkContext * /*ctx*/) override { }

  virtual void enterRecovery_timing_check(SysVerilogParser::Recovery_timing_checkContext * /*ctx*/) override { }
  virtual void exitRecovery_timing_check(SysVerilogParser::Recovery_timing_checkContext * /*ctx*/) override { }

  virtual void enterRemoval_timing_check(SysVerilogParser::Removal_timing_checkContext * /*ctx*/) override { }
  virtual void exitRemoval_timing_check(SysVerilogParser::Removal_timing_checkContext * /*ctx*/) override { }

  virtual void enterRecrem_timing_check(SysVerilogParser::Recrem_timing_checkContext * /*ctx*/) override { }
  virtual void exitRecrem_timing_check(SysVerilogParser::Recrem_timing_checkContext * /*ctx*/) override { }

  virtual void enterSkew_timing_check(SysVerilogParser::Skew_timing_checkContext * /*ctx*/) override { }
  virtual void exitSkew_timing_check(SysVerilogParser::Skew_timing_checkContext * /*ctx*/) override { }

  virtual void enterTimeskew_timing_check(SysVerilogParser::Timeskew_timing_checkContext * /*ctx*/) override { }
  virtual void exitTimeskew_timing_check(SysVerilogParser::Timeskew_timing_checkContext * /*ctx*/) override { }

  virtual void enterFullskew_timing_check(SysVerilogParser::Fullskew_timing_checkContext * /*ctx*/) override { }
  virtual void exitFullskew_timing_check(SysVerilogParser::Fullskew_timing_checkContext * /*ctx*/) override { }

  virtual void enterPeriod_timing_check(SysVerilogParser::Period_timing_checkContext * /*ctx*/) override { }
  virtual void exitPeriod_timing_check(SysVerilogParser::Period_timing_checkContext * /*ctx*/) override { }

  virtual void enterWidth_timing_check(SysVerilogParser::Width_timing_checkContext * /*ctx*/) override { }
  virtual void exitWidth_timing_check(SysVerilogParser::Width_timing_checkContext * /*ctx*/) override { }

  virtual void enterNochange_timing_check(SysVerilogParser::Nochange_timing_checkContext * /*ctx*/) override { }
  virtual void exitNochange_timing_check(SysVerilogParser::Nochange_timing_checkContext * /*ctx*/) override { }

  virtual void enterTimecheck_condition(SysVerilogParser::Timecheck_conditionContext * /*ctx*/) override { }
  virtual void exitTimecheck_condition(SysVerilogParser::Timecheck_conditionContext * /*ctx*/) override { }

  virtual void enterControlled_reference_event(SysVerilogParser::Controlled_reference_eventContext * /*ctx*/) override { }
  virtual void exitControlled_reference_event(SysVerilogParser::Controlled_reference_eventContext * /*ctx*/) override { }

  virtual void enterData_event(SysVerilogParser::Data_eventContext * /*ctx*/) override { }
  virtual void exitData_event(SysVerilogParser::Data_eventContext * /*ctx*/) override { }

  virtual void enterDelayed_data(SysVerilogParser::Delayed_dataContext * /*ctx*/) override { }
  virtual void exitDelayed_data(SysVerilogParser::Delayed_dataContext * /*ctx*/) override { }

  virtual void enterDelayed_reference(SysVerilogParser::Delayed_referenceContext * /*ctx*/) override { }
  virtual void exitDelayed_reference(SysVerilogParser::Delayed_referenceContext * /*ctx*/) override { }

  virtual void enterEnd_edge_offset(SysVerilogParser::End_edge_offsetContext * /*ctx*/) override { }
  virtual void exitEnd_edge_offset(SysVerilogParser::End_edge_offsetContext * /*ctx*/) override { }

  virtual void enterEvent_based_flag(SysVerilogParser::Event_based_flagContext * /*ctx*/) override { }
  virtual void exitEvent_based_flag(SysVerilogParser::Event_based_flagContext * /*ctx*/) override { }

  virtual void enterNotifier(SysVerilogParser::NotifierContext * /*ctx*/) override { }
  virtual void exitNotifier(SysVerilogParser::NotifierContext * /*ctx*/) override { }

  virtual void enterReference_event(SysVerilogParser::Reference_eventContext * /*ctx*/) override { }
  virtual void exitReference_event(SysVerilogParser::Reference_eventContext * /*ctx*/) override { }

  virtual void enterRemain_active_flag(SysVerilogParser::Remain_active_flagContext * /*ctx*/) override { }
  virtual void exitRemain_active_flag(SysVerilogParser::Remain_active_flagContext * /*ctx*/) override { }

  virtual void enterTimestamp_condition(SysVerilogParser::Timestamp_conditionContext * /*ctx*/) override { }
  virtual void exitTimestamp_condition(SysVerilogParser::Timestamp_conditionContext * /*ctx*/) override { }

  virtual void enterStart_edge_offset(SysVerilogParser::Start_edge_offsetContext * /*ctx*/) override { }
  virtual void exitStart_edge_offset(SysVerilogParser::Start_edge_offsetContext * /*ctx*/) override { }

  virtual void enterThreshold(SysVerilogParser::ThresholdContext * /*ctx*/) override { }
  virtual void exitThreshold(SysVerilogParser::ThresholdContext * /*ctx*/) override { }

  virtual void enterTiming_check_limit(SysVerilogParser::Timing_check_limitContext * /*ctx*/) override { }
  virtual void exitTiming_check_limit(SysVerilogParser::Timing_check_limitContext * /*ctx*/) override { }

  virtual void enterTiming_check_event(SysVerilogParser::Timing_check_eventContext * /*ctx*/) override { }
  virtual void exitTiming_check_event(SysVerilogParser::Timing_check_eventContext * /*ctx*/) override { }

  virtual void enterControlled_timing_check_event(SysVerilogParser::Controlled_timing_check_eventContext * /*ctx*/) override { }
  virtual void exitControlled_timing_check_event(SysVerilogParser::Controlled_timing_check_eventContext * /*ctx*/) override { }

  virtual void enterTiming_check_event_control(SysVerilogParser::Timing_check_event_controlContext * /*ctx*/) override { }
  virtual void exitTiming_check_event_control(SysVerilogParser::Timing_check_event_controlContext * /*ctx*/) override { }

  virtual void enterSpecify_terminal_descriptor(SysVerilogParser::Specify_terminal_descriptorContext * /*ctx*/) override { }
  virtual void exitSpecify_terminal_descriptor(SysVerilogParser::Specify_terminal_descriptorContext * /*ctx*/) override { }

  virtual void enterEdge_control_specifier(SysVerilogParser::Edge_control_specifierContext * /*ctx*/) override { }
  virtual void exitEdge_control_specifier(SysVerilogParser::Edge_control_specifierContext * /*ctx*/) override { }

  virtual void enterEdge_descriptor(SysVerilogParser::Edge_descriptorContext * /*ctx*/) override { }
  virtual void exitEdge_descriptor(SysVerilogParser::Edge_descriptorContext * /*ctx*/) override { }

  virtual void enterTiming_check_condition(SysVerilogParser::Timing_check_conditionContext * /*ctx*/) override { }
  virtual void exitTiming_check_condition(SysVerilogParser::Timing_check_conditionContext * /*ctx*/) override { }

  virtual void enterScalar_timing_check_condition(SysVerilogParser::Scalar_timing_check_conditionContext * /*ctx*/) override { }
  virtual void exitScalar_timing_check_condition(SysVerilogParser::Scalar_timing_check_conditionContext * /*ctx*/) override { }

  virtual void enterScalar_constant(SysVerilogParser::Scalar_constantContext * /*ctx*/) override { }
  virtual void exitScalar_constant(SysVerilogParser::Scalar_constantContext * /*ctx*/) override { }

  virtual void enterConcatenation(SysVerilogParser::ConcatenationContext * /*ctx*/) override { }
  virtual void exitConcatenation(SysVerilogParser::ConcatenationContext * /*ctx*/) override { }

  virtual void enterConstant_concatenation(SysVerilogParser::Constant_concatenationContext * /*ctx*/) override { }
  virtual void exitConstant_concatenation(SysVerilogParser::Constant_concatenationContext * /*ctx*/) override { }

  virtual void enterConstant_multiple_concatenation(SysVerilogParser::Constant_multiple_concatenationContext * /*ctx*/) override { }
  virtual void exitConstant_multiple_concatenation(SysVerilogParser::Constant_multiple_concatenationContext * /*ctx*/) override { }

  virtual void enterModule_path_concatenation(SysVerilogParser::Module_path_concatenationContext * /*ctx*/) override { }
  virtual void exitModule_path_concatenation(SysVerilogParser::Module_path_concatenationContext * /*ctx*/) override { }

  virtual void enterModule_path_multiple_concatenation(SysVerilogParser::Module_path_multiple_concatenationContext * /*ctx*/) override { }
  virtual void exitModule_path_multiple_concatenation(SysVerilogParser::Module_path_multiple_concatenationContext * /*ctx*/) override { }

  virtual void enterMultiple_concatenation(SysVerilogParser::Multiple_concatenationContext * /*ctx*/) override { }
  virtual void exitMultiple_concatenation(SysVerilogParser::Multiple_concatenationContext * /*ctx*/) override { }

  virtual void enterStreaming_concatenation(SysVerilogParser::Streaming_concatenationContext * /*ctx*/) override { }
  virtual void exitStreaming_concatenation(SysVerilogParser::Streaming_concatenationContext * /*ctx*/) override { }

  virtual void enterStream_operator(SysVerilogParser::Stream_operatorContext * /*ctx*/) override { }
  virtual void exitStream_operator(SysVerilogParser::Stream_operatorContext * /*ctx*/) override { }

  virtual void enterSlice_size(SysVerilogParser::Slice_sizeContext * /*ctx*/) override { }
  virtual void exitSlice_size(SysVerilogParser::Slice_sizeContext * /*ctx*/) override { }

  virtual void enterStream_concatenation(SysVerilogParser::Stream_concatenationContext * /*ctx*/) override { }
  virtual void exitStream_concatenation(SysVerilogParser::Stream_concatenationContext * /*ctx*/) override { }

  virtual void enterStream_expression(SysVerilogParser::Stream_expressionContext * /*ctx*/) override { }
  virtual void exitStream_expression(SysVerilogParser::Stream_expressionContext * /*ctx*/) override { }

  virtual void enterArray_range_expression(SysVerilogParser::Array_range_expressionContext * /*ctx*/) override { }
  virtual void exitArray_range_expression(SysVerilogParser::Array_range_expressionContext * /*ctx*/) override { }

  virtual void enterEmpty_queue(SysVerilogParser::Empty_queueContext * /*ctx*/) override { }
  virtual void exitEmpty_queue(SysVerilogParser::Empty_queueContext * /*ctx*/) override { }

  virtual void enterTf_call(SysVerilogParser::Tf_callContext * /*ctx*/) override { }
  virtual void exitTf_call(SysVerilogParser::Tf_callContext * /*ctx*/) override { }

  virtual void enterMethod_call(SysVerilogParser::Method_callContext * /*ctx*/) override { }
  virtual void exitMethod_call(SysVerilogParser::Method_callContext * /*ctx*/) override { }

  virtual void enterSystem_tf_call(SysVerilogParser::System_tf_callContext * /*ctx*/) override { }
  virtual void exitSystem_tf_call(SysVerilogParser::System_tf_callContext * /*ctx*/) override { }

  virtual void enterSubroutine_call(SysVerilogParser::Subroutine_callContext * /*ctx*/) override { }
  virtual void exitSubroutine_call(SysVerilogParser::Subroutine_callContext * /*ctx*/) override { }

  virtual void enterArgument(SysVerilogParser::ArgumentContext * /*ctx*/) override { }
  virtual void exitArgument(SysVerilogParser::ArgumentContext * /*ctx*/) override { }

  virtual void enterList_of_arguments(SysVerilogParser::List_of_argumentsContext * /*ctx*/) override { }
  virtual void exitList_of_arguments(SysVerilogParser::List_of_argumentsContext * /*ctx*/) override { }

  virtual void enterArray_manipulation_call(SysVerilogParser::Array_manipulation_callContext * /*ctx*/) override { }
  virtual void exitArray_manipulation_call(SysVerilogParser::Array_manipulation_callContext * /*ctx*/) override { }

  virtual void enterRandomize_call(SysVerilogParser::Randomize_callContext * /*ctx*/) override { }
  virtual void exitRandomize_call(SysVerilogParser::Randomize_callContext * /*ctx*/) override { }

  virtual void enterMethod_name(SysVerilogParser::Method_nameContext * /*ctx*/) override { }
  virtual void exitMethod_name(SysVerilogParser::Method_nameContext * /*ctx*/) override { }

  virtual void enterArray_method_name(SysVerilogParser::Array_method_nameContext * /*ctx*/) override { }
  virtual void exitArray_method_name(SysVerilogParser::Array_method_nameContext * /*ctx*/) override { }

  virtual void enterInc_or_dec_expression(SysVerilogParser::Inc_or_dec_expressionContext * /*ctx*/) override { }
  virtual void exitInc_or_dec_expression(SysVerilogParser::Inc_or_dec_expressionContext * /*ctx*/) override { }

  virtual void enterConstant_expression(SysVerilogParser::Constant_expressionContext * /*ctx*/) override { }
  virtual void exitConstant_expression(SysVerilogParser::Constant_expressionContext * /*ctx*/) override { }

  virtual void enterConstant_mintypmax_expression(SysVerilogParser::Constant_mintypmax_expressionContext * /*ctx*/) override { }
  virtual void exitConstant_mintypmax_expression(SysVerilogParser::Constant_mintypmax_expressionContext * /*ctx*/) override { }

  virtual void enterConstant_param_expression(SysVerilogParser::Constant_param_expressionContext * /*ctx*/) override { }
  virtual void exitConstant_param_expression(SysVerilogParser::Constant_param_expressionContext * /*ctx*/) override { }

  virtual void enterParam_expression(SysVerilogParser::Param_expressionContext * /*ctx*/) override { }
  virtual void exitParam_expression(SysVerilogParser::Param_expressionContext * /*ctx*/) override { }

  virtual void enterConstant_range_expression(SysVerilogParser::Constant_range_expressionContext * /*ctx*/) override { }
  virtual void exitConstant_range_expression(SysVerilogParser::Constant_range_expressionContext * /*ctx*/) override { }

  virtual void enterConstant_part_select_range(SysVerilogParser::Constant_part_select_rangeContext * /*ctx*/) override { }
  virtual void exitConstant_part_select_range(SysVerilogParser::Constant_part_select_rangeContext * /*ctx*/) override { }

  virtual void enterConstant_range(SysVerilogParser::Constant_rangeContext * /*ctx*/) override { }
  virtual void exitConstant_range(SysVerilogParser::Constant_rangeContext * /*ctx*/) override { }

  virtual void enterConstant_indexed_range(SysVerilogParser::Constant_indexed_rangeContext * /*ctx*/) override { }
  virtual void exitConstant_indexed_range(SysVerilogParser::Constant_indexed_rangeContext * /*ctx*/) override { }

  virtual void enterExpression(SysVerilogParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(SysVerilogParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterConditional_expression(SysVerilogParser::Conditional_expressionContext * /*ctx*/) override { }
  virtual void exitConditional_expression(SysVerilogParser::Conditional_expressionContext * /*ctx*/) override { }

  virtual void enterTagged_union_expression(SysVerilogParser::Tagged_union_expressionContext * /*ctx*/) override { }
  virtual void exitTagged_union_expression(SysVerilogParser::Tagged_union_expressionContext * /*ctx*/) override { }

  virtual void enterValue_range(SysVerilogParser::Value_rangeContext * /*ctx*/) override { }
  virtual void exitValue_range(SysVerilogParser::Value_rangeContext * /*ctx*/) override { }

  virtual void enterMintypmax_expression(SysVerilogParser::Mintypmax_expressionContext * /*ctx*/) override { }
  virtual void exitMintypmax_expression(SysVerilogParser::Mintypmax_expressionContext * /*ctx*/) override { }

  virtual void enterModule_path_conditional_expression(SysVerilogParser::Module_path_conditional_expressionContext * /*ctx*/) override { }
  virtual void exitModule_path_conditional_expression(SysVerilogParser::Module_path_conditional_expressionContext * /*ctx*/) override { }

  virtual void enterModule_path_expression(SysVerilogParser::Module_path_expressionContext * /*ctx*/) override { }
  virtual void exitModule_path_expression(SysVerilogParser::Module_path_expressionContext * /*ctx*/) override { }

  virtual void enterModule_path_mintypmax_expression(SysVerilogParser::Module_path_mintypmax_expressionContext * /*ctx*/) override { }
  virtual void exitModule_path_mintypmax_expression(SysVerilogParser::Module_path_mintypmax_expressionContext * /*ctx*/) override { }

  virtual void enterPart_select_range(SysVerilogParser::Part_select_rangeContext * /*ctx*/) override { }
  virtual void exitPart_select_range(SysVerilogParser::Part_select_rangeContext * /*ctx*/) override { }

  virtual void enterIndexed_range(SysVerilogParser::Indexed_rangeContext * /*ctx*/) override { }
  virtual void exitIndexed_range(SysVerilogParser::Indexed_rangeContext * /*ctx*/) override { }

  virtual void enterGenvar_expression(SysVerilogParser::Genvar_expressionContext * /*ctx*/) override { }
  virtual void exitGenvar_expression(SysVerilogParser::Genvar_expressionContext * /*ctx*/) override { }

  virtual void enterConstant_primary(SysVerilogParser::Constant_primaryContext * /*ctx*/) override { }
  virtual void exitConstant_primary(SysVerilogParser::Constant_primaryContext * /*ctx*/) override { }

  virtual void enterModule_path_primary(SysVerilogParser::Module_path_primaryContext * /*ctx*/) override { }
  virtual void exitModule_path_primary(SysVerilogParser::Module_path_primaryContext * /*ctx*/) override { }

  virtual void enterPrimary(SysVerilogParser::PrimaryContext * /*ctx*/) override { }
  virtual void exitPrimary(SysVerilogParser::PrimaryContext * /*ctx*/) override { }

  virtual void enterClass_qualifier(SysVerilogParser::Class_qualifierContext * /*ctx*/) override { }
  virtual void exitClass_qualifier(SysVerilogParser::Class_qualifierContext * /*ctx*/) override { }

  virtual void enterRange_expression(SysVerilogParser::Range_expressionContext * /*ctx*/) override { }
  virtual void exitRange_expression(SysVerilogParser::Range_expressionContext * /*ctx*/) override { }

  virtual void enterPrimary_literal(SysVerilogParser::Primary_literalContext * /*ctx*/) override { }
  virtual void exitPrimary_literal(SysVerilogParser::Primary_literalContext * /*ctx*/) override { }

  virtual void enterTime_literal(SysVerilogParser::Time_literalContext * /*ctx*/) override { }
  virtual void exitTime_literal(SysVerilogParser::Time_literalContext * /*ctx*/) override { }

  virtual void enterTime_unit(SysVerilogParser::Time_unitContext * /*ctx*/) override { }
  virtual void exitTime_unit(SysVerilogParser::Time_unitContext * /*ctx*/) override { }

  virtual void enterImplicit_class_handle(SysVerilogParser::Implicit_class_handleContext * /*ctx*/) override { }
  virtual void exitImplicit_class_handle(SysVerilogParser::Implicit_class_handleContext * /*ctx*/) override { }

  virtual void enterBit_select(SysVerilogParser::Bit_selectContext * /*ctx*/) override { }
  virtual void exitBit_select(SysVerilogParser::Bit_selectContext * /*ctx*/) override { }

  virtual void enterSelect(SysVerilogParser::SelectContext * /*ctx*/) override { }
  virtual void exitSelect(SysVerilogParser::SelectContext * /*ctx*/) override { }

  virtual void enterNonrange_select(SysVerilogParser::Nonrange_selectContext * /*ctx*/) override { }
  virtual void exitNonrange_select(SysVerilogParser::Nonrange_selectContext * /*ctx*/) override { }

  virtual void enterConstant_bit_select(SysVerilogParser::Constant_bit_selectContext * /*ctx*/) override { }
  virtual void exitConstant_bit_select(SysVerilogParser::Constant_bit_selectContext * /*ctx*/) override { }

  virtual void enterConstant_select(SysVerilogParser::Constant_selectContext * /*ctx*/) override { }
  virtual void exitConstant_select(SysVerilogParser::Constant_selectContext * /*ctx*/) override { }

  virtual void enterConstant_cast(SysVerilogParser::Constant_castContext * /*ctx*/) override { }
  virtual void exitConstant_cast(SysVerilogParser::Constant_castContext * /*ctx*/) override { }

  virtual void enterConstant_let_expression(SysVerilogParser::Constant_let_expressionContext * /*ctx*/) override { }
  virtual void exitConstant_let_expression(SysVerilogParser::Constant_let_expressionContext * /*ctx*/) override { }

  virtual void enterCast(SysVerilogParser::CastContext * /*ctx*/) override { }
  virtual void exitCast(SysVerilogParser::CastContext * /*ctx*/) override { }

  virtual void enterNet_lvalue(SysVerilogParser::Net_lvalueContext * /*ctx*/) override { }
  virtual void exitNet_lvalue(SysVerilogParser::Net_lvalueContext * /*ctx*/) override { }

  virtual void enterVariable_lvalue(SysVerilogParser::Variable_lvalueContext * /*ctx*/) override { }
  virtual void exitVariable_lvalue(SysVerilogParser::Variable_lvalueContext * /*ctx*/) override { }

  virtual void enterNonrange_variable_lvalue(SysVerilogParser::Nonrange_variable_lvalueContext * /*ctx*/) override { }
  virtual void exitNonrange_variable_lvalue(SysVerilogParser::Nonrange_variable_lvalueContext * /*ctx*/) override { }

  virtual void enterUnary_operator(SysVerilogParser::Unary_operatorContext * /*ctx*/) override { }
  virtual void exitUnary_operator(SysVerilogParser::Unary_operatorContext * /*ctx*/) override { }

  virtual void enterBinary_operator(SysVerilogParser::Binary_operatorContext * /*ctx*/) override { }
  virtual void exitBinary_operator(SysVerilogParser::Binary_operatorContext * /*ctx*/) override { }

  virtual void enterInc_or_dec_operator(SysVerilogParser::Inc_or_dec_operatorContext * /*ctx*/) override { }
  virtual void exitInc_or_dec_operator(SysVerilogParser::Inc_or_dec_operatorContext * /*ctx*/) override { }

  virtual void enterUnary_module_path_operator(SysVerilogParser::Unary_module_path_operatorContext * /*ctx*/) override { }
  virtual void exitUnary_module_path_operator(SysVerilogParser::Unary_module_path_operatorContext * /*ctx*/) override { }

  virtual void enterBinary_module_path_operator(SysVerilogParser::Binary_module_path_operatorContext * /*ctx*/) override { }
  virtual void exitBinary_module_path_operator(SysVerilogParser::Binary_module_path_operatorContext * /*ctx*/) override { }

  virtual void enterNumber(SysVerilogParser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(SysVerilogParser::NumberContext * /*ctx*/) override { }

  virtual void enterPackage_scope(SysVerilogParser::Package_scopeContext * /*ctx*/) override { }
  virtual void exitPackage_scope(SysVerilogParser::Package_scopeContext * /*ctx*/) override { }

  virtual void enterPsid(SysVerilogParser::PsidContext * /*ctx*/) override { }
  virtual void exitPsid(SysVerilogParser::PsidContext * /*ctx*/) override { }

  virtual void enterHierid(SysVerilogParser::HieridContext * /*ctx*/) override { }
  virtual void exitHierid(SysVerilogParser::HieridContext * /*ctx*/) override { }

  virtual void enterSs(SysVerilogParser::SsContext * /*ctx*/) override { }
  virtual void exitSs(SysVerilogParser::SsContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

