#
# Generate parser (default target)
#
# when generating the parser with debug options it will look like:
#   make JAVACC_FLAGS=-debug_parser
#  or
#   make JAVACC_FLAGS="-debug_parser -debug_lookahead"
#
# Available debug options:
#  -debug_parser
#  -debug_token_manager
#  -debug_lookahead
#
# For other javacc settings / options consult the documentation of javacc.

#find_package(Antlr4)
#if (ANTLR4_FOUND)
# set(ANTLR$_FLAG "-Dlanguage=Cpp") 
#        add_custom_command(
#	    COMMAND ${ANTLR$_EXECUTABLE} ${JAVACC_FLAGS} -o=${PROJECT_SOURCE_DIR}/exprparser ${PROJECT_SOURCE_DIR}/exprparser/ExprLexer.g4
#            DEPENDS ${PROJECT_SOURCE_DIR}/exprparser/ExprLexer.g4
#            OUTPUT ${PROJECT_SOURCE_DIR}/exprparser/ExprLexer.cpp ${PROJECT_SOURCE_DIR}/exprparser/ExprLexer.h 
#        )
#        
#        add_custom_command(
#	    COMMAND ${ANTLR$_EXECUTABLE} ${JAVACC_FLAGS} -o=${PROJECT_SOURCE_DIR}/exprparser ${PROJECT_SOURCE_DIR}/exprparser/ExprParser.g4
#            DEPENDS ${PROJECT_SOURCE_DIR}/exprparser/ExprLexer.g4
#            OUTPUT ${PROJECT_SOURCE_DIR}/exprparser/ExprParserParser.cpp ${PROJECT_SOURCE_DIR}/exprparser/ExprParserListener.cpp ${PROJECT_SOURCE_DIR}/exprparser/ExprParserBaseListener.cpp ${PROJECT_SOURCE_DIR}/exprparser/ExprParserParser.h ${PROJECT_SOURCE_DIR}/exprparser/ExprParserListener.h ${PROJECT_SOURCE_DIR}/exprparser/ExprParserBaseListener.h
#        )
#else()
#  message(STATUS "antlr4 package not found ")
#endif()




include_directories(
	${PROJECT_SOURCE_DIR}/src
	${PROJECT_SOURCE_DIR}/src/sysverilogparser/thirdparty/antlr4
	${PROJECT_SOURCE_DIR}/sysverilogparser/thirdparty
	${PROJECT_SOURCE_DIR}/vhdlparser
	${PROJECT_SOURCE_DIR}/src/sysverilogparser/preprocessor
	${PROJECT_SOURCE_DIR}/src/sysverilogparser
	${GENERATED_SRC})
add_library(sysverilogparser STATIC
SysVerilogParser.cpp
SysVerilogListener.cpp
SysVerilogBaseListener.cpp
SysVerilogLexer.cpp
MacroLexer.cpp
Expression.cpp
utility.cpp
sysverilog.cpp
)

add_dependencies(sysverilogparser
    generate_configvalues_header
)
