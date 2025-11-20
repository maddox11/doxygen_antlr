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

#find_package(Javacc)
#if (JAVACC_FOUND)
#    if (JAVACC_VERSION VERSION_LESS 7.0.6)
#        message(STATUS "  Doxygen requires at least JavaCC version 7.0.6 (installed: ${JAVACC_VERSION})")
#	message(STATUS "  Fall back to JavaCC not installed, using existing files.")
#    else()
#        add_custom_command(
#	    COMMAND ${JAVACC_EXECUTABLE} ${JAVACC_FLAGS} -OUTPUT_DIRECTORY=${PROJECT_SOURCE_DIR}/src/sysverilogparser/preprocessor ${PROJECT_SOURCE_DIR}/src/sysverilogparser/preprocessor/pre.jj
#            DEPENDS ${PROJECT_SOURCE_DIR}/src/sysverilogparser/preprocessor/pre.jj
#            OUTPUT ${PROJECT_SOURCE_DIR}/src/sysverilogparser/preprocessor/CharStream.cc ${PROJECT_SOURCE_DIR}/src/sysverilogparser/preprocessor/CharStream.h ${PROJECT_SOURCE_DIR}/src/sysverilogparser/preprocessor/ErrorHandler.h ${PROJECT_SOURCE_DIR}/src/sysverilogparser/preprocessor/PreProcessorErrorHandler.h ${PROJECT_SOURCE_DIR}/src/sysverilogparser/preprocessor/ParseException.cc ${PROJECT_SOURCE_DIR}/verilogparser/preprocessor/ParseException.h ${PROJECT_SOURCE_DIR}/src/sysverilogparser/preprocessor/Token.cc ${PROJECT_SOURCE_DIR}/src/sysverilogparser/preprocessor/Token.h ${PROJECT_SOURCE_DIR}/src/sysverilogparser/preprocessor/TokenManager.h ${PROJECT_SOURCE_DIR}/src/sysverilogparser/preprocessor/TokenMgrError.cc ${PROJECT_SOURCE_DIR}/src/sysverilogparse/preprocessor/TokenMgrError.h ${PROJECT_SOURCE_DIR}/src/sysverilogparser/preprocessor/VerilogPreProcessor.cc ${PROJECT_SOURCE_DIR}/src/sysverilogparser/preprocessor/VerilogPreProcessor.h ${PROJECT_SOURCE_DIR}/src/sysverilogparser/preprocessor/VerilogPreProcessorConstants.h ${PROJECT_SOURCE_DIR}/src/sysverilogparser/preprocessor/VerilogPreProcessorTokenManager.cc ${PROJECT_SOURCE_DIR}/src/sysverilogparser/preprocessor/VerilogPreProcessorTokenManager.h  ${PROJECT_SOURCE_DIR}/src/sysverilogparser/preprocessor/PrepParser.h ${PROJECT_SOURCE_DIR}/src/sysverilogparser/preprocessor/PrepParser.cpp
#        )
#    endif()
#endif()

#add_custom_command(
#    COMMAND ${PYTHON_EXECUTABLE} ${PROJECT_SOURCE_DIR}/verilogparser/preprocessor/verilogpreprocessor_adj.py ${PROJECT_SOURCE_DIR}/verilogparser/preprocessor/VerilogPreProcessor.cc ${GENERATED_SRC}/VerilogPreProcessor_adj.cc
#    DEPENDS ${PROJECT_SOURCE_DIR}/verilogparser/preprocessor/VerilogPreProcessor.cc  ${PROJECT_SOURCE_DIR}/verilogparser/preprocessor/verilogpreprocessor_adj.py
#    OUTPUT  ${GENERATED_SRC}/VerilogPreProcessor_adj.cc
#)
#set_source_files_properties(${GENERATED_SRC}/VerilogPreProcessor_adj.cc PROPERTIES GENERATED 1)

include_directories(
	${PROJECT_SOURCE_DIR}/src
	${PROJECT_SOURCE_DIR}/src/sysverilogparser
     ${PROJECT_SOURCE_DIR}/src/sysverilogparser/preprocessor
	${GENERATED_SRC})
add_library(verilogpreprocessor STATIC
CharStream.cc
ParseException.cc
Token.cc
TokenMgrError.cc
PrepParser.cpp
VerilogPreProcessor.cc
VerilogPreProcessorTokenManager.cc
)

add_dependencies(verilogpreprocessor
    generate_configvalues_header
)
